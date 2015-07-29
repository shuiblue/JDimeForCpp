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
 i=0;                    |     i=2;
  }                      |     j=0;
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

}
