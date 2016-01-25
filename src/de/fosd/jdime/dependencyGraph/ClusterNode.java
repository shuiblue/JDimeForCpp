package de.fosd.jdime.dependencyGraph;

import java.util.*;

/**
 * Created by shuruiz on 1/13/16.
 */
public class ClusterNode {
    /**
     * This function using greedy algorithm (ICSE'15 PAPER)
     * to cluster nodes
     */

    HashMap<String, HashSet<String[]>> dependencyGraph;
    HashSet<String> checkedNodes;
    HashSet<String> singleNodes;
    ArrayList<HashSet<String>> clusterSet;

    /**
     * greedy algorithm for clustering code
     *
     * @param dependencyGraph
     * @return
     */
    public ArrayList<HashSet<String>> greedyAlgorithm(HashMap<String, HashSet<String[]>> dependencyGraph) {

        this.dependencyGraph = dependencyGraph;
        checkedNodes = new HashSet<>();
        clusterSet = new ArrayList<>();
        singleNodes = new HashSet<>();

        // Getting a Set of Key-value pairs
        Set entrySet = dependencyGraph.entrySet();

        // Obtaining an iterator for the entry set
        Iterator it = entrySet.iterator();

        // Iterate through HashMap entries(Key-Value pairs)
        System.out.println("HashMap Key-Value Pairs : ");
        while (it.hasNext()) {
            Map.Entry node = (Map.Entry) it.next();
            System.out.println("Key is: " + node.getKey());
            String currentNode = (String) node.getKey();
            if (!checkedNodes.contains(currentNode)) {
                if (dependencyGraph.get(currentNode).size() > 0) {
                    checkedNodes.add(currentNode);
                    HashSet<String> tmpcluster = getClusterNodes(currentNode);
                    boolean isNewCluster = isNewCluster(tmpcluster);
                    if (isNewCluster) {
                        clusterSet.add(tmpcluster);
                    }
                } else {
                    if (!checkedNodes.contains(currentNode)) {
                        singleNodes.add(currentNode);
                    }
                }
            }
        }
        if (singleNodes.size() > 0) {
            for (String single : singleNodes) {
                HashSet<String> singleCluster = new HashSet<>();
                singleCluster.add(single);
                clusterSet.add(singleCluster);
            }
        }

        return clusterSet;
    }


    /**
     * This function checks whether the tmpcluster belongs to existing clusters or not.
     *
     * @param tmpcluster
     * @return
     */
    public boolean isNewCluster(HashSet<String> tmpcluster) {
        ArrayList<Integer> overlaps = new ArrayList<>();
        for (int i = 0; i < clusterSet.size(); i++) {
            HashSet<String> cluster = clusterSet.get(i);
            for (String n : tmpcluster) {
                if (cluster.contains(n)) {
                    if (!overlaps.contains(i)) {
                        overlaps.add(i);
                    }

                }
            }
        }
        if (overlaps.size() > 0) {

            if (overlaps.size() > 1) {
                System.out.print("");
                clusterSet.get(overlaps.get(0)).addAll(tmpcluster);
                for (int x = 0; x < overlaps.size() - 1; x++) {

                    HashSet<String> c1 = clusterSet.get(overlaps.get(x));
                    HashSet<String> c2 = clusterSet.get(overlaps.get(x + 1));
                    c1.addAll(c2);
                    clusterSet.set(overlaps.get(x + 1), new HashSet<>());
//                    c2 = new HashSet<>();
//                    clusterSet.add(c2);
                    overlaps.set(x + 1, overlaps.get(x));
                }

            } else {
                clusterSet.get(overlaps.get(0)).addAll(tmpcluster);
            }
            return false;
        } else {
            return true;
        }
    }

    /**
     * This function get cluster nodes for current Node
     *
     * @param currentNode
     * @return
     */
    public HashSet<String> getClusterNodes(String currentNode) {
        HashSet<String[]> currentDependencies = dependencyGraph.get(currentNode);
        HashSet<String> nodeSet = new HashSet<>();

        nodeSet.add(currentNode);

        for (String[] node : currentDependencies) {
            if (!checkedNodes.contains(node[0])) {
                if (singleNodes.contains(node[0])) {
                    singleNodes.remove(node[0]);
                }

                checkedNodes.add(node[0]);
                nodeSet.add(node[0]);
                HashSet<String[]> depends = dependencyGraph.get(node[0]);
                if (depends != null && depends.size() > 0) {
                    nodeSet.addAll(getClusterNodes(node[0]));
                }
            } else {
                nodeSet.add(node[0]);
            }
        }
        return nodeSet;
    }


}
