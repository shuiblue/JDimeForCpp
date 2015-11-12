package de.fosd.jdime.dependencyGraph;

import java.util.List;

import de.fosd.jdime.util.IOFunctionSet;
import  edu.uci.ics.jung.graph.*;
import net.sf.saxon.Configuration;
import net.sf.saxon.s9api.Processor;
import net.sf.saxon.xom.DocumentWrapper;
import net.sf.saxon.xom.NodeWrapper;
import nu.xom.Document;
import nu.xom.Node;


/**
 * Created by shuruiz on 11/5/15.
 */
public class DependencyGraph {
    DirectedSparseGraph<Integer, Edge> createDependencyGraph(List<DeclarationNode> declarations,List<DependencyGraph> dependencies) {
        DirectedSparseGraph<Integer, Edge> g = new DirectedSparseGraph<>();
        for (DeclarationNode decl : declarations) {
            g.addVertex(decl.getLineNumber());
        }


//        for (int i = 0; i < candidates.size(); i++) {
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


   public static void main(String[] args){
       IOFunctionSet ioFunctionSet = new IOFunctionSet();
       String dirPath = "";
       String filePath = "testcpp/dependencyGraph/1/A.cpp";
       String xmlFilePath =ioFunctionSet.getXmlFile(filePath);
       Document astTree = ioFunctionSet.getXmlDom(xmlFilePath);


//       Processor proc= new Processor(true);
//       Configuration config= proc.getUnderlyingConfiguration();

Node node = astTree.getChild(0);

       DocumentWrapper wrap= new DocumentWrapper(astTree, astTree.getBaseURI(),new Configuration());

//       DocumentWrapper wrap= new DocumentWrapper(node, node.getBaseURI(),new Configuration());
//       ioFunctionSet.
       System.out.println("");

    }

}
