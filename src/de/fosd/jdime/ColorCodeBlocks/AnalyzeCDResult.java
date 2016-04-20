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

    public void generatingClusteringTable(String analysisDir, int numberOfCommunities, ArrayList<String> macroList) {
        this.analysisDir = analysisDir;
        HashMap<String, HashMap<String, Integer>> resultTable = new HashMap<>();

        for (int i = 0; i < macroList.size(); i++) {
            resultTable.put(bgcolorList.get(i), new HashMap<>());
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

            printResultTable(resultTable, communityColorList, numberOfCommunities, macroList);

            printClusterDistanceTable(numberOfCommunities);

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private void printClusterDistanceTable(int numberOfCommunities) {
        StringBuffer sb = new StringBuffer();
        HashMap<String, String[]> distanceTable = new HashMap<>();

        ArrayList<String> clusterIDList=new ArrayList<>();
        String[] colorList;
        String[] distanceList;
        try {
            String[] tmp = ioFunctionSet.readResult(analysisDir + numberOfCommunities + "_clusterIdList.txt").split(",");
            for (String s : tmp) {
                if (!s.equals("\n")) {
                    clusterIDList.add(s);
                }

            }
            for (String s : clusterIDList) {
                if (!s.equals("\n")) {
                    distanceTable.put(s, new String[clusterIDList.size()]);
                }
            }

            // TODO: table color
            colorList = ioFunctionSet.readResult(analysisDir + numberOfCommunities + "_clusterColor.txt").split("\n");
            HashMap<String,String> colorTable = new HashMap();
            for (String c : colorList) {
                //[0] id  [1] current color  [2] expect color
                String[] content = c.split(",");
                String id = content[0];
                String current_color = content[1];
                String expect_color = content[2];

                colorTable.put(id,current_color);
            }


            distanceList = ioFunctionSet.readResult(analysisDir + numberOfCommunities + "_distanceBetweenCommunityies.txt").split("\n");
            for (String d : distanceList) {
                String[] content = d.split(",");
                String[] array = distanceTable.get(content[0]);
                array[Integer.valueOf(clusterIDList.indexOf(content[1]))] = content[2];
                distanceTable.put(content[0], array);
            }

            sb.append("<table id=\"distance\"> <tr> <td> </td>\n");
            for (String id : clusterIDList) {
                sb.append("<td bgcolor=\"#"+colorTable.get(id)+"\">" + id + "</td>\n");

            }
            sb.append("</tr>\n");

            for (String id : clusterIDList) {
                sb.append("<tr><td bgcolor=\"#"+colorTable.get(id)+"\">"+id + "</td>\n");

                for (String s : distanceTable.get(id)) {
                    sb.append("<td>" + s + "</td>\n");
                }
                sb.append("</tr>\n");
            }


            sb.append("</table>\n");


            ioFunctionSet.rewriteFile(sb.toString(), analysisDir + numberOfCommunities + ".distanceTable");





        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private void printResultTable(HashMap<String, HashMap<String, Integer>> resultTable, ArrayList<String> communityColorList, int numberOfCommunities,ArrayList<String> macroList) {
        StringBuffer sb = new StringBuffer();
        Iterator it = resultTable.keySet().iterator();


        //print 1st line
        sb.append("<table id=\"cluster\">\n" +
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

        for (int i = 0; i < macroList.size(); i++) {
            String expectColor = bgcolorList.get(i);
            //print rest lines
            sb.append("  <tr>\n" +
                    "        <td bgcolor=\"" + expectColor + "\">\n" +
                    macroList.get(i) +
                    "\n        </td>\n");

            HashMap<String, Integer> distributedMap = resultTable.get(expectColor);


            for (String s : communityColorList) {
                sb.append("<td>" + distributedMap.get(s) + "</td>\n");

            }
            sb.append("</tr>\n");
        }
        sb.append("</table>");
        ioFunctionSet.rewriteFile(sb.toString(), analysisDir + numberOfCommunities + ".color");
    }
}
