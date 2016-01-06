package de.fosd.jdime.dependencyGraph;

import com.sun.org.apache.xerces.internal.util.SynchronizedSymbolTable;
import de.fosd.jdime.util.IOFunctionSet;
import nu.xom.Element;
import nu.xom.Elements;
import org.apache.commons.io.FileUtils;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

/**
 * Created by shuruiz on 12/10/15.
 */
public class DependencyGraph {

    static IOFunctionSet ioFunctionSet = new IOFunctionSet();
    static HashSet<Symbol> symbolTable;
    static HashSet<Symbol> lonelySymbolSet;

    static HashMap<String, HashSet<Symbol>> sameNameMap;

    static File graph;
    static int id;
    static HashMap<String, Integer> nodeList;
    static HashSet<String> edgeList;
    static final public String NAMESPACEURI = "http://www.sdml.info/srcML/src";
    static final public boolean CONTROLFLOW = true;
    static final public String CONTROLFLOW_LABEL = "<Control-Flow>";

    /**
     * This function will parse the test directory and iteratively parse each file (.c/.cpp/.h)
     * to create dependency graph in each file
     *
     * @param testDir directory that contains .c/cpp/h files
     * @return edgeList for testing goal
     */
    public HashSet<String> createDependencyGraph(String testDir) {

        String dirPath = "testcpp/dependencyGraph/";
        String testDirPath = dirPath + testDir + "/";

        //create graph file
        graph = new File(testDirPath + "graph.gv");
        ioFunctionSet.rewriteFile("digraph {\n", graph.getPath());

        File dir = new File(testDirPath);
        String[] names = dir.list();

        symbolTable = new HashSet<>();
        lonelySymbolSet = new HashSet<>();
        sameNameMap = new HashMap<>();
        nodeList = new HashMap<>();
        edgeList = new HashSet<>();
        id = 0;

        for (String fileName : names) {
            if (fileName.endsWith(".cpp") || fileName.endsWith(".h") || fileName.endsWith(".c")) {
                String filePath = testDirPath + fileName;

                // src2srcml cannot parse .h file correctly, so change the suffix '+.cpp'
                if (fileName.endsWith(".h")) {
                    String newPath = "/Users/shuruiz/Work/tmpXMLFile" + filePath.replace("testcpp", "") + ".cpp";
                    try {
                        FileUtils.copyFile(new File(filePath), new File(newPath));
                        filePath = newPath;
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
                // get xml file using src2srcml
                String xmlFilePath = ioFunctionSet.getXmlFile(filePath);
                System.out.print(fileName + "\n");

                //parse dependency graph in each file
                Element root = ioFunctionSet.getXmlDom(xmlFilePath).getRootElement();
                storeSymbols(parseDependency(root, fileName, 1, ""));
            }
        }
        //create edges cross files
        addEdgesCrossFiles();

        ioFunctionSet.writeTofile("}", graph.getPath());
        return edgeList;
    }

    /**
     * This function store a set of symbols into Symbol table and nameMap.
     *
     * @param symbols hashSet of symbols
     */
//    private void storeSymbols(HashSet<Symbol> symbols) {
    private void storeSymbols(ArrayList<Symbol> symbols) {
        //add to symbol table
        symbolTable.addAll(symbols);

        //add to nameMap
        for (Symbol s : symbols) {
            if (s != null) {
                HashSet<Symbol> sameNameSymbols;
                if (!sameNameMap.containsKey(s.getName())) {
                    sameNameSymbols = new HashSet<>();
                    sameNameSymbols.add(s);
                    sameNameMap.put(s.getName(), sameNameSymbols);
                } else {
                    sameNameSymbols = sameNameMap.get(s.getName());
                    if (!sameNameSymbols.contains(s)) {
                        sameNameSymbols.add(s);
                    }
                }
            }
        }
    }


    /**
     * this function add edges cross files
     */
    private void addEdgesCrossFiles() {

        //add call-> function/func_decl
        for (Symbol dependent : lonelySymbolSet) {
            String tag = dependent.getTag();
            if (tag.equals("call")) {
                if (!dependent.getName().equals("printf")) {
                    addFuncDependency(dependent);
                }
            } else if (tag.equals("name")) {
                findVarDependency(dependent);
            }
        }
        //add function->func_decl
        for (Symbol dependent : symbolTable) {
            if (dependent != null) {
                String tag = dependent.getTag();
                if (tag.equals("function")) {
                    addFuncDependency(dependent);
                }
            }
        }
    }

    /**
     * This function is parsing the dependency graph in a tree
     *
     * @param root     root node for an AST
     * @param fileName prefix of the graph node (filename+line#)
     * @param scope    is the level of the declaration node. (1 means the symbol is in the file level, 2 means the symbol is in a function level)
     * @return symbol list for the AST
     */
    public ArrayList<Symbol> parseDependency(Element root, String fileName, int scope, String parentLocation) {
//    public HashSet<Symbol> parseDependency(Element root, String fileName, int scope, String parentLocation) {
//        HashSet<Symbol> tmpSymbolList = new HashSet<>();
        ArrayList<Symbol> tmpSymbolList = new ArrayList<>();
        Elements elements = root.getChildElements();

        for (int i = 0; i < elements.size(); i++) {
            Element ele = elements.get(i);
            if (ele.getLocalName().equals("ifdef") && ele.getNamespacePrefix().equals("cpp")) {
                String macroName = ele.getFirstChildElement("name", NAMESPACEURI).getValue();
                String line = ele.getAttribute(0).getValue();
                Symbol ifdef = new Symbol(macroName, "", line, "ifdef", fileName, scope);
                lonelySymbolSet.add(ifdef);
                storeIntoNodeList(line + "-" + fileName);
            } else if (ele.getLocalName().equals("define")) {
                String macroName = ele.getChildElements().get(1).getValue();
                String line = ele.getAttribute(0).getValue();
                Symbol macro = new Symbol(macroName, "", line, "macro", fileName, scope);
                storeIntoNodeList(line + "-" + fileName);
                tmpSymbolList.add(macro);

            } else if (ele.getLocalName().equals("if") && ele.getNamespacePrefix().equals("cpp")) {
                Element expr = ele.getFirstChildElement("expr", NAMESPACEURI);
                if (expr != null) {
                    findExpr(ele, "", fileName, scope, parentLocation, false);
                }
            } else if (ele.getLocalName().equals("function") || ele.getLocalName().equals("constructor")) {
                tmpSymbolList.addAll(parseFunctionNode(ele, fileName, scope));
            } else if (ele.getLocalName().equals("if") && !ele.getNamespacePrefix().equals("cpp")) {
                tmpSymbolList.addAll(parseIfStmt(ele, fileName, scope, parentLocation));
            } else if (ele.getLocalName().equals("while")) {
                //<while><condition><block>
                Element condition = ele.getFirstChildElement("condition", NAMESPACEURI);
                findExpr(condition, "", fileName, scope, parentLocation, false);
                //Block
                Element block = ele.getFirstChildElement("block", NAMESPACEURI);
//                tmpSymbolList.addAll(parseDependency(block, fileName, scope, parentLocation));
                String lineNumber = ele.getAttribute(0).getValue();
                String whileLocation = lineNumber + "-" + fileName;

                if (block != null) {
                    tmpSymbolList.addAll(parseDependency(block, fileName, scope + 1, whileLocation));
                }

                Element expr = ele.getFirstChildElement("expr_stmt", NAMESPACEURI);
                if (expr != null) {
                    findExpr(expr, "", fileName, scope, parentLocation, false);
                }
            } else if (ele.getLocalName().equals("expr_stmt")) {
                findExpr(ele, "", fileName, scope, parentLocation, false);
            } else if (ele.getLocalName().equals("decl_stmt")) {
                Element decl = ele.getFirstChildElement("decl", NAMESPACEURI);
                tmpSymbolList.add(findSymbol(decl, "decl_stmt", fileName, scope, parentLocation));
            } else if (ele.getLocalName().equals("struct")) {
                //struct
                Symbol parent = findSymbol(ele, "struct", fileName, scope, parentLocation);
                tmpSymbolList.add(parent);
                parentLocation = parent.getLineNumber() + "-" + fileName;
                //block
                Element block = ele.getFirstChildElement("block", NAMESPACEURI);
                for (int s = 0; s < block.getChildElements().size(); s++) {
                    Element group = block.getChildElements().get(s);

                    //get children
//                    HashSet<Symbol>
                    ArrayList<Symbol> children = parseDependency(group, fileName, scope, parentLocation);
                    tmpSymbolList.addAll(children);

                    //link children -> parent
                    linkChildToParent(children, parentLocation, "<belongToStruct>");
                }
            } else if (ele.getLocalName().equals("function_decl")) {
                tmpSymbolList.add(findSymbol(ele, "function_decl", fileName, scope, parentLocation));

            } else if (ele.getLocalName().equals("return")) {
                Element returnContent = ele.getFirstChildElement("expr", NAMESPACEURI);
                if (returnContent != null) {
                    findExpr(ele, "", fileName, scope, parentLocation, false);
                }
            } else if (ele.getLocalName().equals("for")) {

                tmpSymbolList.addAll(parseForStmt(ele, fileName, scope, parentLocation));
            }

            //remove symbol, whose scope >1
            if (((Element) ele.getParent()).getLocalName().equals("unit")) {
                symbolTable = removeLocalSymbol(symbolTable);
            }
        }


        return tmpSymbolList;
    }

    /**
     * this function remove the symbols that in the 2 level , prepare for find edge cross files
     *
     * @param tmpSymbolList symbol table
     * @return symbol table only contains 1st level symbols
     */
    private HashSet<Symbol> removeLocalSymbol(HashSet<Symbol> tmpSymbolList) {
        HashSet<Symbol> finalSymbolList = new HashSet<>();
        for (Symbol s : tmpSymbolList) {
            if (s.getScope() == 1)
                finalSymbolList.add(s);
        }
        return finalSymbolList;
    }

    /**
     * This function create the edge from a set of child to parent (used for struct)
     *
     * @param children       symbols belong to struct
     * @param parentLocation struct node
     */

//    private void linkChildToParent(HashSet<Symbol> children, String parentLocation, String label) {
    private void linkChildToParent(ArrayList<Symbol> children, String parentLocation, String label) {
        for (Symbol child : children) {
            String depenNodeLabel = child.getLineNumber() + "-" + child.getFileName();
            addEdgesToFile(depenNodeLabel, parentLocation, label);
        }
    }

    /**
     * This function link children to parent, used for block -> function, then-> if
     *
     * @param childLabel
     * @param parentLocation
     */
    private void linkChildToParent(String childLabel, String parentLocation) {
        if (!edgeList.contains(childLabel + "->" + parentLocation)) {
            addEdgesToFile(childLabel, parentLocation, "<child>");
        }
    }

    /**
     * This function parses the function node.
     * First, create symbol for the function, scope is 1
     * Second, use {@link #parseDependency(Element, String, int, String)} function to parse the <block> subtree
     *
     * @param element  function element
     * @param fileName current filename, used for mark dependency graph's node name (lineNumber-fileName)
     * @param scope    function's scope is 1, symbol in block is 2
     * @return symbolList in function scope
     */
    private HashSet<Symbol> parseFunctionNode(Element element, String fileName, int scope) {
        HashSet<Symbol> tmpSymbolList = new HashSet<>();

        //add function to symbol table
        Symbol functionSymbol = findSymbol(element, "function", fileName, scope, "");
        tmpSymbolList.add(functionSymbol);
        String parentLocation = functionSymbol.getLineNumber() + "-" + fileName;
        //check parameters
        Element parameter_list = element.getFirstChildElement("parameter_list", NAMESPACEURI);
        if (parameter_list.getChildElements() != null) {
            for (int i = 0; i < parameter_list.getChildElements("param", NAMESPACEURI).size(); i++) {
                Element paramNode = parameter_list.getChildElements("param", NAMESPACEURI).get(i);

                //add Parameter to symbol table
                tmpSymbolList.add(findSymbol((Element) paramNode.getChild(0), "param", fileName, scope + 1, parentLocation));
            }
        }

        //check block
        Element block = element.getFirstChildElement("block", NAMESPACEURI);

        tmpSymbolList.addAll(parseDependency(block, fileName, scope + 1, parentLocation));


        return tmpSymbolList;
    }

    /**
     * this function parse if statement
     *
     * @param ele      if  element
     * @param fileName fileName of this node
     * @param scope    level of the node
     * @return symbols
     */
    private HashSet<Symbol> parseIfStmt(Element ele, String fileName, int scope, String parentLocation) {
        HashSet<Symbol> tmpSymbolList = new HashSet<>();

        //<if><condition><then>[<else>], else is optional
        Element condition = ele.getFirstChildElement("condition", NAMESPACEURI);
        String ifStmtLocation = findExpr(condition, "", fileName, scope, parentLocation, false);

        //<then> [<block>], block is optional
        Element then_Node = ele.getFirstChildElement("then", NAMESPACEURI);
        ArrayList<Symbol> symbolsInThen;
        if (then_Node.getFirstChildElement("block", NAMESPACEURI) != null) {
            Element block = then_Node.getFirstChildElement("block", NAMESPACEURI);
            symbolsInThen = parseDependency(block, fileName, scope, ifStmtLocation);
        } else {
            symbolsInThen = parseDependency(then_Node, fileName, scope, ifStmtLocation);
        }

        tmpSymbolList.addAll(symbolsInThen);


        //else is optional
        Element else_Node = ele.getFirstChildElement("else", NAMESPACEURI);
        ArrayList<Symbol> symbolsInElse = null;
        if (else_Node != null) {
            if (else_Node.getFirstChildElement("block", NAMESPACEURI) != null) {
                Element block = else_Node.getFirstChildElement("block", NAMESPACEURI);
                symbolsInElse = parseDependency(block, fileName, scope, ifStmtLocation);
            } else {
                symbolsInElse = parseDependency(else_Node, fileName, scope, ifStmtLocation);
            }
            tmpSymbolList.addAll(symbolsInElse);
        }

        //add control flow dependency
        if (CONTROLFLOW) {
            addControlFlowDependency(ifStmtLocation, symbolsInThen, fileName);
            if (symbolsInElse.size() > 0) {
                addControlFlowDependency(ifStmtLocation, symbolsInElse, fileName);
            }
        }

        return tmpSymbolList;
    }


    private void addControlFlowDependency(String headLocation, ArrayList<Symbol> symbolList, String fileName) {
        addEdgesToFile(headLocation, symbolList.get(0), CONTROLFLOW_LABEL + " if-then");
        for (int i = 0; i < symbolList.size() - 1; i++) {
            String pre_loc = symbolList.get(i).getLineNumber() + "-" + fileName;
            String after_loc = symbolList.get(i + 1).getLineNumber() + "-" + fileName;
            addEdgesToFile(pre_loc, after_loc, CONTROLFLOW_LABEL);
        }
    }

    /**
     * This function parse for loop
     *
     * @param ele            for node
     * @param fileName
     * @param scope
     * @param parentLocation
     * @return tmpSymbolList
     */
//    private HashSet<Symbol> parseForStmt(Element ele, String fileName, int scope, String parentLocation) {
    private ArrayList<Symbol> parseForStmt(Element ele, String fileName, int scope, String parentLocation) {
//        HashSet<Symbol> tmpSymbolList = new HashSet<>();
        ArrayList<Symbol> tmpSymbolList = new ArrayList<>();

        Element init = ele.getFirstChildElement("init", NAMESPACEURI).getFirstChildElement("decl", NAMESPACEURI);
        Symbol initVarSymbol = findSymbol(init, "for", fileName, scope, parentLocation);
        tmpSymbolList.add(initVarSymbol);
        String lineNumber = ele.getAttribute(0).getValue();
        String forLocation = lineNumber + "-" + fileName;

        Element block = ele.getFirstChildElement("block", NAMESPACEURI);
        if (block != null) {
            tmpSymbolList.addAll(parseDependency(block, fileName, scope + 1, forLocation));
        }

        Element expr = ele.getFirstChildElement("expr_stmt", NAMESPACEURI);
        if (expr != null) {
            findExpr(expr, "", fileName, scope, parentLocation, false);
        }

        return tmpSymbolList;
    }

    /**
     * This function finds symbol and add it to symbolTable
     * <decl_stmt><decl><type><name> [<init>]
     *
     * @param element  declaration element
     * @param tag      srcml tag
     * @param fileName current filename, used for mark dependency graph's node name (lineNumber-fileName)
     * @param scope    function's scope is 1, symbol in block is 2
     * @return new symbol
     */
    private Symbol findSymbol(Element element, String tag, String fileName, int scope, String parentLocation) {
        String type;
        Element type_Node = element.getFirstChildElement("type", NAMESPACEURI);
        if (type_Node != null) {
            type = type_Node.getValue();
        } else {
            type = "";
        }

        Symbol symbol = null;
        Element nameElement = element.getFirstChildElement("name", NAMESPACEURI);
        if (nameElement != null) {
            String name = nameElement.getValue();

//        String className="";
            if (name.contains("::")) {
//            className =name.split("::")[0];
                name = name.split("::")[1];
            }

            String lineNumber;
            if (nameElement.getAttributeCount() > 0) {
                lineNumber = nameElement.getAttribute(0).getValue();
            } else {
                lineNumber = nameElement.getFirstChildElement("name", NAMESPACEURI).getAttribute(0).getValue();
            }

            symbol = new Symbol(name, type, lineNumber, tag, fileName, scope);
//            HashSet<Symbol> newsymbol = new HashSet<>();
            ArrayList<Symbol> newsymbol = new ArrayList<>();
            newsymbol.add(symbol);
            storeSymbols(newsymbol);

            //save into nodeList
            String nodeLabel = lineNumber + "-" + fileName;
            storeIntoNodeList(nodeLabel);

            // init is optional
            Element initNode = element.getFirstChildElement("init", NAMESPACEURI);
            if (initNode != null) {
                findExpr(initNode, lineNumber, fileName, scope, parentLocation, true);
            }
        }

        return symbol;
    }

    /**
     * This function find variables exist in expression
     *
     * @param element  an element contains expression element
     * @param fileName current filename, used for mark dependency graph's node name (lineNumber-fileName)
     * @param scope    is used for mark the symbol's position
     */
    private String findExpr(Element element, String stmtLineNumber, String fileName, int scope, String parentLocation, boolean isInit) {
        Element exprNode = element.getFirstChildElement("expr", NAMESPACEURI);

        String exprLocation = "";
//        String stmtLineNumber;
        //<expr><name> [<name1...><name2...>] </name>  </expr>
        Elements name_Elements = exprNode.getChildElements("name", NAMESPACEURI);
        if (name_Elements.size() > 0) {


            for (int i = 0; i < name_Elements.size(); i++) {
                Elements nameList = name_Elements.get(i).getChildElements("name", NAMESPACEURI);
                String var;
                Symbol dependent;
                if (nameList.size() > 0) {
                    if (stmtLineNumber.equals("")) {
                        stmtLineNumber = nameList.get(0).getAttribute(0).getValue();
                    }
                    exprLocation = stmtLineNumber + "-" + fileName;

                    //save into nodeList
                    storeIntoNodeList(exprLocation);

                    for (int x = 0; x < nameList.size(); x++) {
                        var = nameList.get(x).getValue();
                        dependent = new Symbol(var, "", stmtLineNumber, "name", fileName, scope);
                        findVarDependency(dependent);
                    }
                } else {
                    var = name_Elements.get(i).getValue();
                    if (stmtLineNumber.equals("")) {
                        stmtLineNumber = name_Elements.get(i).getAttribute(0).getValue();
                    }
                    dependent = new Symbol(var, "", stmtLineNumber, "name", fileName, scope);

                    exprLocation = stmtLineNumber + "-" + fileName;
                    //save into nodeList
                    storeIntoNodeList(exprLocation);
                    findVarDependency(dependent);

                    if (!parentLocation.equals("")) {
                        String childLocation = stmtLineNumber + "-" + fileName;
                        linkChildToParent(childLocation, parentLocation);
                    }

                }
            }

        }

        //<expr><call>
        Element callElement = exprNode.getFirstChildElement("call", NAMESPACEURI);
        if (callElement != null) {
            exprLocation = findCall(callElement, stmtLineNumber, fileName, scope, parentLocation, isInit);
        }

        //<expr><sizeof>
        Element sizeofElement = exprNode.getFirstChildElement("sizeof", NAMESPACEURI);
        if (sizeofElement != null) {
            stmtLineNumber = sizeofElement.getAttribute(0).getValue();
//                    findCall(callElement, fileName, scope, parentLocation);
            exprLocation = stmtLineNumber + "-" + fileName;

            //argument list
            Elements argumentList = sizeofElement.getFirstChildElement("argument_list", NAMESPACEURI).getChildElements();
            handleArgumentList(argumentList, stmtLineNumber, fileName, scope, parentLocation);

        }
        //return nodes has its own line Number
        if (element.getLocalName().equals("return")) {
            exprLocation = element.getAttribute(0).getValue() + "-" + fileName;
            //save into nodeList
            storeIntoNodeList(exprLocation);
//            if (!nodeList.containsKey(exprLocation)) {
//                id++;
//                nodeList.put(exprLocation, id);
//                //write into graph file
//                ioFunctionSet.writeTofile(id + " [label = \"" + exprLocation + "\"];\n", graph.getPath());
//            }
        }

        if (!parentLocation.equals("") && !exprLocation.equals("")) {
            System.out.print(exprLocation + "\n");

            if (!exprLocation.equals(parentLocation)) {
                linkChildToParent(exprLocation, parentLocation);
            }
        }
        return exprLocation;
    }

    private void storeIntoNodeList(String exprLocation) {
        //save into nodeList
        if (!nodeList.containsKey(exprLocation)) {
            id++;
            nodeList.put(exprLocation, id);
            //write into graph file
            ioFunctionSet.writeTofile(id + " [label = \"" + exprLocation + "\"];\n", graph.getPath());
        }
    }

    /**
     * This function find call element
     *
     * @param element  call element
     * @param fileName current filename, used for mark dependency graph's node name (lineNumber-fileName)
     * @param scope    is used for mark the symbol's position
     */
//    private String findCall(Element element, String fileName, int scope, String parentLocation) {
    private String findCall(Element element, String stmtLineNumber, String fileName, int scope, String parentLocation, boolean isInit) {
        //<expr><call> <name> <argument_list> </call> </expr>
        //call node
        Element exprNode = element.getFirstChildElement("expr", NAMESPACEURI);
        Element callNode;
        if (exprNode != null) {
            callNode = exprNode.getFirstChildElement("call", NAMESPACEURI);
        } else {
            callNode = element;
        }
        Element callNameElement = callNode.getFirstChildElement("name", NAMESPACEURI);

        String callName = callNameElement.getValue();
        String lineNumber;
        if (isInit) {
            lineNumber = stmtLineNumber;
        } else {
            if (callNameElement.getAttributeCount() > 0) {
                lineNumber = callNameElement.getAttribute(0).getValue();
            } else {
                lineNumber = callNameElement.getFirstChildElement("name", NAMESPACEURI).getAttribute(0).getValue();
            }

        }
        String nodeLabel = lineNumber + "-" + fileName;


        //save into dependent Table
        //TODO: call's level is 1
        Symbol call = new Symbol(callName, "", lineNumber, "call", fileName, 1);
        lonelySymbolSet.add(call);

        //save into nodeList
        if (!nodeList.containsKey(nodeLabel)) {
            id++;
            nodeList.put(nodeLabel, id);
            //write into graph file
            ioFunctionSet.writeTofile(id + " [label = \"" + nodeLabel + "\"];\n", graph.getPath());
        }

        addFuncDependency(call);

        //argument list
        Elements argumentList = callNode.getFirstChildElement("argument_list", NAMESPACEURI).getChildElements();
        handleArgumentList(argumentList, lineNumber, fileName, scope, parentLocation);

        return nodeLabel;
    }

    /**
     * This function handle argumentList in <call> or in <sizeof>
     *
     * @param argument_List  argument list
     * @param fileName
     * @param scope
     * @param parentLocation
     */
    public void handleArgumentList(Elements argument_List, String stmtLineNumber, String fileName, int scope, String parentLocation) {
        for (int i = 0; i < argument_List.size(); i++) {
            Element argument = argument_List.get(i);
            findExpr(argument, stmtLineNumber, fileName, scope, parentLocation, false);
        }
    }

    /**
     * * This function finds the use of variable declaration, and create edge between 'def-use'
     *
     * @param variable 'use' variable symbol is looking for 'def' of variable
     */

    public void findVarDependency(Symbol variable) {
        String var = variable.getName();
        int scope = variable.getScope();
        String depenNodeLabel = variable.getLineNumber() + "-" + variable.getFileName();

        if (!nodeList.containsKey(depenNodeLabel)) {
            id++;
            nodeList.put(depenNodeLabel, id);
            //write into graph file
            ioFunctionSet.writeTofile(id + " [label = \"" + depenNodeLabel + "\"];\n", graph.getPath());
        }
        int edgeNum = 0;
        for (Symbol s : symbolTable) {
            if (s != null) {
                //check local variable
                if (s.getName().equals(var) && scope == s.getScope()) {
                    String edgeLable = "<Def-Use> " + var;
                    addEdgesToFile(depenNodeLabel, s, edgeLable);
                    edgeNum++;
                    break;
                }

                // if the variable is not local, then check global variable def
                if (s.getName().equals(var) && scope > s.getScope()) {
                    String edgeLable = "<Def-Use> " + var;
                    addEdgesToFile(depenNodeLabel, s, edgeLable);
                    edgeNum++;

                }
            }
        }
        if (edgeNum == 0) {
            lonelySymbolSet.add(variable);
        }
    }

    /**
     * This function add the edge between call->function and call->function_declaration
     *
     * @param depend function node / call node
     */

    public void addFuncDependency(Symbol depend) {
        String funcName = depend.getName();
        String depen_position = depend.getLineNumber() + "-" + depend.getFileName();
        String edgeLable = "";
        if (sameNameMap.containsKey(depend.getName())) {
            HashSet<Symbol> candidates = sameNameMap.get(depend.getName());
            for (Symbol s : candidates) {
                if (depend.getTag().equals("call")) {
                    if (s.getTag().equals("function_decl") || s.getTag().equals("function")) {
                        edgeLable = "<Call> " + funcName;
                        addEdgesToFile(depen_position, s, edgeLable);

                    }
                } else if (depend.getTag().equals("function")) {
                    if (s.getTag().equals("function_decl")) {
                        edgeLable = "<func_decl> " + funcName;
                        addEdgesToFile(depen_position, s, edgeLable);
                    }
                }
            }
        }
    }

    /**
     * This function write edge into graph file
     *
     * @param depen_position dependent node position (lineNumber_filename)
     * @param decl           declaration symbol
     * @param edgeLabel      edge label
     */
    public void addEdgesToFile(String depen_position, Symbol decl, String edgeLabel) {
        int dependId = nodeList.get(depen_position);
        String declNodeLabel = decl.getLineNumber() + "-" + decl.getFileName();
        int declId = nodeList.get(declNodeLabel);
        ioFunctionSet.writeTofile(dependId + " -> " + declId + "[label=\"" + edgeLabel + "\"];\n", graph.getPath());
        edgeList.add(depen_position + "->" + declNodeLabel);
    }

    /**
     * This function write edge into graph file
     *
     * @param depen_position dependent node position (lineNumber_filename)
     * @param decl_position  declaration node postion
     * @param edgeLabel      edge label
     */
    public void addEdgesToFile(String depen_position, String decl_position, String edgeLabel) {
        int dependId = nodeList.get(depen_position);
        int declId = nodeList.get(decl_position);
        ioFunctionSet.writeTofile(dependId + " -> " + declId + "[label=\"" + edgeLabel + "\"];\n", graph.getPath());
        edgeList.add(depen_position + "->" + decl_position);
    }

    public void main(String[] args) {

        String testDir = "EmailSystem/test_10";
        createDependencyGraph(testDir);
    }
}
