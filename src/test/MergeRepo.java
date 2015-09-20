package test;

import de.fosd.jdime.util.IOFunctionSet;
import org.junit.Test;

import java.io.File;
import java.io.FilenameFilter;
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

    public HashSet<String> inputFileInit() {
        File upstream = new File(main_repo);
        File[] matches = upstream.listFiles(new FilenameFilter() {
            public boolean accept(File dir, String name) {
                return name.endsWith(".cpp");
//                return name.endsWith(".h") || name.endsWith(".cpp");
            }
        });

        for (File f : matches) {
            if (!f.getName().contains("planner")
                    && !f.getName().contains("temperature")
                    && !f.getName().contains("LiquidCrystalRus")
                    && !f.getName().contains("SdFile")
                    &&!f.getName().contains("SdVolume")) {
                mergedFiles.add(f.getName());
            }

        }
//        File dir = new File(path);
//        String[] names = dir.list();
//        for (String name : names) {
//            if (new File(path + name).isDirectory()) {
//                if (!name.equals("upstream")) {
//                    forkName.add(name);
//                }
//            }
//
//        }
        forkName.add("alromh87");
        forkName.add("johnnyr");
        forkName.add("mattsch");
        forkName.add("quikshot");
        forkName.add("DinoMesina");
        forkName.add("drsdre");
        forkName.add("wgm4321");

        return forkName;
    }


    @Test
    public void NWayMerge_Rev() {

        HashSet<String> forkNames = inputFileInit();
        for (String fork : forkNames) {

            //-----------
            String filePath = "testcpp/statistics/" + "upstream_" + fork + "_" + fork + "Upstream_.txt";
            //-----------


            for (String fileToBeMerged : mergedFiles) {
                System.out.println(fileToBeMerged + "~\n");
                //-----------
                testInitial.writeTofile("!#############!##############!" + fileToBeMerged + "\n", filePath);
                testInitial.writeTofile("+-+-+-\n", filePath);
                //-----------
                testInitial.checkMergeRepo(path, fork, fileToBeMerged);

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

            int upstreamNew = 0;
            int upstreamNewLine = 0;
            int upstreamOld = 0;
            int upstreamOldLine = 0;
            int forkUnique = 0;
            int forkNewLine = 0;
            int new_fork = 0;
            int new_fork_Line = 0;
            int old_fork = 0;
            int old_fork_Line = 0;
            int allUpstream = 0;
            int allUpstream_Line = 0;


            int ifdef = 0;

            ArrayList<String> combination = new ArrayList<>();

            combination.add("upstream");
            combination.add(fork);
            combination.add(fork + "Upstream");


            String[] files = mergedBlock.split("!#############!##############!");
            for (String file : files) {
                String[] blocks = file.split("\\+-\\+-\\+-\n");
                for (String b : blocks) {
                    if (b.contains(combination.get(0)) && !b.contains(combination.get(1)) && !b.contains(combination.get(2))) {
                        upstreamNew++;
                        upstreamNewLine += b.split("\n").length;
                    }
                    if (b.contains(combination.get(1)) && !b.contains(combination.get(0)) && !b.contains(combination.get(2))) {
                        forkUnique++;
                        forkNewLine += b.split("\n").length;
                    }

                    if (b.contains(combination.get(2)) && !b.contains(combination.get(0)) && !b.contains(combination.get(1))) {
                        upstreamOld++;
                        upstreamOldLine += b.split("\n").length;
                    }

                    if (b.contains(combination.get(0)) && b.contains(combination.get(1)) && !b.contains(combination.get(2))) {
                        new_fork++;
                        new_fork_Line += b.split("\n").length;
                    }
                    if (b.contains(combination.get(0)) && b.contains(combination.get(2)) && !b.contains(combination.get(1))) {
                        allUpstream++;
                        allUpstream_Line += b.split("\n").length;
                    }
                    if (b.contains(combination.get(1)) && b.contains(combination.get(2)) && !b.contains(combination.get(0))) {
                        old_fork++;
                        old_fork_Line += b.split("\n").length;
                    }

                    if (b.contains("additional ifdef")) {
                        ifdef++;
                    }
                }
            }

            String statisticsPath = "testcpp/statistics/result.txt";
            ioFunctionSet.writeTofile("\n+++++++++\nCompare 2 version of upstream(upstream_NEW/upstream_OLD) with " + fork + ":\n", statisticsPath);
            ioFunctionSet.writeTofile("(upstream_NEW) Unique: " + upstreamNew + "/LOC:" + upstreamNewLine + "\n", statisticsPath);
            ioFunctionSet.writeTofile("("+fork+") Unique: " + forkUnique + "/LOC:" + forkNewLine + "\n", statisticsPath);
            ioFunctionSet.writeTofile("(upstream_OLD)Unique: " + upstreamOld + "/LOC:" + upstreamOldLine + "\n", statisticsPath);
            ioFunctionSet.writeTofile("(upstreamNew) ^ ("+fork+"): " + new_fork + "/LOC:" + new_fork_Line + "\n", statisticsPath);
            ioFunctionSet.writeTofile("(upstreamOLD) ^ ("+fork+"): " + old_fork + "/LOC:" + old_fork_Line + "\n", statisticsPath);
            ioFunctionSet.writeTofile("upstream(NEW) ^ (OLD): " + allUpstream + "/LOC:" + allUpstream_Line + "\n", statisticsPath);

            ioFunctionSet.writeTofile("introduced ifdef: " + ifdef + "\n", statisticsPath);
            //-----------

        }
    }

}
