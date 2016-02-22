package de.fosd.jdime.dependencyGraph;

import de.fosd.jdime.util.IOFunctionSet;
import org.rosuda.JRI.REXP;
import org.rosuda.JRI.Rengine;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class RCommunityDetection {
    ArrayList<Double> modularityArray;
    HashSet<String> upstreamNode;
    HashSet<String> upstreamEdge;
    HashMap<Integer, Boolean> checkedEdges;
    Graph originGraph;
    String projectPath = "/Users/shuruiz/Work/JDIME/NWayJDime/jdime/testcpp/dependencyGraph/";
    public ArrayList<Integer> cutSequence;
    IOFunctionSet ioFunc = new IOFunctionSet();


    public RCommunityDetection(String fileDir) {
        modularityArray = new ArrayList<>();
        checkedEdges = new HashMap<>();
        cutSequence = new ArrayList<>();
        upstreamNode = new HashSet<>();
        //start import R library
        System.out.println("Creating Rengine (with arguments)");
        //If not started with --vanilla, funny things may happen in this R shell.
        String[] Rargs = {"--vanilla"};
        Rengine re = new Rengine(Rargs, false, null);
        System.out.println("Rengine created, waiting for R");
        // the engine creates R is a new thread, so we should wait until it's
        // ready
        if (!re.waitForR()) {
            System.out.println("Cannot load R");
            return;
        }
        //start to input R cmd
        re.eval("library(igraph)");
        re.eval("oldg<-read.graph(\"" + projectPath + fileDir + "/graph.pajek.net\", format=\"pajek\")\n");
        // removes the loop and/or multiple edges from a graph.
        re.eval("g<-simplify(oldg)");
        re.eval("g<-as.undirected(g)");

        // get original graph
        REXP edgelist_R = re.eval("get.edgelist(g)", true);
        REXP nodelist_R = re.eval("get.vertex.attribute(g)$id", true);
        double[][] edgelist = edgelist_R.asMatrix();
        String[] nodelist = (String[]) nodelist_R.getContent();
        originGraph = new Graph(nodelist, edgelist, null, 0);

        printOriginNodeList(originGraph.getNodelist(), fileDir);


        //get nodes/edges belong to upstream
        storeUpstreamNodes(fileDir);
        upstreamEdge = findUpstreamEdges(originGraph, fileDir);
        //print old edge
        ioFunc.writeTofile("", projectPath + fileDir + "/cluster.txt");


        //initialize removedEdge Map, all the edges have not been removed, so the values are all false
        for (int i = 0; i < edgelist.length; i++) {
            checkedEdges.put(i + 1, false);
        }

        int cutNum = 1;


        while (checkedEdges.values().contains(false)) {
            //count betweenness for current graph
            calculateEachGraph(re, fileDir, cutNum);
            cutNum++;
        }


        StringBuffer cutResult = new StringBuffer();
        String detectResult = findBestClusterResult(originGraph, cutSequence);

        cutResult.append("\n\nCut Sequence(" + cutSequence.size() + " steps): ");
        cutResult.append(detectResult);
        ioFunc.writeTofile(cutResult.toString(), projectPath + fileDir + "/cluster.txt");

        re.end();
        System.out.println("\nBye.");
    }

    private void printOriginNodeList(HashMap<Integer, String> nodelist, String fileDir) {
        StringBuffer nodeList_print = new StringBuffer();
//        nodeList_print.append("NodeList:\n");
        Iterator it_e = nodelist.entrySet().iterator();
        while (it_e.hasNext()) {
            Map.Entry node = (Map.Entry) it_e.next();
            nodeList_print.append(node.getKey()+"---------"+node.getValue()+"\n");
        }
        ioFunc.rewriteFile(nodeList_print.toString(), projectPath + fileDir + "/NodeList.txt");
    }

    private void storeUpstreamNodes(String fileDir) {
        try (BufferedReader br = new BufferedReader(new FileReader(projectPath + fileDir + "/upstreamNode.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                upstreamNode.add(line.trim());
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private HashSet<String> findUpstreamEdges(Graph originGraph, String filePath) {
        HashSet<String> upstreamEdge = new HashSet<>();
        HashMap<Integer, String> allEdges = originGraph.getEdgelist();
        HashMap<Integer, String> allNodes = originGraph.getNodelist();

        //Print upstream Edge
        StringBuffer print = new StringBuffer();
        print.append("Upstream Edgelist:\n");

        Iterator it_e = allEdges.entrySet().iterator();
        while (it_e.hasNext()) {
            Map.Entry edge = (Map.Entry) it_e.next();
            int from = Integer.parseInt(edge.getValue().toString().split(",")[0]);
            int to = Integer.parseInt(edge.getValue().toString().split(",")[1]);

            String from_nodeLabel = allNodes.get(from);
            String to_nodeLabel = allNodes.get(to);
            if (upstreamNode.contains(from_nodeLabel) && upstreamNode.contains(to_nodeLabel)) {
                upstreamEdge.add((String) edge.getValue());
                print.append(edge.getValue() + ": " + allNodes.get(from) + "->" + allNodes.get(to) + "\n");

            }
        }
        ioFunc.rewriteFile(print.toString(), projectPath + filePath + "/cluster.txt");
        return upstreamEdge;

    }


    public void calculateEachGraph(Rengine re, String filePath, int cutNum) {
        //get graph's edgeList and nodeList
        REXP edgelist_R = re.eval("get.edgelist(g)", true);
        REXP nodelist_R = re.eval("get.vertex.attribute(g)$id", true);
        double[][] edgelist = edgelist_R.asMatrix();
        String[] nodelist = (String[]) nodelist_R.getContent();

        //get betweenness for current graph
        REXP betweenness_R = re.eval("edge.betweenness(g)", true);
        double[] betweenness = betweenness_R.asDoubleArray();

        //calculate modularty for current graph
        REXP membership_R = re.eval("cl<-clusters(g)$membership");
        double[] membership = membership_R.asDoubleArray();

        printMemebershipOfCurrentGraph(membership, filePath);


        REXP modularity_R = re.eval("modularity(g,cl)");
        double modularity = modularity_R.asDoubleArray()[0];

        Graph currentGraph = new Graph(nodelist, edgelist, betweenness, modularity);
        modularityArray.add(modularity);

        minimizeUpstreamEdgeBetweenness(currentGraph);

        //modularity find removableEdge
        int removableEdgeID = findRemovableEdge(currentGraph);
        //remove edge
        re.eval("g<-g-edge(\"" + removableEdgeID + "\")");

        //TODO  print membership
        printGraph(currentGraph, filePath, cutNum);
    }

    private void printMemebershipOfCurrentGraph(double[] membership, String fileDir) {
        HashMap<Integer, ArrayList<Integer>> clusters = new HashMap<>();

        for (int i = 0; i < membership.length; i++) {
            ArrayList<Integer> member = clusters.get((int) membership[i]);
            if (member == null) {
                member = new ArrayList<>();
            }
            member.add(i + 1);
            clusters.put((int) membership[i], member);
        }

        //print
        StringBuffer membership_print = new StringBuffer();
        membership_print.append("\n---"+clusters.entrySet().size()+" communities\n");
        Iterator it = clusters.entrySet().iterator();
        while (it.hasNext()) {
            Map.Entry cluster = (Map.Entry) it.next();
            ArrayList<Integer> mem = (ArrayList<Integer>) cluster.getValue();
            membership_print.append("[");
            for (Integer m : mem) {
                membership_print.append(m + " , ");
            }
            membership_print.append("]\n");
        }
        //print old edge
        ioFunc.writeTofile(membership_print.toString(), projectPath + fileDir + "/cluster.txt");

    }


    public int findRemovableEdge(Graph g) {
        int maxBetEdgeID = findMaxNumberLocation(g.getBetweenness()) + 1;
        int oldEdgeID = findCorrespondingEdgeInOriginGraph(maxBetEdgeID, g);
        checkedEdges.put(oldEdgeID, true);
        cutSequence.add(oldEdgeID);
        g.setRemovableEdgeLable(g.getEdgelist().get(maxBetEdgeID));
        return maxBetEdgeID;
    }

    private void minimizeUpstreamEdgeBetweenness(Graph g) {
        HashMap<Integer, String> edgelist = g.getEdgelist();

        Iterator it_e = edgelist.entrySet().iterator();
        while (it_e.hasNext()) {
            Map.Entry edge = (Map.Entry) it_e.next();
            if (upstreamEdge.contains(edge.getValue())) {
                g.betweenness[(int) edge.getKey() - 1] = -1000.0;

                checkedEdges.put((Integer) edge.getKey(), true);
            }

        }

    }

    public int findCorrespondingEdgeInOriginGraph(int maxBetEdgeID, Graph g) {
        HashMap<Integer, String> current_edgelist = g.getEdgelist();
        String edgeLabel = current_edgelist.get(maxBetEdgeID);
        int fromNodeID = Integer.parseInt(edgeLabel.split(",")[0]);
        int toNodeID = Integer.parseInt(edgeLabel.split(",")[1]);

        HashMap<String, Integer> reverseEdgelist = originGraph.getReverseEdgelist();

        return reverseEdgelist.get(fromNodeID + "," + toNodeID);
    }


    public int findMaxNumberLocation(double[] doubleArray) {
        int loc = 0;
        double max = doubleArray[0];
        for (int counter = 1; counter < doubleArray.length; counter++) {
            if (doubleArray[counter] > max) {
                max = doubleArray[counter];
                loc = counter;
            }
        }
        return loc;
    }

    public int findMaxNumberLocation(ArrayList<Double> doubleArray) {
        int loc = 0;
        double max = doubleArray.get(0);
        for (int counter = 1; counter < doubleArray.size(); counter++) {
            if (doubleArray.get(counter) > max) {
                max = doubleArray.get(counter);
                loc = counter;
            }
        }
        return loc;
    }


    public void printGraph(Graph g, String filePath, int cutNum) {
        StringBuffer print = new StringBuffer();

        if (cutNum == 215) {
            System.out.print("GRAPH" + cutNum + "---------\n");
        }
        print.append("\n--------Graph" + cutNum + "-------\n");


        String removableEdge = g.getRemovableEdgeLable();
        int edgeId = originGraph.getReverseEdgelist().get(removableEdge);
        int from = Integer.parseInt(removableEdge.split(",")[0]);
        int to = Integer.parseInt(removableEdge.split(",")[1]);
        String edgeNodes = originGraph.getNodelist().get(from) + "->" + originGraph.getNodelist().get(to);
        print.append("max between edge id:" + edgeId + "-" + removableEdge + "(" + edgeNodes + ")");


        double modularity = g.getModularity();
        print.append("\nModularity: " + modularity);
        ioFunc.writeTofile(print.toString(), projectPath + filePath + "/cluster.txt");

    }

    public String findBestClusterResult(Graph g, ArrayList<Integer> cutSequence) {
        StringBuffer result = new StringBuffer();
        int bestCut = findMaxNumberLocation(modularityArray);
        for (int i = 0; i < bestCut; i++) {
            result.append(cutSequence.get(i) + ",");
        }
        return result.toString();
    }


    public static void main(String[] args) {
//        new RCommunityDetection();
    }
}