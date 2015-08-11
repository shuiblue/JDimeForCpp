package test;

import org.junit.Test;

import java.util.HashSet;

import static org.junit.Assert.assertTrue;

/**
 * Created by shuruiz on 7/26/15.
 */
public class mergeMarlin {
    String path = "testcpp/Marlin/cardreader/";
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

    String output_2way = "AB";
    String output_3way = "ABC";

    /*
    test 1
    main repo: cardreader.cpp ---A
    ut7: -- B

     */


    @Test
    public void test1() {
        inputFileInit(2);
        String testNum = "1/";
        config.add("SDSUPPORT");
        System.out.println("------test 1-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }
}
