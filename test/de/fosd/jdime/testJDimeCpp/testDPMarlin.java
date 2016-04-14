//package de.fosd.jdime.testJDimeCpp;
//
//import de.fosd.jdime.dependencyGraph.DependencyGraph;
//import org.junit.Test;
//
//import java.util.HashSet;
//
//import static org.junit.Assert.assertTrue;
//
///**
// * Created by shuruiz on 12/21/15.
// */
//public class testDPMarlin {
//    HashSet<String> expect_edges;
//    DependencyGraph dependencyGraph = new DependencyGraph();
//    public boolean compareTwoGraphs(HashSet<String> result) {
//        boolean compare = true;
//        for (String edge : expect_edges) {
//            compare = compare && result.contains(edge);
////            if (result.contains(edge) == false) {
////                System.out.print(edge + "\n");
////            }
//        }
//        return compare;
//    }
//
//
//
//    public void expect_10() {
//        expect_edges.add("");
//    }
//
//
//    //        @Ignore
//    @Test
//    public void test10() {
//        expect_edges = new HashSet<>();
//        expect_10();
//
//        String fileName = "test_10";
//        HashSet<String> result = dependencyGraph.createDependencyGraph(fileName);
//        assertTrue(compareTwoGraphs(result));
//    }
//
//
//    //        @Ignore
//    @Test
//    public void test11() {
//        expect_edges = new HashSet<>();
//        expect_10();
//
//        String fileName = "test_11";
//        HashSet<String> result = dependencyGraph.createDependencyGraph(fileName);
//        assertTrue(compareTwoGraphs(result));
//    }
//
//
//    //        @Ignore
//    @Test
//    public void test14() {
//        expect_edges = new HashSet<>();
//
//        String fileName = "test_14";
//        HashSet<String> result = dependencyGraph.createDependencyGraph(fileName);
//        assertTrue(compareTwoGraphs(result));
//    }
//
//}
