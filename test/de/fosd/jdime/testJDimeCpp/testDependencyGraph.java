package de.fosd.jdime.testJDimeCpp;

import de.fosd.jdime.dependencyGraph.DependencyGraph;
import org.junit.Before;
import org.junit.Ignore;
import org.junit.Test;

import java.util.*;

import static org.junit.Assert.assertTrue;


/**
 * Created by shuruiz on 11/5/15.
 */
public class testDependencyGraph {
    HashSet<String> expect_edges = new HashSet<>();

    public HashSet<String> createExpectGraph() {
        expect_edges.add("13-Client.c->8-Client.c");
        expect_edges.add("14-Client.c->8-Client.c");
        expect_edges.add("16-Client.c->8-Client.c");
        expect_edges.add("12-Client.h->10-Client.h");
        expect_edges.add("13-Client.h->10-Client.h");

        //TODO:outgoingBuffer??
        //scope  =  2 ?
//        expect_edges.add("13-Client.c->13-Client.h");
//        expect_edges.add("14-Client.c->13-Client.h");
//        expect_edges.add("16-Client.c->13-Client.h");

        //TODO: struct type
//          expect_edges.add("8-Client.c->10-Client.h");
        return expect_edges;
    }


    public boolean compareTwoGraphs(HashSet<String> result) {
        boolean compare = true;
        for (String edge : expect_edges) {
            compare = compare && result.contains(edge);
        }
        return compare;
    }

    @Before
    public void before() {
        expect_edges = createExpectGraph();
    }

    @Ignore
    @Test
    public void test10() {
        String fileName = "EmailSystem/test_10";
        HashSet<String> result = DependencyGraph.createDependencyGraph(fileName);
        assertTrue(compareTwoGraphs(result));
    }

    @Test
    public void test11() {
        String fileName = "EmailSystem/test_11";
        expect_edges.add("21-Client.c->16-Client.h");
        expect_edges.add("23-Client.c->21-Client.c");
        expect_edges.add("24-Client.c->21-Client.c");
        expect_edges.add("24-Client.c->8-Client.c");
        //TODO:name ??
        //scope  =  2 ?
//        expect_edges.add("23-Client.c->13-Client.h");
//        expect_edges.add("14-Client.c->13-Client.h");
//        expect_edges.add("16-Client.c->13-Client.h");

        HashSet<String> result = DependencyGraph.createDependencyGraph(fileName);
        assertTrue(compareTwoGraphs(result));

    }

    @Ignore
    @Test
    public void test12() {
        String fileName = "test_12";
//        DirectedSparseGraph<String, Edge> result = DependencyGraph.createDependencyGraph(fileName);

//        expect.addVertex("2-A.h");
//        expect.addVertex("5-A.h");
//        expect.addEdge(new Edge("<Func_decl> constructor CardReader", "10-A.cpp", "5-A.h"), "10-A.cpp", "5-A.h");
//        expect.addEdge(new Edge("<Cons_Destruction> class CardReader", "10-A.cpp", "2-A.h"), "10-A.cpp", "2-A.h");
//        expect.addEdge(new Edge("<SAMENAME> CardReader", "5-A.h", "2-A.h"), "5-A.h", "2-A.h");
//
//        expect.addVertex("17-A.cpp");
//        expect.addVertex("19-A.cpp");
//        expect.addVertex("6-A.h");
//        expect.addEdge(new Edge("<Func_decl> void ls", "17-A.cpp", "6-A.h"), "17-A.cpp", "6-A.h");
//        expect.addEdge(new Edge("<BelongsToClass> CardReader", "17-A.cpp", "2-A.h"), "17-A.cpp", "2-A.h");

//        assertTrue(compareTwoGraphs(result, expect));
    }

    @Ignore
    @Test
    public void test13() {
        String fileName = "test_13";
//        DirectedSparseGraph<String, Edge> result = DependencyGraph.createDependencyGraph(fileName);

//        expect.addVertex("2-A.h");
//        expect.addVertex("5-A.h");
//        expect.addEdge(new Edge("<Func_decl> constructor CardReader", "10-A.cpp", "5-A.h"), "10-A.cpp", "5-A.h");
//        expect.addEdge(new Edge("<Cons_Destruction> class CardReader", "10-A.cpp", "2-A.h"), "10-A.cpp", "2-A.h");
//        expect.addEdge(new Edge("<SAMENAME> CardReader", "5-A.h", "2-A.h"), "5-A.h", "2-A.h");
//
//        expect.addVertex("17-A.cpp");
//        expect.addVertex("19-A.cpp");
//        expect.addVertex("6-A.h");
//        expect.addEdge(new Edge("<Func_decl> void ls", "17-A.cpp", "6-A.h"), "17-A.cpp", "6-A.h");
//        expect.addEdge(new Edge("<BelongsToClass> CardReader", "17-A.cpp", "2-A.h"), "17-A.cpp", "2-A.h");
//
//        expect.addVertex("21-A.cpp");
//        expect.addVertex("22-A.cpp");
//        expect.addVertex("23-A.cpp");
//
//        expect.addEdge(new Edge("<Func_decl> void lcd_sdcard_print_menu", "22-A.cpp", "21-A.cpp"), "22-A.cpp", "21-A.cpp");
//        expect.addEdge(new Edge("<SAMENAME> lcd_sdcard_print_menu", "2-B.cpp", "21-A.cpp"), "2-B.cpp", "21-A.cpp");

//        assertTrue(compareTwoGraphs(result, expect));
    }
}
