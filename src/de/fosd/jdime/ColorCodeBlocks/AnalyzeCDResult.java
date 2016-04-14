package de.fosd.jdime.ColorCodeBlocks;

import de.fosd.jdime.dependencyGraph.Symbol;
import de.fosd.jdime.util.IOFunctionSet;

import java.io.File;
import java.io.IOException;
import java.lang.reflect.Array;
import java.util.*;

/**
 * Created by shuruiz on 3/18/16.
 */
public class AnalyzeCDResult {
    IOFunctionSet ioFunctionSet = new IOFunctionSet();
    String analysisDir;
    List<String> bgcolorList = BackgroundColor.getExpectColorList();

    public void generatingClusteringTable(String analysisDir, int numberOfCommunities, int expectClustersNum) {
        this.analysisDir = analysisDir;
        HashMap<String, HashMap<String, Integer>> resultTable = new HashMap<>();

        for(int i =0;i<expectClustersNum;i++){
            resultTable.put(bgcolorList.get(i),new HashMap<String, Integer>());
        }


        String filePath = analysisDir + numberOfCommunities + "_colorTable.txt";
        try {
            String cssString = ioFunctionSet.readResult(filePath);
            String[] colorArray = cssString.split("\n");
            ArrayList<String> nodeColorList = new ArrayList(Arrays.asList(colorArray));
            ArrayList<String> communityColorList = new ArrayList<>();
            for (String node : nodeColorList) {
                if (node.length() > 0) {

                    String[] nodeInfo = node.split(",");
                    String id = nodeInfo[0];
                    String bgColor = nodeInfo[1];
                    String expectColor = nodeInfo[2];
                    System.out.println(id + "-" + bgColor + "-" + expectColor);
                    if (!communityColorList.contains(bgColor)) {
                        communityColorList.add(bgColor);
                    }

                    HashMap<String, Integer> distributedColor = resultTable.get(expectColor);
                    if (distributedColor != null) {
                        if (distributedColor.get(bgColor) == null) {
                            distributedColor.put(bgColor, 1);
                        } else {
                            int num = distributedColor.get(bgColor);
                            distributedColor.put(bgColor, num + 1);
                        }
                    } else {
                        distributedColor = new HashMap<>();
                        distributedColor.put(bgColor, 1);
                    }
                    resultTable.put(expectColor, distributedColor);

                }
            }

            printResultTable(resultTable, communityColorList, numberOfCommunities, expectClustersNum);
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private void printResultTable(HashMap<String, HashMap<String, Integer>> resultTable, ArrayList<String> communityColorList, int numberOfCommunities, int expectClustersNum) {
        StringBuffer sb = new StringBuffer();
        Iterator it = resultTable.keySet().iterator();


        //print 1st line
        sb.append("<table>\n" +
                "    <tr>\n" +
                "        <td>\n" +
                "            <span>Result</span>\n" +
                "            <hr/>\n" +
                "            <span>Expected</span>\n" +
                "        </td>\n");

        for (String color : communityColorList) {
            sb.append("<td bgcolor=\"#" + color + "\"></td>\n");
        }
        sb.append("</tr>\n");

        for (int i = 0; i < expectClustersNum; i++) {
            String expectColor = bgcolorList.get(i);
            //print rest lines
            sb.append("  <tr>\n" +
                    "        <td bgcolor=\"" + expectColor + "\">\n" +
                    expectColor +
                    "\n        </td>");

            HashMap<String, Integer> distributedMap = resultTable.get(expectColor);


            for (String s : communityColorList) {
                sb.append("<td>" + distributedMap.get(s) + "</td>\n");

                System.out.println(distributedMap.get(s));
            }
            sb.append("</tr>");
        }
        sb.append("</table>");
        ioFunctionSet.rewriteFile(sb.toString(), analysisDir+ numberOfCommunities + ".color");
    }
}
