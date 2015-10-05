package de.fosd.jdime.util;

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
}