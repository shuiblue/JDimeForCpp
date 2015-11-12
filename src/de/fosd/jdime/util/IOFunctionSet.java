package de.fosd.jdime.util;

import nu.xom.*;

import java.io.*;
import java.util.Stack;

/**
 * Created by shuruiz on 8/31/15.
 */
public class IOFunctionSet {


    public String printNodeWithoutHeadandEnd(String s, int head) {
        String blockString = "";
        if (s.endsWith(":")) {
            for (int i = head; i < s.split("\n").length - 2; i++) {
                blockString += s.split("\n")[i] + "\n";
            }
            blockString += ":";
        } else {
            for (int i = head; i < s.split("\n").length - 1; i++) {
                blockString += s.split("\n")[i] + "\n";
            }
        }
        return blockString;
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

        String newResult = "";
        Stack<String> conditionStack = new Stack<>();
        String[] elements = res.split("\\+-\\+-\\+-\n");
        for (int j = 0; j < elements.length; j++) {
            String e = elements[j];

            if (e.length() > 0 && !e.equals("\n")) {
                String[] tmp = e.split("\n");
                if (conditionStack.size() > 0) {
                    String lastCon = conditionStack.lastElement();
                    if (lastCon.equals(tmp[0])) {
                        newResult += printNodeWithoutHeadandEnd(e, 1);
                        continue;
                    } else {
                        conditionStack.pop();
                        if (tmp[0].equals(blockCondition.replace("\n", ""))) {
                            newResult += "#endif\n";
                            if (tmp.length > 3) {
                                for (int i = 1; i < tmp.length - 1; i++) {
                                    newResult += tmp[i] + "\n";
                                }
                            } else {
                                newResult += tmp[1] + "\n";
                            }
                            continue;
                        } else {
                            newResult += "#endif\n";

                            if (!tmp[0].startsWith("#if defined")) {
                                newResult += e;
                            } else {
                                newResult += printNodeWithoutHeadandEnd(e, 0);
                                conditionStack.push(tmp[0]);
                            }
                        }
                    }
                } else {
                    if (tmp[0].startsWith("#if defined")) {
                        if (!tmp[0].equals(blockCondition.replace("\n", ""))) {
                            conditionStack.push(tmp[0]);
                            newResult += printNodeWithoutHeadandEnd(e, 0);
                        } else {
                            newResult += printNodeWithoutHeadandEnd(e, 1);
                        }
                    } else {
                        newResult += e;
                        if (!e.endsWith("\n")) {
                            newResult += "\n";
                        }
                    }
                }
            }
        }
        if (conditionStack.size() > 0) {
            conditionStack.pop();
            newResult += "#endif\n";
        }

        return newResult;
    }


    public String presicePrettyprint(String res) {
        boolean uniqueIFDEF = false;

        while (res.contains("#endif+-+-+-")) {
            res = res.replace("#endif+-+-+-", "#endif");

        }
        String newResult = "";
        Stack<String> conditionStack = new Stack<>();
        String[] elements = res.split("\\+-\\+-\\+-\n");
        for (String e : elements) {
            if (e.length() > 0) {
                if (e.startsWith("#if")) {
                    String[] tmp = e.split("\n");
                    if (conditionStack.size() > 0) {
                        String lastCon = conditionStack.lastElement();
                        if (lastCon.equals(tmp[0])) {
                            String x = "";
                            for (int i = 1; i < tmp.length - 1; i++) {
                                x += tmp[i] + "\n";
                            }
                            newResult += x;
                            continue;
                        } else {
                            conditionStack.pop();
                            conditionStack.push(tmp[0]);
                            newResult += "#endif";
                            if (uniqueIFDEF == true) {
                                newResult += "(IFDEF)";
                                uniqueIFDEF = false;
                            }

                            //-----------
//                        newResult += "\n+-+-+-\n";
                            newResult += "\n";
                            //-----------


                        }
                    }

                    conditionStack.push(tmp[0]);

                    newResult += printNodeWithoutHeadandEnd(e, 0);
                    if (e.contains("IFDEF")) {
                        uniqueIFDEF = true;
                    }


                } else {
                    if (conditionStack.size() > 0) {
                        conditionStack.pop();
                        newResult += "#endif\n";

                    }
                    newResult += e;
                    if (e.contains("###")) {
                        newResult += "+-+-+-\n";
                    }

                }
            }
        }

        //----------
        newResult += "#endif";
        if (uniqueIFDEF == true) {
            newResult += "(IFDEF)";
        }

        return newResult;
        //-----------
//        return newResult + "#endif\n";
    }



    public String clearBlank(String s) {
        return s.replace("\n", "").replace(" ", "").replace("\t", "");
    }


    /**
     * @param inputFile file that need to be parsed by srcML
     * @return path of XML file
     * @throws IOException e
     */
    public static String getXmlFile(String inputFile) {
        // create dir for store xml files
        String outXmlFile = "/Users/shuruiz/Work/tmpXMLFile" + inputFile.replace("testcpp", "") + ".xml";
        String[] paths = inputFile.replace("testcpp", "").split("/");
        String dir_suffix = "";
        for (int i = 1; i < paths.length - 1; i++) {
            dir_suffix += "/" + paths[i];
        }
        if (!new File(outXmlFile).exists()) {
            new File("/Users/shuruiz/Work/tmpXMLFile/" + dir_suffix).mkdirs();
        }

        //run srcML
        if (new File(inputFile).isFile()) {
            try {
                new ProcessBuilder("/usr/local/bin/src2srcml","--xmlns:PREFIX=http://www.sdml.info/srcML/position",
                        inputFile, "-o", outXmlFile).start();
                sleep();
            } catch (IOException e) {
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
        Document doc = null;
        try {
            Builder builder = new Builder();
            File file = new File(xmlFilePath);
            sleep();
            doc = builder.build(file);
        } catch (ParsingException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return doc;
    }

    /**
     * parse AST to add CppNode into candidates
     *
//     * @param astNode
     */
//    public static void parseASTforDependencyGraph(Node astNode) {
//
//        int childrenNum = astNode.getChildCount();
//        for (int i = 0; i < childrenNum; i++) {
//            Node child = astNode.getChild(i);
//            String astNodeType = child.getClass().getName();
//
//            if (astNodeType.contains("Text")) {
//                if (child.getValue().contains("\n")) {
//                    lineNum++;
//                }
//            }
//            if (astNodeType.contains("Element")) {
//                String localName = ((Element) child).getLocalName();
//                if (localName.equals("decl_stmt")) {
//                    String type = ((Element) child).getChildElements().get(0).getChildElements("type", "http://www.sdml.info/srcML/src").get(0).getValue();
//                    String name = ((Element) child).getChildElements().get(0).getChildElements("name", "http://www.sdml.info/srcML/src").get(0).getValue();
//                    candidates.add(new CppNode(name, type, localName, lineNum));
//                } else if (localName.equals("function_decl")) {
//                    String type = ((Element) child).getChildElements().get(0).getValue();
//                    String name = ((Element) child).getChildElements().get(1).getValue();
//                    candidates.add(new CppNode(name, type, localName, lineNum));
//                } else if (localName.equals("function")) {
//                    String type = ((Element) child).getChildElements().get(0).getValue();
//                    String name = ((Element) child).getChildElements().get(1).getValue();
//                    candidates.add(new CppNode(name, type, localName, lineNum));
//                    parseAST(child);
//                } else if (localName.equals("block")) {
//                    parseAST(child);
//                } else if (localName.equals("expr_stmt")) {
//                    Element exprChild = ((Element) ((Element) child).getChildElements().get(0).getChild(0));
//                    String exprType = exprChild.getLocalName();
//                    if (exprType.equals("name")) {
//                        String name = exprChild.getValue();
//                        String type = "";
//                        candidates.add(new CppNode(name, type, localName, lineNum));
//                    } else if (exprType.equals("call")) {
//                        String name = exprChild.getChild(0).getValue();
//                        String type = "call";
//                        candidates.add(new CppNode(name, type, localName, lineNum));
//                        parseAST(exprChild);
//                    }
//                } else if (localName.equals("call")) {
//                    String name = child.getChild(0).getValue();
//                    String type = "call";
//                    candidates.add(new CppNode(name, type, localName, lineNum));
//                    parseAST(child);
//                } else if (localName.equals("argument")) {
//                    Element c = ((Element) ((Element) child).getChildElements().get(0).getChild(0));
//                    if (c.getLocalName().equals("name")) {
//                        String name = c.getValue();
//                        String type = "";
//                        candidates.add(new CppNode(name, type, localName, lineNum));
//                    } else {
//                        parseAST(child);
//                    }
//
//
//                } else if (!entity.getTerminal().contains(localName)) {
//                    parseAST(child);
//                }
//
//            }
//        }
//
//    }

    public static void sleep() {
        try {
            Thread.sleep(300);                 //1000 milliseconds is one second.
        } catch (InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
    }

}