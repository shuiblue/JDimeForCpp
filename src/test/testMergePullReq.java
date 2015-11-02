package test;

import org.junit.Test;

import java.io.File;
import java.io.FilenameFilter;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by shuruiz on 9/20/15.
 */
public class testMergePullReq {
    String path = "testcpp/testMergePullReq/";
    String upstreamBeforeMerge = "/upstreamBeforeMerge/Marlin/Marlin/";
    String forkBeforeMerge = "/forkBeforeMerge/Marlin/Marlin/";
    TestInitial testInitial = new TestInitial(path);
    List<String> mergedFiles = new ArrayList<>();

    public void mergePR(String forkName) {
//        File upstream = new File(path+forkName+upstreamBeforeMerge);
//        File[] matches = upstream.listFiles(new FilenameFilter() {
//            public boolean accept(File dir, String name) {
//                return name.endsWith(".h") || name.endsWith(".cpp");
//            }
//        });
//
//        for (File f : matches) {
//            if(!f.getName().equals("fastio.h")||f.getName().contains("language")||f.getName().contains("pins")) {
//                mergedFiles.add(f.getName());
//            }
//        }

//<<<<<<< HEAD
//        mergedFiles.add("pins.h");
//=======
        mergedFiles.add("ConfigurationStore.cpp");
//>>>>>>> countIfdef


        for (String fileToBeMerged : mergedFiles) {
            ArrayList<String> inputFilePaths = new ArrayList<>();
            inputFilePaths.add(path+forkName+upstreamBeforeMerge+fileToBeMerged+"+upstreamBeforeMerge");
            inputFilePaths.add(path+forkName+forkBeforeMerge+fileToBeMerged+"+forkBeforeMerge");
            System.out.println("NOW: "+fileToBeMerged);
//<<<<<<< HEAD
//                testInitial.mergePullRQ(path, inputFilePaths,forkName,fileToBeMerged);
//            }
//=======
            testInitial.mergePullRQ(path, inputFilePaths,forkName,fileToBeMerged);
        }
//>>>>>>> countIfdef


    }

    @Test
    public void mocPullReq_10() {
        mergePR("wgm4321");

    }

//<<<<<<< HEAD
//}
//=======
}
//>>>>>>> countIfdef
