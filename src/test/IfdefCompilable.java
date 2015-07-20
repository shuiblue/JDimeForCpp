package test;

import org.junit.Test;

import java.util.ArrayList;

import static org.junit.Assert.assertTrue;

/**
 * Created by shuruiz on 7/19/15.
 */
public class IfdefCompilable {
    String path = "testcpp/IFDEF/forCompile/";
    TestInitial testInitial = new TestInitial(path);
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
        String A = "A";
        String B = "B";
        String output = "AB";
        String testNum = "1/";

        String input_A = testNum + A;
        String input_B = testNum + B;
        String outputPath = testNum + output;
        String expectResultPath = testNum + "expect";

        String prefix = "compiled/";
        String mixedPath_prefix = path + testNum + prefix;

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add(input_A);
        inputFilePaths.add(input_B);
        // check Merged result
        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));


        String compiledMergedResult_AX = testInitial.checkCompiledResult("-DA,-DX," + path + outputPath, mixedPath_prefix + "AX");
        String compiledMergedResult_B = testInitial.checkCompiledResult("-DB," + path + outputPath, mixedPath_prefix + "B");

        String compiled_A = testInitial.checkCompiledResult("-DA,-DX," + path + input_A, mixedPath_prefix + "Ori_A");
        String compiled_B = testInitial.checkCompiledResult("-DB," + path + input_B, mixedPath_prefix + "Ori_B");


        assertTrue(compiledMergedResult_AX.equals(compiled_A));
        assertTrue(compiledMergedResult_B.equals(compiled_B));

    }
}
