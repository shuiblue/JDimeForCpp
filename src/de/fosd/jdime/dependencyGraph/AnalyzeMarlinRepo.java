package de.fosd.jdime.dependencyGraph;

import de.fosd.jdime.ColorCodeBlocks.ColorCodeBlocks;
import org.rosuda.JRI.Rengine;

import java.util.ArrayList;
import java.util.HashMap;


/**
 * Created by shuruiz on 3/22/16.
 */
public class AnalyzeMarlinRepo {

    public void analyzeRepository(String repo, int dirNum, String projectPath, ArrayList<String> commitList, ArrayList<String> macroList, int numOfIteration, Rengine re) {
        String DPGraphDir = "/DPGraph/";
        String filePath = projectPath + repo;
        DependencyGraph dependencyGraph = new DependencyGraph();
        boolean SHA = false;
        boolean IFDEF = true;
//                IdentifyChangedCode icc = new IdentifyChangedCode();
//                if (SHA) {
//                    icc.identifyChangedCodeBySHA(projectPath ,repo, commitList);
//                } else if (IFDEF) {
//                    icc.identifyIfdefs(projectPath ,repo, dirNum,macroList);
//                }
        dependencyGraph.getDependencyGraphForProject(projectPath, repo, dirNum);
        RCommunityDetection rCommunityDetection = new RCommunityDetection();
        int bestCut = rCommunityDetection.detectingCommunitiesWithIgraph(filePath + DPGraphDir + dirNum, numOfIteration, re);
        ColorCodeBlocks colorCodeBlocks = new ColorCodeBlocks();
//                colorCodeBlocks.parseEachUsefulClusteringResult(projectPath ,repo, dirNum,macroList.size());
        colorCodeBlocks.parseEachUsefulClusteringResult(projectPath, repo, dirNum, 3);
    }
}
