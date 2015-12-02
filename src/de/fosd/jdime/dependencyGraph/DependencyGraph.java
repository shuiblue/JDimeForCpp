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
import org.apache.commons.io.FileUtils;

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
        String testDirPath = dirPath + testDir + "/";

        File dir = new File(testDirPath);
        String[] names = dir.list();
        for (String fileName : names) {
            if (fileName.endsWith(".cpp") || fileName.endsWith(".h") || fileName.endsWith(".c")) {
                String filePath = testDirPath + fileName;

                // src2srcml cannot parse .h file correctly, so change the suffix '+.cpp'
                if (fileName.endsWith(".h")) {
                   String newPath= "/Users/shuruiz/Work/tmpXMLFile" + filePath.replace("testcpp", "") + ".cpp";

                    try {
                        FileUtils.copyFile(new File(filePath), new File(newPath));
                        filePath = newPath;
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }

                String xmlFilePath = ioFunctionSet.getXmlFile(filePath);
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
        for (DependenceNode dep1 : dependenceNodes) {
            for (DependenceNode dep2 : dependenceNodes) {
                if (dep1.getName().equals(dep2.getName())) {
                    Relation relation = isRelated(dep1, dep2);
                    if (!relation.equals(Relation.False)) {
                        Edge edge = new Edge("<" + relation.name() + "> " + dep1.getTag() + " " + dep1.getName(),
                                dep1.getLineNumber() + "-" + dep1.getFileName(), dep2.getLineNumber() + "-" + dep2.getFileName());
                        g.addEdge(edge, dep1.getLineNumber() + "-" + dep1.getFileName(), dep2.getLineNumber() + "-" + dep2.getFileName());
                    }
                }
            }
        }
        //find dependency between depen Node --> decl Node
        for (int i = 0; i < declarationNodes.size(); i++) {
            for (int j = 0; j < dependenceNodes.size(); j++) {
                DeclarationNode decl = declarationNodes.get(i);
                DependenceNode depen = dependenceNodes.get(j);
                if (decl.getName().equals(depen.getName())) {
                    Relation relation = isRelated(decl, depen);
                    String type = decl.getType();
                    String name = decl.getName();
                    if (relation.equals(Relation.BelongsToClass)) {
                        Edge edge = new Edge("<" + relation.name() + "> " + name, depen.getLineNumber() + "-" + depen.getFileName(), decl.getLineNumber() + "-" + decl.getFileName());
                        g.addEdge(edge, depen.getLineNumber() + "-" + depen.getFileName(), decl.getLineNumber() + "-" + decl.getFileName());
                        continue;
                    }
                    if (!relation.equals(Relation.SAMENAME)) {
                        Edge edge = new Edge("<" + relation.name() + "> " + type + " " + name, depen.getLineNumber() + "-" + depen.getFileName(), decl.getLineNumber() + "-" + decl.getFileName());
                        g.addEdge(edge, depen.getLineNumber() + "-" + depen.getFileName(), decl.getLineNumber() + "-" + decl.getFileName());
                    } else {
                        Edge edge = new Edge("<" + relation.name() + "> " + name,
                                depen.getLineNumber() + "-" + depen.getFileName(),
                                decl.getLineNumber() + "-" + decl.getFileName());
                        g.addEdge(edge, depen.getLineNumber() + "-" + depen.getFileName(), decl.getLineNumber() + "-" + decl.getFileName());

                    }
                }
            }
        }
        return g;
    }

    public static Relation isRelated(DependenceNode d1, DependenceNode d2) {
        Entity entity = new Entity();
        if (d1.getTag() != d2.getTag()) {
            if (d1.getFileName().endsWith("cpp") && d2.getFileName().endsWith("h")
                    && entity.getConsDestructorEntity().contains(d1.getTag())
                    && d2.getTag().equals("call")) {
                return Relation.Func_decl;
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

//        if (decl.getName().equals(depen.getName())) {
        if (decl.getDecl_tag().equals("decl_stmt") && depen.getTag().contains("expr")) {
            return Relation.Statment;
        } else if (depen.getTag().equals("call") && entity.getFuncionEntity().contains(decl.getDecl_tag())) {
            return Relation.Call;
        } else if (entity.getFuncionDeclarationEntity().contains(decl.getDecl_tag()) && entity.getFuncionBodyEntity().contains(depen.getTag())) {
            return Relation.Func_decl;
        } else if (decl.getType().equals("class") && entity.getConsDestructorEntity().contains(depen.getTag())) {
            return Relation.Cons_Destruction;
        } else if (depen.getTag().equals("Func_Class")) {
            return Relation.BelongsToClass;
        } else {
            return Relation.SAMENAME;
        }
//        }
//        return Relation.FALSE;
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
//                    if (decl_tag.contains("function")) {
                    //get type
                    Element typeNode = typeList_root.getChildElements().get(0);
                    String type = typeNode.getValue();

                    String functionName = nameNode.getValue();
                    String lineNum = nameNode.getChildElements().get(0).getAttribute(0).getValue();

                    declarationNodes.add(new DeclarationNode(functionName, type, lineNum, decl_tag, fileName));

//                    if (functionName.contains("::")) {
////                        String className = functionName.split("::")[0];
//                        String newfunctionName = functionName.split("::")[1];
//
////                        declarationNodes.add(new DeclarationNode(className, "class-func", lineNum, "class-func", fileName));
//                        declarationNodes.add(new DeclarationNode(newfunctionName, type, lineNum, decl_tag, fileName));
//                    } else {
//
//                        declarationNodes.add(new DeclarationNode(functionName, type, lineNum, decl_tag, fileName));
//                    }
//                    }
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
        Elements elements = nameList_root.getChildElements();
        for (int i = 0; i < elements.size(); i++) {
            Element nameNode = elements.get(i);
            if (((Element) nameNode.getChild(0)).getAttributeCount() > 0) {
                String depenStmt_name = nameNode.getValue();
                String lineNum = ((Element) nameNode.getChild(0)).getAttribute(0).getValue();
                dependenceNodes.add(new DependenceNode(depenStmt_name, tag, lineNum, fileName));
            } else if (((Element) nameNode.getChild(0)).getChildElements().size() > 0) {
                Element e = (Element) nameNode.getChild(0);
                if (e.getValue().contains("::")) {

                    Element child = e.getChildElements().get(1);
                    String depenStmt_name = child.getValue();
                    String lineNum = child.getAttribute(0).getValue();
                    dependenceNodes.add(new DependenceNode(depenStmt_name, tag, lineNum, fileName));

                    if (tag.equals("function")) {
                        Element className_element = e.getChildElements().get(0);
                        String className = className_element.getValue();
                        dependenceNodes.add(new DependenceNode(className, "Func_Class", lineNum, fileName));
                    }

                } else {
//
                    for (int j = 0; j < e.getChildElements().size(); j++) {
                        Element child = e.getChildElements().get(j);
                        String depenStmt_name = child.getValue();
                        String lineNum = child.getAttribute(0).getValue();
                        dependenceNodes.add(new DependenceNode(depenStmt_name, tag, lineNum, fileName));
                    }
                }
            }
            System.out.print("");
        }
    }


    public static void visualizeGraph(DirectedSparseGraph<String, Edge> g) {
        VisualizationImageServer<String, Edge> vv =
                new VisualizationImageServer<String, Edge>(new CircleLayout<String, Edge>(g), new Dimension(800, 800));
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

        String testDir = "test_14";
        DirectedSparseGraph<String, Edge> graph = createDependencyGraph(testDir);
        visualizeGraph(graph);

    }


}
