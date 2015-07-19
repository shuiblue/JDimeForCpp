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
 * Created by shuruiz on 7/10/15.
 */
public class FunctionNameOnly {
    TestInitial testInitial = new TestInitial("testcpp/functionNameOnly/");

    //----------------2 WAY-----------------------------
    /*
     test1
     A: void a();
     B: void b();
     */
    @Test
    public void test1() {
        String outputPath = "1/12";
        String expectResultPath = "1/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("1/1");
        inputFilePaths.add("1/2");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

    /*
    test2
    A: void a();
    B: void a();
    */
    @Test
    public void test2() {
        String outputPath = "1_1/12";
        String expectResultPath = "1_1/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("1_1/1");
        inputFilePaths.add("1_1/2");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

    /*
    test3
    A: void c();  |  B: void c();
       void a();  |     void b();
    */
    @Test
    public void test3() {
        String outputPath = "2/AB";
        String expectResultPath = "2/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("2/A");
        inputFilePaths.add("2/B");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

    /*
       test4
       A: void c();  |  B: void c();
          void a();  |
    */
    @Test
    public void test4() {
        String outputPath = "2_1/AB";
        String expectResultPath = "2_1/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("2_1/A");
        inputFilePaths.add("2_1/B");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

    /*
       test5
       A: void a();  |  B: void x();
          void x();  |     void b();
    */
    @Test
    public void test5() {
        String outputPath = "2_2/AB";
        String expectResultPath = "2_2/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("2_2/A");
        inputFilePaths.add("2_2/B");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

    //----------------3 WAY-----------------------------
    /*
       test6
       A: void x();  |  B: void x();  |  C: void x();
          void a();  |     void b();  |     void c();
    */
    @Test
    public void test6() {
        String outputPath = "3/ABC";
        String expectResultPath = "3/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("3/A");
        inputFilePaths.add("3/B");
        inputFilePaths.add("3/C");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

    /*
       test7
       A: void ab();  |  B: void ab();  |  C: void c();
    */
    @Test
    public void test7() {
        String outputPath = "3_1/ABC";
        String expectResultPath = "3_1/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("3_1/A");
        inputFilePaths.add("3_1/B");
        inputFilePaths.add("3_1/C");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

    /*
       test7_1
       A: void ac();  |  B: void b();  |  C: void ac();
    */
    @Test
    public void test7_1() {
        String outputPath = "3_2/ABC";
        String expectResultPath = "3_2/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("3_2/A");
        inputFilePaths.add("3_2/B");
        inputFilePaths.add("3_2/C");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

    /*
       test7_2
       A: void a();  |  B: void bc();  |  C: void bc();
    */
    @Test
    public void test7_2() {
        String outputPath = "3_2_1/ABC";
        String expectResultPath = "3_2_1/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("3_2_1/A");
        inputFilePaths.add("3_2_1/B");
        inputFilePaths.add("3_2_1/C");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

    /*
       test8
       A: void x();  |  B: void x();  |  C: void x();
          void ab(); |     void ab(); |     void c();
    */
    @Test
    public void test8() {
        String outputPath = "3_3/ABC";
        String expectResultPath = "3_3/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("3_3/A");
        inputFilePaths.add("3_3/B");
        inputFilePaths.add("3_3/C");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

    /*
   test8
   A: void x();  |  B: void x();  |  C: void x();
      void ac(); |     void b();  |     void ac();
*/
    @Test
    public void test8_1() {
        String outputPath = "3_4/ABC";
        String expectResultPath = "3_4/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("3_4/A");
        inputFilePaths.add("3_4/B");
        inputFilePaths.add("3_4/C");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

    /*
  test8_2
  A:   void a(); | B:  void x(); |  C:  void x();
       void x(); |     void bc();|      void bc();
  */
    @Test
    public void test8_2() {
        String outputPath = "3_5/ABC";
        String expectResultPath = "3_5/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("3_5/A");
        inputFilePaths.add("3_5/B");
        inputFilePaths.add("3_5/C");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

    /*
    test8_3
        A:   void a(); | B:  void x(); |  C:  void bc();
             void x(); |     void bc();|      void x();
    */
    @Test
    public void test8_3() {
        String outputPath = "3_6/ABC";
        String expectResultPath = "3_6/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("3_6/A");
        inputFilePaths.add("3_6/B");
        inputFilePaths.add("3_6/C");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

    /*
test8_3
    A:   void a(); | B:  void x(); |  C:  void bc();
         void x(); |     void bc();|      void x();
*/
    @Test
    public void test8_4() {
        String outputPath = "3_7/ABC";
        String expectResultPath = "3_7/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("3_7/A");
        inputFilePaths.add("3_7/B");
        inputFilePaths.add("3_7/C");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

    //----------------4 WAY-----------------------------    /*
    /*
    test9
    A: void x();  |  B: void x();  |  C: void x();  |  D: void x();
       void a();  |     void b();  |     void c();  |     void d();
    */
    @Test
    public void test9() {
        String outputPath = "4/ABCD";
        String expectResultPath = "4/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("4/A");
        inputFilePaths.add("4/B");
        inputFilePaths.add("4/C");
        inputFilePaths.add("4/D");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

    /*
    test10
    A: void x();  |  B: void x();  |  C: void x();  |  D: void x();
       void ab(); |    void ab();  |     void c();  |     void d();
    */
    @Test
    public void test10() {
        String outputPath = "4_1/ABCD";
        String expectResultPath = "4_1/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("4_1/A");
        inputFilePaths.add("4_1/B");
        inputFilePaths.add("4_1/C");
        inputFilePaths.add("4_1/D");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

    /*
   test10_1
   A: void x();  |  B: void x();  |  C: void x();  |  D: void x();
      void ab(); |    void ab();  |     void c();  |     void d();
   */
    @Test
    public void test10_1() {
        String outputPath = "4_1_1/ABCD";
        String expectResultPath = "4_1_1/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("4_1_1/A");
        inputFilePaths.add("4_1_1/B");
        inputFilePaths.add("4_1_1/C");
        inputFilePaths.add("4_1_1/D");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

    /*
    test11
    A: void x();  |  B: void x();  |  C: void x();  |  D: void x();
       void ac(); |    void b();   |     void ac(); |     void d();
    */
    @Test
    public void test11() {
        String outputPath = "4_2/ABCD";
        String expectResultPath = "4_2/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("4_2/A");
        inputFilePaths.add("4_2/B");
        inputFilePaths.add("4_2/C");
        inputFilePaths.add("4_2/D");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

    /*
    test12
    A: void x();  |  B: void x();  |  C: void x();   |  D: void x();
       void ac();|      void bd(); |     void ac(); |      void bd();
    */
    @Test
    public void test12() {
        String outputPath = "4_3/ABCD";
        String expectResultPath = "4_3/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("4_3/A");
        inputFilePaths.add("4_3/B");
        inputFilePaths.add("4_3/C");
        inputFilePaths.add("4_3/D");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

    /*
    test13
    A: void x();  |  B: void x();  |  C: void x();   |  D: void x();
       void abc();|    void abc(); |     void abc(); |     void d();
    */
    @Test
    public void test13() {
        String outputPath = "4_4/ABCD";
        String expectResultPath = "4_4/expect";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("4_4/A");
        inputFilePaths.add("4_4/B");
        inputFilePaths.add("4_4/C");
        inputFilePaths.add("4_4/D");


        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }
}
