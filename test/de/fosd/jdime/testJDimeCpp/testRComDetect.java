package de.fosd.jdime.testJDimeCpp;

import de.fosd.jdime.dependencyGraph.DependencyGraph;
import de.fosd.jdime.dependencyGraph.RCommunityDetection;
import org.junit.Test;

import java.util.HashMap;
import java.util.HashSet;

/**
 * Created by shuruiz on 2/14/16.
 */
public class testRComDetect {
    DependencyGraph dependencyGraph = new DependencyGraph();
    HashMap<String, HashSet<String[]>> nodes;

    @Test
    public void test10() {

        String filePath = "EmailSystem/test_18";
//        String filePath = "test_18";

        nodes = dependencyGraph.getDependencyGraph(filePath);
        new RCommunityDetection(filePath);
        System.out.print("");
    }
}
