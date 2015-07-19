package test;

import de.fosd.jdime.Main;
import org.apache.commons.cli.ParseException;
import org.junit.Test;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

import static org.junit.Assert.assertTrue;

/**
 * Created by shuruiz on 7/15/15.
 */
public class IfdefAndFunction {
    TestInitial testInitial = new TestInitial("testcpp/IFDEF/");

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

    /*
    test2
    A:                      | B:
    #ifdef X                |   void a();
    void a();               |   void b();
    #endif                  |
    */
    @Test
    public void test2() {
        String outputPath = "2/AB";
        String expectResultPath = "2/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("2/A");
        inputFilePaths.add("2/B");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }


    /*
    test2
    A:                      | B:
    #ifdef X                |   void b();
    void a();               |   void a();
    #endif                  |
    */
    @Test
    public void test3() {
        String outputPath = "3/AB";
        String expectResultPath = "3/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("3/A");
        inputFilePaths.add("3/B");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }
}
