package de.fosd.jdime.dependencyGraph;

import de.fosd.jdime.ColorCodeBlocks.ColorCodeBlocks;

import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

import static de.fosd.jdime.dependencyGraph.DependencyGraph.dependencyGraph;

/**
 * Created by shuruiz on 3/22/16.
 */
public class AnalyzeMarlinRepo {

//    public void analyzeMarlinRepo(String repo, String projectPath, ArrayList<String> commitList, int expectClusterNum, ArrayList<String> macroList) {
    public void analyzeMarlinRepo(String repo, String projectPath, ArrayList<String> commitList,ArrayList<String> macroList) {
        String DPGraphDir = "DPGraph";
        String filePath = projectPath + repo;
        File dir = new File(filePath);
        String[] names = dir.list();
        DependencyGraph dependencyGraph = new DependencyGraph();

        for (String fileName : names) {
            if (fileName.startsWith("Marlin")) {
                filePath += "/" + fileName;
                IdentifyChangedCode icc = new IdentifyChangedCode();
//                icc.identifyChangedCodeBySHA(filePath, commitList);
//
                icc.identifyIfdefs(filePath, macroList);
                dependencyGraph.getDependencyGraph(filePath);
//                RCommunityDetection rCommunityDetection = new RCommunityDetection();
                filePath += "/";
//                int bestCut = rCommunityDetection.detectingCommunitiesWithIgraph(filePath + DPGraphDir);
//
                ColorCodeBlocks colorCodeBlocks = new ColorCodeBlocks();
                colorCodeBlocks.parseEachUsefulClusteringResult(filePath, 1, macroList.size());
                break;
            }
        }
    }



}
