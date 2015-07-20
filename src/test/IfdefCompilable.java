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
    HashSet<String> config = new HashSet<>();
    HashSet<String> fileName = new HashSet<>();

    //----------------2 WAY-----------------------------
    String output_2way = "AB";

    public void twoWay_inputFileInit() {
        fileName.add("A");
        fileName.add("B");
    }


    /*
    test1
    A:                      | B:
    #ifdef X                |   void b();
    void a();               |
    #endif                  |
    */

    @Test
    public void test1() {
        twoWay_inputFileInit();
        config.add("X");
        String testNum = "1/";
System.out.println("------test 1-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
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
        twoWay_inputFileInit();
        config.add("X");
        String testNum = "2/";
        System.out.println("------test 2-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
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
        twoWay_inputFileInit();
        config.add("X");
        String testNum = "3/";
        System.out.println("------test 3-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }


    /*
 test4
 A:                      | B:
 #ifdef X                |   #ifdef X
 void a();               |   void b();
 #endif                  |   #endif
 */
    @Test
    public void test4() {
        twoWay_inputFileInit();
        config.add("X");
        String testNum = "4/";
        System.out.println("------test 4-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }

    /*
     test5
     A:                      | B:
     #ifdef X                |   #ifdef Y
     void a();               |   void b();
     #endif                  |   #endif
     */
    @Test
    public void test5() {
        twoWay_inputFileInit();
        config.add("X");
        config.add("Y");
        String testNum = "5/";
        System.out.println("------test 5-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }

    /*
         test6
         A:                      | B:
         #ifdef X                |
         void a();               |   void b();
         #endif                  |
         void b();
         */
    @Test
    public void test6() {
        twoWay_inputFileInit();
        config.add("X");
        String testNum = "6/";
        System.out.println("------test 6-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }
    /*
         test7
         A:                      | B:
         #ifdef X                |   #ifdef X
         void a();               |    void a();
         #endif                  |    void b();
         void b();               |   #endif
         */
    @Test
    public void test7() {
        twoWay_inputFileInit();
        config.add("X");
        String testNum = "7/";
        System.out.println("------test 7-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
        testInitial.clearTmpFile();
    }
}
