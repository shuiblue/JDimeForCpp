package de.fosd.jdime.util;

import nu.xom.*;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;
import java.util.stream.Stream;

/**
 * Created by shuruiz on 8/31/15.
 */
public class IOFunctionSet {


    public String printNodeWithoutHeadandEnd(String s, int head) {
        StringBuffer blockString = new StringBuffer();

        if (s.endsWith(":")) {
            for (int i = head; i < s.split("\n").length - 2; i++) {
                blockString.append(s.split("\n")[i] + "\n");
            }
            blockString.append(":");
        } else {
            for (int i = head; i < s.split("\n").length - 1; i++) {
                blockString.append(s.split("\n")[i] + "\n");
            }
        }
        return blockString.toString();
    }


    public void writeTofile(String content, String filepath) {

        try {
            File file = new File(filepath);
            // if file doesnt exists, then create it
            if (!file.exists()) {
                file.createNewFile();
            }
            FileWriter fw = new FileWriter(file.getAbsoluteFile(), true);
            BufferedWriter bw = new BufferedWriter(fw);
            bw.write(content);
            bw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void rewriteFile(String content, String filepath) {

        try {
            File file = new File(filepath);
            // if file doesnt exists, then create it
            if (!file.exists()) {
                file.createNewFile();
            }
            FileWriter fw = new FileWriter(file.getAbsoluteFile(), false);
            BufferedWriter bw = new BufferedWriter(fw);
            bw.write(content);
            bw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public void writeToPajekFile(HashMap<String, HashSet<String[]>> dependencyGraph, HashMap<String, Integer> nodeList, String filepath) {
        String pajek = "/graph.pajek.net";
        rewriteFile("*Vertices " + nodeList.size() + "\n", filepath + pajek);
        // Getting a Set of Key-value pairs
        Set nodeSet = nodeList.entrySet();
        // Obtaining an iterator for the entry set
        Iterator it_node = nodeSet.iterator();

        while (it_node.hasNext()) {
            Map.Entry node = (Map.Entry) it_node.next();

            String nodeId = (String) node.getKey();
            writeTofile(nodeList.get(nodeId) + " \"" + nodeId + "\"\n", filepath + pajek);

        }

        // Getting a Set of Key-value pairs
        Set entrySet = dependencyGraph.entrySet();

        writeTofile("*arcs \n", filepath + pajek);

        // Obtaining an iterator for the entry set
        Iterator it_edge = entrySet.iterator();

        // Iterate through HashMap entries(Key-Value pairs)
        System.out.println("HashMap Key-Value Pairs : ");
        while (it_edge.hasNext()) {
            Map.Entry node = (Map.Entry) it_edge.next();

            String currentNode = (String) node.getKey();

            String to = nodeList.get(currentNode).toString();
            HashSet<String[]> dependencyNodes = (HashSet<String[]>) node.getValue();
            for (String[] dn : dependencyNodes) {

                writeTofile(nodeList.get(dn[0]) + " " + to + " " + dn[2] + "\n", filepath + pajek);

            }

        }
    }


    /**
     * This function presice the pretty print result of a block when:
     * 1)neighbor lines have the same condition
     * 2) the element has the same condition with the block
     *
     * @param res            origin pretty print result
     * @param blockCondition condition of the block
     * @return presiced result
     */
    public String precisePrettyprint(String res, String blockCondition) {

        StringBuffer newResult = new StringBuffer();
        Stack<String> conditionStack = new Stack<>();
        String[] elements = res.split("\\+-\\+-\\+-\n");
        for (int j = 0; j < elements.length; j++) {
            String e = elements[j];

            if (e.length() > 0 && !e.equals("\n")) {
                String[] tmp = e.split("\n");
                if (conditionStack.size() > 0) {
                    String lastCon = conditionStack.lastElement();
                    if (lastCon.equals(tmp[0])) {
                        newResult.append(printNodeWithoutHeadandEnd(e, 1));
                        continue;
                    } else {
                        conditionStack.pop();
                        if (tmp[0].equals(blockCondition.replace("\n", ""))) {
                            newResult.append("#endif\n");
                            if (tmp.length > 3) {
                                for (int i = 1; i < tmp.length - 1; i++) {
                                    newResult.append(tmp[i] + "\n");
                                }
                            } else {
                                newResult.append(tmp[1] + "\n");
                            }
                            continue;
                        } else {
                            newResult.append("#endif\n");

                            if (!tmp[0].startsWith("#if defined")) {
                                newResult.append(e);
                            } else {
                                newResult.append(printNodeWithoutHeadandEnd(e, 0));
                                conditionStack.push(tmp[0]);
                            }
                        }
                    }
                } else {
                    if (tmp[0].startsWith("#if defined")) {
                        if (!tmp[0].equals(blockCondition.replace("\n", ""))) {
                            conditionStack.push(tmp[0]);
                            newResult.append(printNodeWithoutHeadandEnd(e, 0));
                        } else {
                            newResult.append(printNodeWithoutHeadandEnd(e, 1));
                        }
                    } else {
                        newResult.append(e);
                        if (!e.endsWith("\n")) {
                            newResult.append("\n");
                        }
                    }
                }
            }
        }
        if (conditionStack.size() > 0) {
            conditionStack.pop();
            newResult.append("#endif\n");
        }

        return newResult.toString();
    }


    public String presicePrettyprint(String res) {
        boolean uniqueIFDEF = false;

        while (res.contains("#endif+-+-+-")) {
            res = res.replace("#endif+-+-+-", "#endif");

        }
        StringBuffer newResult = new StringBuffer();
        Stack<String> conditionStack = new Stack<>();
        String[] elements = res.split("\\+-\\+-\\+-\n");
        for (String e : elements) {
            if (e.length() > 0) {
                if (e.startsWith("#if")) {
                    String[] tmp = e.split("\n");
                    if (conditionStack.size() > 0) {
                        String lastCon = conditionStack.lastElement();
                        if (lastCon.equals(tmp[0])) {
                            StringBuffer x = new StringBuffer();
                            for (int i = 1; i < tmp.length - 1; i++) {
                                x.append(tmp[i] + "\n");
                            }
                            newResult.append(x);
                            continue;
                        } else {
                            conditionStack.pop();
                            conditionStack.push(tmp[0]);
                            newResult.append("#endif");
                            if (uniqueIFDEF == true) {
                                newResult.append("(IFDEF)");
                                uniqueIFDEF = false;
                            }

                            //-----------
//                        newResult += "\n+-+-+-\n";
                            newResult.append("\n");
                            //-----------


                        }
                    }

                    conditionStack.push(tmp[0]);

                    newResult.append(printNodeWithoutHeadandEnd(e, 0));
                    if (e.contains("IFDEF")) {
                        uniqueIFDEF = true;
                    }


                } else {
                    if (conditionStack.size() > 0) {
                        conditionStack.pop();
                        newResult.append("#endif\n");

                    }
                    newResult.append(e);
                    if (e.contains("###")) {
                        newResult.append("+-+-+-\n");
                    }

                }
            }
        }

        //----------
        newResult.append("#endif");
        if (uniqueIFDEF == true) {
            newResult.append("(IFDEF)");
        }

        return newResult.toString();
        //-----------
//        return newResult + "#endif\n";
    }


    public String clearBlank(String s) {
        return s.replace("\n", "").replace(" ", "").replace("\t", "");
    }

    /**
     * this function read the content of the file from filePath, and ready for comparing
     *
     * @param filePath file path
     * @return content of the file
     * @throws IOException e
     */
    public String readResult(String filePath) throws IOException {
        BufferedReader result_br = new BufferedReader(new FileReader(filePath));
        String result = "";
        try {
            StringBuilder sb = new StringBuilder();
            String line = result_br.readLine();

            while (line != null) {
                if (!line.isEmpty()) {
                    sb.append(line);
                    sb.append(System.lineSeparator());
                }
                line = result_br.readLine();
            }
            result = sb.toString();
        } finally {
            result_br.close();
        }
        return result;
    }


    public static String readCertainLine(int lineNum, String filePath) {

        String content = "";
        try (Stream<String> lines = Files.lines(Paths.get(filePath))) {
            content = lines.skip(lineNum - 1).findFirst().get();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return content;
    }

    /**
     * @param inputFile file that need to be parsed by srcML
     * @return path of XML file
     * @throws IOException e
     */
    public static String getXmlFile(String inputFile) {
        // create dir for store xml files

        String outXmlFile = inputFile + ".xml";
        //run srcML
        if (new File(inputFile).isFile()) {
            try {
                ProcessBuilder processBuilder = new ProcessBuilder("srcML/src2srcml", "--xmlns:PREFIX=http://www.sdml.info/srcML/position",
                        inputFile, "-o", outXmlFile);
                Process process = processBuilder.start();
                process.waitFor();

            } catch (IOException e) {
                e.printStackTrace();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        } else {
            System.out.println("File does not exist: " + inputFile);
        }
        return outXmlFile;
    }

    /**
     * parse xml file to DOM.
     *
     * @param xmlFilePath path of xml file
     */
    public static Document getXmlDom(String xmlFilePath) {
        IOFunctionSet io = new IOFunctionSet();
        Document doc = null;
        try {
            Builder builder = new Builder();
            File file = new File(xmlFilePath);

            sleep();
            String xml = io.readResult(xmlFilePath);
            if (xml.length() > 0) {
                doc = builder.build(file);

            }
        } catch (ParsingException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return doc;
    }


    public static void sleep() {
        try {
            Thread.sleep(500);                 //1000 milliseconds is one second.
        } catch (InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
    }


    public static String preprocessFile(String inputFile) {
        IOFunctionSet io = new IOFunctionSet();
        StringBuffer sb = new StringBuffer();
        String newInputFilePath;
        newInputFilePath = "/Users/shuruiz/Work/tmpXMLFile" + inputFile.replace("/Users/shuruiz/Work", "");

        String[] paths = inputFile.replace("testcpp", "").split("/");
        StringBuffer dir_suffix = new StringBuffer();
        for (int i = 1; i < paths.length - 1; i++) {
            dir_suffix.append("/" + paths[i]);
        }

        if (!new File(inputFile).exists()) {
            new File("/Users/shuruiz/Work/tmpXMLFile/" + dir_suffix.toString().replace("/Users/shuruiz/Work/", "")).mkdirs();
        }

        try (BufferedReader br = new BufferedReader(new FileReader(inputFile))) {

            String line;
            while ((line = br.readLine()) != null) {
                if (line.contains("typedef") && !line.contains("struct")) {
                    line = line.replace("typedef", "");
                }
                if (line.trim().endsWith("\\")) {
                    line = line.replace("\\", "");
                }

                sb.append(line.replace("inline _attribute_((always_inline))", "") + "\n");
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
        io.rewriteFile(sb.toString(), newInputFilePath);

        return newInputFilePath;
    }

    public String changeFileName(String fileName) {
        String suffix = fileName.split("\\.")[1];


        return fileName.replace("." + suffix, suffix.toUpperCase());
    }

}