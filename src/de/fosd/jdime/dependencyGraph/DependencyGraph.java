package de.fosd.jdime.dependencyGraph;

import java.awt.*;
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
    static String xmlFilePath = "";

    public static DirectedSparseGraph<Integer, Edge> createDependencyGraph(String xmlFilePath) {

        xmlFilePath = ioFunctionSet.getXmlFile(xmlFilePath);
        findAllNodes();


        DirectedSparseGraph<Integer, Edge> g = new DirectedSparseGraph<>();

        //add vertex
        for (DeclarationNode decl : declarationNodes) {
            g.addVertex(decl.getLineNumber());
        }
        for (DependenceNode depen : dependenceNodes) {
            g.addVertex(depen.getLineNumber());
        }

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
                    g.addEdge(new Edge(type + " " + name), depen.getLineNumber(), decl.getLineNumber());
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


    public static void findAllNodes() {
        Entity entity = new Entity();
        for (String tag : entity.getOneLayerEntity()) {
            String query = "src:" + tag;
            System.out.println(tag+"\n");
            if (entity.getDeclarationEntity().contains(tag)) {
                findDeclarationNode(query, tag);
            } else if (entity.getDependencyEntity().contains(tag)) {
                findDependencyNode(query, tag);
            }
        }

        for (String tag : entity.getStmtEntity()) {
            String stmtTag = tag + "_stmt";

            System.out.println(stmtTag+"\n");

            String query = "src:" + stmtTag + "/src:" + tag;
            if (entity.getDeclarationEntity().contains(tag)) {
                findDeclarationNode(query, stmtTag);
            } else if (entity.getDependencyEntity().contains(tag)) {
                findDependencyNode(query, stmtTag);
            }
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


    public static void findDeclarationNode(String query, String decl_tag) {
        //get decl_stmt name list
        String name_output = "/Users/shuruiz/Work/tmpXMLFile/dependencyGraph/1/"+decl_tag+"_name.xml";
        String declStmt_name_Query = "//" + query + "/src:name";
        searchQuery(xmlFilePath, declStmt_name_Query, name_output);
        Document declStmtNodeListTree = ioFunctionSet.getXmlDom(name_output);
        Node nameList_root = declStmtNodeListTree.getChild(0);

        //get decl_stmt type list
        String type_output = "/Users/shuruiz/Work/tmpXMLFile/dependencyGraph/1/"+decl_tag+"_type.xml";
        String declSdeclStmt_type_QuerytmtQuery = "//" + query + "/src:type/src:name";
        searchQuery(xmlFilePath, declSdeclStmt_type_QuerytmtQuery, type_output);
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
    }

    public static void findDependencyNode(String query, String tag) {
        //get  name list
        String name_output = "/Users/shuruiz/Work/tmpXMLFile/dependencyGraph/1/"+tag+"_dep.xml";
        String name_Query = "//" + query + "/src:name";

        searchQuery(xmlFilePath, name_Query, name_output);


        Document declStmtNodeListTree = ioFunctionSet.getXmlDom(name_output);

        if(declStmtNodeListTree!=null) {
            Element nameList_root = (Element) declStmtNodeListTree.getChild(0);
            Elements elements = nameList_root.getChildElements();

            for (int i = 0; i < elements.size(); i++) {
                Element nameNode = elements.get(i);
                String declStmt_name = nameNode.getValue();
                int lineNum = Integer.parseInt(((Element) nameNode.getChild(0)).getAttribute(0).getValue());
                dependenceNodes.add(new DependenceNode(declStmt_name, tag, lineNum));
                System.out.print("");
            }
        }
    }


    public static void visualizeGraph(DirectedSparseGraph<Integer, Edge> g) {
        VisualizationImageServer<Integer, Edge> vv =
                new VisualizationImageServer<Integer, Edge>(new CircleLayout<Integer, Edge>(g), new Dimension(400, 400));
// Setup up a new vertex to paint transformer...
        Transformer<Integer, Paint> vertexPaint = new Transformer<Integer, Paint>() {
            public Paint transform(Integer i) {
                return Color.GREEN;
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
        String filePath = args[0];
        DirectedSparseGraph<Integer, Edge> graph = createDependencyGraph(filePath);
        visualizeGraph(graph);

    }




}
