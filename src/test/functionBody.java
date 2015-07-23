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


    //----------------2 WAY-----------------------------
    String output_2way = "AB";
    /*
    test1
    A:                      | B:
    void a(){               |
      int a=1;              |
     }                      |   void b();
                            |
    */

    @Test
    public void test1() {
        fileName = testInitial.inputFileInit(2);
        config.add("X");
        String testNum = "1/";
        System.out.println("------test 1-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }

}
