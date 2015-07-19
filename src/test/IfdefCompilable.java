package test;

import org.junit.Test;

import java.util.ArrayList;

import static org.junit.Assert.assertTrue;

/**
 * Created by shuruiz on 7/19/15.
 */
public class IfdefCompilable {
    TestInitial testInitial = new TestInitial("testcpp/IFDEF/forCompile/");
    //----------------2 WAY-----------------------------

    /*
    test1
    A:                      | B:
    #ifdef X                |   void b();
    void a();               |
    #endif                  |
    */
    @Test
    public void test1() {
        String outputPath = "1/AB";
        String expectResultPath = "1/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("1/A");
        inputFilePaths.add("1/B");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }
}
