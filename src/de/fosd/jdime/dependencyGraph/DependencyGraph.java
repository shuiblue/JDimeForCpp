package de.fosd.jdime.dependencyGraph;

import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import de.fosd.jdime.util.Entity;
import de.fosd.jdime.util.IOFunctionSet;
import de.fosd.jdime.util.Relation;
import nu.xom.Document;
import nu.xom.Element;
import nu.xom.Elements;
import org.apache.commons.io.FileUtils;


/**
 * Created by shuruiz on 11/5/15.
 */
public class DependencyGraph {
    static List<DeclarationNode> declarationNodes = new ArrayList<>();
    static List<DependenceNode> dependenceNodes = new ArrayList<>();
    static IOFunctionSet ioFunctionSet = new IOFunctionSet();
    static Entity entity = new Entity();
    static HashMap<String, String> nodeList = new HashMap<>();
    static File graph;

    public static void createDependencyGraph(String testDir) {


        String dirPath = "testcpp/dependencyGraph/";
        String testDirPath = dirPath + testDir + "/";

        File graph = new File(testDirPath + "graph.gv");
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
                findAllNodes(xmlFilePath, fileName);
            }
        }

        nodeList = createNodeList();

        //find dependency between depen Node --> decl Node
        for (int i = 0; i < declarationNodes.size(); i++) {
            for (int j = 0; j < dependenceNodes.size(); j++) {
                DeclarationNode decl = declarationNodes.get(i);
                DependenceNode depen = dependenceNodes.get(j);
                if (decl.getName().equals(depen.getName())) {
                    Relation relation = isRelated(decl, depen);
//                    String type = decl.getType();
//                    String name = decl.getName();
//                    if (relation.equals(Relation.BelongsTo)) {
//                        Edge edge = new Edge("<" + relation.name() + "> " + name, depen.getLineNumber() + "-" + depen.getFileName(), decl.getLineNumber() + "-" + decl.getFileName());
////                        g.addEdge(edge, depen.getLineNumber() + "-" + depen.getFileName(), decl.getLineNumber() + "-" + decl.getFileName());
//                        continue;
//                    }
//                    if (!relation.equals(Relation.SAMENAME)) {
                    decl.dependencies.add(depen);
                    depen.setDeclaration(decl);
                    String depenNode = nodeList.get(depen.getLineNumber() + "-" + depen.getFileName());
                    String declNode = nodeList.get(decl.getLineNumber() + "-" + decl.getFileName());
                    String edgeLable = "<" + relation.name() + "> " + decl.getName();
                    ioFunctionSet.writeTofile(depenNode + " -> " + declNode + "[ label=\"" + edgeLable + "\" ];\n", graph.getPath());
//                    }
                }
            }
        }


        //check .h define function and  .cpp define the body
        for (DependenceNode dep1 : dependenceNodes) {
            for (DependenceNode dep2 : dependenceNodes) {
                if (dep1.getName().equals(dep2.getName())) {
                    Relation relation = isRelated(dep1, dep2);
                    if (!relation.equals(Relation.False)) {
                        //dep2 -> dep1
                        dep1.dependList.add(dep2);
                        dep2.setDependOn(dep1);
//
                        String depenNode = nodeList.get(dep2.getLineNumber() + "-" + dep2.getFileName());
                        String declNode = nodeList.get(dep1.getLineNumber() + "-" + dep1.getFileName());
                        String edgeLable = "<" + relation.name() + "> " + dep2.getName();
                        ioFunctionSet.writeTofile(depenNode + " -> " + declNode + "[ label=\"" + edgeLable + "\" ];\n", graph.getPath());
                    }
                }
            }
        }
        ioFunctionSet.writeTofile("}", graph.getPath());


    }


    public static HashMap<String, String> createNodeList() {
        HashMap<String, String> nodeList = new HashMap<>();
        int id = 0;

        //add vertex
        for (DeclarationNode decl : declarationNodes) {

            String nodeLabel = decl.getLineNumber() + "-" + decl.getFileName();
            int num = id + 1;
            addNode(nodeLabel, num);
            id++;

        }
        for (DependenceNode depen : dependenceNodes) {
            String nodeLabel = depen.getLineNumber() + "-" + depen.getFileName();
            int num = id + 1;
            addNode(nodeLabel, num);
            id++;


        }
        return nodeList;
    }

    public static void addNode(String nodeLabel, int num) {
        try {
            if (!ioFunctionSet.readResult(graph.getPath()).contains(nodeLabel)) {

                ioFunctionSet.writeTofile(num + " [label = \"" + nodeLabel + "\"];\n", graph.getPath());
                nodeList.put(nodeLabel, num + "");

            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static Relation isRelated(DependenceNode d1, DependenceNode d2) {

        if (d1.getTag() != d2.getTag()) {
            if (d2.getTag().equals("call") && d2.getDeclaration() == null) {

                return Relation.Call;
            }
        }
        return Relation.False;
    }


    /**
     * check whether two nodes has dependency relation
     *
     * @param decl  declaration node
     * @param depen dependency node
     * @return true, if is related.
     */
    public static Relation isRelated(DeclarationNode decl, DependenceNode depen) {
        Entity entity = new Entity();
        if (decl.getDecl_tag().equals("decl_stmt") && depen.getTag().contains("expr")) {
            return Relation.Statment;
        } else if (depen.getTag().equals("call") && entity.getFuncionEntity().contains(decl.getDecl_tag())) {
            return Relation.Call;
        } else if (entity.getFuncionDeclarationEntity().contains(decl.getDecl_tag()) && entity.getFuncionBodyEntity().contains(depen.getTag())) {
            return Relation.Func_decl;
        } else if (decl.getType().equals("class") && entity.getConsDestructorEntity().contains(depen.getTag())) {
            return Relation.Cons_Destruction;
        } else if (depen.getTag().equals("Func_Class")) {
            return Relation.BelongsTo;
        } else {
            return Relation.SAMENAME;
        }
    }


    public static void findAllNodes(String xmlFilePath, String fileName) {
        Entity entity = new Entity();
//        for (String tag : entity.getOneLayerEntity()) {
//            String query = "src:" + tag;
//            if (entity.getDeclarationEntity().contains(tag)) {
//                findDeclarationNode(xmlFilePath, query, tag, fileName);
//            }
//            if (entity.getDependencyEntity().contains(tag)) {
//                findDependencyNode(xmlFilePath, query, tag, fileName);
//            }
//        }
//
//        for (String tag : entity.getStmtEntity()) {
//            String stmtTag = tag + "_stmt";
//            String query = "src:" + stmtTag + "/src:" + tag;
//            if (entity.getDeclarationEntity().contains(tag)) {
//                findDeclarationNode(xmlFilePath, query, stmtTag, fileName);
//            } else if (entity.getDependencyEntity().contains(tag)) {
//                findDependencyNode(xmlFilePath, query, stmtTag, fileName);
//            }
//        }

        for (String decl : entity.getDeclarationEntity()) {
            String query = "src:" + decl;
            if (entity.getDeclarationEntity().contains(decl)) {
                if (decl.equals("decl_stmt")) {
                    query = query + "/src:decl";
                }
                findDeclarationNode(xmlFilePath, query, decl, fileName);
            }
        }

        for (String depen : entity.getDependencyEntity()) {
            String query = "src:" + depen;
            if (entity.getDependencyEntity().contains(depen)) {
                findDependencyNode(xmlFilePath, query, depen, fileName);
            }
        }
    }


    public static void searchQuery(String xmlPath, String xpathQuery, String output) {

        //run srcML
        if (new File(xmlPath).isFile()) {
            try {
                String cmd = "srcML/srcml2src " + "--xpath " + xpathQuery + " " + xmlPath + " -o " + output;
                String[] command = cmd.split(" ");
                ProcessBuilder processBuilder = new ProcessBuilder(command);

                Process process = processBuilder.start();
                process.waitFor();

                //I don't have choice,,, when I use this loop, the wired bug is gone...
                while (ioFunctionSet.clearBlank(ioFunctionSet.readResult(output)).length() == 0) {
                    ProcessBuilder processBuilder1 = new ProcessBuilder(command);
                    Process process1 = processBuilder.start();
                    process1.waitFor();
                }
            } catch (IOException e) {
                e.printStackTrace();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        } else {
            System.out.println("File does not exist: " + xmlPath);
        }
    }


    public static void findDeclarationNode(String xmlFilePath, String query, String decl_tag, String fileName) {

        //get decl_stmt name list
        String name_output = xmlFilePath + "_" + decl_tag + "_name.xml";
        String declStmt_name_Query = "//" + query + "/src:name";
        searchQuery(xmlFilePath, declStmt_name_Query, name_output);
        Document declStmtNodeListTree = ioFunctionSet.getXmlDom(name_output);


        Element nameList_root = (Element) declStmtNodeListTree.getChild(0);

        if (nameList_root.getChildElements().size() > 0) {
            //get decl_stmt type list
            String type_output = xmlFilePath + "_" + decl_tag + "_type.xml";
            String declStmtQuery = "//" + query + "/src:type/src:name";
            searchQuery(xmlFilePath, declStmtQuery, type_output);

            Document declStmtTypeNodeListTree = ioFunctionSet.getXmlDom(type_output);
            Element typeList_root = (Element) declStmtTypeNodeListTree.getChild(0);

            Elements elements = nameList_root.getChildElements();
            for (int i = 0; i < elements.size(); i++) {
                Element nameNode = (Element) elements.get(i).getChild(0);

                if (nameNode.getAttributeCount() > 0) {
                    String declStmt_name = nameNode.getValue();
                    String lineNum = nameNode.getAttribute(0).getValue();
                    //get type
                    Element typeNode = (Element) typeList_root.getChildElements().get(i).getChild(0);
                    String type = typeNode.getValue();

                    declarationNodes.add(new DeclarationNode(declStmt_name, type, lineNum, decl_tag, fileName));
                } else if ((nameNode.getChildElements().size() > 0)) {
                    //get type
                    Element typeNode = typeList_root.getChildElements().get(0);
                    String type = typeNode.getValue();

                    String functionName = nameNode.getValue();
                    String lineNum = nameNode.getChildElements().get(0).getAttribute(0).getValue();


                    declarationNodes.add(new DeclarationNode(functionName, type, lineNum, decl_tag, fileName));
                }
            }
        }

    }

    public static void findDependencyNode(String xmlFilePath, String query, String tag, String fileName) {
        //get  name list
        String name_output = xmlFilePath + "_" + tag + "_dep.xml";
        String name_Query = "//" + query + "/src:name";

        searchQuery(xmlFilePath, name_Query, name_output);
        Document depStmtNodeListTree = ioFunctionSet.getXmlDom(name_output);
        Element nameList_root = (Element) depStmtNodeListTree.getChild(0);


        //get  type list
        String type_output = xmlFilePath + "_" + tag + "_type.xml";
        String declStmtQuery = "//" + query + "/src:type/src:name";
        searchQuery(xmlFilePath, declStmtQuery, type_output);

        Document declStmtTypeNodeListTree = ioFunctionSet.getXmlDom(type_output);
        Element typeList_root = (Element) declStmtTypeNodeListTree.getChild(0);


        Elements elements = nameList_root.getChildElements();
        for (int i = 0; i < elements.size(); i++) {
            Element nameNode = elements.get(i);
            if (((Element) nameNode.getChild(0)).getAttributeCount() > 0) {
                String depenStmt_name = nameNode.getValue();
                String lineNum = ((Element) nameNode.getChild(0)).getAttribute(0).getValue();
                String type = "";
                if (!entity.getNoTypeEntity().contains(tag)) {
                    //get type
                    Element typeNode = (Element) typeList_root.getChildElements().get(i).getChild(0);
                    type = typeNode.getValue();
                }
                dependenceNodes.add(new DependenceNode(depenStmt_name, type, tag, lineNum, fileName));
            } else if (((Element) nameNode.getChild(0)).getChildElements().size() > 0) {
                //TODO
                Element e = (Element) nameNode.getChild(0);
//                if (e.getValue().contains("::")) {
//
//
//
//                    Element child = e.getChildElements().get(1);
//                    String depenStmt_name = child.getValue();
//                    String lineNum = child.getAttribute(0).getValue();
//                    dependenceNodes.add(new DependenceNode(depenStmt_name, tag, lineNum, fileName));
//
//                    if (tag.equals("function")) {
//                        Element className_element = e.getChildElements().get(0);
//                        String className = className_element.getValue();
//                        dependenceNodes.add(new DependenceNode(className, "Func_Class", lineNum, fileName));
//                    }
//
//                } else {
////
//                    for (int j = 0; j < e.getChildElements().size(); j++) {
//                        Element child = e.getChildElements().get(j);
//                        String depenStmt_name = child.getValue();
//                        String lineNum = child.getAttribute(0).getValue();
//                        dependenceNodes.add(new DependenceNode(depenStmt_name, tag, lineNum, fileName));
//                    }
//                }
            }
            System.out.print("");
        }
    }

    public static void main(String[] args) {

        String testDir = "test_14";
        createDependencyGraph(testDir);

    }


}
