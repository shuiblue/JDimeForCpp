package test;

import org.junit.Test;

import java.util.HashSet;

import static org.junit.Assert.assertTrue;

/**
 * Created by shuruiz on 7/23/15.
 */
public class functionBody {

    String path = "testcpp/functionBody/";
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
    void a() {              |   void a(){
    i=0;                    |     i=0;
     }                      |     j=0;
                            |  }
    */

    @Test
    public void test1() {
        inputFileInit(2);
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
    void a() {              |   void a(){
    i=0;                    |     i=2;
     }                      |     j=0;
                            |  }
*/
    @Test
    public void test2() {
        inputFileInit(2);
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
   void a() {              |   void a(){
   i=0;                    |     i=2;
    }                      |     j=0;
                           |  }
*/
    @Test
    public void test3() {
        inputFileInit(2);
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
 int x=0;                |
 void a() {              |   void a(){
 i=0;                    |     i=1;
  }                      |
                         |  }
*/
    @Test
    public void test4() {
        inputFileInit(2);
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
 int x=0;                |
 void a() {              |   void a(){
 #ifdef X                |
 i=0;                    |     i=1;
 #endif                  |
 j=2            ;        |   }

*/
    @Test
    public void test5() {
        inputFileInit(2);
        config.add("X");
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
 int x=0;                |
 int y=0;
 void a() {              |   void a(){
 #ifdef X                |
 i=0;                    |     i=1;
 #endif                  |
 j=2            ;        |   }

*/
    @Test
    public void test6() {
        inputFileInit(2);
        config.add("X");
        String testNum = "6/";
        System.out.println("------test6-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }
    /*
test7
A:                      | B:
int x=0;                |
int y=0;
void a() {              |   void a(){
i=0;                    |     i=1;
}                       |   }
void aa(){              |
j=1 ;                   |
}

*/
    @Test
    public void test7() {
        inputFileInit(2);
        String testNum = "7/";
        System.out.println("------test7-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }
    /*
test8
A:                      | B:
int x=0;                |
int y=0;
void a() {              |   void a(){
i=0;                    |     i=1;
}                       |   }
int z=0;
void aa(){              |
j=1 ;                   |
}

*/
    @Test
    public void test8() {
        inputFileInit(2);
        String testNum = "8/";
        System.out.println("------test8-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));

    }
    /*
test9
A:                      | B:
int x=0;                |
int y=0;                |   int x=0;
void a() {              |   void a(){
i=0;                    |     i=1;
}                       |   }
int z=0;
void aa(){              |
j=1 ;                   |
}

*/
    @Test
    public void test9() {
        inputFileInit(2);
        String testNum = "9/";
        System.out.println("------test9-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
//        afterTest();
    }

    /*
test11
A:                      | B:
void a()  {             | void b()  {
i=0;                    | i=0;
}                       |}

*/
    @Test
    public void test11() {
        inputFileInit(2);
        String testNum = "11/";
        System.out.println("------test11-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
        afterTest();
    }
}
