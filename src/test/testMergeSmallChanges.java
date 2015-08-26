package test;

import org.junit.Test;

import java.util.ArrayList;

/**
 * Created by shuruiz on 8/25/15.
 */
public class testMergeSmallChanges {
    String path = "testcpp/mocrepo/";
TestInitial testInitial = new TestInitial(path);
String output = "mergednew.cpp";
    @Test
    public void mergeIncrementally() {

        ArrayList<String> inputFilePaths = new ArrayList<>();
//        inputFilePaths.add("mocrepo/foo.cpp");
        inputFilePaths.add("merged.cpp");
        inputFilePaths.add("mocrepoFork1/foo.cpp");
        testInitial.runMain(inputFilePaths,output);


    }
}
