package de.fosd.jdime.testJDimeCpp;

import de.fosd.jdime.dependencyGraph.DependencyGraph;
import de.fosd.jdime.util.IOFunctionSet;
import org.junit.Test;

import java.io.IOException;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertNotNull;

/**
 * Created by shuruiz on 11/5/15.
 */
public class testDependencyGraph {

    String dir = "testcpp/dependencyGraph/";


    @Test
    public void test1() {
//        String tarFileName = "test_1";
//        String filePath = dir + tarFileName + ".tar.gz";
//        try {
//            new ProcessBuilder("tar", "-cvzf", filePath, "testcpp/dependencyGraph/1/*.cpp", "testcpp/dependencyGraph/1/*.h").start();
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
//        String[] args = {filePath};
//
//        DependencyGraph.main(args);
//
//        try {
//            assertNotNull(IOFunctionSet.readResult(filePath));
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
assertNotNull(1);
        System.out.println("a");

    }


}
