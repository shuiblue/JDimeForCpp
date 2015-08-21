package test;

import org.junit.Ignore;
import org.junit.Test;

import java.io.File;
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
    TestInitial testInitial = new TestInitial(path);
    HashSet<String> forkName = new HashSet<>();
    List<String> mergedFiles = new ArrayList<>();

    public HashSet<String> inputFileInit() {
        mergedFiles.add("cardreader");
//        mergedFiles.add("Marlin_main");
//        mergedFiles.add("BlinkM");
//        mergedFiles.add("ConfigurationStore");
//        mergedFiles.add("digipot_mcp4451");
//        mergedFiles.add("LiquidCrystalRus");
//        mergedFiles.add("MarlinSerial");
//        mergedFiles.add("motion_control");
//        mergedFiles.add("planner");
//        mergedFiles.add("qr_solve");
//        mergedFiles.add("Sd2Card");
//        mergedFiles.add("SdFatUtil");
//        mergedFiles.add("SdBaseFile");
//        mergedFiles.add("SdFile");
//        mergedFiles.add("SdVolume");
//        mergedFiles.add("stepper");
//        mergedFiles.add("Servo");
//        mergedFiles.add("ultralcd");
//        mergedFiles.add("watchdog");
//        mergedFiles.add("vector_3");

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
        try {
            Thread.sleep(10);                 //1000 milliseconds is one second.
        } catch (InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
        testInitial.clearTmpFile();
    }

    public static void sleep() {
        try {
            Thread.sleep(500);                 //1000 milliseconds is one second.
        } catch (InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
    }


    //    @Ignore
    @Test
    public void NWayMerge() {
        HashSet<String> forkNames = inputFileInit();
        for (String fileToBeMerged : mergedFiles) {
//            for (int i = 2; i <= 4; i++) {
            sleep();
            Set<Set<String>> combinationFiles = testInitial.getAllConfigurations(forkNames, 5);
            for (Set<String> combination : combinationFiles) {
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, combination, fileToBeMerged));

//            }
            }
        }

//        afterTest();
    }

    @Ignore
    @Test
    public void testCardReader() {
        String mergedFile = "cardreader";
        HashSet<String> forkNames = inputFileInit();
        for (int i = 2; i <= 4; i++) {
            sleep();
            Set<Set<String>> combinationFiles = testInitial.getAllConfigurations(forkNames, i);
            for (Set<String> combination : combinationFiles) {
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, combination, mergedFile));
            }
        }
    }


    @Ignore
    @Test
    public void testMarlinMain() {
        String mergedFile = "Marlin_main";
        HashSet<String> forkNames = inputFileInit();

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile) != null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }


    @Ignore
    @Test
    public void testBlinkM() {
        String mergedFile = "BlinkM";
        HashSet<String> forkNames = inputFileInit();

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile) != null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }


    @Ignore
    @Test
    public void testConfigurationStore() {
        String mergedFile = "ConfigurationStore";
        HashSet<String> forkNames = inputFileInit();

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile) != null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }


    @Ignore
    @Test
    public void testdigipot_mcp4451() {
        String mergedFile = "digipot_mcp4451";
        HashSet<String> forkNames = inputFileInit();

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile) != null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }


    @Ignore
    @Test
    public void testLiquidCrystalRus() {
        String mergedFile = "LiquidCrystalRus";
        HashSet<String> forkNames = inputFileInit();

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile) != null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }


    @Ignore
    @Test
    public void testMarlinSerial() {
        String mergedFile = "MarlinSerial";
        HashSet<String> forkNames = inputFileInit();

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile) != null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }


    @Ignore
    @Test
    public void testmotion_control() {
        String mergedFile = "motion_control";
        HashSet<String> forkNames = inputFileInit();

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile) != null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }


    @Ignore
    @Test
    public void testplanner() {
        String mergedFile = "planner";
        HashSet<String> forkNames = inputFileInit();

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile) != null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }


    @Ignore
    @Test
    public void testqr_solve() {
        String mergedFile = "qr_solve";
        HashSet<String> forkNames = inputFileInit();

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile) != null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }


    @Ignore
    @Test
    public void testSd2Card() {
        String mergedFile = "Sd2Card";
        HashSet<String> forkNames = inputFileInit();

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile) != null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }


    @Ignore
    @Test
    public void testSdBaseFile() {
        String mergedFile = "SdBaseFile";
        HashSet<String> forkNames = inputFileInit();

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile) != null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }


    @Ignore
    @Test
    public void testSdFatUtil() {
        String mergedFile = "SdFatUtil";
        HashSet<String> forkNames = inputFileInit();

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile) != null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }


    @Ignore
    @Test
    public void testSdFile() {
        String mergedFile = "SdFile";
        HashSet<String> forkNames = inputFileInit();

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile) != null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }


    @Ignore
    @Test
    public void testSdVolume() {
        String mergedFile = "SdVolume";
        HashSet<String> forkNames = inputFileInit();

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile) != null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }


    @Ignore
    @Test
    public void testServo() {
        String mergedFile = "Servo";
        HashSet<String> forkNames = inputFileInit();

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile) != null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }


    @Ignore
    @Test
    public void teststepper() {
        String mergedFile = "stepper";
        HashSet<String> forkNames = inputFileInit();

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile) != null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }
//  @Ignore  @Test
//    public void testtemperature() {
//        String mergedFile = "temperature";
//        HashSet<String> forkNames = inputFileInit(mergedFile);
//
//        // ----------------check Merged result equal to expect result
//        for (String fork : forkNames) {
//            sleep();
//            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");
//
//
//            if (!fork.equals("upstream")) {
//                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile)!=null);
//                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
//            }
//        }
//    }


    @Ignore
    @Test
    public void testultralcd() {
        String mergedFile = "ultralcd";
        HashSet<String> forkNames = inputFileInit();

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile) != null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }


    @Ignore
    @Test
    public void testvector_3() {
        String mergedFile = "vector_3";
        HashSet<String> forkNames = inputFileInit();

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile) != null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }

    ///!!!!!

    @Ignore
    @Test
    public void testwatchdog() {
        String mergedFile = "watchdog";
        HashSet<String> forkNames = inputFileInit();

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile) != null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }
}
