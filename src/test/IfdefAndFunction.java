package test;

import org.junit.Test;
import java.util.ArrayList;
import static org.junit.Assert.assertTrue;

/**
 * Created by shuruiz on 7/15/15.
 */
public class IfdefAndFunction {
    TestInitial testInitial = new TestInitial("testcpp/IFDEF/");
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
    test3
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

    /*
 test4
 A:                      | B:
 #ifdef X                |  #ifdef X
 void a();               |  void b();
 #endif                  |  #endif
 */
    @Test
    public void test4() {
        String outputPath = "4/AB";
        String expectResultPath = "4/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("4/A");
        inputFilePaths.add("4/B");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }


}
