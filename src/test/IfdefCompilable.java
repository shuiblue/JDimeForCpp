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

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add(input_A);
        inputFilePaths.add(input_B);
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));

        // ----------------check preprocessed Merged result equal to origin
        String[] config_1 = {"A", "X"};
        assertTrue(testInitial.checkProprocessResult(config_1, output, A, path, testNum));

        String[] config_2 = {"A"};
        assertTrue(testInitial.checkProprocessResult(config_2, output, A, path, testNum));

        String[] config_3 = {"B"};
        assertTrue(testInitial.checkProprocessResult(config_3, output, B, path, testNum));

    }
}
