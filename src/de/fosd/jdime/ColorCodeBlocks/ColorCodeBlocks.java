package de.fosd.jdime.ColorCodeBlocks;

import de.fosd.jdime.util.IOFunctionSet;

import java.awt.*;
import java.io.*;
import java.util.*;
import java.util.List;

/**
 * Created by shuruiz on 2/9/16.
 */
public class ColorCodeBlocks {

    static IOFunctionSet iofunc = new IOFunctionSet();
    static final String CSS = ".css";
    static String expectTxt = "/expectCluster.txt";
    static String sourceCodeTxt = "/sourceCode.txt";
    static String nodeListTxt = "/NodeList.txt";
    static String upstreamNodeTxt = "/upstreamNode.txt";
    static String forkAddedNodeTxt = "/forkAddedNode.txt";
    static String jsFileHeader = "/jshead.txt";
    static HashMap<Integer, String> nodeMap;
    static ArrayList<String> colorList = new ArrayList<>();
    static HashMap<Integer, String> colorMap = new HashMap<>();

    static StringBuffer jsContent = new StringBuffer();
    static String forkAddedNode = "";
    int expectClustersNum;
    String sourcecodeDir;
    String analysisDir;
    boolean print = false;

    public void createSourceFileHtml() throws IOException {
        File dir = new File(sourcecodeDir);
        String[] names = dir.list();
        StringBuilder sb = new StringBuilder();
        for (String fileName : names) {
//            if (fileName.endsWith(".cpp") || fileName.endsWith(".h") || fileName.endsWith(".c")) {
            if (fileName.endsWith(".cpp") || fileName.endsWith(".h") || fileName.endsWith(".c") || fileName.endsWith(".pde")) {
                System.out.print(fileName + "\n");
                String newFileName;
                String suffix = fileName.split("\\.")[1];
                newFileName = fileName.replace("." + suffix, suffix.toUpperCase());
                if (forkAddedNode.contains(newFileName)) {
                    sb.append("<h1 id=\"" + newFileName + "title\" >" + fileName + "</h1>\n<pre id=\"" + newFileName + "\"  class=\"prettyprint linenums\">");
                    BufferedReader result_br = null;
                    int lineNumber = 1;
                    try {
                        result_br = new BufferedReader(new FileReader(sourcecodeDir + "/" + fileName));

                        String line;
                        while ((line = result_br.readLine()) != null) {

                            String lable = newFileName + "-" + lineNumber;
                            sb.append("<front id=\"" + lable + "\">");

                            /* for print
                            if(line.trim().startsWith("#if")) {
                                sb.append("#ifdef ??\n");
                            }else{
                                sb.append(line.replace("<", "&lt;").replace(">", "&gt;"));

                            }
*/
                            sb.append(line.replace("<", "&lt;").replace(">", "&gt;"));
                            sb.append("</front>\n");
                            if (!forkAddedNode.contains(lable + " ")) {
                                jsContent.append("$(\"#" + lable + "\").toggle()\n");
                            }

                            lineNumber++;
                        }
                    } catch (FileNotFoundException e) {
                        e.printStackTrace();
                    } catch (IOException e) {
                        e.printStackTrace();
                    } finally {
                        result_br.close();
                    }
                    sb.append(" </pre>\n");
                }

            }


        }

        iofunc.rewriteFile(sb.toString(), analysisDir + sourceCodeTxt);
    }

    public void writeClusterToCSS(ArrayList<String> clusters, int numberOfClusters) {
        BufferedReader br;
        String line;
        nodeMap = new HashMap<>();

        BackgroundColor bgcolor = new BackgroundColor();

        try {
            br = new BufferedReader(new FileReader(analysisDir + nodeListTxt));
            while ((line = br.readLine()) != null) {
                // use comma as separator
                nodeMap.put(Integer.valueOf(line.trim().split("---------")[0]), line.trim().split("---------")[1]);
            }

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        //get upstream Node
        String upstreamNode = "";

        File upstreamNodeFile = new File(analysisDir + upstreamNodeTxt);
        if (upstreamNodeFile.exists()) {
            try {
                upstreamNode = iofunc.readResult(analysisDir + upstreamNodeTxt);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        String expectNode = "";
        try {
            expectNode = iofunc.readResult(analysisDir + expectTxt);
        } catch (IOException e) {
            e.printStackTrace();
        }
        HashMap<String, Integer> expectNodeMap = new HashMap<>();
        String[] nodeCluster = expectNode.split("\n");
        for (int i = 0; i < nodeCluster.length; i++) {
            expectNodeMap.put(nodeCluster[i].split(" ")[0], Integer.valueOf(nodeCluster[i].split(" ")[1]));
        }

        StringBuilder sb = new StringBuilder();
        StringBuilder colorTable = new StringBuilder();
        sb.append("td {\n" +
                "    width: 5px;\n" +
                "    border:1px solid black;\n" +
                "    text-align:center;\n" +
                "}\n" +
                "\n" +
                "hr {\n" +
                "     -moz-transform: rotate(45deg);  \n" +
                "       -o-transform: rotate(45deg);  \n" +
                "  -webkit-transform: rotate(45deg);  \n" +
                "      -ms-transform: rotate(45deg);  \n" +
                "          transform: rotate(45deg);  \n" +
                "             width:150%;\n" +
                "    margin-left:-15px;\n" +
                "}\n" +
                "\n" +
                "table{\n" +
                "\tposition:fixed;\n" +
                "\ttop:100px;\n" +
                "\tright:50px;\n" +
                "}\n");
        for (int i = 0; i < clusters.size(); i++) {

            if (clusters.get(i).length() > 0) {
                String current_color = "";
//                if (colorList.size() > i - 1) {
//                    current_color = colorList.get(i - 1);
//                } else {
//                    current_color = randomColor();
//                    colorList.add(current_color);
//
//                }
                String[] elementList = clusters.get(i).trim().split(",");
                int length = elementList.length;
                for (int j = 0; j < length; j++) {
                    String nodeIdStr = elementList[j].trim().replace("[", "").replace("]", "");
                    if (nodeIdStr.length() > 0) {
                        int nodeID = Integer.parseInt(nodeIdStr);
                        String nodeLabel = nodeMap.get(nodeID);

                        if (j == 0) {
                            String color = colorMap.get(nodeID);
                            if (color != null) {
                                current_color = colorMap.get(nodeID);
                            } else {
                                current_color = randomColor();

                                colorMap.put(nodeID, current_color);
                            }
                        }

                        /*for printing purpose*/
                        if (print) {
                            sb.append("#" + nodeLabel + "{\n\tbackground-color:;\n");
                        } else {
                            sb.append("#" + nodeLabel + "{\n\tbackground-color:#" + current_color + ";\n");
                        }

                        String sidebarColor = "";
                        if (expectNodeMap.get(nodeLabel) != null) {

                            /*for print*/
                            if(print) {
                                sidebarColor = "Black";
                            }else{
                            sidebarColor = bgcolor.getExpectColorList().get(expectNodeMap.get(nodeLabel) - 1);
                            }
                            System.out.println(nodeLabel);

                        }
                        if (!upstreamNode.equals("")) {
                            if (upstreamNode.contains(nodeLabel)) {
                                   /*for print */
                                if(print) {
                                    sidebarColor = "White";
                                }else{
                                    sidebarColor = "Gray";
                                }

                            }
                        } else if (!forkAddedNode.equals("")) {
                            if (!forkAddedNode.contains(nodeLabel)) {
//                                sidebarColor = "Gray";
                                   /*for print */
                                if(print) {
                                    sidebarColor = "White";
                                }else{
                                    sidebarColor = "Gray";
                                }

                            }
                        }
                        sb.append("\tborder-style: solid;\n\tborder-width: thin thick;\n\tborder-color: white white white "
                                + sidebarColor + ";\n" + "}\n");


                        //write to file for calculate color table
                        if (expectNode.contains(nodeLabel + " ")) {
                            colorTable.append(nodeLabel + "," + current_color + "," + sidebarColor + "\n");

                        }
                    }
                }
            }
        }

        iofunc.rewriteFile(sb.toString(), analysisDir + "/" + numberOfClusters + CSS);
        iofunc.rewriteFile(colorTable.toString(), analysisDir + "/" + numberOfClusters + "_colorTable.txt");
    }

    private String randomColor() {
        Random rand = new Random();
        float r = (float) (rand.nextFloat() / 2f + 0.5);
        float g = (float) (rand.nextFloat() / 2f + 0.5);
        float b = (float) (rand.nextFloat() / 2f + 0.5);
        Color randomColor = new Color(r, g, b);
        String color = Integer.toHexString(randomColor.getRGB() & 0x00ffffff);

        if (!colorMap.keySet().contains(color)) {
            return color;
        } else {
            return randomColor();
        }

    }


    public void combineFiles(int numberOfClusters) {
        String htmlfilePath = "/Users/shuruiz/Work/MarlinRepo/visualizeHtml/";
        String headtxt = "head.txt";
        String bodyPreTxt = "body_pre.txt";
        String endtxt = "end.txt";
        String togglejsPath = "/toggle.js";
        String html = "/" + numberOfClusters + ".html";
        try {
            //write code.html
            iofunc.rewriteFile(iofunc.readResult(htmlfilePath + headtxt).replace("style.css", numberOfClusters + ".css"), analysisDir + html);


            iofunc.writeTofile(iofunc.readResult(analysisDir + "/" + numberOfClusters + ".color"), analysisDir + html);
            iofunc.writeTofile(iofunc.readResult(htmlfilePath + bodyPreTxt), analysisDir + html);
            iofunc.writeTofile(iofunc.readResult(analysisDir + sourceCodeTxt), analysisDir + html);

            iofunc.writeTofile(iofunc.readResult(htmlfilePath + endtxt), analysisDir + html);

            //toggle js
            iofunc.rewriteFile(iofunc.readResult(htmlfilePath + jsFileHeader), analysisDir + togglejsPath);
            iofunc.writeTofile(jsContent.toString() + "\n});", analysisDir + togglejsPath);


        } catch (IOException e) {
            e.printStackTrace();
        }


    }

    /**
     * This function parse the cluster.txt file, to analyze each clustering result after removing a bridge
     */
    public void parseEachUsefulClusteringResult(String filePath, int bestcut, int expectClustersNum) {
        sourcecodeDir = filePath + "Marlin";
        analysisDir = filePath + "DPGraph";
        this.expectClustersNum = expectClustersNum;
        String clusterFilePath = analysisDir + "/clusterTMP.txt";
        String clusterResultListString = "";

        //get fork added node
        File forkAddedFile = new File(analysisDir + forkAddedNodeTxt);
        if (forkAddedFile.exists()) {
            try {
                forkAddedNode = iofunc.readResult(analysisDir + forkAddedNodeTxt);
//                clusterResultListString = iofunc.readResult(clusterFilePath);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        try {
            createSourceFileHtml();
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            clusterResultListString = iofunc.readResult(clusterFilePath);
        } catch (IOException e) {
            e.printStackTrace();
        }
        String[] resultArray = clusterResultListString.split("--------Graph-------");
        for (int i = 0; i < resultArray.length; i++) {
            String result = resultArray[i];


            if (result.contains("communities")) {
                int[] clusterInfo = getClusterInfo(result.split("communities")[0]);
                int numberOfCommunities = clusterInfo[0];
                int numOfCutEdge = clusterInfo[1];
                if (numOfCutEdge <= bestcut) {
                    result = result.split("communities")[1];
                    String[] clusterArray = result.split("\n");

                    ArrayList<String> clusters = new ArrayList(Arrays.asList(clusterArray));
                    writeClusterToCSS(clusters, numberOfCommunities);

                    AnalyzeCDResult analyzeCDResult = new AnalyzeCDResult();
                    analyzeCDResult.generatingClusteringTable(analysisDir, numberOfCommunities, expectClustersNum);

                    combineFiles(numberOfCommunities);
                } else {
                    break;
                }
            }
        }
    }

    /**
     * This function get the number of communities and how many edges have been removed in current cluster result
     *
     * @param s cluster information
     * @return int array [0] --> num of communities
     * array[1] --> number of cut edges
     */

    private int[] getClusterInfo(String s) {
        int[] clusterInfo = new int[2];

        //get community number
        int start = s.indexOf("---");
        String number = s.substring(start + 3);
        clusterInfo[0] = Integer.valueOf(number.trim());

        // get number of cut edge
        int i = s.indexOf("**");
        int j = s.indexOf("edges");
        String numOfCutEdges = s.substring(i + 3, j);
        clusterInfo[1] = Integer.valueOf(numOfCutEdges.trim());

        return clusterInfo;
    }

    public static void main(String[] args) {

//        visualizeGraph(false, testDir);
    }


}





