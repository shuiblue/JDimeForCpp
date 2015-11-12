package de.fosd.jdime.dependencyGraph;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import de.fosd.jdime.util.Entity;
import de.fosd.jdime.util.IOFunctionSet;
import edu.uci.ics.jung.graph.*;
import nu.xom.Document;
import nu.xom.Element;
import nu.xom.Elements;
import nu.xom.Node;


/**
 * Created by shuruiz on 11/5/15.
 */
public class DependencyGraph {
    static List<DeclarationNode> declarationNodes = new ArrayList<>();
    static List<DependenceNode> dependenceNodes = new ArrayList<>();
    static IOFunctionSet ioFunctionSet = new IOFunctionSet();
    static String xmlFilePath = "";

    DirectedSparseGraph<Integer, Edge> createDependencyGraph(List<DeclarationNode> declarations, List<DependencyGraph> dependencies) {
        DirectedSparseGraph<Integer, Edge> g = new DirectedSparseGraph<>();
//        for (DeclarationNode decl : declarations) {
//            g.addVertex(decl.getLineNumber());
//        }


        for (int i = 0; i < declarationNodes.size(); i++) {
            for(int j=0;j<dependenceNodes.size();j++){
                dependenceNodes.get(i);
            }
        }

//            String name_1 = candidates.get(i).getName();
//            String type_1 = candidates.get(i).getType();
//            String local_1 = candidates.get(i).getLocalName();
//            int line_1 = candidates.get(i).getLineNumber();
//
//            for (int t = 0; t < candidates.size(); t++) {
//                if (i != t) {
//                    String name_2 = candidates.get(t).getName();
//                    String type_2 = candidates.get(t).getType();
//                    String local_2 = candidates.get(t).getLocalName();
//                    int line_2 = candidates.get(t).getLineNumber();
//                    if (name_1.equals(name_2)) {
//                        if (local_1.contains("decl")) {
//                            candidates.get(t).getDependencies().add(candidates.get(i));
//                            g.addEdge(new Edge(type_2 + " " + name_2), line_2, line_1);
//
//                        } else if (local_2.contains("decl")) {
//                            candidates.get(i).getDependencies().add(candidates.get(t));
//                            g.addEdge(new Edge(type_1 + "  " + name_1), line_1, line_2);
//                        } else {
//                            candidates.get(i).sameNameList.add(candidates.get(t));
//                            candidates.get(t).sameNameList.add(candidates.get(i));
//
//                        }
//
//                    }
//                }
//            }
//
//        }
        return g;
    }

    public static void parseMergedXML(String xmlPath, String xpathQuery, String output) {

        //run srcML
        if (new File(xmlPath).isFile()) {
            try {
                new ProcessBuilder("srcML/srcml2src", "--xpath", xpathQuery, xmlPath, "-o", output).start();
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            System.out.println("File does not exist: " + xmlPath);
        }
    }



    public static void findDeclarationNode(String query, String decl_tag) {
        //get decl_stmt name list
        String name_output = "/Users/shuruiz/Work/tmpXMLFile/dependencyGraph/1/name.xml";
        String declStmt_name_Query = "//" + query + "/src:name";
        parseMergedXML(xmlFilePath, declStmt_name_Query, name_output);
        Document declStmtNodeListTree = ioFunctionSet.getXmlDom(name_output);
        Node nameList_root = declStmtNodeListTree.getChild(0);

        //get decl_stmt type list
        String type_output = "/Users/shuruiz/Work/tmpXMLFile/dependencyGraph/1/type.xml";
        String declSdeclStmt_type_QuerytmtQuery = "//" + query + "/src:type/src:name";
        parseMergedXML(xmlFilePath, declSdeclStmt_type_QuerytmtQuery, type_output);
        Document declStmtTypeNodeListTree = ioFunctionSet.getXmlDom(type_output);
        Node typeList_root = declStmtTypeNodeListTree.getChild(0);

        int declStmtNum = nameList_root.getChildCount();
        for (int i = 0; i < declStmtNum; i++) {
            Node declStmtNode = nameList_root.getChild(i);
            if (declStmtNode.getClass().getName().contains("Element")) {
                Element nameNode = (Element) declStmtNode.getChild(0);
                String declStmt_name = nameNode.getValue();
                int lineNum = Integer.parseInt(nameNode.getAttribute(0).getValue());

                //get type
                Element typeNode = (Element) typeList_root.getChild(i).getChild(0);
                String type = typeNode.getValue();
                declarationNodes.add(new DeclarationNode(declStmt_name, type, lineNum, decl_tag));
            }
        }
        System.out.print("");
    }

    public static void findDependencyNode(String query, String tag) {
        //get  name list
        String name_output = "/Users/shuruiz/Work/tmpXMLFile/dependencyGraph/1/dep.xml";
        String name_Query = "//" + query + "/src:name";
        parseMergedXML(xmlFilePath, name_Query, name_output);

        Document declStmtNodeListTree = ioFunctionSet.getXmlDom(name_output);
        Element nameList_root = (Element)declStmtNodeListTree.getChild(0);
       Elements elements = nameList_root.getChildElements();

            for(int i=0;i<elements.size();i++){
                Element nameNode = elements.get(i);
                String declStmt_name = nameNode.getValue();
                int lineNum = Integer.parseInt(((Element)nameNode.getChild(0)).getAttribute(0).getValue());
                dependenceNodes.add(new DependenceNode(declStmt_name, tag, lineNum));
                System.out.print("");
        }


    }



    public static void main(String[] args) {

        String dirPath = "";

        String filePath = "testcpp/dependencyGraph/1/A.cpp";
        xmlFilePath = ioFunctionSet.getXmlFile(filePath);

        //decl_stmt
        String decl_stmt_query = "src:decl_stmt/src:decl";
        findDeclarationNode(decl_stmt_query, "decl_stmt");

        //function_decl
        String function_decl_query = "src:function_decl";
        findDeclarationNode(function_decl_query, "function_decl");

        //function
        String function_query = "src:function";
        findDeclarationNode(function_query, "function");

        //expr_stmt
        String expr_stmt_tag = "expr_stmt";
        String expr_stmt_query = "src:" + expr_stmt_tag + "/src:expr";
        findDependencyNode(expr_stmt_query, expr_stmt_tag);

        //call
        String func_call_tag = "call";
        String func_call_query= "src:"+func_call_tag;
        findDependencyNode(func_call_query, func_call_tag);

        //expr
        String expr_tag ="expr";
        String expr_query="src:"+expr_tag;
        findDependencyNode(expr_query,expr_tag);

        System.out.print("");
//        parseASTforDependencyGraph(astTree);

    }

}
