package test;

import org.junit.Ignore;
import org.junit.Test;

import java.util.ArrayList;
import java.util.HashSet;

import static org.junit.Assert.assertTrue;

/**
 * Created by shuruiz on 7/28/15.
 */
public class testMarlin {
    ArrayList<String> paths = new ArrayList<>();
//    String path = "testcpp/Marlin/cardreader/2way/";
//    TestInitial testInitial = new TestInitial(path);
    HashSet<String> config = new HashSet<>();
    HashSet<String> fileName = new HashSet<>();

    public void inputFileInit(int i) {


        char A = 'A';
        fileName.add("A");
        for (int j = 1; j < i; j++) {
            fileName.add(String.valueOf(++A));
        }
    }

//    public void afterTest() {
//        try {
//            Thread.sleep(10);                 //1000 milliseconds is one second.
//        } catch (InterruptedException ex) {
//            Thread.currentThread().interrupt();
//        }
//        testInitial.clearTmpFile();
//
//    }

    //----------------2 WAY-----------------------------
    String output_2way = "AB";
  /*
A : upstream
B : ut7
  */
@Ignore
    @Test
    public void testCardReader() {
        String path = "testcpp/Marlin/cardreader/2way/";
        TestInitial testInitial = new TestInitial(path);
        inputFileInit(2);
        String testNum = "1/";
        System.out.println("------test 1-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }
    @Test
    public void test2() {
        String path = "testcpp/Marlin/ConfigurationStore/2way/";
        TestInitial testInitial = new TestInitial(path);
        inputFileInit(2);
        String testNum = "1/";
        System.out.println("------test 2-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }
@Ignore
    @Test
    public void test3() {
        String path = "testcpp/Marlin/Marlin_main/2way/";
        TestInitial testInitial = new TestInitial(path);
        inputFileInit(2);
        String testNum = "1/";
        System.out.println("------test 3-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }
@Ignore
    @Test
    public void test4() {
        String path = "testcpp/Marlin/planner/2way/";
        TestInitial testInitial = new TestInitial(path);
        inputFileInit(2);
        String testNum = "1/";
        System.out.println("------test 4-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }
}
