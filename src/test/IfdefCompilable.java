package test;

import org.junit.Test;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

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
        HashSet<String> config = new HashSet<>();
        Set<String> fileName = new HashSet<>();

        config.add("");
        config.add("X");
        String A = "A";
        String B = "B";
        String output = "AB";
        String testNum = "1/";
        fileName.add(A);
        fileName.add(B);

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

        for (String file : fileName) {
            Set<String> feature = new HashSet<>();
            for (String c : config) {
                feature.add(file);
                if (c != "") {
                    feature.add(c);
                }
                System.out.println("## running config " + feature + "--" + file);
                System.out.println(testInitial.checkProprocessResult((HashSet<String>) feature, output, file, path, testNum));
                assertTrue(testInitial.checkProprocessResult((HashSet<String>) feature, output, file, path, testNum));
            }
        }
    }

    /*
   test2
   A:                      | B:
   #ifdef X                |   void a();
   void a();               |
   #endif                  |
   */
    @Test
    public void test2() {
        HashSet<String> config = new HashSet<>();
        Set<String> fileName = new HashSet<>();

        config.add("");
        config.add("X");
        String A = "A";
        String B = "B";
        String output = "AB";
        String testNum = "2/";
        fileName.add(A);
        fileName.add(B);

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

        for (String file : fileName) {
            Set<String> feature = new HashSet<>();
            for (String c : config) {
                feature.add(file);
                if (c != "") {
                    feature.add(c);
                }
                System.out.println("## running config " + feature + "--" + file);
                System.out.println(testInitial.checkProprocessResult((HashSet<String>) feature, output, file, path, testNum));
                assertTrue(testInitial.checkProprocessResult((HashSet<String>) feature, output, file, path, testNum));
            }
        }
    }
}
