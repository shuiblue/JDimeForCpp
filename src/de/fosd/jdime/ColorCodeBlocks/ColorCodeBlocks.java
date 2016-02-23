package de.fosd.jdime.ColorCodeBlocks;

import de.fosd.jdime.util.IOFunctionSet;

import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/**
 * Created by shuruiz on 2/9/16.
 */
public class ColorCodeBlocks {
    static IOFunctionSet iofunc = new IOFunctionSet();
    static String dir = "/Users/shuruiz/Work/JDIME/NWayJDime/jdime";
    static String dgPath = "/testcpp/dependencyGraph";
    static String testDir = "/EmailSystem/test_18";
    static String testDirPath = dir + dgPath + testDir;

    static String clusterstxt = "/maxModularityCluster.txt";
    static String expectTxt = "/expectCluster.txt";

    static String sourceCodeTxt = "/sourceCode.txt";
    static String nodeListTxt = "/NodeList.txt";
    static String upstreamNodeTxt = "/upstreamNode.txt";
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
            while ((line = br.readLine()) != null) {
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
                    result_br = new BufferedReader(new FileReader(testDirPath +"/"+ fileName));

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

        Color color = new Color();

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
        String upstreamNode = "";
        try {
            upstreamNode = iofunc.readResult(testDirPath + upstreamNodeTxt);
        } catch (IOException e) {
            e.printStackTrace();
        }

        String expectNode="";
        try {
            expectNode = iofunc.readResult(testDirPath + expectTxt);
        } catch (IOException e) {
            e.printStackTrace();
        }
       HashMap<String,Integer> expectNodeMap = new HashMap<>();
        String[] nodeCluster = expectNode.split("\n");
        for(int i=0;i<nodeCluster.length;i++){
            expectNodeMap.put(nodeCluster[i].split(" ")[0], Integer.valueOf(nodeCluster[i].split(" ")[1]));
        }

        List<String> colorList = color.getColorList();
        StringBuilder sb = new StringBuilder();
        sb.append("#svgContainer{\n\tposition:absolute;\n}\n");
        for (int i = 0; i < clusters.size(); i++) {

            String[] elementList = clusters.get(i).trim().split(",");
            for (int j = 0; j < elementList.length; j++) {
                String current_color = colorList.get(i);

                int nodeID = Integer.parseInt(elementList[j].trim());
                String nodeLabel = nodeMap.get(nodeID);

                if(nodeLabel.equals("ClientC-108")||nodeLabel.equals("ClientC-99")){
                    System.out.print("");
                }
                if (upstreamNode.contains(nodeLabel)) {
                    current_color = "Gray";
                }
                sb.append("#" + nodeLabel + "{\n\tbackground-color:" + current_color + ";\n");
                if(expectNodeMap.get(nodeLabel)!=null){
                    sb.append("\tborder-style: solid;\n\tborder-color: white white white "+ colorList.get(expectNodeMap.get(nodeLabel))+";");
                }

                sb.append("\n}\n");

            }

        }

        iofunc.rewriteFile(sb.toString(), testDirPath + "/style.css");

    }

    public static void createPaths(boolean printPath) {
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


    public static void visualizeGraph(boolean printPath) {
        try {
            createSourceFileHtml();
        } catch (IOException e) {
            e.printStackTrace();
        }

        ArrayList<String> clusters = getClusters();
        writeClusterToCSS(clusters);


        createPaths(printPath);

        combineFiles();
    }

    public static void main(String[] args) {

        visualizeGraph(false);
    }


}





