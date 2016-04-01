package de.fosd.jdime.testJDimeCpp;

import de.fosd.jdime.dependencyGraph.AnalyzeMarlinRepo;
import org.junit.Ignore;
import org.junit.Test;

import java.util.ArrayList;

/**
 * Created by shuruiz on 2/14/16.
 */
public class testRComDetect {
    String projectPath = "/Users/shuruiz/Work/MarlinRepo/";
    ArrayList<String> commitList = new ArrayList<>();
    AnalyzeMarlinRepo amr = new AnalyzeMarlinRepo();

//    @Ignore
//    //https://github.com/gralco/MarlinDev/commit/7a37d34ff41097eada38db396c5c645282f3d442
//    @Test
//    public void test10() {
//        commitList.add("27ffdaf");
//        commitList.add("bf217f2");
//        commitList.add("af4cc61");
//        commitList.add("7a37d34");
//        String repo = "garlco";
//        int expectClusterNum = 2;
//        amr.analyzeMarlinRepo(repo, projectPath, commitList, expectClusterNum);
//    }
//
//    @Ignore
//    @Test
//    //https://github.com/gralco/Marlin/commit/038fccd
//    public void test11() {
//        String repo = "test11";
//        commitList.add("038fccd");
//        int expectClusterNum = 2;
//        amr.analyzeMarlinRepo(repo, projectPath, commitList, expectClusterNum);
//    }
//
//    @Ignore
//    @Test
//    //https://github.com/gralco/MarlinDev/commit/094afe7
//    /**
//     * bug
//     * SdFile.cpp
//     SdFileCPP-25
//     handleCallNode(DependencyGraph.java:1027)
//     */
//    public void test12() {
//        String repo = "test12";
//        commitList.add("094afe7");
//        int expectClusterNum = 2;
//        amr.analyzeMarlinRepo(repo, projectPath, commitList, expectClusterNum);
//    }
//
//    @Ignore
//    @Test
//    //https://github.com/MarlinFirmware/Marlin/commit/073e4af
//    public void test13() {
//        String repo = "test13";
//        commitList.add("073e4af");
//        int expectClusterNum = 2;
//        amr.analyzeMarlinRepo(repo, projectPath, commitList, expectClusterNum);
//    }
//
//    @Ignore
//    @Test
//    //https://github.com/MarlinFirmware/Marlin/commit/aad4b75
//    public void test14() {
//        String repo = "test14";
//        commitList.add("aad4b75");
//        int expectClusterNum = 2;
//        amr.analyzeMarlinRepo(repo, projectPath, commitList, expectClusterNum);
//    }
//
//    //Done!
//    @Ignore //1 ifdef
//    @Test
//    //https://github.com/MarlinFirmware/Marlin/commit/aacbebb
//    public void test15() {
//        String repo = "test15";
//        commitList.add("aacbebb");
//        int expectClusterNum = 1;
//        amr.analyzeMarlinRepo(repo, projectPath, commitList, expectClusterNum);
//    }
//
//    //Done!
//    @Ignore
//    @Test
//    //https://github.com/MarlinFirmware/Marlin/commit/aa65fe2
//    public void test16() {
//        String repo = "test16";
//        commitList.add("aa65fe2");
//        int expectClusterNum = 2;
//        amr.analyzeMarlinRepo(repo, projectPath, commitList, expectClusterNum);
//    }
//
//    @Ignore
//    @Test
//    //https://github.com/MarlinFirmware/Marlin/commit/fd1ea9d
//    public void test17() {
//        String repo = "test17";
//        commitList.add("fd1ea9d");
//        int expectClusterNum = 1;
//        amr.analyzeMarlinRepo(repo, projectPath, commitList, expectClusterNum);
//    }
//
//    @Ignore
//    @Test
//    //https://github.com/MarlinFirmware/Marlin/commit/fbd899a
//    public void test18() {
//        String repo = "test18";
//        commitList.add("fbd899a");
//        int expectClusterNum = 2;
//        amr.analyzeMarlinRepo(repo, projectPath, commitList, expectClusterNum);
//    }
//
//
//    @Ignore//https://github.com/MarlinFirmware/Marlin/commit/f40cff5
//    @Test
//    public void test19() {
//        String repo = "test19";
//        commitList.add("f40cff5");
//        int expectClusterNum = 2;
//        amr.analyzeMarlinRepo(repo, projectPath, commitList, expectClusterNum);
//    }
//
//    @Ignore
//    //https://github.com/MarlinFirmware/Marlin/commit/eea3ba5
//    @Test
//    public void test20() {
//        String repo = "test20";
//        commitList.add("eea3ba5");
//        int expectClusterNum = 2;
//        amr.analyzeMarlinRepo(repo, projectPath, commitList, expectClusterNum);
//    }
//
//    @Ignore
//    //https://github.com/MarlinFirmware/Marlin/commit/7c24b97
//    @Test
//    public void test21() {
//        String repo = "test20";
//        commitList.add("7c24b97");
//        int expectClusterNum = 1;
//        amr.analyzeMarlinRepo(repo, projectPath, commitList, expectClusterNum);
//    }

    // independent features
//@Ignore
    @Test
    public void test22() {
        String repo = "test22";
        ArrayList<String> macroList = new ArrayList<>();
        macroList.add("FILAMENT_SENSOR");
        macroList.add("MESH_BED_LEVELING");
        macroList.add("ADVANCE");
        macroList.add("HAS_BUZZER");
        macroList.add("PREVENT_DANGEROUS_EXTRUDE");
        commitList = new ArrayList<>();
        amr.analyzeMarlinRepo(repo, projectPath, commitList, macroList);
    }


    // nested last 2
    @Ignore
    @Test
    public void test23() {
        String repo = "test23";
        ArrayList<String> macroList = new ArrayList<>();
        macroList.add("FILAMENT_SENSOR");
        macroList.add("MESH_BED_LEVELING");
        macroList.add("ADVANCE");
        macroList.add("HAS_Z_MIN_PROBE");
        macroList.add("HAS_SERVO_ENDSTOPS");
        commitList = new ArrayList<>();
        amr.analyzeMarlinRepo(repo, projectPath, commitList, macroList);
    }
}
