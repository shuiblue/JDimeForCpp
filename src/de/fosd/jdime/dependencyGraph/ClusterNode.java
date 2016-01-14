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
                if (dependencyGraph.get(currentNode).size() > 0) {
                    checkedNodes.add(currentNode);
                    HashSet<String> tmpcluster = getClusterNodes(currentNode);
                    boolean isNewCluster = isNewCluster(tmpcluster);
                    if (isNewCluster) {
                        clusterSet.add(tmpcluster);
//                    cluster = new HashSet<>();
                    }
                } else {
                    if (!checkedNodes.contains(currentNode)) {
                        singleNodes.add(currentNode);
                    }
                }
            }
        }


        return clusterSet;
    }


    public boolean isNewCluster(HashSet<String> tmpcluster) {
        for (HashSet<String> tmpCluster : clusterSet) {
            for (String n : tmpcluster) {
                if (tmpCluster.contains(n)) {
                    tmpCluster.addAll(tmpcluster);
                    return false;
                }
            }
        }
        return true;
    }

    public HashSet<String> getClusterNodes(String currentNode) {
        HashSet<String> currentDependencies = dependencyGraph.get(currentNode);
        HashSet<String> nodeSet = new HashSet<>();

        nodeSet.add(currentNode);

        for (String node : currentDependencies) {
            if (!checkedNodes.contains(node)) {
                if (singleNodes.contains(node)) {
                    singleNodes.remove(node);
                }

                checkedNodes.add(node);
                nodeSet.add(node);
                HashSet<String> depends = dependencyGraph.get(node);
                if (depends != null && depends.size() > 0) {
                    nodeSet.addAll(getClusterNodes(node));
                }
            }else {
                nodeSet.add(node);
            }
        }
        return nodeSet;
    }


}
