package de.fosd.jdime.testJDimeCpp;

import org.junit.Test;

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
        mergedFiles.add("ConfigurationStore.cpp");
        for (String fileToBeMerged : mergedFiles) {
            ArrayList<String> inputFilePaths = new ArrayList<>();
            inputFilePaths.add(path+forkName+upstreamBeforeMerge+fileToBeMerged+"+upstreamBeforeMerge");
            inputFilePaths.add(path+forkName+forkBeforeMerge+fileToBeMerged+"+forkBeforeMerge");
            System.out.println("NOW: "+fileToBeMerged);
            testInitial.mergePullRQ(path, inputFilePaths,forkName,fileToBeMerged);
        }
    }

    @Test
    public void mocPullReq_10() {
        mergePR("wgm4321");

    }
}