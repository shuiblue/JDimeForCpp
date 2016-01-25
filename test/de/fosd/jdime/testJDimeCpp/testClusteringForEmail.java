package de.fosd.jdime.testJDimeCpp;

import de.fosd.jdime.dependencyGraph.ClusterNode;
import de.fosd.jdime.dependencyGraph.DependencyGraph;
import de.fosd.jdime.util.IOFunctionSet;
import org.junit.Test;

import java.util.HashMap;
import java.util.HashSet;

import static org.junit.Assert.assertTrue;

/**
 * Created by shuruiz on 1/13/16.
 */
public class testClusteringForEmail {
    DependencyGraph dependencyGraph = new DependencyGraph();
    ClusterNode clusterNode = new ClusterNode();
    HashMap<String, HashSet<String[]>> nodes;
    //        @Ignore
    @Test
    public void test10() {

        String fileName = "EmailSystem/test_16";

        nodes = dependencyGraph.getDependencyGraph(fileName);




//        clusterNode.greedyAlgorithm(nodes);
//        assertTrue();
    }

}
