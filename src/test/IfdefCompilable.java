package test;

import org.junit.Test;

import java.util.HashSet;

import static org.junit.Assert.assertTrue;

/**
 * Created by shuruiz on 7/19/15.
 */
public class IfdefCompilable {
    String path = "testcpp/IFDEF/forCompile/";
    TestInitial testInitial = new TestInitial(path);
    HashSet<String> config = new HashSet<>();
    HashSet<String> fileName = new HashSet<>();

    public void inputFileInit(int i) {
        char A = 'A';
        fileName.add("A");
        for (int j = 1; j < i; j++) {
            fileName.add(String.valueOf(++A));
        }
    }

    //----------------2 WAY-----------------------------
    String output_2way = "AB";
    /*
    test1
    A:                      | B:
    #ifdef X                |   void b();
    void a();               |
    #endif                  |
    */

    @Test
    public void test1() {
        inputFileInit(2);
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
        inputFileInit(2);
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
        inputFileInit(2);
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
        inputFileInit(2);
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
        inputFileInit(2);
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
        inputFileInit(2);
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
        inputFileInit(2);
        config.add("X");
        String testNum = "7/";
        System.out.println("------test 7-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }

    /*
        test8
        A:                      | B:
        #ifdef X                |   #ifdef X
        void a();               |   void a();
        #endif                  |   #endif
        void b();               |   void c();
     */
    @Test
    public void test8() {
        inputFileInit(2);
        config.add("X");
        String testNum = "8/";
        System.out.println("------test 8-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }

    /*
           test9
           A:                      | B:
           #ifdef X                |   #ifdef X
           void a();               |    void a();
           #endif                  |   #endif
           void b();               |   #ifdef Y
                                   |     void b();
                                   |   #endif
           */
    @Test
    public void test9() {
        inputFileInit(2);
        config.add("X");
        config.add("Y");
        String testNum = "9/";
        System.out.println("------test 9-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
        afterTest();
    }

    //----------------3 WAY-----------------------------
    String output_3way = "ABC";

    /*
          test10
          A:                      | B:              | C:
          #ifdef X                |   #ifdef X      |   c();
          void a();               |    void a();    |
          #endif                  |   #endif        |
          void b();               |                 |
                                  |                 |
                                  |                 |
          */
    @Test
    public void test10() {
        inputFileInit(3);
        config.add("X");
        String testNum = "10/";
        System.out.println("------test 10-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_3way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_3way, path, testNum));
    }
    /*
             test11
             A:                      | B:              | C:
             #ifdef X                |   #ifdef X      |   #ifdef Y
             void a();               |    void a();    |    void c
             #endif                  |   #endif        |   #endif
             void b();               |                 |
                                     |                 |
                                     |                 |
             */
    @Test
    public void test11() {
        inputFileInit(3);
        config.add("X");
        String testNum = "11/";
        System.out.println("------test 11-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_3way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_3way, path, testNum));
    }


    public void afterTest() {
        try {
            Thread.sleep(10);                 //1000 milliseconds is one second.
        } catch (InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
        testInitial.clearTmpFile();

    }
}
