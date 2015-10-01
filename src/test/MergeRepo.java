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

    public HashSet<String> inputFileInit() {
//        File upstream = new File(main_repo);
//        File[] matches = upstream.listFiles(new FilenameFilter() {
//            public boolean accept(File dir, String name) {
//                return name.endsWith(".cpp");
////                return name.endsWith(".h") || name.endsWith(".cpp");
//            }
//        });

//        for (File f : matches) {
//            if(!f.getName().equals("fastio.h")||f.getName().contains("language")) {
//                mergedFiles.add(f.getName());
//            }
//
//        }
        File dir = new File(path);
        String[] names = dir.list();
        for (String name : names) {
            if (new File(path + name).isDirectory()) {
                if (!name.equals("upstream")) {
                    forkName.add(name);
                }
            }

        }
mergedFiles.add("language.h");

        forkName.add("drsdre");
        return forkName;
    }


    @Test
    public void NWayMerge_Rev() {
        HashSet<String> forkNames = inputFileInit();
        for (String fork : forkNames) {

            for (String fileToBeMerged : mergedFiles) {
                testInitial.checkMergeRepo(path, fork, fileToBeMerged);
            }
        }

//         Set<Set<String>> combinationFiles = testInitial.getAllConfigurations(forkNames, 3);
//        for (Set<String> combination : combinationFiles) {
//            for (String fileToBeMerged : mergedFiles) {
//                testInitial.checkMergeRepo(path, combination, fileToBeMerged);
//
//            }
//        }
    }
}