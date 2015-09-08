package test;

import org.junit.Test;

import java.io.File;
import java.io.FilenameFilter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * Created by shuruiz on 9/7/15.
 */
public class MergeRepo {
    String path = "testcpp/originMarlin/";
    String main_repo = "testcpp/originMarlin/upstream/Marlin/Marlin/";
    TestInitial testInitial = new TestInitial(path);
    HashSet<String> forkName = new HashSet<>();
    List<String> mergedFiles = new ArrayList<>();

    public HashSet<String> inputFileInit_1() {

        mergedFiles.add("pins.h");
//        mergedFiles.add("Configuration.h");
//        File upstream = new File(main_repo);
//        File[] matches = upstream.listFiles(new FilenameFilter() {
//            public boolean accept(File dir, String name) {
//                return name.endsWith(".h");
////                return name.endsWith(".h") || name.endsWith(".cpp");
//            }
//        });
//
//        for (File f : matches) {
//            if(!f.getName().equals("fastio.h")||f.getName().equals("language.h")) {
//                mergedFiles.add(f.getName());
//            }
//        }
        forkName.add("upstreamAlromh87");
        forkName.add("alromh87");
        return forkName;
    }

    @Test
    public void NWayMerge_Rev() {

//        HashSet<String> forkNames = inputFileInit();
        HashSet<String> forkNames = inputFileInit_1();
//        for (String fileToBeMerged : mergedFiles) {
//            for (int i = 2; i <= 20; i++) {

        Set<Set<String>> combinationFiles = testInitial.getAllConfigurations(forkNames, 3);
        for (Set<String> combination : combinationFiles) {
            for (String fileToBeMerged : mergedFiles) {
                testInitial.checkMergeRepo(path, combination, fileToBeMerged);
            }

//            }
        }
    }
}