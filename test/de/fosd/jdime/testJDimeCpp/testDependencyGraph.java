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

    //@Ignore
    @Test
    public void test10() {
        String fileName = "EmailSystem/test_10";
        HashSet<String> result = DependencyGraph.createDependencyGraph(fileName);
        assertTrue(compareTwoGraphs(result));
    }

    //@Ignore
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

    //@Ignore
    @Test
    public void test12() {
        String fileName = "EmailSystem/test_12";
        expect_edges.add("38-Client.c->18-Client.h");
        expect_edges.add("40-Client.c->29-Client.c");
        expect_edges.add("40-Client.c->38-Client.c");

        HashSet<String> result = DependencyGraph.createDependencyGraph(fileName);
        assertTrue(compareTwoGraphs(result));
    }


    @Test
    public void test13() {
        String fileName = "EmailSystem/test_13";
        expect_edges.add("7-Email.c->10-Email.h");
        expect_edges.add("24-Email.c->12-Email.h");
        expect_edges.add("35-Email.c->14-Email.h");
        expect_edges.add("20-Email.c->9-Email.c");


        HashSet<String> result = DependencyGraph.createDependencyGraph(fileName);
        assertTrue(compareTwoGraphs(result));
    }
}
