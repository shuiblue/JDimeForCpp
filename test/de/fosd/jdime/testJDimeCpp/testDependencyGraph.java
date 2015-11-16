package de.fosd.jdime.testJDimeCpp;

import de.fosd.jdime.dependencyGraph.DependencyGraph;
import de.fosd.jdime.dependencyGraph.Edge;
import edu.uci.ics.jung.graph.DirectedSparseGraph;
import org.junit.Before;
import org.junit.Test;

import java.util.*;

import static org.junit.Assert.assertTrue;

/**
 * Created by shuruiz on 11/5/15.
 */
public class testDependencyGraph {
    DirectedSparseGraph<String, Edge> expect = new DirectedSparseGraph<>();

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
        expect.addVertex("2-B.cpp");

        //Func_decl,Call,Statment
        //add edge
        expect.addEdge(new Edge("<Func_decl> void SendColors", "1-A.cpp", "1-A.h"), "1-A.cpp", "1-A.h");

        expect.addEdge(new Edge("<Statment> int filesize", "12-A.cpp", "5-A.cpp"), "12-A.cpp", "5-A.cpp");
        expect.addEdge(new Edge("<Statment> int filesize", "13-A.cpp", "5-A.cpp"), "13-A.cpp", "5-A.cpp");

        expect.addEdge(new Edge("<Statment> String file", "15-A.cpp", "9-A.cpp"), "15-A.cpp", "9-A.cpp");

        expect.addEdge(new Edge("<Call> void print", "13-A.cpp", "7-A.cpp"), "13-A.cpp", "7-A.cpp");

        expect.addEdge(new Edge("<Call> int write", "13-A.cpp", "8-A.cpp"), "13-A.cpp", "8-A.cpp");
        expect.addEdge(new Edge("<Call> int write", "14-A.cpp", "8-A.cpp"), "14-A.cpp", "8-A.cpp");
        expect.addEdge(new Edge("<Call> int write", "15-A.cpp", "8-A.cpp"), "15-A.cpp", "8-A.cpp");

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
        int edgeList_size = result_edges.size();
        int i =0;
        while (it1_e.hasNext()) {
            Edge e1 = (Edge) it1_e.next();
            it2_e = expect.getEdges().iterator();

            while (it2_e.hasNext()) {
                Edge e2 = (Edge) it2_e.next();
                    if(e1.compare(e1, e2)){
                     i++;
                    }
            }
        }
        if (edgeList_size!=i) {
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

        int vertexList_size= result_vertex.size();
        //compare element
        it1_v = result.getVertices().iterator();
        same = false;
         i=0;
        while (it1_v.hasNext()) {
            String v1 = (String) it1_v.next();
            it2_v = expect.getVertices().iterator();

            while (it2_v.hasNext()) {
                String v2 = (String) it2_v.next();
                if(v1.equals(v2)){
                 i++;
                }
            }
        }
        if (vertexList_size != i) {
            return false;
        }

        return true;

    }

@Before
    public void before() {
        expect = createExpectGraph();
    }

//    @Ignore
    @Test
    public void test10() {
        String fileName = "test_10";
        DirectedSparseGraph<String, Edge> result = DependencyGraph.createDependencyGraph(fileName);
        assertTrue(compareTwoGraphs(result, expect));
    }

    @Test
    public void test11() {
        String fileName = "test_11";
        DirectedSparseGraph<String, Edge> result = DependencyGraph.createDependencyGraph(fileName);

        expect.addVertex("2-A.h");
        expect.addVertex("5-A.h");
        expect.addEdge(new Edge("<Func_decl> constructor CardReader", "10-A.cpp", "5-A.h"), "10-A.cpp", "5-A.h");
        expect.addEdge(new Edge("<Cons_Destruction> class CardReader", "10-A.cpp", "2-A.h"), "10-A.cpp", "2-A.h");
        expect.addEdge(new Edge("<SAMENAME> CardReader", "5-A.h", "2-A.h"), "5-A.h", "2-A.h");

        assertTrue(compareTwoGraphs(result, expect));
    }



    @Test
    public void test12() {
        String fileName = "test_12";
        DirectedSparseGraph<String, Edge> result = DependencyGraph.createDependencyGraph(fileName);

        expect.addVertex("2-A.h");
        expect.addVertex("5-A.h");
        expect.addEdge(new Edge("<Func_decl> constructor CardReader", "10-A.cpp", "5-A.h"), "10-A.cpp", "5-A.h");
        expect.addEdge(new Edge("<Cons_Destruction> class CardReader", "10-A.cpp", "2-A.h"), "10-A.cpp", "2-A.h");
        expect.addEdge(new Edge("<SAMENAME> CardReader", "5-A.h", "2-A.h"), "5-A.h", "2-A.h");

        expect.addVertex("17-A.cpp");
        expect.addVertex("19-A.cpp");
        expect.addVertex("6-A.h");
        expect.addEdge(new Edge("<Func_decl> void ls","17-A.cpp","6-A.h"),"17-A.cpp","6-A.h");
        expect.addEdge(new Edge("<BelongsToClass> CardReader","17-A.cpp","2-A.h"),"17-A.cpp","2-A.h");

        assertTrue(compareTwoGraphs(result, expect));
    }

    @Test
    public void test13() {
        String fileName = "test_13";
        DirectedSparseGraph<String, Edge> result = DependencyGraph.createDependencyGraph(fileName);

        expect.addVertex("2-A.h");
        expect.addVertex("5-A.h");
        expect.addEdge(new Edge("<Func_decl> constructor CardReader", "10-A.cpp", "5-A.h"), "10-A.cpp", "5-A.h");
        expect.addEdge(new Edge("<Cons_Destruction> class CardReader", "10-A.cpp", "2-A.h"), "10-A.cpp", "2-A.h");
        expect.addEdge(new Edge("<SAMENAME> CardReader", "5-A.h", "2-A.h"), "5-A.h", "2-A.h");

        expect.addVertex("17-A.cpp");
        expect.addVertex("19-A.cpp");
        expect.addVertex("6-A.h");
        expect.addEdge(new Edge("<Func_decl> void ls","17-A.cpp","6-A.h"),"17-A.cpp","6-A.h");
        expect.addEdge(new Edge("<BelongsToClass> CardReader","17-A.cpp","2-A.h"),"17-A.cpp","2-A.h");

        expect.addVertex("21-A.cpp");
        expect.addVertex("22-A.cpp");
        expect.addVertex("23-A.cpp");

        expect.addEdge(new Edge("<Func_decl> void lcd_sdcard_print_menu","22-A.cpp","21-A.cpp"),"22-A.cpp","21-A.cpp");
        expect.addEdge(new Edge("<SAMENAME> lcd_sdcard_print_menu","2-B.cpp","21-A.cpp"),"2-B.cpp","21-A.cpp");

        assertTrue(compareTwoGraphs(result, expect));
    }
}
