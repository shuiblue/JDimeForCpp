package de.fosd.jdime.testJDimeCpp;

import de.fosd.jdime.dependencyGraph.DependencyGraph;
import de.fosd.jdime.dependencyGraph.Edge;
import de.fosd.jdime.util.IOFunctionSet;
import edu.uci.ics.jung.graph.DirectedSparseGraph;
import org.junit.Test;

import java.io.IOException;
import java.util.*;

import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;

/**
 * Created by shuruiz on 11/5/15.
 */
public class testDependencyGraph {

    public DirectedSparseGraph<String, Edge> createExpectGraph() {
        DirectedSparseGraph<String, Edge> expect = new DirectedSparseGraph<>();

        //add vertex
        expect.addVertex("1-A.cpp");
        expect.addVertex("3-A.cpp");
        expect.addVertex("5-A.cpp");
        expect.addVertex("7-A.cpp");
        expect.addVertex("8-A.cpp");
        expect.addVertex("9-A.cpp");
        expect.addVertex("10-A.cpp");
        expect.addVertex("12-A.cpp");
        expect.addVertex("13-A.cpp");
        expect.addVertex("14-A.cpp");
        expect.addVertex("15-A.cpp");

        expect.addVertex("1-A.h");

        expect.addVertex("1-B.cpp");
        expect.addVertex("3-B.cpp");

        //add edge
        expect.addEdge(new Edge("define void SendColors", "1-A.h", "1-A.cpp"), "1-A.h", "1-A.cpp");

        expect.addEdge(new Edge("int filesize", "12-A.cpp", "5-A.cpp"), "12-A.cpp", "5-A.cpp");
        expect.addEdge(new Edge("int filesize", "13-A.cpp", "5-A.cpp"), "13-A.cpp", "5-A.cpp");

        expect.addEdge(new Edge("String file", "15-A.cpp", "9-A.cpp"), "15-A.cpp", "9-A.cpp");

        expect.addEdge(new Edge("call print", "13-A.cpp", "7-A.cpp"), "13-A.cpp", "7-A.cpp");

        expect.addEdge(new Edge("call write", "13-A.cpp", "8-A.cpp"), "13-A.cpp", "8-A.cpp");
        expect.addEdge(new Edge("call write", "14-A.cpp", "8-A.cpp"), "14-A.cpp", "8-A.cpp");
        expect.addEdge(new Edge("call write", "15-A.cpp", "8-A.cpp"), "15-A.cpp", "8-A.cpp");

//expect.getInEdges()
        return expect;
    }


    public boolean compareTwoGraphs(DirectedSparseGraph<String, Edge> result, DirectedSparseGraph<String, Edge> expect) {
        //compare edges
        Set<Edge> result_edges = new HashSet<>();
        Set<Edge> expect_edges = new HashSet<>();
        Iterator it1_e = result.getEdges().iterator();
        while (it1_e.hasNext()) {
            result_edges.add((Edge) it1_e.next());
        }

        Iterator it2_e = expect.getEdges().iterator();
        while (it2_e.hasNext()) {
            expect_edges.add((Edge) it2_e.next());
        }

        //compare size
        if (result_edges.size() != expect_edges.size()) {
            return false;
        }

        //compare element
        it1_e = result.getEdges().iterator();
        boolean same = false;
        while (it1_e.hasNext()) {
            Edge e1 = (Edge) it1_e.next();
            it2_e = expect.getEdges().iterator();

            while (it2_e.hasNext()) {
                Edge e2 = (Edge) it2_e.next();
                same = same || e1.compare(e1, e2);
            }
        }
        if (same == false) {
            return false;
        }

//compare vertex

        Set<String> result_vertex = new HashSet<>();
        Set<String> expect_vertex = new HashSet<>();
        Iterator it1_v = result.getVertices().iterator();
        while (it1_v.hasNext()) {
            result_vertex.add((String) it1_v.next());
        }

        Iterator it2_v = expect.getVertices().iterator();
        while (it2_v.hasNext()) {
            expect_vertex.add((String) it2_v.next());
        }
        //Compare size
        if (result_vertex.size() != expect_vertex.size()) {
            return false;
        }

        //compare element
        it1_v = result.getVertices().iterator();
        same = false;
        while (it1_v.hasNext()) {
            String v1 = (String) it1_v.next();
            it2_v = expect.getVertices().iterator();

            while (it2_v.hasNext()) {
                String v2 = (String) it2_v.next();
                same = same || v1.equals(v2);
            }
        }
        if (same == false) {
            return false;
        }

        return true;

    }


    @Test
    public void test10() {
        String fileName = "test_10";
        DirectedSparseGraph<String, Edge> result = DependencyGraph.createDependencyGraph(fileName);
        DirectedSparseGraph<String, Edge> expect = new DirectedSparseGraph<>();
        expect = createExpectGraph();
        assertTrue(compareTwoGraphs(result, expect));
        DependencyGraph.visualizeGraph(result);
    }


}
