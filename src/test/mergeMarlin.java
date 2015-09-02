package test;

import org.junit.Ignore;
import org.junit.Test;

import java.io.*;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import static org.junit.Assert.assertNotNull;

/**
 * Created by shuruiz on 7/26/15.
 */
public class mergeMarlin {
    String path = "testcpp/originMarlin/";
    String main_repo = "testcpp/originMarlin/upstream/Marlin/Marlin/";
    TestInitial testInitial = new TestInitial(path);
    HashSet<String> forkName = new HashSet<>();
    List<String> mergedFiles = new ArrayList<>();

    public HashSet<String> inputFileInit() {
        File upstream = new File(main_repo);
        File[] matches = upstream.listFiles(new FilenameFilter() {
            public boolean accept(File dir, String name) {
                return  name.endsWith(".cpp");
//                return name.endsWith(".h") || name.endsWith(".cpp");
            }
        });

        for (File f : matches) {
            mergedFiles.add(f.getName());
        }

        File dir = new File(path);
        String[] names = dir.list();
        for (String name : names) {
            if (new File(path + name).isDirectory()) {
                if (!name.equals("upstream")) {
                    forkName.add(name);
                }
            }

        }
        return forkName;
    }

    public HashSet<String> inputFileInit_1(){

//        mergedFiles.add("watchdog.cpp");
        File upstream = new File(main_repo);
        File[] matches = upstream.listFiles(new FilenameFilter() {
            public boolean accept(File dir, String name) {
                return  name.endsWith(".cpp");
//                return name.endsWith(".h") || name.endsWith(".cpp");
            }
        });

        for (File f : matches) {
            mergedFiles.add(f.getName());
        }

        forkName.add("yuroller");
//        forkName.add("marlin4Due");

        return forkName;
    }
    public void afterTest() {
        testInitial.clearTmpFile();
    }

    public static void sleep() {
        try {
            Thread.sleep(500);                 //1000 milliseconds is one second.
        } catch (InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
    }

    @Test
    public void NWayMerge_Rev() {
        HashSet<String> forkNames = inputFileInit_1();
//        HashSet<String> forkNames = inputFileInit();
        String testPath = "testcpp/mergedResult/countIfdef.txt";
        testInitial.writeTofile("!!!fork: "+forkNames.toArray()[0],testPath);

        for (String fileToBeMerged : mergedFiles) {

//            for (int i = 2; i <= 20; i++) {
            sleep();
            Set<Set<String>> combinationFiles = testInitial.getAllConfigurations(forkNames, 2);
            for (Set<String> combination : combinationFiles) {
                testInitial.writeTofile("\n\n**--**-**--merge: "+fileToBeMerged+"\n\n",testPath);

                testInitial.checkMerge_wrapper4Marlin(path, combination, fileToBeMerged);


            }
//            }
        }

//        afterTest();
    }


}