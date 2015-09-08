package test;
import de.fosd.jdime.util.IOFunctionSet;
import org.junit.Test;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
/**
 * Created by shuruiz on 9/8/15.
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
        String filePath;
//        HashSet<String> forkNames = inputFileInit();
        HashSet<String> forkNames = inputFileInit_1();
//        for (String fileToBeMerged : mergedFiles) {
//            for (int i = 2; i <= 20; i++) {

        Set<Set<String>> combinationFiles = testInitial.getAllConfigurations(forkNames, 3);
        for (Set<String> combination : combinationFiles) {


            //-----------
            String forkName = "";
            for (String com : combination) {
                forkName += com+"_";
            }
            filePath = "testcpp/statistics/" + "upstream_" + forkName  + ".txt";

            //-----------



            for (String fileToBeMerged : mergedFiles) {
                //-----------
                testInitial.writeTofile("!#############!##############!" + fileToBeMerged + "\n", filePath);
                testInitial.writeTofile("+-+-+-\n", filePath);
                //-----------
                testInitial.checkMergeRepo(path, combination, fileToBeMerged);
            }

//            }


            //-----------
            IOFunctionSet ioFunctionSet = new IOFunctionSet();
            String mergedBlock = "";
            try {
                mergedBlock = ioFunctionSet.presicePrettyprint(testInitial.readResult(filePath));
                ioFunctionSet.writeTofile(mergedBlock, filePath + ".new");
            } catch (IOException e) {
                e.printStackTrace();
            }

            int upstream = 0;
            int upstreamNewLine = 0;
            int fork = 0;
            int forkNewLine = 0;
            int ifdef = 0;
            String[] files = mergedBlock.split("!#############!##############!");
            for (String file : files) {
                String[] blocks = file.split("\\+-\\+-\\+-\n");
                for (String b : blocks) {
                    if (b.contains("#if defined (upstream)")) {
                        upstream++;
                        upstreamNewLine += b.split("\n").length;

                    }
                    if (b.contains("#if defined (" + forkName + ")")) {
                        fork++;
                        forkNewLine += b.split("\n").length;
                    }
                    if (b.contains("additional ifdef")) {
                        ifdef++;
                    }
                }
            }

            String statisticsPath = "testcpp/statistics/result.txt";
            ioFunctionSet.writeTofile("\n+++++++++\nCompare upstream with " + forkName + ":\n", statisticsPath);
            ioFunctionSet.writeTofile("upstream unique: " + upstream + "\n", statisticsPath);
            ioFunctionSet.writeTofile("LOC upstream unique: " + upstreamNewLine + "\n", statisticsPath);
            ioFunctionSet.writeTofile("fork unique: " + fork + "\n", statisticsPath);
            ioFunctionSet.writeTofile("LOC fork unique: " + forkNewLine + "\n", statisticsPath);

            ioFunctionSet.writeTofile("introduced ifdef: " + ifdef + "\n", statisticsPath);
            //-----------

        }
    }

}
