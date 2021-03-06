package test;

import de.fosd.jdime.util.IOFunctionSet;
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
                return name.endsWith(".cpp");
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


    public void afterTest() {
        testInitial.clearTmpFile();
    }

    @Ignore
    @Test
    public void NWayMerge_Rev() {

        HashSet<String> forkNames = inputFileInit();

//        for (String fileToBeMerged : mergedFiles) {
//            for (int i = 2; i <= 20; i++) {
        Set<Set<String>> combinationFiles = testInitial.getAllConfigurations(forkNames, 2);
        for (Set<String> combination : combinationFiles) {
            for (String fileToBeMerged : mergedFiles) {
                testInitial.checkMerge_wrapper4Marlin(path, combination, fileToBeMerged);
            }
        }
    }

    @Test
    public void twoWayMerge() {
        HashSet<String> forkNames = inputFileInit();
        for(String s:forkNames){
            Set<String> combination = new HashSet<>();
            combination.add(s);
            for (String fileToBeMerged : mergedFiles) {
                testInitial.checkMerge_wrapper4Marlin(path, combination, fileToBeMerged);
            }
        }
    }

}