package de.fosd.jdime.dependencyGraph;

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
    static HashMap<String,HashSet<String>> dependencyGraph;
    static HashSet<String> edgeList;
    static HashSet<Edge> edges;
    static final public String NAMESPACEURI = "http://www.sdml.info/srcML/src";
    static final public boolean CONTROL_FLOW = true;
    static final public String CONTROLFLOW_LABEL = "<Control-Flow>";

    /**
     * This function will parse the test directory and iteratively parse each file (.c/.cpp/.h)
     * to create dependency graph in each file
     *
     * @param testDir directory that contains .c/cpp/h files
     * @return edgeList for testing directory
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
        edges = new HashSet<>();
        dependencyGraph = new HashMap<>();
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
                parseDependencyForSubTree(root, fileName, 1, "");
            }
        }
        //create edges cross files
        addEdgesCrossFiles();

        ioFunctionSet.writeTofile("}", graph.getPath());
        return edgeList;
    }

    /**
     * This function just call the create Dependency Graph, used for cluster nodes.
     * TODO modify compareTwoGraphs return type
     * @param testDir
     * @return dependency graph, no edge label stored.
     */

   public HashMap<String,HashSet<String>> getDependencyGraph(String  testDir) {
       createDependencyGraph(testDir);
       return  dependencyGraph;
   }

    /**
     * This function store a set of symbols to Symbol table and nameMap.
     *
     * @param symbols ArrayList of symbols
     */
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
     * ind dependency for symbol in
     * 1. lonelySymbolSet
     * 2. symbolTable(func_decl)
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
                findVarDependency(dependent,"");
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
     * This function is parsing the dependency graph in a sub-tree
     *
     * @param subTreeRoot    root node for the sub tree
     * @param fileName       prefix of the graph node (filename+line#)
     * @param scope          is the level of the declaration node. (1 means the symbol is in the file level, 2 means the symbol is in a function level)
     * @param parentLocation parent node of the root, used for creating edge: root->parent
     * @return a list of statement locations of the subtree
     */
    public ArrayList<String> parseDependencyForSubTree(Element subTreeRoot, String fileName, int scope, String parentLocation) {
        ArrayList<String> tmpStmtList = new ArrayList<>();
        Elements elements = subTreeRoot.getChildElements();

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
                symbolTable.add(macro);

            } else if (ele.getLocalName().equals("if") && ele.getNamespacePrefix().equals("cpp")) {
                Element expr = ele.getFirstChildElement("expr", NAMESPACEURI);
                if (expr != null) {
                    tmpStmtList.add(handleVarInExpr(ele, "", fileName, scope, parentLocation, false));
                }
            } else if (ele.getLocalName().equals("function") || ele.getLocalName().equals("constructor")) {
                parseFunctionNode(ele, fileName, scope);
            } else if (ele.getLocalName().equals("if") && !ele.getNamespacePrefix().equals("cpp")) {
                tmpStmtList.addAll(parseIfStmt(ele, fileName, scope, parentLocation));
            } else if (ele.getLocalName().equals("while")) {
                tmpStmtList.addAll(parseWhileStmt(ele, fileName, scope, parentLocation));
            } else if (ele.getLocalName().equals("expr_stmt")) {
                tmpStmtList.add(handleVarInExpr(ele, "", fileName, scope, parentLocation, false));
            } else if (ele.getLocalName().equals("decl_stmt")) {
                Element decl = ele.getFirstChildElement("decl", NAMESPACEURI);
                Symbol declSymbol = addDeclarationSymbol(decl, "decl_stmt", fileName, scope, parentLocation);
                tmpStmtList.add(declSymbol.getLineNumber() + "-" + fileName);
            } else if (ele.getLocalName().equals("struct")) {
                //struct
                Symbol parent = addDeclarationSymbol(ele, "struct", fileName, scope, parentLocation);
                parentLocation = parent.getLineNumber() + "-" + fileName;
                //block
                Element block = ele.getFirstChildElement("block", NAMESPACEURI);
                for (int s = 0; s < block.getChildElements().size(); s++) {
                    Element group = block.getChildElements().get(s);

                    //get children
//                    HashSet<Symbol>
                    ArrayList<String> children = parseDependencyForSubTree(group, fileName, scope, parentLocation);
                    //link children -> parent
                    linkChildToParent(children, parentLocation, "<belongToStruct>");
                }
            } else if (ele.getLocalName().equals("function_decl")) {
                addDeclarationSymbol(ele, "function_decl", fileName, scope, parentLocation);

            } else if (ele.getLocalName().equals("return")) {
                Element returnContent = ele.getFirstChildElement("expr", NAMESPACEURI);
                if (returnContent != null) {
                    tmpStmtList.add(handleVarInExpr(ele, "", fileName, scope, parentLocation, false));
                }
            } else if (ele.getLocalName().equals("for")) {
                tmpStmtList.addAll(parseForStmt(ele, fileName, scope, parentLocation));
            }
            //remove symbol, whose scope >1
            if (((Element) ele.getParent()).getLocalName().equals("unit")) {
                symbolTable = removeLocalSymbol(symbolTable);
            }
        }
        return tmpStmtList;
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
     * @param childrenLocations       statements' location
     * @param parentLocation struct node's location
     */

    private void linkChildToParent(ArrayList<String> childrenLocations, String parentLocation, String label) {
        for (String child : childrenLocations) {
            addEdgesToFile(child, parentLocation, label);
        }
    }

    /**
     * This function link children to parent, used for block -> function, then-> if, else->if
     *
     * @param childLocation
     * @param parentLocation
     */
    private void linkChildToParent(String childLocation, String parentLocation) {
        if (!edgeList.contains(childLocation + "->" + parentLocation)) {
            addEdgesToFile(childLocation, parentLocation, "<child>");
        }
    }

    /**
     * This function parses the function node.
     * First, create symbol for the function, scope is 1
     * Second, use {@link #parseDependencyForSubTree(Element, String, int, String)} function to parse the <block> subtree
     *
     * @param element  function element
     * @param fileName current filename, used for mark dependency graph's node name (lineNumber-fileName)
     * @param scope    function's scope is 1, symbol in block is 2
     */
    private void parseFunctionNode(Element element, String fileName, int scope) {
        //add function to symbol table
        Symbol functionSymbol = addDeclarationSymbol(element, "function", fileName, scope, "");
        String parentLocation = functionSymbol.getLineNumber() + "-" + fileName;
        //check parameters
        Element parameter_list = element.getFirstChildElement("parameter_list", NAMESPACEURI);
        if (parameter_list.getChildElements() != null) {
            for (int i = 0; i < parameter_list.getChildElements("param", NAMESPACEURI).size(); i++) {
                Element paramNode = parameter_list.getChildElements("param", NAMESPACEURI).get(i);
                //add Parameter to symbol table
                addDeclarationSymbol((Element) paramNode.getChild(0), "param", fileName, scope + 1, parentLocation);
            }
        }

        //check block
        Element block = element.getFirstChildElement("block", NAMESPACEURI);
        parseDependencyForSubTree(block, fileName, scope + 1, parentLocation);
    }

    /**
     * this function parse if statement
     *
     * @param ele      if  element
     * @param fileName fileName of this node
     * @param scope    level of the node
     * @return list of statement location
     */
    private ArrayList<String> parseIfStmt(Element ele, String fileName, int scope, String parentLocation) {
        //<if><condition><then>[<else>], else is optional
        Element condition = ele.getFirstChildElement("condition", NAMESPACEURI);

        ArrayList<String> stmtList = new ArrayList<>();
        String ifStmtLocation = handleVarInExpr(condition, "", fileName, scope, parentLocation, false);
        stmtList.add(ifStmtLocation);
        //control flow analysis dependency
        if (!CONTROL_FLOW) {
            ifStmtLocation = "";
        }

        //<then> [<block>], block is optional
        Element then_Node = ele.getFirstChildElement("then", NAMESPACEURI);
        ArrayList<String> symbolsInThen = null;
        if (then_Node.getFirstChildElement("block", NAMESPACEURI) != null) {
            Element block = then_Node.getFirstChildElement("block", NAMESPACEURI);
            symbolsInThen = parseDependencyForSubTree(block, fileName, scope, ifStmtLocation);
        } else {
            symbolsInThen = parseDependencyForSubTree(then_Node, fileName, scope, ifStmtLocation);
        }

        ArrayList<String> symbolsInElse = null;

        //else is optional
        Element else_Node = ele.getFirstChildElement("else", NAMESPACEURI);
        if (else_Node != null) {
            if (else_Node.getFirstChildElement("block", NAMESPACEURI) != null) {
                Element block = else_Node.getFirstChildElement("block", NAMESPACEURI);
                symbolsInElse = parseDependencyForSubTree(block, fileName, scope, ifStmtLocation);
            } else {
                symbolsInElse = parseDependencyForSubTree(else_Node, fileName, scope, ifStmtLocation);
            }
        }

        //add control flow dependency
        if (CONTROL_FLOW && symbolsInThen.size() > 0) {
            addControlFlowDependency(ifStmtLocation, symbolsInThen, fileName);
            if (symbolsInElse != null && symbolsInElse.size() > 0) {
                addControlFlowDependency(ifStmtLocation, symbolsInElse, fileName);
            }
        }

        stmtList.addAll(symbolsInThen);
        if (symbolsInElse != null) {
            stmtList.addAll(symbolsInElse);
        }
        return stmtList;
    }


    /**
     * this function parse while node.
     *
     * @param ele            while node , type is element
     * @param fileName       file name
     * @param scope          while node's scope
     * @param parentLocation parent's location
     * @return a list of statement location of 'while' node
     */
    private ArrayList<String> parseWhileStmt(Element ele, String fileName, int scope, String parentLocation) {

        //<while><condition><block>
        Element condition = ele.getFirstChildElement("condition", NAMESPACEURI);
        ArrayList<String> stmtList = new ArrayList<>();
        String whileLocation = handleVarInExpr(condition, "", fileName, scope, parentLocation, false);

        if(whileLocation.equals("")){
            whileLocation = condition.getAttribute(0).getValue()+"-"+fileName;
            //save into nodeList
            storeIntoNodeList(whileLocation);
        }
        stmtList.add(whileLocation);
        //Block
        Element block = ele.getFirstChildElement("block", NAMESPACEURI);

        if (block != null) {
            stmtList.addAll(parseDependencyForSubTree(block, fileName, scope + 1, whileLocation));
        }

        Element expr = ele.getFirstChildElement("expr_stmt", NAMESPACEURI);
        if (expr != null) {
            stmtList.add(handleVarInExpr(expr, "", fileName, scope, parentLocation, false));
        }

        //add control flow dependency
        if (CONTROL_FLOW && stmtList.size() > 1) {
            addControlFlowDependency(whileLocation, stmtList, fileName);
        }
        return stmtList;
    }

    /**
     * this function add control flow dependency for if-then-else, while, etc.
     * @param headLocation condition location
     * @param stmtList statement list in block
     * @param fileName current file, used for marking location
     */
    private void addControlFlowDependency(String headLocation, ArrayList<String> stmtList, String fileName) {
        addEdgesToFile(stmtList.get(0), headLocation, CONTROLFLOW_LABEL + " if-then");
        for (int i = 0; i < stmtList.size() - 1; i++) {
            String pre_loc = stmtList.get(i);
            String after_loc = stmtList.get(i + 1);
            if (!pre_loc.equals(after_loc)) {
                addEdgesToFile(after_loc, pre_loc, CONTROLFLOW_LABEL);
            }
        }
    }


    /**
     * This function parse for loop
     *
     * @param ele            for node
     * @param fileName
     * @param scope
     * @param parentLocation
     * @return List of statement location
     */
    private ArrayList<String> parseForStmt(Element ele, String fileName, int scope, String parentLocation) {
        ArrayList<String> tmpStmtList = new ArrayList<>();

        String lineNumber = ele.getAttribute(0).getValue();
        String forLocation = lineNumber + "-" + fileName;
        Element init = ele.getFirstChildElement("init", NAMESPACEURI).getFirstChildElement("decl", NAMESPACEURI);
        Symbol initVarSymbol;
        if(init!=null){
        initVarSymbol = addDeclarationSymbol(init, "for", fileName, scope, parentLocation);
            tmpStmtList.add(initVarSymbol.getLineNumber() + "-" + fileName);
        }else{

            Element condition = ele.getFirstChildElement("condition", NAMESPACEURI);

           handleVarInExpr(condition, "", fileName, scope, parentLocation, false);
//            stmtList.add(ifStmtLocation);

//            init=  ele.getFirstChildElement("init", NAMESPACEURI).getFirstChildElement("expr", NAMESPACEURI);
//            Elements name_Elements = init.getChildElements("name", NAMESPACEURI);
//            String name = name_Elements.get(0).getValue();
//            initVarSymbol = new Symbol(name, "", lineNumber, "for", fileName, scope);
//            ArrayList<Symbol> newsymbol = new ArrayList<>();
//            newsymbol.add(initVarSymbol);
//            storeSymbols(newsymbol);

            //save into nodeList
            String nodeLabel = lineNumber + "-" + fileName;
            storeIntoNodeList(nodeLabel);

        }


        Element block = ele.getFirstChildElement("block", NAMESPACEURI);
        if (block != null) {
            tmpStmtList.addAll(parseDependencyForSubTree(block, fileName, scope + 1, forLocation));
        }

        Element expr = ele.getFirstChildElement("expr_stmt", NAMESPACEURI);
        if (expr != null) {
            handleVarInExpr(expr, "", fileName, scope, parentLocation, false);
        }

        return tmpStmtList;
    }

    /**
     * This function adds symbol and add it to symbolTable
     * e.g.: <decl_stmt><decl><type><name> [<init>]
     * parameter definition
     * function
     * ...
     *
     * @param element  declaration element
     * @param tag      srcml tag
     * @param fileName current filename, used for mark dependency graph's node name (lineNumber-fileName)
     * @param scope    function's scope is 1, symbol in block is 2
     * @return new symbol
     */
    private Symbol addDeclarationSymbol(Element element, String tag, String fileName, int scope, String parentLocation) {
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

            if (name.contains("::")) {
                name = name.split("::")[1];
            }

            String lineNumber;
            if (nameElement.getAttributeCount() > 0) {
                lineNumber = nameElement.getAttribute(0).getValue();
            } else {
                lineNumber = nameElement.getFirstChildElement("name", NAMESPACEURI).getAttribute(0).getValue();
            }

            symbol = new Symbol(name, type, lineNumber, tag, fileName, scope);
            ArrayList<Symbol> newsymbol = new ArrayList<>();
            newsymbol.add(symbol);
            storeSymbols(newsymbol);

            //save into nodeList
            String nodeLabel = lineNumber + "-" + fileName;
            storeIntoNodeList(nodeLabel);

            // init is optional
            Element initNode = element.getFirstChildElement("init", NAMESPACEURI);
            if (initNode != null) {
                handleVarInExpr(initNode, lineNumber, fileName, scope, parentLocation, true);
            }
        }

        return symbol;
    }

    /**
     * * This function find variables exist in expression, and create edges if needed
     *
     * @param element        an element contains expression element
     * @param stmtLineNumber line number for the statement
     * @param fileName       current filename, used for mark dependency graph's node name (lineNumber-fileName)
     * @param scope          is used for mark the symbol's position
     * @param parentLocation parent node's location
     * @param isInit         whether this element is a initial (function call)
     * @return expression's Location
     */
    private String handleVarInExpr(Element element, String stmtLineNumber, String fileName, int scope, String parentLocation, boolean isInit) {
        Element exprNode = element.getFirstChildElement("expr", NAMESPACEURI);

        String exprLocation = "";
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
                        findVarDependency(dependent,exprLocation);
//                        findVarDependency(dependent);

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
//                    findVarDependency(dependent);
                    findVarDependency(dependent,exprLocation);

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
            String callLocation = handleCallNode(callElement, stmtLineNumber, fileName, scope, parentLocation, isInit);
            if (exprLocation.equals("")) {
                exprLocation = callLocation;
            }
        }

        //<expr><sizeof>
        Element sizeofElement = exprNode.getFirstChildElement("sizeof", NAMESPACEURI);
        if (sizeofElement != null) {
            stmtLineNumber = sizeofElement.getAttribute(0).getValue();
            exprLocation = stmtLineNumber + "-" + fileName;

            //argument list
            Elements argumentList = sizeofElement.getFirstChildElement("argument_list", NAMESPACEURI).getChildElements();
        }
        //return nodes has its own line Number
        if (element.getLocalName().equals("return")) {
            exprLocation = element.getAttribute(0).getValue() + "-" + fileName;
            //save into nodeList
            storeIntoNodeList(exprLocation);
        }

        if (!parentLocation.equals("") && !exprLocation.equals("")) {
            System.out.print(exprLocation + "\n");

            if (!exprLocation.equals(parentLocation)) {
                linkChildToParent(exprLocation, parentLocation);
            }
        }
        return exprLocation;
    }

    /**
     * This function store node in dependency graph and
     *
     * @param exprLocation
     */
    private void storeIntoNodeList(String exprLocation) {
        //save into nodeList
        if (!nodeList.containsKey(exprLocation)) {
            id++;
            nodeList.put(exprLocation, id);

            dependencyGraph.put(exprLocation,new HashSet<>());


            //write into graph file
            ioFunctionSet.writeTofile(id + " [label = \"" + exprLocation + "\"];\n", graph.getPath());
        }
    }

    /**
     * * This function parse call element
     * <expr><call> <name> <argument_list> </call> </expr>
     *
     * @param element        call element
     * @param stmtLineNumber
     * @param fileName       current filename, used for mark dependency graph's node name (lineNumber-fileName)
     * @param scope          is used for mark the symbol's position
     * @param parentLocation
     * @param isInit         whether this call node is an isolated node or initialization for a variable.
     *                       if it is a initialization, isInit = true
     * @return call node Location
     */

    private String handleCallNode(Element element, String stmtLineNumber, String fileName, int scope, String parentLocation, boolean isInit) {
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
        //call's level is 1
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
          handleVarInExpr(argument, stmtLineNumber, fileName, scope, parentLocation, false);
        }
    }

    /**
     * * This function finds the use of variable declaration, and create edge between 'def-use'
     *
     * @param variable 'use' variable symbol is looking for 'def' of variable
     */

    public void findVarDependency(Symbol variable,String depenNodeLabel) {
//    public void findVarDependency(Symbol variable) {
        String var = variable.getName();
        int scope = variable.getScope();
        if(depenNodeLabel.equals("")) {
        depenNodeLabel = variable.getLineNumber() + "-" + variable.getFileName();
        }
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
//        int dependId = nodeList.get(depen_position);
//        String decl_position = decl.getLineNumber() + "-" + decl.getFileName();
//        int declId = nodeList.get(decl_position);
//        ioFunctionSet.writeTofile(dependId + " -> " + declId + "[label=\"" + edgeLabel + "\"];\n", graph.getPath());
//        edgeList.add(depen_position + "->" + decl_position);
//        //add edge obj
//        edges.add(new Edge(edgeLabel,depen_position,decl_position));

        String decl_position = decl.getLineNumber() + "-" + decl.getFileName();
        addEdgesToFile(depen_position,decl_position,edgeLabel);
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

        //add to dependency graph
       HashSet<String> dependNodes = dependencyGraph.get(decl_position);
        if(dependNodes==null){
            dependNodes = new HashSet<>();
        }
        dependNodes.add(depen_position);
        dependencyGraph.put(decl_position,dependNodes);


        //add edge obj
        edges.add(new Edge(edgeLabel,depen_position,decl_position));
    }

    public void main(String[] args) {

        String testDir = "EmailSystem/test_10";
        createDependencyGraph(testDir);
    }
}
