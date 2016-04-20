package de.fosd.jdime.testJDimeCpp;

import de.fosd.jdime.dependencyGraph.AnalyzeMarlinRepo;
import de.fosd.jdime.util.IOFunctionSet;
import org.junit.Ignore;
import org.junit.Test;
import org.rosuda.JRI.Rengine;

import java.io.File;
import java.util.ArrayList;

/**
 * Created by shuruiz on 4/3/16.
 */
public class testGroundTruthByIfdef {
    String projectPath = "/Users/shuruiz/Work/MarlinRepo/IfdefGroundTruth/";
    ArrayList<String> commitList = new ArrayList<>();
    AnalyzeMarlinRepo amr = new AnalyzeMarlinRepo();

    // independent features
    @Ignore
    @Test
    public void test10() {
        String repo= "Marlin";
        //start import R library
        System.out.println("Creating Rengine (with arguments)");
        //If not started with --vanilla, funny things may happen in this R shell.

        String[] Rargs = {"--vanilla"};
        Rengine re = new Rengine(Rargs, false, null);
        System.out.println("Rengine created, waiting for R");
        // the engine creates R is a new thread, so we should wait until it's
        // ready
        if (!re.waitForR()) {
            System.out.println("Cannot load R");
            return;
        }

        int dirNum = 888;
        ArrayList<String> macroList = new ArrayList<>();
        macroList.add("FILAMENT_SENSOR");
        macroList.add("MESH_BED_LEVELING");
        macroList.add("ADVANCE");
//        macroList.add("HAS_BUZZER");
        macroList.add("PREVENT_DANGEROUS_EXTRUDE");

        StringBuffer sb = new StringBuffer();
        for (int i = 1; i <= macroList.size(); i++) {
            sb.append("<h3>" + i + ") " + macroList.get(i - 1) + "</h3>\n");
        }

       String analysisDir = projectPath + repo + "/DPGraph/";
        new File(analysisDir + dirNum).mkdir();
        IOFunctionSet iof=new IOFunctionSet();
        iof.rewriteFile(sb.toString(), analysisDir + dirNum + "/testedMacros.txt");


        commitList = new ArrayList<>();
        int numOfIteration = 5;
        amr.analyzeRepository(repo, dirNum, projectPath, commitList, macroList, numOfIteration, re);
    }


    //marlin
    @Ignore
    @Test
    public void test11() {
        String repo= "Marlin";
        //start import R library
        System.out.println("Creating Rengine (with arguments)");
        //If not started with --vanilla, funny things may happen in this R shell.

        String[] Rargs = {"--vanilla"};
        Rengine re = new Rengine(Rargs, false, null);
        System.out.println("Rengine created, waiting for R");
        // the engine creates R is a new thread, so we should wait until it's
        // ready
        if (!re.waitForR()) {
            System.out.println("Cannot load R");
            return;
        }

        int dirNum = 999;
        ArrayList<String> macroList = new ArrayList<>();
        macroList.add("FILAMENT_SENSOR");
        macroList.add("MESH_BED_LEVELING");
        macroList.add("ADVANCE");
        macroList.add("HAS_Z_MIN_PROBE");
        macroList.add("HAS_SERVO_ENDSTOPS");

        commitList = new ArrayList<>();
        int numOfcut = 3;
        amr.analyzeRepository(repo, dirNum, projectPath, commitList, macroList, numOfcut, re);
    }


    //marlin
//    @Ignore
    @Test
    public void test12() {
        String repo= "Marlin";
        //start import R library
        System.out.println("Creating Rengine (with arguments)");
        //If not started with --vanilla, funny things may happen in this R shell.

        String[] Rargs = {"--vanilla"};
        Rengine re = new Rengine(Rargs, false, null);
        System.out.println("Rengine created, waiting for R");
        // the engine creates R is a new thread, so we should wait until it's
        // ready
        if (!re.waitForR()) {
            System.out.println("Cannot load R");
            return;
        }

        int dirNum = 332;
        ArrayList<String> macroList = new ArrayList<>();
        macroList.add("Z_PROBE_ALLEN_KEY");
//        macroList.add("SD_DETECT_INVERTED");
//        macroList.add("LCD_USE_I2C_BUZZER");
//        macroList.add("THERMAL_PROTECTION_HOTENDS");
        macroList.add("ULTRA_LCD");
        StringBuffer sb = new StringBuffer();
        for (int i = 1; i <= macroList.size(); i++) {
            sb.append("<h3>" + i + ") " + macroList.get(i - 1) + "</h3>\n");
        }
        String analysisDir = projectPath + repo + "/DPGraph/";
        new File(analysisDir + dirNum).mkdir();
        IOFunctionSet iof=new IOFunctionSet();
        iof.rewriteFile(sb.toString(), analysisDir + dirNum + "/testedMacros.txt");

        commitList = new ArrayList<>();
        int numOfcut = 6;
        amr.analyzeRepository(repo, dirNum, projectPath, commitList, macroList, numOfcut, re);
    }


            @Ignore
    //email system
    @Test
    public void test13() {
        String repo= "Email";
        //start import R library
        System.out.println("Creating Rengine (with arguments)");
        //If not started with --vanilla, funny things may happen in this R shell.

        String[] Rargs = {"--vanilla"};
        Rengine re = new Rengine(Rargs, false, null);
        System.out.println("Rengine created, waiting for R");
        // the engine creates R is a new thread, so we should wait until it's
        // ready
        if (!re.waitForR()) {
            System.out.println("Cannot load R");
            return;
        }

        int dirNum = 111;
        ArrayList<String> macroList = new ArrayList<>();


        commitList = new ArrayList<>();
        int numOfcut = 6;
        amr.analyzeRepository(repo, dirNum, projectPath, commitList, macroList, numOfcut, re);
    }

            @Ignore
    //Apache
    @Test
    public void test14() {
        String repo= "Apache";
        //start import R library
        System.out.println("Creating Rengine (with arguments)");
        //If not started with --vanilla, funny things may happen in this R shell.

        String[] Rargs = {"--vanilla"};
        Rengine re = new Rengine(Rargs, false, null);
        System.out.println("Rengine created, waiting for R");
        // the engine creates R is a new thread, so we should wait until it's
        // ready
        if (!re.waitForR()) {
            System.out.println("Cannot load R");
            return;
        }

        int dirNum = 55;
        ArrayList<String> macroList = new ArrayList<>();


        commitList = new ArrayList<>();
        int numOfcut = 6;
        amr.analyzeRepository(repo, dirNum, projectPath, commitList, macroList, numOfcut, re);
    }

}
