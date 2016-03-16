package de.fosd.jdime.testJDimeCpp;

import de.fosd.jdime.ColorCodeBlocks.ColorCodeBlocks;
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

        RCommunityDetection rCommunityDetection = new RCommunityDetection();
        boolean printPath = false;
        String filePath = "EmailSystem/test_18";
//        String filePath = "MinePump/test_11";
//        String filePath = "Marlin";
//        String filePath = "test_14";

        nodes = dependencyGraph.getDependencyGraph(filePath);
        int bestCut = rCommunityDetection.detectingCommunitiesWithIgraph(filePath);
        ColorCodeBlocks colorCodeBlocks = new ColorCodeBlocks();
        colorCodeBlocks.parseEachUsefulClusteringResult(printPath, filePath,bestCut);

    }
}
