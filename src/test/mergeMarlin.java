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
//        File upstream = new File(main_repo);
//        File[] matches = upstream.listFiles(new FilenameFilter() {
//            public boolean accept(File dir, String name) {
//                return  name.endsWith(".cpp");
////                return name.endsWith(".h") || name.endsWith(".cpp");
//            }
//        });
//
//        for (File f : matches) {
//            mergedFiles.add(f.getName());
//        }


//        mergedFiles.add("LiquidCrystalRus.cpp");
        mergedFiles.add("SdVolume.cpp");


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
        HashSet<String> forkNames = inputFileInit();
        for (String fileToBeMerged : mergedFiles) {



           try {
                    File file = new File("testcpp/mergedResult/parseIFDEF.txt");

                    // if file doesnt exists, then create it
                    if (!file.exists()) {
                        file.createNewFile();
                    }
                    FileWriter fw = new FileWriter(file.getAbsoluteFile(), true);
                    BufferedWriter bw = new BufferedWriter(fw);
                    bw.write("\n------"+fileToBeMerged + "\n");
                    bw.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }




//            for (int i = 2; i <= 19; i++) {
            sleep();
            Set<Set<String>> combinationFiles = testInitial.getAllConfigurations(forkNames, 2);
            for (Set<String> combination : combinationFiles) {




               testInitial.checkMerge_wrapper4Marlin(path, combination, fileToBeMerged);

            }
//            }
        }

//        afterTest();
    }


}