package de.fosd.jdime.dependencyGraph;

import java.awt.*;
import java.awt.geom.AffineTransform;
import java.awt.geom.Arc2D;
import java.io.File;
import java.io.FilenameFilter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

import de.fosd.jdime.util.Entity;
import de.fosd.jdime.util.IOFunctionSet;
import edu.uci.ics.jung.graph.*;
import nu.xom.Document;
import nu.xom.Element;
import nu.xom.Elements;
import nu.xom.Node;
import org.apache.commons.collections15.Transformer;
import edu.uci.ics.jung.visualization.VisualizationImageServer;
import edu.uci.ics.jung.algorithms.layout.CircleLayout;
import edu.uci.ics.jung.visualization.decorators.ToStringLabeller;
import edu.uci.ics.jung.visualization.renderers.Renderer;
import javax.swing.*;


/**
 * Created by shuruiz on 11/5/15.
 */
public class DependencyGraph {
    static List<DeclarationNode> declarationNodes = new ArrayList<>();
    static List<DependenceNode> dependenceNodes = new ArrayList<>();
    static IOFunctionSet ioFunctionSet = new IOFunctionSet();

    public static DirectedSparseGraph<String, Edge> createDependencyGraph() {


        DirectedSparseGraph<String, Edge> g = new DirectedSparseGraph<>();

        //add vertex
        for (DeclarationNode decl : declarationNodes) {
            g.addVertex(decl.getLineNumber() + "--" + decl.getFileName());
        }
        for (DependenceNode depen : dependenceNodes) {
            g.addVertex(depen.getLineNumber() + "--" + depen.getFileName());
        }
        //check .h define function and  .cpp define the body
        for (DeclarationNode d1 : declarationNodes) {
            for (DeclarationNode d2 : declarationNodes) {
                if ((d1.getFileName().split("\\.")[0].equals(d2.getFileName().split("\\.")[0]))
                        && !d1.getFileName().equals(d2.getFileName())) {
                    if (d1.getName().equals(d2.getName()) && d1.getType().equals(d2.getType())) {
                        if (d1.getFileName().endsWith(".h")) {
                            g.addEdge(new Edge("define " + d1.getType() + " " + d1.getName()), d2.getLineNumber() + "--" + d2.getFileName(), d1.getLineNumber() + "--" + d1.getFileName());
//                       d1.dependencies.add(d2);
                        } else {
                            g.addEdge(new Edge("define " + d1.getType() + " " + d1.getName()), d1.getLineNumber() + "--" + d1.getFileName(), d2.getLineNumber() + "--" + d2.getFileName());

                        }
                    }
                }
            }
        }

        //find dependency between depen Node --> decl Node
        for (int i = 0; i < declarationNodes.size(); i++) {
            for (int j = 0; j < dependenceNodes.size(); j++) {
                DeclarationNode decl = declarationNodes.get(i);
                DependenceNode depen = dependenceNodes.get(j);
                if (isRelated(decl, depen)) {

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
                    g.addEdge(new Edge(type + " " + name), depen.getLineNumber() + "--" + depen.getFileName(), decl.getLineNumber() + "--" + decl.getFileName());
                }
            }
        }
        return g;
    }

    /**
     * check whether two nodes has dependency relation
     *
     * @param decl  declaration node
     * @param depen dependency node
     * @return true, if is related.
     */
    public static boolean isRelated(DeclarationNode decl, DependenceNode depen) {

        if (decl.getName().equals(depen.getName())) {
            if (decl.getDecl_tag().equals("decl_stmt") && depen.getTag().contains("expr")) {
                return true;
            } else if (depen.getTag().equals("call")) {
                return true;
            }
        }
        return false;
    }


    public static void findAllNodes(String xmlFilePath, String fileName) {
        Entity entity = new Entity();
        for (String tag : entity.getOneLayerEntity()) {
            String query = "src:" + tag;
            System.out.println(tag + "\n");
            if (entity.getDeclarationEntity().contains(tag)) {
                findDeclarationNode(xmlFilePath, query, tag, fileName);
            } else if (entity.getDependencyEntity().contains(tag)) {
                findDependencyNode(xmlFilePath, query, tag, fileName);
            }
        }

        for (String tag : entity.getStmtEntity()) {
            String stmtTag = tag + "_stmt";

            System.out.println(stmtTag + "\n");

            String query = "src:" + stmtTag + "/src:" + tag;
            if (entity.getDeclarationEntity().contains(tag)) {
                findDeclarationNode(xmlFilePath, query, stmtTag, fileName);
            } else if (entity.getDependencyEntity().contains(tag)) {
                findDependencyNode(xmlFilePath, query, stmtTag, fileName);
            }
        }
    }


    public static void separateFileNode(String xmlFilePath) {
        Document doc = ioFunctionSet.getXmlDom(xmlFilePath);
        Elements fileElementList = ((Element) doc.getChild(0)).getChildElements();
        for (int i = 0; i < fileElementList.size(); i++) {
            String[] filePath = fileElementList.get(i).getAttributeValue("filename").split("/");

            String fileName = filePath[filePath.length - 1];
            findAllNodes(xmlFilePath, fileName);
        }
    }

    public static void searchQuery(String xmlPath, String xpathQuery, String output) {

        //run srcML
        if (new File(xmlPath).isFile()) {
            try {
                ProcessBuilder processBuilder = new ProcessBuilder("srcML/srcml2src", "--xpath", xpathQuery, xmlPath, "-o", output);
                processBuilder.start();
            } catch (IOException e) {
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

                    String declStmt_name = nameNode.getValue();
                    String lineNum = nameNode.getChildElements().get(0).getAttribute(0).getValue();

                    declarationNodes.add(new DeclarationNode(declStmt_name, type, lineNum, decl_tag, fileName));
                }
            }
//            }
        }
    }

    public static void findDependencyNode(String xmlFilePath, String query, String tag, String fileName) {
        //get  name list


        String name_output = xmlFilePath + "_" + tag + "_dep.xml";
        String name_Query = "//" + query + "/src:name";

        searchQuery(xmlFilePath, name_Query, name_output);


        Document declStmtNodeListTree = ioFunctionSet.getXmlDom(name_output);

        if (declStmtNodeListTree != null) {
            Element nameList_root = (Element) declStmtNodeListTree.getChild(0);
            Elements elements = nameList_root.getChildElements();

            for (int i = 0; i < elements.size(); i++) {
                Element nameNode = elements.get(i);
                if (((Element) nameNode.getChild(0)).getAttributeCount() > 0) {
                    String declStmt_name = nameNode.getValue();
                    String lineNum = ((Element) nameNode.getChild(0)).getAttribute(0).getValue();
                    dependenceNodes.add(new DependenceNode(declStmt_name, tag, lineNum, fileName));
                } else if (((Element) nameNode.getChild(0)).getChildElements().size() > 0) {
                    Element e = (Element) nameNode.getChild(0);
                    for (int j = 0; j < e.getChildElements().size(); j++) {
                        Element child = e.getChildElements().get(j);
                        String declStmt_name = child.getValue();
                        String lineNum = child.getAttribute(0).getValue();
                        dependenceNodes.add(new DependenceNode(declStmt_name, tag, lineNum, fileName));
                    }
                }

//                String lineNum = ((Element) nameNode.getChild(0)).getAttribute(0).getValue();
                System.out.print("");
            }
        }
    }


    public static void visualizeGraph(DirectedSparseGraph<String, Edge> g) {
        VisualizationImageServer<String, Edge> vv =
                new VisualizationImageServer<String, Edge>(new CircleLayout<String, Edge>(g), new Dimension(400, 400));
// Setup up a new vertex to paint transformer...
        Transformer<String, Paint> vertexPaint = new Transformer<String, Paint>() {
            public Paint transform(String str) {
                if(str.contains(".h")) {
                    return Color.GREEN;
                }else{
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

        String dirPath = "testcpp/dependencyGraph/";

        String testDir = "test_3";
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
        DirectedSparseGraph<String, Edge> graph = createDependencyGraph();
        visualizeGraph(graph);

    }


}
