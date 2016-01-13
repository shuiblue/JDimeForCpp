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

    HashMap<String, HashSet<String>> dependencyGraph;
    HashSet<String> checkedNodes;
    HashSet<String> singleNodes;
    HashSet<HashSet<String>> clusterSet;

    public HashSet<HashSet<String>> greedyAlgorithm(HashMap<String, HashSet<String>> dependencyGraph) {

        this.dependencyGraph = dependencyGraph;
        checkedNodes = new HashSet<>();
        clusterSet = new HashSet<>();
        singleNodes = new HashSet<>();
        HashSet<String> cluster = new HashSet<>();

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
                checkedNodes.add(currentNode);
                HashSet<String> clusterNodes = getClusterNodes(currentNode);
                cluster.addAll(clusterNodes);
                if (cluster.size() > 0) {
                    clusterSet.add(cluster);
                    cluster = new HashSet<>();
                }
            }
        }
        return clusterSet;
    }

    public HashSet<String> getClusterNodes(String currentNode) {
        HashSet<String> currentDependencies = dependencyGraph.get(currentNode);
        HashSet<String> nodeSet = new HashSet<>();

        nodeSet.add(currentNode);
        if (currentDependencies != null) {
            if (currentDependencies.size() == 0) {
                singleNodes.add(currentNode);
                return nodeSet;
            }


            for (String node : currentDependencies) {
                if (singleNodes.contains(node)) {
                    singleNodes.remove(node);
                }

                if (!checkedNodes.contains(node)) {

                    checkedNodes.add(node);
                    nodeSet.add(node);
                    HashSet<String> depends = dependencyGraph.get(node);
                    if (depends != null) {
                        nodeSet.addAll(getClusterNodes(node));
                    }
                } else {
                    for (HashSet<String> cluster : clusterSet) {
                        if (cluster.contains(node)) {
                            cluster.add(currentNode);
                            for (String n : currentDependencies) {
                                if (!checkedNodes.contains(n)) {
                                    HashSet<String> dependencies = getClusterNodes(n);
//                                    cluster.add(node);
                                    cluster.addAll(dependencies);
                                }
                            }
                            nodeSet = new HashSet<>();
                            return nodeSet;
                        }
                    }
                }

            }
        }


        return nodeSet;


    }


}
