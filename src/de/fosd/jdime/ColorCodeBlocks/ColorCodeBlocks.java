package de.fosd.jdime.ColorCodeBlocks;

import de.fosd.jdime.dependencyGraph.Symbol;
import de.fosd.jdime.util.IOFunctionSet;
import nu.xom.Element;
import org.apache.commons.io.FileUtils;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.stream.Stream;

/**
 * Created by shuruiz on 2/9/16.
 */
public class ColorCodeBlocks {
    static String dir = "/Users/shuruiz/Work/JDIME/NWayJDime/jdime";
    static String dgPath = "/testcpp/dependencyGraph";
    static String testDir = "/EmailSystem/test_18";
    static String clusterstxt = "/maxModularityCluster.txt";
    static String nodeListTxt = "/NodeList.txt";
    static String upstreamNodeTxt = "/upstreamNode.txt";


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
        String testDirPath = dir + dgPath + testDir + "/";
        File dir = new File(testDirPath);
        String[] names = dir.list();
        StringBuilder sb = new StringBuilder();
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
                    result_br = new BufferedReader(new FileReader(testDirPath + fileName));

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


        iofunc.rewriteFile(sb.toString(), testDirPath + "/sourceCode.txt");
        System.out.print("");
    }

    public static void writeClusterToCSS(ArrayList<String> clusters) {
        String testDirPath = dir + dgPath + testDir;
        BufferedReader br = null;
        String line;
        HashMap<Integer, String> nodeMap = new HashMap<>();

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

        List<String> colorList = color.getColorList();
        StringBuilder sb = new StringBuilder();
        sb.append("#svgContainer{\n\tposition:absolute;\n}\n");
        for (int i = 0; i < clusters.size(); i++) {
            String current_color = colorList.get(i);

            String[] elementList = clusters.get(i).trim().split(",");
            for (int j = 0; j < elementList.length; j++) {
                int nodeID = Integer.parseInt(elementList[j].trim());
                String nodeLabel = nodeMap.get(nodeID);

                if (upstreamNode.contains(nodeLabel)) {
                    current_color = "gray";
                }
                sb.append("#" + nodeLabel + "{\n\tbackground-color:" + current_color + ";\n}\n");

            }

            System.out.print("");
        }

        iofunc.rewriteFile(sb.toString(), testDirPath + "/nodeColor.css");

    }

    public static void main(String[] args) {

        String htmlfilePath = dir + "/visualizeHtml/";
        String headtxt = "head.txt";
        String endtxt = "end.txt";
        String html = "code.html";
        String head = "";
        String end = "";
        IOFunctionSet ioFunctionSet = new IOFunctionSet();

        try {
            createSourceFileHtml();
        } catch (IOException e) {
            e.printStackTrace();
        }

        ArrayList<String> clusters = new ArrayList<>();
        clusters = getClusters();
        writeClusterToCSS(clusters);
        try {
            head = ioFunctionSet.readResult(htmlfilePath + headtxt);
            end = ioFunctionSet.readResult(htmlfilePath + endtxt);
        } catch (IOException e) {
            e.printStackTrace();
        }
        ioFunctionSet.writeTofile(head, html);


    }

    static IOFunctionSet iofunc = new IOFunctionSet();


}





