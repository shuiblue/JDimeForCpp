package test;
<<<<<<< origin/develop

=======
>>>>>>> HEAD~64
import org.junit.Test;

import java.util.HashSet;

<<<<<<< origin/develop
import static org.junit.Assert.assertTrue;
=======
import static org.junit.Assert.assertNotNull;
>>>>>>> HEAD~64

/**
 * Created by shuruiz on 7/26/15.
 */
public class mergeMarlin {
    String path = "testcpp/Marlin/cardreader/";
    TestInitial testInitial = new TestInitial(path);
<<<<<<< origin/develop
    HashSet<String> config = new HashSet<>();
    HashSet<String> fileName = new HashSet<>();
=======
    HashSet<String> forkName = new HashSet<>();

    public HashSet<String> inputFileInit(String mergedFile) {
        File dir = new File(path);
        String[] names = dir.list();
        for (String name : names) {
            if (new File(path + name).isDirectory()) {
                forkName.add(name);

            }
>>>>>>> HEAD~64

    public void inputFileInit(int i) {
        char A = 'A';
        fileName.add("A");
        for (int j = 1; j < i; j++) {
            fileName.add(String.valueOf(++A));
        }
    }

    public void afterTest() {
        try {
            Thread.sleep(10);                 //1000 milliseconds is one second.
        } catch (InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
        testInitial.clearTmpFile();
    }

<<<<<<< origin/develop
    String output_2way = "AB";
    String output_3way = "ABC";
=======
    public static void sleep() {
        try {
            Thread.sleep(200);                 //1000 milliseconds is one second.
        } catch (InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
    }

    @Test
    public void testCardReader() {
        String mergedFile = "cardreader";
        HashSet<String> forkNames = inputFileInit(mergedFile);

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile)!=null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }
>>>>>>> HEAD~64

    /*
    test 1
    main repo: cardreader.cpp ---A
    ut7: -- B

<<<<<<< origin/develop
     */
=======
    @Test
    public void testMarlinMain() {
        String mergedFile = "Marlin_main";
        HashSet<String> forkNames = inputFileInit(mergedFile);

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile)!=null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }

    @Test
    public void testBlinkM() {
        String mergedFile = "BlinkM";
        HashSet<String> forkNames = inputFileInit(mergedFile);

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile)!=null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }

    @Test
    public void testConfigurationStore() {
        String mergedFile = "ConfigurationStore";
        HashSet<String> forkNames = inputFileInit(mergedFile);

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile)!=null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }
    @Test
    public void testdigipot_mcp4451() {
        String mergedFile = "digipot_mcp4451";
        HashSet<String> forkNames = inputFileInit(mergedFile);

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile)!=null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }

    @Test
    public void testLiquidCrystalRus() {
        String mergedFile = "LiquidCrystalRus";
        HashSet<String> forkNames = inputFileInit(mergedFile);

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile)!=null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }
    @Test
    public void testMarlinSerial() {
        String mergedFile = "MarlinSerial";
        HashSet<String> forkNames = inputFileInit(mergedFile);

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile)!=null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }
    @Test
    public void testmotion_control() {
        String mergedFile = "motion_control";
        HashSet<String> forkNames = inputFileInit(mergedFile);

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile)!=null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }


    @Test
    public void testplanner() {
        String mergedFile = "planner";
        HashSet<String> forkNames = inputFileInit(mergedFile);

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile)!=null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }
    @Test
    public void testqr_solve() {
        String mergedFile = "qr_solve";
        HashSet<String> forkNames = inputFileInit(mergedFile);

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile)!=null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }
    @Test
    public void testSd2Card() {
        String mergedFile = "Sd2Card";
        HashSet<String> forkNames = inputFileInit(mergedFile);

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile)!=null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }
    @Test
    public void testSdBaseFile() {
        String mergedFile = "SdBaseFile";
        HashSet<String> forkNames = inputFileInit(mergedFile);

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile)!=null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }
    @Test
    public void testSdFatUtil() {
        String mergedFile = "SdFatUtil";
        HashSet<String> forkNames = inputFileInit(mergedFile);

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile)!=null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }
    @Test
    public void testSdFile() {
        String mergedFile = "SdFile";
        HashSet<String> forkNames = inputFileInit(mergedFile);

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile)!=null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }
    @Test
    public void testSdVolume() {
        String mergedFile = "SdVolume";
        HashSet<String> forkNames = inputFileInit(mergedFile);

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile)!=null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }
    @Test
    public void testServo() {
        String mergedFile = "Servo";
        HashSet<String> forkNames = inputFileInit(mergedFile);

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile)!=null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }
    @Test
    public void teststepper() {
        String mergedFile = "stepper";
        HashSet<String> forkNames = inputFileInit(mergedFile);

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile)!=null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }
    @Test
    public void testtemperature() {
        String mergedFile = "temperature";
        HashSet<String> forkNames = inputFileInit(mergedFile);

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile)!=null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }
    @Test
    public void testultralcd() {
        String mergedFile = "ultralcd";
        HashSet<String> forkNames = inputFileInit(mergedFile);

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile)!=null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }
    @Test
    public void testvector_3() {
        String mergedFile = "vector_3";
        HashSet<String> forkNames = inputFileInit(mergedFile);

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile)!=null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }
    @Test
    public void testwatchdog() {
        String mergedFile = "watchdog";
        HashSet<String> forkNames = inputFileInit(mergedFile);

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            sleep();
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");
>>>>>>> HEAD~64


    @Test
    public void test1() {
        inputFileInit(2);
        String testNum = "1/";
        config.add("SDSUPPORT");
        System.out.println("------test 1-----------");
        // ----------------check Merged result equal to expect result
        assertTrue(testInitial.checkMerge_wrapper(fileName, testNum, output_2way));
        // ----------------check preprocessed Merged result equal to origin
        assertTrue(testInitial.testEveryConfig(config, fileName, output_2way, path, testNum));
    }
}
