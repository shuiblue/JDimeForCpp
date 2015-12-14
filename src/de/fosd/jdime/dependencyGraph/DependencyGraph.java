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
    static HashSet<Symbol> symbolTable = new HashSet<>();
    static HashSet<Symbol> dependentTable = new HashSet<>();
    static File graph;
    static int id;
    static HashMap<String, Integer> nodeList = new HashMap<>();
    static HashSet<String> edgeList = new HashSet<>();

    /**
     * This function will parse the test directory and iteratively parse each file (.c/.cpp/.h)
     * to create dependency graph in each file
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

                Element root = ioFunctionSet.getXmlDom(xmlFilePath).getRootElement();
                symbolTable.addAll(parseDependency(root, fileName, 1));

            }
        }

        ioFunctionSet.writeTofile("}", graph.getPath());
        return edgeList;
    }

    /**
     * This function is parsing the dependency graph in a tree
     *
     * @param root     root node for an AST
     * @param fileName prefix of the graph node (filename+line#)
     * @param scope is the level of the declaration node. (1 means the symbol is in the file level, 2 means the symbol is in a function level)
     * @return symbol list for the AST
     */
    public static HashSet<Symbol> parseDependency(Element root, String fileName, int scope) {

        HashSet<Symbol> tmpSymbolList = new HashSet<>();
        Elements elements = root.getChildElements();

        for (int i = 0; i < elements.size(); i++) {
            Element ele = elements.get(i);
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
            } else if (ele.getLocalName().equals("expr_stmt")) {
                Element expr_Node = ele.getFirstChildElement("expr", "http://www.sdml.info/srcML/src");
                //<expr> <name>
                if (expr_Node.getFirstChildElement("name", "http://www.sdml.info/srcML/src") != null) {
                    Elements nameList = expr_Node.getFirstChildElement("name", "http://www.sdml.info/srcML/src").getChildElements();
                    if (nameList.size() > 0) {
                        findExpr(ele, fileName, scope);
                    }
                }

                //<expr> <call>
                if (expr_Node.getFirstChildElement("call", "http://www.sdml.info/srcML/src") != null) {
                    Elements call_children = expr_Node.getFirstChildElement("call", "http://www.sdml.info/srcML/src").getChildElements();
                    if (call_children.size() > 0) {
                        findCall(ele, fileName, scope);
                    }
                }
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
                    Element group = block.getChildElements().get(i);

                    //get children
                    HashSet<Symbol> children = parseDependency(group, fileName, scope);
                    tmpSymbolList.addAll(children);

                    //link children -> parent
                    linkChildToParent(children, parent);
                    System.out.print("");
                }
            }else if(ele.getLocalName().equals("function_decl")){
                tmpSymbolList.add(findSymbol(ele,"function_decl",fileName,scope));
            }
        }
        return tmpSymbolList;
    }

    /**
     * This function create the edge from child to parent (used for struct)
     * @param children symbols belong to struct
     * @param parent struct node
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
     * Second, use {@link #parseDependency(Element,String,int)} function to parse the <block> subtree
     * @param element function element
     * @param fileName current filename, used for mark dependency graph's node name (lineNumber-fileName)
     * @param scope function's scope is 1, symbol in block is 2
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
     * @param element declaration element
     * @param tag srcml tag
     * @param fileName current filename, used for mark dependency graph's node name (lineNumber-fileName)
     * @param scope function's scope is 1, symbol in block is 2
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
        return symbol;
    }

    /**
     * This function find variables exist in expression
     * @param element expression element
     * @param fileName current filename, used for mark dependency graph's node name (lineNumber-fileName)
     * @param scope is used for mark the symbol's position
     */
    private static void findExpr(Element element, String fileName, int scope) {

        Element nameNode;
        //<expr><name> <name1...><name2...> </name>  </expr>
        if (element.getFirstChildElement("expr", "http://www.sdml.info/srcML/src") != null) {
            nameNode = element.getFirstChildElement("expr", "http://www.sdml.info/srcML/src")
                    .getFirstChildElement("name", "http://www.sdml.info/srcML/src");
        } else {
            nameNode = element;
        }

        Elements nameList = nameNode.getChildElements();
        if (nameList.size() > 0) {
            for (int i = 0; i < nameList.size(); i++) {
                findExpr(nameList.get(i), fileName, scope);
            }
        } else {
            String var = nameNode.getValue();
            String lineNumber = nameNode.getAttribute(0).getValue();

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
            findVarDependency(var, scope, nodeLabel);
        }
    }

    /**
     * This function find call element
     * @param element call element
     * @param fileName current filename, used for mark dependency graph's node name (lineNumber-fileName)
     * @param scope is used for mark the symbol's position
     */
    private static void findCall(Element element, String fileName, int scope) {
        //<expr><call> <name> <argument_list> </call> </expr>

        //call node
        Element callNode = element.getFirstChildElement("expr", "http://www.sdml.info/srcML/src")
                .getFirstChildElement("call", "http://www.sdml.info/srcML/src");
        String callName = callNode.getFirstChildElement("name", "http://www.sdml.info/srcML/src").getValue();
        String lineNumber = callNode.getFirstChildElement("name", "http://www.sdml.info/srcML/src").getAttribute(0).getValue();
        String nodeLabel = lineNumber + "-" + fileName;
        findFuncDependency(callName, scope, nodeLabel);

        //save into dependent Table
        Symbol call = new Symbol(callName, "", lineNumber, "call", fileName, scope);
        dependentTable.add(call);


        //argument list
        Elements argument_List = callNode.getFirstChildElement("argument_list", "http://www.sdml.info/srcML/src").getChildElements();
        for (int i = 0; i < argument_List.size(); i++) {
            Element argument = argument_List.get(i);
            findExpr(argument, fileName, scope);
        }


    }

    /**
     * This function finds the use of variable declaration, and create edge between 'def-use'
     * @param var variable name
     * @param scope position of the variable
     * @param depenNodeLabel dependent node's label: lineNumber-filename
     */
    public static void findVarDependency(String var, int scope, String depenNodeLabel) {
        for (Symbol s : symbolTable) {
            if (s.getName().equals(var) && scope >= s.getScope()) {
                String edgeLable = "<Def-Use> " + var;
                addEdgesToFile(depenNodeLabel, s, edgeLable);
            }
        }
    }

    /**
     * This function find the edge between call->function and call->function_declaration
     * @param funcName function Name
     * @param scope function scope
     * @param depenNodeLabel call symbol's label (lineNumber-fileName)
     */
    public static void findFuncDependency(String funcName, int scope, String depenNodeLabel) {
        for (Symbol s : symbolTable) {
            if (s.getName().equals(funcName)) {
                if (s.getTag().equals("func_decl") || s.getTag().equals("function")) {
                    String edgeLable = "<Call> " + funcName;
                    addEdgesToFile(depenNodeLabel, s, edgeLable);
                }
            }
        }
    }

    /**
     * This function write edge into graph file
     * @param depenNodeLabel dependent node lable
     * @param decl declaration symbol
     * @param edgeLabel  edge label
     */
    public static void addEdgesToFile(String depenNodeLabel, Symbol decl, String edgeLabel) {
        int dependId = nodeList.get(depenNodeLabel);
        String declNodeLabel = decl.getLineNumber() + "-" + decl.getFileName();
        int declId = nodeList.get(declNodeLabel);
        ioFunctionSet.writeTofile(dependId + " -> " + declId + "[label=\"" + edgeLabel + "\"];\n", graph.getPath());
        edgeList.add(depenNodeLabel + "->" + declNodeLabel);
    }

    public static void main(String[] args) {

        String testDir = "EmailSystem/test_10";
        createDependencyGraph(testDir);
    }
}
