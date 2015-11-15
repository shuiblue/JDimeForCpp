package de.fosd.jdime.dependencyGraph;

import java.awt.*;
import java.io.*;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;
import java.util.List;

import de.fosd.jdime.util.Entity;
import de.fosd.jdime.util.IOFunctionSet;
import de.fosd.jdime.util.Relation;
import edu.uci.ics.jung.graph.*;
import nu.xom.Document;
import nu.xom.Element;
import nu.xom.Elements;
import org.apache.commons.collections15.Transformer;
import edu.uci.ics.jung.visualization.VisualizationImageServer;
import edu.uci.ics.jung.algorithms.layout.CircleLayout;
import edu.uci.ics.jung.visualization.decorators.ToStringLabeller;
import edu.uci.ics.jung.visualization.renderers.Renderer;
import org.apache.commons.collections15.bag.SynchronizedBag;

import javax.swing.*;


/**
 * Created by shuruiz on 11/5/15.
 */
public class DependencyGraph {
    static List<DeclarationNode> declarationNodes = new ArrayList<>();
    static List<DependenceNode> dependenceNodes = new ArrayList<>();
    static IOFunctionSet ioFunctionSet = new IOFunctionSet();

    public static DirectedSparseGraph<String, Edge> createDependencyGraph(String testDir) {


        String dirPath = "testcpp/dependencyGraph/";

////        String testDir = "test_3";
//        String testDir = args[0]+"/";

        String testDirPath = dirPath + testDir + "/";


        File dir = new File(testDirPath);
        String[] names = dir.list();
        for (String fileName : names) {
            if (fileName.endsWith(".cpp") || fileName.endsWith(".h")) {
                String filePath = testDirPath + fileName;
                String xmlFilePath = ioFunctionSet.getXmlFile(filePath);
//            String fileName = filePath.split("/")[filePath.split("/").length - 1];
                System.out.print(fileName + "\n");
                findAllNodes(xmlFilePath, fileName);
            }
        }


        DirectedSparseGraph<String, Edge> g = new DirectedSparseGraph<>();

        //add vertex
        for (DeclarationNode decl : declarationNodes) {
            if (!g.containsVertex(decl.getLineNumber() + "-" + decl.getFileName())) {
                g.addVertex(decl.getLineNumber() + "-" + decl.getFileName());
            }
        }
        for (DependenceNode depen : dependenceNodes) {

            if (!g.containsVertex(depen.getLineNumber() + "-" + depen.getFileName())) {
                g.addVertex(depen.getLineNumber() + "-" + depen.getFileName());
            }
        }
        //check .h define function and  .cpp define the body
        for (DeclarationNode d1 : declarationNodes) {
            for (DeclarationNode d2 : declarationNodes) {
                //for example: A.cpp vs A.h

//                if ((d1.getFileName().split("\\.")[0].equals(d2.getFileName().split("\\.")[0]))
//                        && !d1.getFileName().equals(d2.getFileName())) {
//
//                    if (d1.getName().equals(d2.getName())) {
                Relation relation = isRelated(d1, d2);
                if(relation.equals(Relation.TRUE)){

                    if(d1.getDecl_tag().contains("function")){
                        if (d1.getDecl_tag().contains("decl")) {

                            Edge edge = new Edge(d1.getDecl_tag()+" "+d1.getType()+" " + d1.getName(), d2.getLineNumber() + "-" + d2.getFileName(), d1.getLineNumber() + "-" + d1.getFileName());
                            g.addEdge(edge, d2.getLineNumber() + "-" + d2.getFileName(), d1.getLineNumber() + "-" + d1.getFileName());
                        } else {
                            Edge edge = new Edge(d2.getDecl_tag()+" "+d2.getType()+" "  + d2.getName(), d1.getLineNumber() + "-" + d1.getFileName(), d2.getLineNumber() + "-" + d2.getFileName());
                            g.addEdge(edge, d1.getLineNumber() + "-" + d1.getFileName(), d2.getLineNumber() + "-" + d2.getFileName());
                        }
                    }else if(d1.getFileName().equals(d2.getFileName())){

//                        if (d1.getType().equals(d2.getType())) {
                            if (d1.getFileName().endsWith(".h")) {

                                Edge edge = new Edge(d1.getDecl_tag()+" "+d1.getType()+" " + d1.getName(), d2.getLineNumber() + "-" + d2.getFileName(), d1.getLineNumber() + "-" + d1.getFileName());
                                g.addEdge(edge, d2.getLineNumber() + "-" + d2.getFileName(), d1.getLineNumber() + "-" + d1.getFileName());
                            } else {
                                Edge edge = new Edge(d2.getDecl_tag()+" "+d2.getType()+" "  + d2.getName(), d1.getLineNumber() + "-" + d1.getFileName(), d2.getLineNumber() + "-" + d2.getFileName());
                                g.addEdge(edge, d1.getLineNumber() + "-" + d1.getFileName(), d2.getLineNumber() + "-" + d2.getFileName());
                            }
                        } else if (d1.getType().contains("class")) {
                            if (d1.getType().endsWith("-func")) {
                                Edge edge = new Edge("<SAME class> " + d1.getName(), d1.getLineNumber() + "-" + d1.getFileName(), d2.getLineNumber() + "-" + d2.getFileName());
                                g.addEdge(edge, d1.getLineNumber() + "-" + d1.getFileName(), d2.getLineNumber() + "-" + d2.getFileName());
                            } else if(d2.getType().endsWith("-func")){
                                Edge edge = new Edge("<SAME class>" + d2.getName(), d2.getLineNumber() + "-" + d2.getFileName(), d1.getLineNumber() + "-" + d1.getFileName());
                                g.addEdge(edge, d2.getLineNumber() + "-" + d2.getFileName(), d1.getLineNumber() + "-" + d1.getFileName());

                            }
                        }
//                    }
                }
            }
        }

        //find dependency between depen Node --> decl Node
        for (int i = 0; i < declarationNodes.size(); i++) {
            for (int j = 0; j < dependenceNodes.size(); j++) {
                DeclarationNode decl = declarationNodes.get(i);
                DependenceNode depen = dependenceNodes.get(j);
                Relation relation = isRelated(decl, depen);
                if (relation.equals(Relation.TRUE)) {

                    //in .h file, function declaration is <expr_stmt><call>,
                    //prevent .cpp function_decl ---> .h function declaration
                    if (decl.getFileName().endsWith("cpp") && depen.getFileName().endsWith("h")) {
                        //create edge
                        String  name= depen.getName();
                        Edge edge = new Edge("function_decl "+decl.getType()+" " + name, decl.getLineNumber() + "-" + decl.getFileName(), depen.getLineNumber() + "-" + depen.getFileName());
                        g.addEdge(edge, decl.getLineNumber() + "-" + decl.getFileName(), depen.getLineNumber() + "-" + depen.getFileName());

                    } else {
                        decl.getDependencies().add(depen);
                        depen.setDeclaration(decl);

                        //create edge
                        String type, name;
                        if (decl.getDecl_tag().equals("decl_stmt")) {
                            type = decl.getType();
                        } else {
                            type = depen.getTag();
                        }
                        name = depen.getName();
                        Edge edge = new Edge(type + " " + name, depen.getLineNumber() + "-" + depen.getFileName(), decl.getLineNumber() + "-" + decl.getFileName());
                        g.addEdge(edge, depen.getLineNumber() + "-" + depen.getFileName(), decl.getLineNumber() + "-" + decl.getFileName());

                    }
                } else if (relation.equals(Relation.SAMENAME)) {
                    String type, name;
                    type = decl.getType();
                    name = depen.getName();
                    Edge edge = new Edge("<SAMENAME> " + type + " " + name, depen.getLineNumber() + "-" + depen.getFileName(), decl.getLineNumber() + "-" + decl.getFileName());
                    g.addEdge(edge, depen.getLineNumber() + "-" + depen.getFileName(), decl.getLineNumber() + "-" + decl.getFileName());

                }
            }
        }

        return g;
    }

    public static Relation isRelated(DeclarationNode d1,DeclarationNode d2){
        if(d1.getType().equals(d2.getType())&&d1.getName().equals(d2.getName())){
           if( d1.getDecl_tag()!=d2.getDecl_tag()){
                return  Relation.TRUE;
            }else{
                return  Relation.FALSE;
            }
        }
        return  Relation.FALSE;
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

        if (decl.getName().equals(depen.getName())) {
            if (decl.getDecl_tag().equals("decl_stmt") && depen.getTag().contains("expr")) {
                return Relation.TRUE;
            } else if (depen.getTag().equals("call") && entity.getFuncionDeclarationEntity().contains(decl.getDecl_tag())) {
                return Relation.TRUE;
            }
//            else if (decl.getDecl_tag().contains("class")) {
//                return Relation.SAMENAME;
//            }
            else{
                return  Relation.SAMENAME;
            }
        }
        return Relation.FALSE;
    }


    public static void findAllNodes(String xmlFilePath, String fileName) {
        Entity entity = new Entity();
        for (String tag : entity.getOneLayerEntity()) {
            String query = "src:" + tag;
            if (entity.getDeclarationEntity().contains(tag)) {
                findDeclarationNode(xmlFilePath, query, tag, fileName);
            } else if (entity.getDependencyEntity().contains(tag)) {
                findDependencyNode(xmlFilePath, query, tag, fileName);
            }
        }

        for (String tag : entity.getStmtEntity()) {
            String stmtTag = tag + "_stmt";
            String query = "src:" + stmtTag + "/src:" + tag;
            if (entity.getDeclarationEntity().contains(tag)) {
                findDeclarationNode(xmlFilePath, query, stmtTag, fileName);
            } else if (entity.getDependencyEntity().contains(tag)) {
                findDependencyNode(xmlFilePath, query, stmtTag, fileName);
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
                    if (decl_tag.contains("function")) {
                        //get type
                        Element typeNode = typeList_root.getChildElements().get(0);
                        String type = typeNode.getValue();

                        String functionName = nameNode.getValue();
                        String lineNum = nameNode.getChildElements().get(0).getAttribute(0).getValue();


                        if (functionName.contains("::")) {
                            String className = functionName.split("::")[0];
                            String newfunctionName = functionName.split("::")[1];

                            declarationNodes.add(new DeclarationNode(className, "class-func", lineNum, "class-func", fileName));
                            declarationNodes.add(new DeclarationNode(newfunctionName, type, lineNum, decl_tag, fileName));
                        } else {

                            declarationNodes.add(new DeclarationNode(functionName, type, lineNum, decl_tag, fileName));
                        }
                    }
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
        if (nameList_root.getChildElements().size() > 0) {
            Elements elements = nameList_root.getChildElements();
            for (int i = 0; i < elements.size(); i++) {
                Element nameNode = elements.get(i);
                if (((Element) nameNode.getChild(0)).getAttributeCount() > 0) {
                    String depenStmt_name = nameNode.getValue();
                    String lineNum = ((Element) nameNode.getChild(0)).getAttribute(0).getValue();
                    dependenceNodes.add(new DependenceNode(depenStmt_name, tag, lineNum, fileName));
                } else if (((Element) nameNode.getChild(0)).getChildElements().size() > 0) {
                    Element e = (Element) nameNode.getChild(0);
                    for (int j = 0; j < e.getChildElements().size(); j++) {
                        Element child = e.getChildElements().get(j);
                        String depenStmt_name = child.getValue();
                        String lineNum = child.getAttribute(0).getValue();
                        dependenceNodes.add(new DependenceNode(depenStmt_name, tag, lineNum, fileName));
                    }
                }
                System.out.print("");
            }
        }
    }


    public static void visualizeGraph(DirectedSparseGraph<String, Edge> g) {
        VisualizationImageServer<String, Edge> vv =
                new VisualizationImageServer<String, Edge>(new CircleLayout<String, Edge>(g), new Dimension(600, 600));
// Setup up a new vertex to paint transformer...
        Transformer<String, Paint> vertexPaint = new Transformer<String, Paint>() {
            public Paint transform(String str) {
                if (str.contains(".h")) {
                    return Color.GREEN;
                } else {
                    return Color.PINK;
                }
            }
        };


// Set up a new stroke Transformer for the edges
        float dash[] = {10.0f};
        final Stroke edgeStroke = new BasicStroke(1.0f, BasicStroke.CAP_BUTT,
                BasicStroke.JOIN_MITER, 10.0f, dash, 0.0f);
        Transformer<Edge, Stroke> edgeStrokeTransformer =
                new Transformer<Edge, Stroke>() {
                    public Stroke transform(Edge s) {
                        return edgeStroke;
                    }
                };
        vv.getRenderContext().setVertexFillPaintTransformer(vertexPaint);
        vv.getRenderContext().setEdgeStrokeTransformer(edgeStrokeTransformer);
        vv.getRenderContext().setVertexLabelTransformer(new ToStringLabeller());
        vv.getRenderContext().setEdgeLabelTransformer(new ToStringLabeller());
        vv.getRenderer().getVertexLabelRenderer().setPosition(Renderer.VertexLabel.Position.CNTR);

        JFrame frame = new JFrame();
        frame.getContentPane().add(vv);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }


    public static void main(String[] args) {

        String testDir = "test_13";
        DirectedSparseGraph<String, Edge> graph = createDependencyGraph(testDir);
        visualizeGraph(graph);

    }


}
