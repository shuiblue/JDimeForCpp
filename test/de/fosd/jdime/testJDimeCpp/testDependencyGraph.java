package de.fosd.jdime.testJDimeCpp;

import de.fosd.jdime.dependencyGraph.DependencyGraph;
import org.junit.Test;

import java.io.IOException;

/**
 * Created by shuruiz on 11/5/15.
 */
public class testDependencyGraph {

    @Test
    public void test1() {
        String[] args = {"testcpp/dependencyGraph/1/A.cpp"};
        String cmd = "tar -cvzf x.tar.gz ./*.cpp";
        try {
            new ProcessBuilder("tar", "-cvzf", "1.tar.gz", "testcpp/dependencyGraph/1/*").start();
        } catch (IOException e) {
            e.printStackTrace();
        }

        DependencyGraph.main(args);

//        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }


}
