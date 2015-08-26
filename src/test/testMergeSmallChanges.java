package test;

import org.junit.Test;

import java.util.ArrayList;

/**
 * Created by shuruiz on 8/25/15.
 */
public class testMergeSmallChanges {
    String path = "testcpp/mocrepo/";
    TestInitial testInitial = new TestInitial(path);
    String output = "merged.cpp";

    @Test
    public void mergeIncrementally() {

        ArrayList<String> inputFilePaths = new ArrayList<>();
//        inputFilePaths.add("mocrepo/foo.cpp+upstream");
        inputFilePaths.add("mocrepoFork1/+fork1_commit2");
        testInitial.runMain4Marlin_withRevision(inputFilePaths, path+output, "foo.cpp");


    }
}
