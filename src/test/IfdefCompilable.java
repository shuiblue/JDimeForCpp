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

    public void afterTest() {
        try {
            Thread.sleep(10);                 //1000 milliseconds is one second.
        } catch (InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
        testInitial.clearTmpFile();

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


    //----------------2 WAY- if ndef----------------------------
 /*
         test12
         A:                      | B:
         #ifndef X                |
         void a();               |   void b();
         #endif                  |

         */
    @Test
    public void test12() {
        inputFileInit(2);
        config.add("X");
        String testNum = "12/";
        System.out.println("------test 12-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }

    /*
        test13
        A:                      | B:
        #ifndef X               |
        void a();               |   void a();
        #endif                  |
        */
    @Test
    public void test13() {
        inputFileInit(2);
        config.add("X");
        String testNum = "13/";
        System.out.println("------test 13-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }

    /*
        test14
        A:                      | B:
        #ifndef X               |   #ifdef Y
        void a();               |   void b();
        #endif                  |   #endif
        */
    @Test
    public void test14() {
        inputFileInit(2);
        config.add("X");
        config.add("Y");
        String testNum = "14/";
        System.out.println("------test 14-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }

    /*
       test15
       A:                      | B:
       #ifndef X               |   #ifdef X
       void a();               |   void b();
       #endif                  |   #endif
       */
    @Test
    public void test15() {
        inputFileInit(2);
        config.add("X");
        String testNum = "15/";
        System.out.println("------test 15-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }
    //----------------if defined " && " ----------------------------

    /*
   test16
   A:                                  | B:
   #if defined (X) && defined(Y)       |
   void a();                           |   void b();
   #endif                              |
   */
    @Test
    public void test16() {
        inputFileInit(2);
        config.add("X");
        config.add("Y");

        String testNum = "16/";
        System.out.println("------test 16-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }

    /*
test17
A:                                  | B:
#if defined (X) && defined(Y)       |  #if defined (Z)
void a();                           |   void b();
#endif                              |  #endif
*/
    @Test
    public void test17() {
        inputFileInit(2);
        config.add("X");
        config.add("Y");
        config.add("Z");
        String testNum = "17/";
        System.out.println("------test 17-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }

    /*
test18
A:                                  | B:
#if defined (X) && !defined(Y)      |  #if defined (Z)
void a();                           |   void b();
#endif                              |  #endif
*/
    @Test
    public void test18() {
        inputFileInit(2);
        config.add("X");
        config.add("Y");
        config.add("Z");
        String testNum = "18/";
        System.out.println("------test 18-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }


//----------------if defined " || " ----------------------------

    /*
test16
A:                                  | B:
#if defined (X) && defined(Y)       |
void a();                           |   void b();
#endif                              |
*/
    @Test
    public void test19() {
        inputFileInit(2);
        config.add("X");
        config.add("Y");

        String testNum = "19/";
        System.out.println("------test 19-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }


}
