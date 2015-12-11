package de.fosd.jdime.testJDimeCpp;

import de.fosd.jdime.dependencyGraph.DependencyGraph;
import de.fosd.jdime.dependencyGraph.Edge;
import org.junit.Test;

import java.util.HashSet;

/**
 * Created by shuruiz on 12/2/15.
 */
public class testEmailSystem {
String dir = "EmailSystem/";

    @Test
    public void test_10(){
        String fileName = dir+"test_10";
        HashSet<Edge> edges= DependencyGraph.createDependencyGraph(fileName);

    }

}
