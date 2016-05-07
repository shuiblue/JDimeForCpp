package de.fosd.jdime.dependencyGraph;

import de.fosd.jdime.util.IOFunctionSet;
import nu.xom.Element;
import nu.xom.Elements;
import nu.xom.Text;
import org.apache.commons.io.FileUtils;

import java.io.File;
import java.io.IOException;
import java.util.*;

/**
 * Created by shuruiz on 12/10/15.
 */
public class DependencyGraph {

    IOFunctionSet ioFunctionSet = new IOFunctionSet();

    //symbol Table stores all the declaration nodes.
    HashSet<Symbol> symbolTable = new HashSet<>();

    // lonelySymbolSet stores all the nodes that haven't find any node that could be point to.
    HashSet<Symbol> lonelySymbolSet = new HashSet<>();

    // this map stores nodes that have same name, used for search, in order to find dependencies effectively.
    HashMap<String, HashSet<Symbol>> sameNameMap = new HashMap<>();

    String edgeListTxt;

    // node id
    int id = 0;

    //node list stores  the id for the node, used for create graph file. HashMap<String, Integer>
    HashMap<String, Integer> nodeList = new HashMap<>();

    // this is the dependency Graph HashMap<String, HashSet<String[]>> ;
    // key: node label
    HashMap<String, HashSet<String[]>> dependencyGraph = new HashMap<>();
    HashMap<String, HashSet<String[]>> completeGraph = new HashMap<>();

    //edge list stores all the edges, used for testing
    HashSet<String> edgeList = new HashSet<>();
    // used for srcml
    final public String NAMESPACEURI = "http://www.sdml.info/srcML/src";

    //hierachical and control flow edges are optional
    public boolean HIERACHICAL = true;
    static final public boolean CONTROL_FLOW = false;
    static final public String CONTROLFLOW_LABEL = "<Control-Flow>";

    // directory stores source code of target project
    String sourcecodeDir;

    // directory stores analyzing result
    String analysisDir;

    //node list about changed code : filename+linenumber
    ArrayList<String> forkaddedNodeList;

    /**
     * This function just call the create Dependency Graph, used for cluster nodes.
     * TODO modify compareTwoGraphs return type
     *
     * @return dependency graph, no edge label stored.
     */

    public  HashMap<String, Integer>  getDependencyGraphForProject(String projectPath, String repo, int dirNum) {
        String testDir = projectPath + repo;
        sourcecodeDir = testDir + "/" + repo;
        analysisDir = testDir + "/DPGraph/" + dirNum + "/";
        new File(analysisDir).mkdirs();

        //fork added node/ changed code
        String forkAddedNodeTxt = "forkAddedNode.txt";
        String[] forkaddedNode = new String[0];
        try {
            forkaddedNode = ioFunctionSet.readResult(analysisDir + forkAddedNodeTxt).split("\n");
        } catch (IOException e) {
            e.printStackTrace();
        }
        forkaddedNodeList = new ArrayList(Arrays.asList(forkaddedNode));

        //create graph file
        edgeListTxt = analysisDir + "edgeList.txt";
        ioFunctionSet.rewriteFile("", edgeListTxt);
        ioFunctionSet.rewriteFile("", analysisDir + "parsedLines.txt");

        //parse every source code file in the project
        File dir = new File(sourcecodeDir);
        String[] names = dir.list();
        for (String fileName : names) {
            parseSingleFile(fileName);
        }

        //create edges cross files
        addEdgesCrossFiles();

        //generate edge about consecutive lines
        createNeighborEdges();

        ioFunctionSet.writeToPajekFile(dependencyGraph, nodeList, analysisDir + "/changedCode.pajek.net");
        ioFunctionSet.writeToPajekFile(completeGraph, nodeList, analysisDir + "/complete.pajek.net");
        return nodeList;
//        return dependencyGraph;
    }

    /**
     * This function parse each file/directory to find source code files
     *
     * @param fileName
     */
    public void parseSingleFile(String fileName) {
        File currentFile = new File(sourcecodeDir + "/" + fileName);
        if (currentFile.isFile()) {
            if (fileName.endsWith(".cpp") || fileName.endsWith(".h") || fileName.endsWith(".c") || fileName.endsWith(".pde")) {
                String filePath = sourcecodeDir + "/" + fileName;
                String newPath = "/Users/shuruiz/Work/tmpXMLFile/" + sourcecodeDir.replace("/Users/shuruiz/Work/", "");

                new File(newPath).mkdirs();
// src2srcml cannot parse .h file correctly, so change the suffix '+.cpp'
                if (fileName.endsWith(".h") || fileName.endsWith(".pde")) {
                    newPath = "/Users/shuruiz/Work/tmpXMLFile/" + filePath.replace("/Users/shuruiz/Work/", "") + ".cpp";

                } else {
                    newPath += "/" + fileName;
                }

                try {
                    FileUtils.copyFile(new File(filePath), new File(newPath));
                    filePath = newPath;
                } catch (IOException e) {
                    e.printStackTrace();
                }
                //preprocess file in case the misinterpretation of srcml
//                String newFilePath =
                ioFunctionSet.preprocessFile(filePath);

                // get xml file using src2srcml
                String xmlFilePath = ioFunctionSet.getXmlFile(newPath);

                //parse dependency graph in each file
                Element root = ioFunctionSet.getXmlDom(xmlFilePath).getRootElement();

                //Rewrite the file name for html purpose
                String newFileName = ioFunctionSet.changeFileName(fileName);

/*  for Apache
                if (!newFileName.equals("server/util_expr_parseC")) {
 */

                if (!fileName.contains("pcre_globals")) {
                    parseDependencyForSubTree(root, newFileName, 1, "");
                }
            }
        } else if (currentFile.isDirectory()) {
            String[] subNames = currentFile.list();
            for (String f : subNames) {
                parseSingleFile(fileName + "/" + f);
            }
        }
    }

    /**
     * This function create edges between consecutive lines,
     * ignore comments
     */
    private void createNeighborEdges() {
        String currentFile = "";
        int preLineNum = -1;
        int diff = 1;
        for (String s : forkaddedNodeList) {
            s = s.trim();
            if (!s.equals("")) {
                String[] node = s.trim().split("-");
                String fileName = node[0];
                int lineNum = Integer.valueOf(node[1]);
                if (fileName.equals(currentFile)) {
                    if (lineNum == preLineNum + diff) {
                        String preloc = fileName + "-" + preLineNum;
                        if (dependencyGraph.get(s) != null && dependencyGraph.get(preloc) != null) {
                            addEdgesToFile(s, preloc, "<neighbor>");
                            diff = 1;
                            preLineNum = lineNum;
                        } else if (dependencyGraph.get(preloc) == null && dependencyGraph.get(s) != null) {
                            preLineNum = lineNum;
                        } else if (dependencyGraph.get(preloc) != null && dependencyGraph.get(s) == null) {
                            diff++;
                        } else {
                            preLineNum = lineNum + 1;
                        }
                    } else {
                        preLineNum = lineNum;
                        diff = 1;
                    }
                } else {
                    diff = 1;
                    preLineNum = lineNum;
                }
                if (preLineNum == -1) {
                    preLineNum = lineNum;
                }
                currentFile = fileName;
            }
        }
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
            String line = "";
            Element ele = elements.get(i);
            /*
            This block is parsing #if ~~, currently useless

            if ((ele.getLocalName().equals("ifdef") && ele.getNamespacePrefix().equals("cpp")) ||
                    (ele.getLocalName().equals("ifndef") && ele.getNamespacePrefix().equals("cpp"))) {
                String macroName = ele.getFirstChildElement("name", NAMESPACEURI).getValue();
                line = ele.getAttribute(0).getValue();
                Symbol ifdef = new Symbol(macroName, "", line, "ifdef", fileName, scope);
                symbolTable.add(ifdef);
                ioFunctionSet.writeTofile(fileName + " " + line + "\n", testDirPath + "parsedLines.txt");

                lonelySymbolSet.add(ifdef);
                storeIntoNodeList(fileName + "-" + line);
            } else if (ele.getLocalName().equals("define")) {
                Element macroEle = (Element) ele.getChildElements().get(1);

                Element paramEle = macroEle.getFirstChildElement("parameter_list", NAMESPACEURI);
                String tag;
                if (paramEle == null) {
                    tag = "macro";

                } else {
                    tag = "function_decl";
                }
                Element nameEle = macroEle.getFirstChildElement("name", NAMESPACEURI);
                String macroName = nameEle.getValue();
                line = nameEle.getAttribute(0).getValue();
                Symbol macro = new Symbol(macroName, "", line, tag, fileName, scope);
                storeIntoNodeList(fileName + "-" + line);
                symbolTable.add(macro);
                ioFunctionSet.writeTofile(fileName + " " + line + "\n", testDirPath + "parsedLines.txt");
//                System.out.println(fileName + "-" + line);

            } else if ((ele.getLocalName().equals("if") && ele.getNamespacePrefix().equals("cpp"))
                    || (ele.getLocalName().equals("elif") && ele.getNamespacePrefix().equals("cpp"))) {
                Element expr = ele.getFirstChildElement("expr", NAMESPACEURI);
                if (expr != null) {
                    String loc = handleVarInExpr(ele, "", fileName, scope, parentLocation, false);
                    if (!loc.equals("")) {
                        tmpStmtList.add(loc);
                    }
                }
            } else
*/
            if (ele.getLocalName().equals("function") || ele.getLocalName().equals("constructor")) {
                parseFunctionNode(ele, fileName, scope);
            } else if (ele.getLocalName().equals("if") && !ele.getNamespacePrefix().equals("cpp")) {
                tmpStmtList.addAll(parseIfStmt(ele, fileName, scope, parentLocation));
            } else if (ele.getLocalName().equals("expr_stmt")) {
                String exprLocation = handleVarInExpr(ele, "", fileName, scope, parentLocation, false);
                if (!exprLocation.equals("")) {
                    tmpStmtList.add(exprLocation);
                }
            } else if (ele.getLocalName().equals("decl_stmt")) {
                Element decl = ele.getFirstChildElement("decl", NAMESPACEURI);
                Symbol declSymbol = addDeclarationSymbol(decl, "decl_stmt", fileName, scope, parentLocation, "");
                if (declSymbol != null) {
                    tmpStmtList.add(fileName + "-" + declSymbol.getLineNumber());
                }
            } else if (ele.getLocalName().equals("label") && (((Element) ele.getParent().getParent()).getLocalName().equals("block"))) {
                // this is spicifically for struct definition include bitfiles for certain fields
                //e.g.   unsigned short icon : 8;
                // srcml to interpret it in a wrong way, so I hard code this case to parse the symbol
                // <macro><label><expr_stmt>  represent a field
                Symbol declSymbol = addDeclarationSymbol(ele, "decl_stmt", fileName, scope, parentLocation, "");
                tmpStmtList.add(fileName + "-" + declSymbol.getLineNumber());
            } else if (ele.getLocalName().equals("typedef")) {
                parseTypedef(ele, fileName, scope, parentLocation);
            } else if (ele.getLocalName().equals("function_decl")) {
                addDeclarationSymbol(ele, "function_decl", fileName, scope, parentLocation, "");

            } else if (ele.getLocalName().equals("return")) {
                Element returnContent = ele.getFirstChildElement("expr", NAMESPACEURI);
                if (returnContent != null) {
                    tmpStmtList.add(handleVarInExpr(ele, "", fileName, scope, parentLocation, false));
                }
            } else if (ele.getLocalName().equals("for")) {
                tmpStmtList.addAll(parseForStmt(ele, fileName, scope, parentLocation));
            } else if (ele.getLocalName().equals("while") || ele.getLocalName().equals("switch")) {
                tmpStmtList.addAll(parseWhileStmt(ele, fileName, scope, parentLocation));
            } else if (ele.getLocalName().equals("case")) {
                tmpStmtList.addAll(parseCaseStmt(ele, fileName, scope, parentLocation));
            } else if (ele.getLocalName().equals("enum")) {
                parseEnum(ele, fileName, scope);
            } else if (ele.getLocalName().equals("macro")) {
                parseMacros(ele, fileName, scope);
            } else if (ele.getLocalName().equals("block")) {
                tmpStmtList.addAll(parseDependencyForSubTree(ele, fileName, scope + 1, parentLocation));
            } else if (ele.getLocalName().equals("do")) {
                tmpStmtList.addAll(parseDoWhile(ele, fileName, scope, parentLocation));
            } else if (ele.getLocalName().equals("using")) {
                Element nameEle = ele.getFirstChildElement("name", NAMESPACEURI);
                line = getLineNumOfElement(nameEle);
                tmpStmtList.add(fileName + "-" + line);
                Symbol symbol = new Symbol(nameEle.getValue(), "", line, "using", fileName, scope);
                findVarDependency(symbol);
            } else if (ele.getLocalName().equals("expr")) {
                handleVarInExpr(subTreeRoot, line, fileName, scope, parentLocation, false);
            } else {
                if (ele.getLocalName().equals("struct")
                        || ele.getLocalName().equals("class")
                        || ele.getLocalName().equals("namespace")
                        || ele.getLocalName().equals("union")
                        ) {
                    parseStructOrClass(ele, fileName, scope, parentLocation, "", ele.getLocalName());
                }
            }

            //remove symbol, whose scope >1
            if (((Element) ele.getParent()).getLocalName().equals("unit")) {
                symbolTable = removeLocalSymbol(symbolTable);
            }
        }
        return tmpStmtList;
    }

    /**
     * This function parse
     * do{} while()
     *
     * @param ele            do-element
     * @param fileName       current fileName
     * @param scope          scope for current node
     * @param parentLocation location of parent's node
     * @return list of variable location
     */
    private ArrayList<String> parseDoWhile(Element ele, String fileName, int scope, String parentLocation) {
        ArrayList<String> blockStmtList = new ArrayList<>();
        parentLocation = fileName + "-" + getLineNumOfElement(ele);
        storeIntoNodeList(parentLocation);

        blockStmtList.addAll(parseDependencyForSubTree(ele, fileName, scope + 1, parentLocation));
        if (CONTROL_FLOW) {
            addControlFlowDependency(parentLocation, blockStmtList, fileName);
        }
        //while <condition>
        Element conditionEle = ele.getFirstChildElement("condition", NAMESPACEURI);
        if (conditionEle != null) {
            String line = getLineNumOfElement(conditionEle);
            handleVarInExpr(conditionEle, line, fileName, scope + 1, parentLocation, false);
        }
        return blockStmtList;
    }

    /**
     * This function parse Case stmt of 'switch case '
     *
     * @param ele
     * @param fileName
     * @param scope
     * @param parentLocation
     * @return
     */
    private ArrayList<String> parseCaseStmt(Element ele, String fileName, int scope, String parentLocation) {
        String caseLocation = fileName + "-" + getLineNumOfElement(ele);
        storeIntoNodeList(caseLocation);
        ArrayList<String> case_tmpStmtList = new ArrayList<>();

        case_tmpStmtList.addAll(parseDependencyForSubTree(ele, fileName, scope + 1, caseLocation));

        if (CONTROL_FLOW && case_tmpStmtList.size() > 0) {
            addControlFlowDependency(caseLocation, case_tmpStmtList, fileName);
        }
        return case_tmpStmtList;
    }

    /**
     * This function parse typedef
     *
     * @param ele
     * @param fileName
     * @param scope
     * @param parentLocation
     */
    private void parseTypedef(Element ele, String fileName, int scope, String parentLocation) {
        //typedef struct
        Element type_ele = ele.getFirstChildElement("type", NAMESPACEURI);
        if (type_ele != null) {
            //struct definition
            Element structChild = type_ele.getFirstChildElement("struct", NAMESPACEURI);
            boolean structDef = (structChild != null);
            //struct declaration :" typedef struct name alias;"
            boolean structDecl = (type_ele.getChild(0) instanceof Text) && type_ele.getChild(0).getValue().trim().equals("struct");

            if (structDef) {
                if (structChild.getLocalName().equals("struct")) {
                    String alias = ele.getFirstChildElement("name", NAMESPACEURI).getValue();
                    parseStructOrClass(structChild, fileName, scope, parentLocation, alias, "struct");
                }
            } else if (structDecl) {
                String alias = ele.getFirstChildElement("name", NAMESPACEURI).getValue();
                addDeclarationSymbol(type_ele, "struct", fileName, scope, parentLocation, alias);
            }

        }
        //typedef function
        Element funcDecl_ele = ele.getFirstChildElement("function_decl", NAMESPACEURI);
        if (funcDecl_ele != null) {
            addDeclarationSymbol(funcDecl_ele, "function_decl", fileName, scope, parentLocation, "");

        }
    }


    private void parseMacros(Element ele, String fileName, int scope) {
        Element nameEle = ele.getFirstChildElement("name", NAMESPACEURI);
        Element argumentListEle = ele.getFirstChildElement("argument_list", NAMESPACEURI);
        String tag = "macro";
        if (argumentListEle != null) {
            tag = "call";
        }

        String macroName = nameEle.getValue();
        String line = getLineNumOfElement(nameEle);
        Symbol macro = new Symbol(macroName, "", line, tag, fileName, scope);
        storeIntoNodeList(fileName + "-" + line);

        symbolTable.add(macro);
        lonelySymbolSet.add(macro);
        ioFunctionSet.writeTofile(fileName + " " + line + "\n", analysisDir + "parsedLines.txt");

        if (argumentListEle != null) {
            Elements arguments = argumentListEle.getChildElements();
            for (int x = 0; x < arguments.size(); x++) {

                Element argument = arguments.get(x);
                String argumentLocation = fileName + "-" + line;

                //save into nodeList
                storeIntoNodeList(argumentLocation);

                String var = argument.getValue();
                Symbol dependent = new Symbol(var, "", line, "name", fileName, scope);
                findVarDependency(dependent);

            }
        }
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
     * @param childrenLocations statements' location
     * @param parentLocation    struct node's location
     */

    private void linkChildToParent(ArrayList<String> childrenLocations, String parentLocation, String label) {
        if (HIERACHICAL && !parentLocation.equals("")) {
            for (String child : childrenLocations) {
                addEdgesToFile(child, parentLocation, label);
            }
        }
    }

    /**
     * This function link children to parent, used for block -> function, then-> if, else->if
     *
     * @param childLocation
     * @param parentLocation
     */
    private void linkChildToParent(String childLocation, String parentLocation) {
        if (HIERACHICAL) {
//            if (!edgeList.contains(childLocation + "->" + parentLocation)) {
            addEdgesToFile(childLocation, parentLocation, "<child>");
//            }
        }
    }


    private void parseStructOrClass(Element ele, String fileName, int scope, String parentLocation, String alias, String tag) {
        String edgeLabel = "";
        if (tag.equals("struct")) {
            edgeLabel = "<belongToStruct>";
        } else if (tag.equals("class")) {
            edgeLabel = "<belongToClass>";
        } else if (tag.equals("namespace")) {
            edgeLabel = "<belongToNamespace>";
        } else if (tag.equals("union")) {
            edgeLabel = "<belongToUnion>";
        }

        //struct
        Symbol parent = addDeclarationSymbol(ele, tag, fileName, scope, parentLocation, alias);
        if (parent != null) {
            parentLocation = fileName + "-" + parent.getLineNumber();
        }

        //block
        Element block = ele.getFirstChildElement("block", NAMESPACEURI);
        if (block != null) {
            if (block.getChildElements().size() > 0) {
                if (block.getChildElements().get(0).getLocalName().equals("public")
                        || block.getChildElements().get(0).getLocalName().equals("private")
                        || block.getChildElements().get(0).getLocalName().equals("protected")) {

                    //for common struct definition
                    for (int s = 0; s < block.getChildElements().size(); s++) {
                        Element group = block.getChildElements().get(s);

                        //get children
                        ArrayList<String> children = parseDependencyForSubTree(group, fileName, scope, parentLocation);
                        boolean tmpHierarchy = true;
                        if (!HIERACHICAL) {
                            tmpHierarchy = HIERACHICAL;
                            HIERACHICAL = true;
                        }
                        //link children -> parent
                        linkChildToParent(children, parentLocation, edgeLabel);
                        if (!tmpHierarchy) {
                            HIERACHICAL = tmpHierarchy;
                        }
                    }

            } else {
                //get children
                ArrayList<String> children = parseDependencyForSubTree(block, fileName, scope, parentLocation);
                boolean tmpHierarchy = true;
                if (!HIERACHICAL) {
                    tmpHierarchy = HIERACHICAL;
                    HIERACHICAL = true;
                }
                //link children -> parent
                linkChildToParent(children, parentLocation, edgeLabel);
                if (!tmpHierarchy) {
                    HIERACHICAL = tmpHierarchy;
                }
            }
        }}
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
        Symbol functionSymbol = addDeclarationSymbol(element, "function", fileName, scope, "", "");
        String parentLocation = fileName + "-" + functionSymbol.getLineNumber();
        //check parameters
        Element parameter_list = element.getFirstChildElement("parameter_list", NAMESPACEURI);
        if (parameter_list!=null&&parameter_list.getChildElements() != null) {
            for (int i = 0; i < parameter_list.getChildElements("param", NAMESPACEURI).size(); i++) {
                Element paramNode = parameter_list.getChildElements("param", NAMESPACEURI).get(i);
                //add Parameter to symbol table
                if (paramNode.getChildElements().size() > 0) {
                    addDeclarationSymbol((Element) paramNode.getChild(0), "param", fileName, scope + 1, parentLocation, "");
                }
            }
        }

        //check block
        Element block = element.getFirstChildElement("block", NAMESPACEURI);
        if (block != null) {
            parseDependencyForSubTree(block, fileName, scope + 1, parentLocation);
        }
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

        if (then_Node != null) {
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
        }
        return stmtList;
    }

    /**
     * this function parse if statement
     *
     * @param ele      if  element
     * @param fileName fileName of this node
     * @param scope    level of the node
     * @return list of statement location
     */
    private void parseEnum(Element ele, String fileName, int scope) {
        ArrayList<Symbol> newsymbol = new ArrayList<>();
        //name
        Element enumNameElement = ele.getFirstChildElement("name", NAMESPACEURI);
        if (enumNameElement != null) {
            String enum_lineNumber = getLineNumOfElement(enumNameElement);
            Symbol enumSymbol = new Symbol(enumNameElement.getValue(), "", enum_lineNumber, "enum", fileName, scope);
            newsymbol.add(enumSymbol);
            storeIntoNodeList(fileName + "-" + enum_lineNumber);

        }
        //<block>
        Element block = ele.getFirstChildElement("block", NAMESPACEURI);
        if (block != null) {
            Elements elements = block.getChildElements();
            for (int i = 0; i < elements.size(); i++) {
                Element decl = elements.get(i).getFirstChildElement("name", NAMESPACEURI);
                if (decl != null) {
                    String declLineNumber = getLineNumOfElement(decl);
                    Symbol declSymbol = new Symbol(decl.getValue(), "", declLineNumber, "decl", fileName, scope);
                    newsymbol.add(declSymbol);
                    storeIntoNodeList(fileName + "-" + declLineNumber);

                    linkChildToParent(fileName + "-" + declLineNumber, fileName + "-" + declLineNumber);
                }
            }
        }
        storeSymbols(newsymbol);

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

        if (whileLocation.equals("")) {
            whileLocation = fileName + "-" + getLineNumOfElement(condition);
            //save into nodeList
            storeIntoNodeList(whileLocation);
        }
        //Block
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
        if (CONTROL_FLOW && stmtList.size() > 0) {
            addControlFlowDependency(whileLocation, stmtList, fileName);
        }
        return stmtList;
    }

    /**
     * this function add control flow dependency for if-then-else, while, etc.
     *
     * @param headLocation condition location
     * @param stmtList     statement list in block
     * @param fileName     current file, used for marking location
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

        String lineNumber = getLineNumOfElement(ele);
        String forLocation = fileName + "-" + lineNumber;
        Element init = ele.getFirstChildElement("init", NAMESPACEURI).getFirstChildElement("decl", NAMESPACEURI);
        Symbol initVarSymbol;
        if (init != null) {
            initVarSymbol = addDeclarationSymbol(init, "for", fileName, scope, parentLocation, "");
            tmpStmtList.add(fileName + "-" + initVarSymbol.getLineNumber());
        } else {

            Element condition = ele.getFirstChildElement("condition", NAMESPACEURI);
            Element cond_exprNode = condition.getFirstChildElement("expr", NAMESPACEURI);

            if (cond_exprNode != null) {
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

            }

        }
//        String nodeLabel = fileName + "-" + lineNumber;
        storeIntoNodeList(forLocation);

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
    private Symbol addDeclarationSymbol(Element element, String tag, String fileName, int scope, String parentLocation, String alias) {
        String type;
        Element type_Node = element.getFirstChildElement("type", NAMESPACEURI);
        if (type_Node != null) {
            type = type_Node.getValue();
        } else {
            type = "";
        }

        Symbol symbol;
        Element nameElement = element.getFirstChildElement("name", NAMESPACEURI);

        String name;


        if (nameElement != null && alias.equals("")) {
            //for the case of array , e.g. a[3]  <name><name>a</name><index>3</index><name>

            Element subnameEle = nameElement.getFirstChildElement("name", NAMESPACEURI);
            if (subnameEle != null) {
                name = subnameEle.getValue();
            } else {
                name = nameElement.getValue();
            }
            if (name.contains("::")) {
                name = name.split("::")[1];
            }
        } else if (nameElement == null && !alias.equals("")) {
            name = alias;    //this is only used for typedef struct
        } else if (nameElement != null && !alias.equals("")) {
            name = alias;
            alias = nameElement.getValue();
        } else {
            return null;
        }

        String lineNumber = "";
        if (nameElement != null) {
            lineNumber = getLineNumOfElement(nameElement);
        } else {
            lineNumber = getLineNumOfElement(element);
        }

        symbol = new Symbol(name, type, lineNumber, tag, fileName, scope, alias);
        ArrayList<Symbol> newsymbol = new ArrayList<>();
        newsymbol.add(symbol);
        storeSymbols(newsymbol);

        //save into nodeList
        String nodeLabel = fileName + "-" + lineNumber;
        storeIntoNodeList(nodeLabel);


        //index is optional
        if (nameElement != null) {
            Element indexNode = nameElement.getFirstChildElement("index", NAMESPACEURI);
            if (indexNode != null) {
                handleVarInExpr(indexNode, lineNumber, fileName, scope, parentLocation, true);
            }
        }

        // init is optional
        Element initNode = element.getFirstChildElement("init", NAMESPACEURI);
        if (initNode != null) {

            handleVarInExpr(initNode, lineNumber, fileName, scope, parentLocation, true);
        }


//        System.out.println(fileName + " " + lineNumber);

        ioFunctionSet.writeTofile(fileName + " " + lineNumber + "\n", analysisDir + "parsedLines.txt");

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
        if (exprNode != null) {

            //<expr><name> [<name1...><name2...>] </name>  </expr>
            Elements name_Elements = exprNode.getChildElements("name", NAMESPACEURI);
            if (name_Elements.size() > 0) {
                for (int i = 0; i < name_Elements.size(); i++) {
                    Elements nameList = name_Elements.get(i).getChildElements("name", NAMESPACEURI);
                    String var;
                    Symbol dependent;
                    if (nameList.size() > 0) {
                        if (stmtLineNumber.equals("")) {
                            stmtLineNumber = getLineNumOfElement(nameList.get(0));
                        }
                        exprLocation = fileName + "-" + stmtLineNumber;

                        //save into nodeList
                        storeIntoNodeList(exprLocation);

                        for (int x = 0; x < nameList.size(); x++) {
                            var = nameList.get(x).getValue();
                            dependent = new Symbol(var, "", stmtLineNumber, "name", fileName, scope);
                            findVarDependency(dependent);
                        }
                    } else {
                        var = name_Elements.get(i).getValue();
                        if (!var.equals("void") && !var.equals("float")) {
                            if (stmtLineNumber.equals("")) {
                                stmtLineNumber = getLineNumOfElement(name_Elements.get(i));
                            }
                            dependent = new Symbol(var, "", stmtLineNumber, "name", fileName, scope);
                            exprLocation = fileName + "-" + stmtLineNumber;
                            //save into nodeList
                            storeIntoNodeList(exprLocation);
                            findVarDependency(dependent);

                            if (!parentLocation.equals("")) {
                                String childLocation = fileName + "-" + stmtLineNumber;
                                linkChildToParent(childLocation, parentLocation);
                            }
                        }
                    }

                }
            }

            //<expr><call>
            Elements callElementList = exprNode.getChildElements("call", NAMESPACEURI);
            for (int i = 0; i < callElementList.size(); i++) {
                Element callElement = callElementList.get(i);
                if (callElement != null) {
                    // <expr> <name> = <call>, call is initializing the name
                    if (!exprLocation.equals("")) {
                        isInit = true;
                    }
                    String callLocation = handleCallNode(callElement, stmtLineNumber, fileName, scope, parentLocation, isInit);
                    if (exprLocation.equals("")) {
                        exprLocation = callLocation;
                    }
                }
            }

            //<expr><sizeof>
            Elements sizeofElements = exprNode.getChildElements("sizeof", NAMESPACEURI);
            if (sizeofElements.size() > 0)
//            Element sizeofElement = exprNode.getFirstChildElement("sizeof", NAMESPACEURI);
                for (int i = 0; i < sizeofElements.size(); i++) {
                    Element sizeofElement = sizeofElements.get(i);
                    stmtLineNumber = getLineNumOfElement(sizeofElement);
                    exprLocation = fileName + "-" + stmtLineNumber;

                    //argument list
                    Elements argumentList = sizeofElement.getFirstChildElement("argument_list", NAMESPACEURI).getChildElements();
                    handleArgumentList(argumentList, stmtLineNumber, fileName, scope, parentLocation);
                }

            //return nodes has its own line Number
            if (element.getLocalName().equals("return")) {
                String line = getLineNumOfElement(element);
                exprLocation = fileName + "-" + line;
                //save into nodeList
                storeIntoNodeList(exprLocation);
            }

            //block node
            Element exprBlockEle = exprNode.getFirstChildElement("block", NAMESPACEURI);

            if (exprBlockEle != null) {
                if (parentLocation.equals("") && !((Element) exprNode.getParent()).getLocalName().equals("unit")) {
                    parentLocation = fileName + "-" + getLineNumOfElement(exprBlockEle);
                }
                storeIntoNodeList(parentLocation);
                ArrayList<String> tmpStmtList = parseDependencyForSubTree(exprBlockEle, fileName, scope + 1, parentLocation);

                linkChildToParent(tmpStmtList, parentLocation, "<init>");
            }

            //macro node  (hard code wrong output from src2srcml)

            Elements macroEleList = exprNode.getChildElements("macro", NAMESPACEURI);
            for (int j = 0; j < macroEleList.size(); j++) {
                Element macroEle = macroEleList.get(j);
                parseMacros(macroEle, fileName, scope);
            }


            if (!parentLocation.equals("") && !exprLocation.equals("")) {

                if (!exprLocation.equals(parentLocation)) {
                    linkChildToParent(exprLocation, parentLocation);
                }
            }
//        System.out.println(exprLocation);

            ioFunctionSet.writeTofile(exprLocation + "\n", analysisDir + "parsedLines.txt");
        }

        if (exprLocation.equals("")) {
            exprLocation = fileName + "-" + getLineNumOfElement(element);
            storeIntoNodeList(exprLocation);
        }
        return exprLocation;
    }

    private String getLineNumOfElement(Element element) {
        String lineNum = "-1";
        if (element.getAttributeCount() > 0) {
            lineNum = element.getAttribute(0).getValue();
        } else if (element.getChildElements().size() > 0) {
            for (int i = 0; i < element.getChildElements().size(); i++) {
                lineNum = getLineNumOfElement(element.getChildElements().get(i));
                if (!lineNum.equals("")) {
                    break;
                }
            }

        } else {
            lineNum = getLineNumOfElement((Element) element.getParent());
        }
        return lineNum;
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

            if (forkaddedNodeList.contains(exprLocation+" ")) {
                dependencyGraph.put(exprLocation, new HashSet<>());
            }
            completeGraph.put(exprLocation, new HashSet<>());
//            System.out.println(exprLocation);
            //write into graph file .gv
//            ioFunctionSet.writeTofile(id + " [label = \"" + exprLocation + "\"];\n", graph.getPath());
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
        String lineNumber = "";
        String nodeLabel = "";

        if (callNameElement != null) {
            String callName = callNameElement.getValue();
            if (isInit && stmtLineNumber.length() > 0) {
                lineNumber = stmtLineNumber;
            } else {
                lineNumber = getLineNumOfElement(callNameElement);
            }

            nodeLabel = fileName + "-" + lineNumber;
            //save into dependent Table
            //call's level is 1

            if (!callName.equals("defined")) {
                //save into nodeList
                storeIntoNodeList(nodeLabel);
                Symbol call = new Symbol(callName, "", lineNumber, "call", fileName, 1);
                lonelySymbolSet.add(call);
                addFuncDependency(call);


            }
        }


        //argument list
        Element argumentListEle = callNode.getFirstChildElement("argument_list", NAMESPACEURI);
        Elements argumentList = argumentListEle.getChildElements("argument", NAMESPACEURI);
        if (lineNumber.equals("")) {
            lineNumber = getLineNumOfElement(argumentListEle);
            nodeLabel = fileName + "-" + lineNumber;
        }
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

    public void findVarDependency(Symbol variable) {
//    public void findVarDependency(Symbol variable) {
        String var = variable.getName();
        int scope = variable.getScope();
        String depenNodeLabel = variable.getFileName() + "-" + variable.getLineNumber();
        storeIntoNodeList(depenNodeLabel);
        int edgeNum = 0;
        for (Symbol s : symbolTable) {
            if (s != null) {

                if (!s.tag.contains("function")) {
                    //check local variable
                    if (s.getName().equals(var) && scope == s.getScope()) {
                        String declLabel = s.getFileName() + "-" + s.getLineNumber();
                        if (!declLabel.equals(depenNodeLabel)) {
                            String edgeLable = "<Def-Use> " + var;
                            addEdgesToFile(depenNodeLabel, s, edgeLable);
                            edgeNum++;
                            break;
                        }
                    }

                    // if the variable is not local, then check global variable def
                    if (s.getName().equals(var) && scope > s.getScope()) {
                        String edgeLable = "<Def-Use> " + var;
                        addEdgesToFile(depenNodeLabel, s, edgeLable);
                        edgeNum++;

                    }
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
        String depen_position = depend.getFileName() + "-" + depend.getLineNumber();
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
        String decl_position = decl.getFileName() + "-" + decl.getLineNumber();
        addEdgesToFile(depen_position, decl_position, edgeLabel);
    }

    /**
     * This function write edge into graph file
     *
     * @param depen_position dependent node position (lineNumber_filename)
     * @param decl_position  declaration node postion
     * @param edgeLabel      edge label
     */
    public void addEdgesToFile(String depen_position, String decl_position, String edgeLabel) {
//# reserve multipul edges between 2 nodes

        boolean addNewEdge = true;
        HashSet<String[]> dependencyNodes = dependencyGraph.get(decl_position);

        if (dependencyNodes != null && dependencyNodes.size() > 0) {
            for (String[] sn : dependencyNodes) {
                if (sn[0].equals(depen_position)) {

                    // not allow : multipul edges between 2 nodes
//                    addNewEdge = false;
//                    break;
                    if (sn[1].contains(edgeLabel)) {
//                        // allow : same edge with different label appears twice
                        addNewEdge = false;
                        break;
                    }
                }
            }
        }

        if (addNewEdge) {
//             only consider edge between fork added node
//            if (forkaddedNodeList.contains(depen_position + " ") && forkaddedNodeList.contains(decl_position + " ")) {

            int dependId = nodeList.get(depen_position);
            int declId = nodeList.get(decl_position);
            if (dependId != declId) {
                ioFunctionSet.writeTofile(dependId + "," + declId + "," + edgeLabel + "\n", edgeListTxt);
                edgeList.add(depen_position + "->" + decl_position);

                //add to dependency graph
                HashSet<String[]> dependNodes = dependencyGraph.get(decl_position);
                HashSet<String[]> com_dependNodes = completeGraph.get(decl_position);
                if (dependNodes == null) {
                    if (forkaddedNodeList.contains(depen_position + " ") && forkaddedNodeList.contains(decl_position + " ")) {
                        dependNodes = new HashSet<>();
                    }
                } else if (com_dependNodes == null) {
                    com_dependNodes = new HashSet<>();
                }

                String[] tmpEdge;
                //         edge between fork added node , weight is bigger
//                if (forkaddedNodeList.contains(depen_position + " ") && forkaddedNodeList.contains(decl_position + " ")) {
//
//                    tmpEdge = new String[]{depen_position, edgeLabel, "3"};
//                }else{
//                    tmpEdge = new String[]{depen_position, edgeLabel, "1"};
//                }

                //Another solution of weights
                if (edgeLabel.contains("neighbor")) {
                    tmpEdge = new String[]{depen_position, edgeLabel, "1"};
                } else {
                    tmpEdge = new String[]{depen_position, edgeLabel, "5"};
                }


                if (forkaddedNodeList.contains(depen_position + " ") && forkaddedNodeList.contains(decl_position + " ")) {
                    dependNodes.add(tmpEdge);
                    dependencyGraph.put(decl_position, dependNodes);
                }
                com_dependNodes.add(tmpEdge);
                completeGraph.put(decl_position, com_dependNodes);
            }

//            }


        }
    }


    public void main(String[] args) {

        String testDir = "EmailSystem/test_10";
//        createDependencyGraph(testDir);
    }
}
