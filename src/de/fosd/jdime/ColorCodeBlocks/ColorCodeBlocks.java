package de.fosd.jdime.ColorCodeBlocks;

import de.fosd.jdime.util.IOFunctionSet;

import java.awt.*;
import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Random;

/**
 * Created by shuruiz on 2/9/16.
 */
public class ColorCodeBlocks {

    //    static String testDir = "/MinePump/test_11";
    static String testDir;
//        static String testDir = "/EmailSystem/test_18";


    static IOFunctionSet iofunc = new IOFunctionSet();
    static String dir = "/Users/shuruiz/Work/JDIME/NWayJDime/jdime";
    static String dgPath = "/testcpp/dependencyGraph";
    static String testDirPath ;
    static String clusterstxt = "/maxModularityCluster.txt";
    static String expectTxt = "/expectCluster.txt";
    static String sourceCodeTxt = "/sourceCode.txt";
    static String nodeListTxt = "/NodeList.txt";
    static String upstreamNodeTxt = "/upstreamNode.txt";
    static String forkAddedNodeTxt = "/forkAddedNode.txt";
    static String graphFile = "/upstreamNode.txt";
    static String edgeListTxt = "/edgeList.txt";
    static String pathListScript = "/pathscript.txt";
    static String addPathFunctionStmtTxt = "/addPathFunc.txt";
    static HashMap<Integer, String> nodeMap;

    public static ArrayList<String> getClusters() {
        String clusterFilePath = dir + dgPath + testDir + clusterstxt;
        BufferedReader br = null;
        ArrayList<String> clusters = new ArrayList<>();
        String line;

        try {
            br = new BufferedReader(new FileReader(clusterFilePath));
            while ((line = br.readLine()) != null && !line.equals("")) {

                // use comma as separator
                clusters.add(line.replace("[", "").replace("]", ""));
            }

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (br != null) {
                try {
                    br.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        return clusters;
    }

    public static void createSourceFileHtml() throws IOException {
        File dir = new File(testDirPath);
        String[] names = dir.list();
        StringBuilder sb = new StringBuilder();
//        sb.append(" <div style=\"left: 5%; position: absolute;\">");
        for (String fileName : names) {
            if (fileName.endsWith(".cpp") || fileName.endsWith(".h") || fileName.endsWith(".c")) {
                System.out.print(fileName + "\n");

                sb.append("<h1>" + fileName + "</h1>\n<pre  class=\"prettyprint linenums\">");

                //Rewrite the file name for html purpose
                String suffix = fileName.split("\\.")[1];
                String newFileName = fileName.replace("." + suffix, suffix.toUpperCase());


                BufferedReader result_br = null;
                int lineNumber = 1;
                try {
                    result_br = new BufferedReader(new FileReader(testDirPath + "/" + fileName));

                    String line;
                    while ((line = result_br.readLine()) != null) {

                        sb.append("<front id=\"" + newFileName + "-" + lineNumber + "\">");
                        sb.append(line.replace("<", "&lt;").replace(">", "&gt;"));
                        sb.append("</front>\n");
                        System.out.print("");
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
//        sb.append(" </div>\n");

        iofunc.rewriteFile(sb.toString(), testDirPath + sourceCodeTxt);
        System.out.print("");
    }

    public static void writeClusterToCSS(ArrayList<String> clusters) {
        String testDirPath = dir + dgPath + testDir;
        BufferedReader br = null;
        String line;
        nodeMap = new HashMap<>();

        BackgroundColor bgcolor = new BackgroundColor();

        try {
            br = new BufferedReader(new FileReader(testDirPath + nodeListTxt));
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

        File upstreamNodeFile = new File(testDirPath + upstreamNodeTxt);
        if (upstreamNodeFile.exists()) {
            try {
                upstreamNode = iofunc.readResult(testDirPath + upstreamNodeTxt);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        //get fork added node
        String forkAddedNode = "";
        File forkAddedFile = new File(testDirPath + forkAddedNodeTxt);
        if (forkAddedFile.exists()) {
            try {
                forkAddedNode = iofunc.readResult(testDirPath + forkAddedNodeTxt);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        String expectNode = "";
        try {
            expectNode = iofunc.readResult(testDirPath + expectTxt);
        } catch (IOException e) {
            e.printStackTrace();
        }
        HashMap<String, Integer> expectNodeMap = new HashMap<>();
        String[] nodeCluster = expectNode.split("\n");
        for (int i = 0; i < nodeCluster.length; i++) {
            expectNodeMap.put(nodeCluster[i].split(" ")[0], Integer.valueOf(nodeCluster[i].split(" ")[1]));
        }

//        List<String> colorList = bgcolor.getColorList();
        List<String> colorList = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        sb.append("#expectIMG{\n\tposition:fixed;\n\ttop:100px;\n\tright:50px;\n" +
                "}\n#resultIMG{\n\tposition:fixed;\n\ttop:500px;\n\tright:50px;\n}");
        sb.append("#svgContainer{\n\tposition:absolute;\n}\n");
        for (int i = 0; i < clusters.size(); i++) {

            String[] elementList = clusters.get(i).trim().split(",");
            for (int j = 0; j < elementList.length; j++) {
//                String current_color = colorList.get(i);
                Random rand = new Random();
                float r = (float) (rand.nextFloat() / 2f + 0.5);
                float g = (float) (rand.nextFloat() / 2f + 0.5);
                float b = (float) (rand.nextFloat() / 2f + 0.5);
                Color randomColor = new Color(r, g, b);
                String    current_color = Integer.toHexString(randomColor.getRGB() & 0x00ffffff);


//            creating ramdom color

                System.out.println("elementList[j]:" + elementList[j]);
                int nodeID = Integer.parseInt(elementList[j].trim());
                String nodeLabel = nodeMap.get(nodeID);


                sb.append("#" + nodeLabel + "{\n\tbackground-color:" + current_color + ";\n");


//                if(!upstreamNode.equals("")) {
//                    if (upstreamNode.contains(nodeLabel)) {
//                        current_color = "Gray";
//                    }
//                }else if(!forkAddedNode.equals("")){
//                    if (!forkAddedNode.contains(nodeLabel)) {
//                        current_color = "Gray";
//                    }
//                }

                String sidebarColor = "";
                if (expectNodeMap.get(nodeLabel) != null) {
                    sidebarColor = bgcolor.getExpectColorList().get(expectNodeMap.get(nodeLabel) - 1);
                }
                if (!upstreamNode.equals("")) {
                    if (upstreamNode.contains(nodeLabel)) {
                        sidebarColor = "Gray";
                    }
                } else if (!forkAddedNode.equals("")) {
                    if (!forkAddedNode.contains(nodeLabel)) {
                        sidebarColor = "Gray";
                    }
                }


                sb.append("\tborder-style: solid;\n\tborder-width: thin thick;\n\tborder-color: white white white " + sidebarColor + ";");


                sb.append("\n}\n");

            }

        }

        iofunc.rewriteFile(sb.toString(), testDirPath + "/style.css");

    }

    public static void createEdges(boolean printPath) {
        if (printPath) {
            String edgeList = null;
            try {
                edgeList = iofunc.readResult(testDirPath + edgeListTxt);

            } catch (IOException e) {
                e.printStackTrace();
            }
            StringBuilder pathScript = new StringBuilder();
            StringBuilder addPathFuncStmt = new StringBuilder();

            pathScript.append("<div id=\"svgContainer\" style=\"margin: 50px 50px;\">\n" +
                    "\t<svg id=\"svg1\" width=\"0\" height=\"0\" >\n");
            addPathFuncStmt.append("function connectAll() {\n");


            String[] edgeArray = edgeList.split("\n");
            for (int i = 0; i < edgeArray.length; i++) {
                String[] edge = edgeArray[i].split(",");
                String from = nodeMap.get(Integer.parseInt(edge[0]));
                String to = nodeMap.get(Integer.parseInt(edge[1]));
                String label = edge[2];
                int pathID = i + 1;

                pathScript.append("<path\n\tid=\"path" + pathID + "\""
                        + "\n\td=\"M0 0\""
                        + "\n\topacity=\"0.3\""
                        + "\n\tstroke=\"blue\""
                        + "\n\tfill=\"none\""
                        + "\n\tstroke-width=\"2px\";"
                        + "\n\tonmouseover=\"evt.target.setAttribute('opacity', '1.0');\""
                        + "\n\tonmouseout=\"evt.target.setAttribute('opacity', '0.3'); \""
                        + "\n\tonclick=\"alert(\'"
                        + from + "->" + to + " [" + label + "]\')\"/>\n");

                addPathFuncStmt.append("connectElements($(\"#svg1\"), $(\"#path" + pathID + "\"), $(\"#"
                        + from + "\"),$(\"#" + to + "\"));\n");
            }

            pathScript.append("</svg>\n</div>");
            addPathFuncStmt.append("}\n");
            iofunc.rewriteFile(pathScript.toString(), testDirPath + pathListScript);
            iofunc.rewriteFile(addPathFuncStmt.toString(), testDirPath + addPathFunctionStmtTxt);

        } else {
            iofunc.rewriteFile("", testDirPath + pathListScript);
            iofunc.rewriteFile("", testDirPath + addPathFunctionStmtTxt);

        }

    }

    public static void combineFiles() {
        String htmlfilePath = dir + "/visualizeHtml/";
        String headtxt = "head.txt";
        String endtxt = "end.txt";
        String jsPretxt = "svgDrawPre.txt";
        String jsPath = "/svgDraw.js";
        String html = "/code.html";
        try {
            //write code.html
            iofunc.rewriteFile(iofunc.readResult(htmlfilePath + headtxt), testDirPath + html);
            iofunc.writeTofile(iofunc.readResult(testDirPath + pathListScript), testDirPath + html);
            iofunc.writeTofile(iofunc.readResult(testDirPath + sourceCodeTxt), testDirPath + html);
            iofunc.writeTofile(iofunc.readResult(htmlfilePath + endtxt), testDirPath + html);

            //write js file
            iofunc.rewriteFile(iofunc.readResult(htmlfilePath + jsPretxt), testDirPath + jsPath);
            iofunc.writeTofile(iofunc.readResult(testDirPath + addPathFunctionStmtTxt), testDirPath + jsPath);
        } catch (IOException e) {
            e.printStackTrace();
        }


    }


    public static void visualizeGraph(boolean printEdges, String filePath) {
        testDir = "/"+filePath+"/";
        testDirPath = dir + dgPath + testDir;
        try {
            createSourceFileHtml();
        } catch (IOException e) {
            e.printStackTrace();
        }

        ArrayList<String> clusters = getClusters();
        writeClusterToCSS(clusters);


        createEdges(printEdges);

        combineFiles();
    }

    public static void main(String[] args) {

        visualizeGraph(false, testDir);
    }


}





