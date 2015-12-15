package de.fosd.jdime.dependencyGraph;

import de.fosd.jdime.util.IOFunctionSet;
import nu.xom.Element;
import nu.xom.Elements;
import org.apache.commons.io.FileUtils;

import java.io.File;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;

/**
 * Created by shuruiz on 12/10/15.
 */
public class DependencyGraph {

    static IOFunctionSet ioFunctionSet = new IOFunctionSet();
    static HashSet<Symbol> symbolTable;
    static HashSet<Symbol> dependentTable;
    static File graph;
    static int id;
    static HashMap<String, Integer> nodeList;
    static HashSet<String> edgeList;

    /**
     * This function will parse the test directory and iteratively parse each file (.c/.cpp/.h)
     * to create dependency graph in each file
     *
     * @param testDir directory that contains .c/cpp/h files
     * @return edgeList for testing goal
     */
    public static HashSet<String> createDependencyGraph(String testDir) {

        String dirPath = "testcpp/dependencyGraph/";
        String testDirPath = dirPath + testDir + "/";

        //create graph file
        graph = new File(testDirPath + "graph.gv");
        ioFunctionSet.rewriteFile("digraph {\n", graph.getPath());

        File dir = new File(testDirPath);
        String[] names = dir.list();

        symbolTable = new HashSet<>();
        dependentTable = new HashSet<>();
        nodeList = new HashMap<>();
        edgeList = new HashSet<>();

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
                symbolTable.addAll(parseDependency(root, fileName, 1));

            }
        }


        //create edges cross files
        addEdgesCrossFiles();

        ioFunctionSet.writeTofile("}", graph.getPath());
        return edgeList;
    }

    /**
     * this function add edges cross files
     */
    private static void addEdgesCrossFiles() {

        //add call-> function/func_decl
        for (Symbol dependent : dependentTable) {
            String tag = dependent.getTag();
            if (tag.equals("call")) {
                if (!dependent.getName().equals("printf")) {
                    findFuncDependency(dependent);
                }
            } else if (tag.equals("name")) {
                findVarDependency(dependent);
            }
        }
        //add function->func_decl
        for (Symbol dependent : symbolTable) {
            String tag = dependent.getTag();
            if (tag.equals("function")) {
                findFuncDependency(dependent);
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
    public static HashSet<Symbol> parseDependency(Element root, String fileName, int scope) {

        HashSet<Symbol> tmpSymbolList = new HashSet<>();
        Elements elements = root.getChildElements();

        for (int i = 0; i < elements.size(); i++) {
            Element ele = elements.get(i);
//            System.out.print(ele.getValue()+"!\n");
            if (ele.getLocalName().equals("function")) {
                tmpSymbolList.addAll(parseFunctionNode(ele, fileName, scope));
            } else if (ele.getLocalName().equals("if")) {
                //<if><condition><then>[<else>], else is optional
                Element condition = ele.getFirstChildElement("condition", "http://www.sdml.info/srcML/src");
                findExpr(condition, fileName, scope);

                //<then> [<block>], block is optional
                Element then_Node = ele.getFirstChildElement("then", "http://www.sdml.info/srcML/src");
                if (then_Node.getFirstChildElement("block", "http://www.sdml.info/srcML/src") != null) {
                    Element block = then_Node.getFirstChildElement("block", "http://www.sdml.info/srcML/src");
                    tmpSymbolList.addAll(parseDependency(block, fileName, scope));
                } else {
                    tmpSymbolList.addAll(parseDependency(then_Node, fileName, scope));
                }
                //else is optional
                Element else_Node = ele.getFirstChildElement("else", "http://www.sdml.info/srcML/src");
                if (else_Node != null) {
                    if (else_Node.getFirstChildElement("block", "http://www.sdml.info/srcML/src") != null) {
                        Element block = else_Node.getFirstChildElement("block", "http://www.sdml.info/srcML/src");
                        tmpSymbolList.addAll(parseDependency(block, fileName, scope));
                    } else {
                        tmpSymbolList.addAll(parseDependency(else_Node, fileName, scope));
                    }
                }
            } else if (ele.getLocalName().equals("while")) {
                //<while><condition><block>
                Element condition = ele.getFirstChildElement("condition", "http://www.sdml.info/srcML/src");
                findExpr(condition, fileName, scope);

                Element block = ele.getFirstChildElement("block", "http://www.sdml.info/srcML/src");
                tmpSymbolList.addAll(parseDependency(block, fileName, scope));
            } else if (ele.getLocalName().equals("expr_stmt")) {
                Element expr_Node = ele.getFirstChildElement("expr", "http://www.sdml.info/srcML/src");
//                //<expr> <name>
//                if (expr_Node.getChildElements("name", "http://www.sdml.info/srcML/src") != null) {
//                    for (int x = 0; x < expr_Node.getChildElements("name", "http://www.sdml.info/srcML/src").size(); x++) {
//                        Elements nameList = expr_Node.getChildElements("name", "http://www.sdml.info/srcML/src").get(x).getChildElements();
//                        if (nameList.size() > 0) {
//                            findExpr(ele, fileName, scope);
//                        }
//                    }
//                }
//                //<expr> <call>
//                if (expr_Node.getFirstChildElement("call", "http://www.sdml.info/srcML/src") != null) {
//                    Elements call_children = expr_Node.getFirstChildElement("call", "http://www.sdml.info/srcML/src").getChildElements();
//                    if (call_children.size() > 0) {
//                        findCall(ele, fileName, scope);
//                    }
//                }
                findExpr(ele, fileName, scope);
            } else if (ele.getLocalName().equals("decl_stmt")) {
                Element decl = ele.getFirstChildElement("decl", "http://www.sdml.info/srcML/src");
                tmpSymbolList.add(findSymbol(decl, "decl_stmt", fileName, scope));
            } else if (ele.getLocalName().equals("struct")) {
                //struct
                Symbol parent = findSymbol(ele, "struct", fileName, scope);
                tmpSymbolList.add(parent);

                //block
                Element block = ele.getFirstChildElement("block", "http://www.sdml.info/srcML/src");
                for (int s = 0; s < block.getChildElements().size(); s++) {
                    Element group = block.getChildElements().get(s);

                    //get children
                    HashSet<Symbol> children = parseDependency(group, fileName, scope);
                    tmpSymbolList.addAll(children);

                    //link children -> parent
                    linkChildToParent(children, parent);

                }
            } else if (ele.getLocalName().equals("function_decl")) {
                tmpSymbolList.add(findSymbol(ele, "function_decl", fileName, scope));

            } else if (ele.getLocalName().equals("return")) {
                Element returnContent = ele.getFirstChildElement("expr", "http://www.sdml.info/srcML/src");
                if (returnContent != null) {
                    findExpr(ele, fileName, scope);
                }
            }

            //remove symbol, whose scope >1
            if (((Element) ele.getParent()).getLocalName().equals("unit")) {
                symbolTable = removeLocalSymbol(symbolTable);
                dependentTable = removeLocalSymbol(dependentTable);
            }
        }


        return tmpSymbolList;
    }

    private static HashSet<Symbol> removeLocalSymbol(HashSet<Symbol> tmpSymbolList) {
        HashSet<Symbol> finalSymbolList = new HashSet<>();
        for (Symbol s : tmpSymbolList) {
            if (s.getScope() == 1)
                finalSymbolList.add(s);
        }
        return finalSymbolList;
    }

    /**
     * This function create the edge from child to parent (used for struct)
     *
     * @param children symbols belong to struct
     * @param parent   struct node
     */

    private static void linkChildToParent(HashSet<Symbol> children, Symbol parent) {
        for (Symbol child : children) {
            String depenNodeLabel = child.getLineNumber() + "-" + child.getFileName();
            addEdgesToFile(depenNodeLabel, parent, "<child>");
        }
    }

    /**
     * This function parses the function node.
     * First, create symbol for the function, scope is 1
     * Second, use {@link #parseDependency(Element, String, int)} function to parse the <block> subtree
     *
     * @param element  function element
     * @param fileName current filename, used for mark dependency graph's node name (lineNumber-fileName)
     * @param scope    function's scope is 1, symbol in block is 2
     * @return symbolList in function scope
     */
    private static HashSet<Symbol> parseFunctionNode(Element element, String fileName, int scope) {
        HashSet<Symbol> tmpSymbolList = new HashSet<>();

        //add function to symbol table
        tmpSymbolList.add(findSymbol(element, "function", fileName, scope));

        //check parameters
        Element parameter_list = element.getFirstChildElement("parameter_list", "http://www.sdml.info/srcML/src");
        if (parameter_list.getChildElements() != null) {
            for (int i = 0; i < parameter_list.getChildElements().size(); i++) {
                Element paramNode = parameter_list.getChildElements().get(i);

                //add Parameter to symbol table
                tmpSymbolList.add(findSymbol((Element) paramNode.getChild(0), "param", fileName, scope + 1));
            }
        }

        //check block
        Element block = element.getFirstChildElement("block", "http://www.sdml.info/srcML/src");
        tmpSymbolList.addAll(parseDependency(block, fileName, scope + 1));
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
    private static Symbol findSymbol(Element element, String tag, String fileName, int scope) {
        String type;
        Element type_Node = element.getFirstChildElement("type", "http://www.sdml.info/srcML/src");
        if (type_Node != null) {
            type = type_Node.getValue();
        } else {
            type = "";
        }

        String name = element.getFirstChildElement("name", "http://www.sdml.info/srcML/src").getValue();
        String lineNumber = element.getFirstChildElement("name", "http://www.sdml.info/srcML/src").getAttribute(0).getValue();

        Symbol symbol = new Symbol(name, type, lineNumber, tag, fileName, scope);
        symbolTable.add(symbol);

        //save into nodeList
        String nodeLabel = lineNumber + "-" + fileName;
        if (!nodeList.containsKey(nodeLabel)) {
            id++;
            nodeList.put(nodeLabel, id);
            //write into graph file
            ioFunctionSet.writeTofile(id + " [label = \"" + nodeLabel + "\"];\n", graph.getPath());
        }

        // init is optional
        Element initNode = element.getFirstChildElement("init", "http://www.sdml.info/srcML/src");
        if (initNode != null) {
            findExpr(initNode, fileName, scope);
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
    private static void findExpr(Element element, String fileName, int scope) {

        Element exprNode = element.getFirstChildElement("expr", "http://www.sdml.info/srcML/src");

        //<expr><name> <name1...><name2...> </name>  </expr>
        Elements name_Elements = exprNode.getChildElements("name", "http://www.sdml.info/srcML/src");

        //<expr><call>
        Element callElement = exprNode.getFirstChildElement("call", "http://www.sdml.info/srcML/src");
        if (name_Elements.size() > 0) {
            for (int i = 0; i < name_Elements.size(); i++) {
                Elements nameList = name_Elements.get(i).getChildElements();
                if (nameList.size() > 0) {
                    saveDependentSymbol(nameList.get(i), fileName, scope);
                } else {
                    saveDependentSymbol(name_Elements.get(i), fileName, scope);
                }
            }
        } else if (callElement != null) {
            //<expr><call>
            findCall(callElement, fileName, scope);
        }
    }

    public static void saveDependentSymbol(Element element, String fileName, int scope) {
        String var = element.getValue();
        String lineNumber = element.getAttribute(0).getValue();

        //save into dependent Table
        Symbol dependent = new Symbol(var, "", lineNumber, "name", fileName, scope);
        dependentTable.add(dependent);

        //save into nodeList
        String nodeLabel = lineNumber + "-" + fileName;
        if (!nodeList.containsKey(nodeLabel)) {
            id++;
            nodeList.put(nodeLabel, id);
            //write into graph file
            ioFunctionSet.writeTofile(id + " [label = \"" + nodeLabel + "\"];\n", graph.getPath());
        }
        findVarDependency(dependent);
    }

    /**
     * This function find call element
     *
     * @param element  call element
     * @param fileName current filename, used for mark dependency graph's node name (lineNumber-fileName)
     * @param scope    is used for mark the symbol's position
     */
    private static void findCall(Element element, String fileName, int scope) {
        //<expr><call> <name> <argument_list> </call> </expr>

        //call node

        Element exprNode = element.getFirstChildElement("expr", "http://www.sdml.info/srcML/src");
        Element callNode;
        if (exprNode != null) {
            callNode = exprNode.getFirstChildElement("call", "http://www.sdml.info/srcML/src");
        } else {
            callNode = element;
        }
        String callName = callNode.getFirstChildElement("name", "http://www.sdml.info/srcML/src").getValue();
        String lineNumber = callNode.getFirstChildElement("name", "http://www.sdml.info/srcML/src").getAttribute(0).getValue();
        String nodeLabel = lineNumber + "-" + fileName;

        //save into dependent Table
        //TODO: call's level is 1?
        Symbol call = new Symbol(callName, "", lineNumber, "call", fileName, 1);
        dependentTable.add(call);

        //save into nodeList
        if (!nodeList.containsKey(nodeLabel)) {
            id++;
            nodeList.put(nodeLabel, id);
            //write into graph file
            ioFunctionSet.writeTofile(id + " [label = \"" + nodeLabel + "\"];\n", graph.getPath());
        }

        findFuncDependency(call);

        //argument list
        Elements argument_List = callNode.getFirstChildElement("argument_list", "http://www.sdml.info/srcML/src").getChildElements();
        for (int i = 0; i < argument_List.size(); i++) {
            Element argument = argument_List.get(i);
            findExpr(argument, fileName, scope);
        }


    }

    /**
     * * This function finds the use of variable declaration, and create edge between 'def-use'
     *
     * @param variable 'use' variable symbol is looking for 'def' of variable
     */

//    public static void findVarDependency() {
    public static void findVarDependency(Symbol variable) {
        String var = variable.getName();
        int scope = variable.getScope();
        String depenNodeLabel = variable.getLineNumber() + "-" + variable.getFileName();
        for (Symbol s : symbolTable) {
            if (s.getName().equals(var) && scope >= s.getScope()) {
                String edgeLable = "<Def-Use> " + var;
                addEdgesToFile(depenNodeLabel, s, edgeLable);
            }
        }
    }

    /**
     * * This function find the edge between call->function and call->function_declaration
     *
     * @param depend function node / call node
     */

//    public static void findFuncDependency(String funcName, int scope, String depenNodeLabel) {
    public static void findFuncDependency(Symbol depend) {
        String funcName = depend.getName();
        String depen_position = depend.getLineNumber() + "-" + depend.getFileName();
        String edgeLable = "";
        for (Symbol s : symbolTable) {
            String s_position = s.getLineNumber() + "-" + s.getFileName();
            if (s.getName().equals(funcName) && !depen_position.equals(s_position)) {
                if (depend.getTag().equals("call")) {
                    if (s.getTag().equals("function_decl") || s.getTag().equals("function")) {
                        edgeLable = "<Call> " + funcName;
                    }
                } else if (depend.getTag().equals("function")) {
                    if (s.getTag().equals("function_decl")) {
                        edgeLable = "<func_decl> " + funcName;
                    }
                }
                addEdgesToFile(depen_position, s, edgeLable);
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
    public static void addEdgesToFile(String depen_position, Symbol decl, String edgeLabel) {
        if (depen_position.equals("40-Client.c")) {
            System.out.print(depen_position + "!!\n");
        }
        int dependId = nodeList.get(depen_position);
        String declNodeLabel = decl.getLineNumber() + "-" + decl.getFileName();
        int declId = nodeList.get(declNodeLabel);
        ioFunctionSet.writeTofile(dependId + " -> " + declId + "[label=\"" + edgeLabel + "\"];\n", graph.getPath());
        edgeList.add(depen_position + "->" + declNodeLabel);
    }

    public static void main(String[] args) {

        String testDir = "EmailSystem/test_10";
        createDependencyGraph(testDir);
    }
}
