package de.fosd.jdime.dependencyGraph;

import de.fosd.jdime.util.IOFunctionSet;

import java.io.*;
import java.util.ArrayList;

/**
 * Created by shuruiz on 3/20/16.
 */
public class IdentifyChangedCode {
    String forkAddedNodeTxt = "forkAddedNode.txt";
    String expectTxt = "expectCluster.txt";
    String sourcecodeDir, analysisDir;
    ArrayList<String> commitSHAList;
    IOFunctionSet iof = new IOFunctionSet();

    public void identifyChangedCodeBySHA(String testDir, ArrayList<String> commitSHAList) {
        this.commitSHAList = commitSHAList;
        sourcecodeDir = testDir + "/Marlin/";
        analysisDir = testDir + "/DPGraph/";
        new File(analysisDir).mkdir();
        File dir = new File(sourcecodeDir);
        String[] names = dir.list();
        iof.rewriteFile("", analysisDir + forkAddedNodeTxt);
        iof.rewriteFile("", analysisDir + expectTxt);


        for (String fileName : names) {
//            if (fileName.endsWith(".cpp") || fileName.endsWith(".h") || fileName.endsWith(".c")) {
            if (fileName.endsWith(".cpp") || fileName.endsWith(".h") || fileName.endsWith(".c") || fileName.endsWith(".pde")) {
                try {
                    String cmd = "/usr/bin/git --git-dir=" + testDir + "/.git --work-tree=" + testDir + " blame -n --abbrev=6 " + sourcecodeDir + fileName;
                    Process p = Runtime.getRuntime().exec(cmd);
                    BufferedReader in = new BufferedReader(
                            new InputStreamReader(p.getInputStream()));
                    String line;
                    while ((line = in.readLine()) != null) {
                        if (line.length() > 0) {
                            checkSHA(line, fileName);
                        }
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
//                iof.rewriteFile(sb.toString(), analysisDir + fileName + SHA);
            }
        }
    }

    private void checkSHA(String line, String fileName) {
        String suffix = fileName.split("\\.")[1];
        String newFileName = fileName.replace("." + suffix, suffix.toUpperCase());

        String blameLines[] = line.split(" ");
        String sha = blameLines[0];

//        String blameLines[] = line.split(" ");
//        String sha = blameLines[0]
        String splitParenthesis = line.split(" \\(")[0];
        String lineNum = splitParenthesis.substring(splitParenthesis.lastIndexOf(" ") + 1, splitParenthesis.length());


        if (commitSHAList.contains(sha)) {
            String s = line.split("\\)")[0];
            String code = line.split("\\)")[1];

//            String lineNum = s.substring(s.lastIndexOf(" ") + 1, s.length());

            boolean comments = false;
            String cleanCode = code.trim();
            if (!cleanCode.equals("")) {
                if (!cleanCode.startsWith("//") && !comments) {
//                    System.out.println(newFileName + "-" + lineNum);
                    iof.writeTofile(newFileName + "-" + lineNum + " \n", analysisDir + forkAddedNodeTxt);
                    if (!cleanCode.startsWith("#")) {
                        iof.writeTofile(newFileName + "-" + lineNum + " 1\n", analysisDir + expectTxt);
                    }
                } else if (cleanCode.startsWith("/*")) {
                    comments = true;
                } else if (cleanCode.startsWith("*/") && comments) {
                    comments = false;
                }
            }


        }


    }

    public void identifyIfdefs(String testDir, ArrayList<String> macroList) {
        sourcecodeDir = testDir + "/Marlin/";
        analysisDir = testDir + "/DPGraph/";
        File dir1 = new File(sourcecodeDir);
        File dir2 = new File(analysisDir);
        dir2.mkdir();
        String[] names = dir1.list();
        iof.rewriteFile("", analysisDir + forkAddedNodeTxt);
        iof.rewriteFile("", analysisDir + expectTxt);
        ArrayList<String> macroStack = new ArrayList<>();
        StringBuffer forkAddedNodeString = new StringBuffer();
        StringBuffer expectedClusterString = new StringBuffer();

        for (String fileName : names) {
//            if (fileName.endsWith(".cpp") || fileName.endsWith(".h") || fileName.endsWith(".c")) {
            if (fileName.endsWith(".cpp") || fileName.endsWith(".h") || fileName.endsWith(".c") || fileName.endsWith(".pde")) {

                int startLine = 0;
                boolean withinIfdef = false;
                String newFileName = "";

                for (String targetMacro : macroList) {
//                    System.out.println(targetMacro + "!");
                    try {
                        BufferedReader result = new BufferedReader(new FileReader(sourcecodeDir + fileName));
                        String line;
                        int lineNum = 1;
                        String macro = "";
                        int currentCommunityNum = -1;
                        while ((line = result.readLine()) != null) {
//                            System.out.println(fileName + "-" + lineNum);
                            if (line.contains("#if") || line.contains("#elif")) {
                                if (line.contains("if ENABLED(")) {


                                    if (macroStack.size() > 0 && line.contains("elif")) {
                                        macroStack.remove(macroStack.size() - 1);
                                        if (macroStack.size() == 0) {
                                            withinIfdef = false;
                                        }
                                    }
                                    String[] conditions = line.split("\\|\\|");
                                    for (String c : conditions) {
                                        if (c.contains("ENABLED(")) {

                                            int leftPare = c.indexOf("(");
                                            int rightPare = c.indexOf(")");
                                            macro = c.substring(leftPare + 1, rightPare).trim();
                                            if (targetMacro.equals(macro)) {
                                                break;
                                            }
                                        }
                                    }

                                } else if (line.contains("#ifdef")) {
                                    macro = line.trim().substring(7);
                                }


                                if (targetMacro.equals(macro)) {
                                    withinIfdef = true;
                                    startLine = lineNum + 1;
                                    macroStack.add(macro);
                                    currentCommunityNum = macroList.indexOf(macro) + 1;
                                    //Rewrite the file name for html purpose
                                    newFileName = iof.changeFileName(fileName);
                                }
                            /* for test 22
                            else if (line.contains("#if HAS_BUZZER")) {
                                withinIfdef = true;
                                startLine = lineNum + 1;
                                macro = "HAS_BUZZER";
                                currentCommunityNum=macroList.indexOf(macro) + 1;
                                macroStack.add(macro);
                                //Rewrite the file name for html purpose
                                String suffix = fileName.split("\\.")[1];
                                newFileName = fileName.replace("." + suffix, suffix.toUpperCase());

                            }
                            */
                                else if (macroStack.size() > 0) {
                                    macroStack.add(line);
                                }

                            } else if (macroStack.size() > 0 && (line.contains("#endif"))) {
                                macroStack.remove(macroStack.size() - 1);
                                if (macroStack.size() == 0) {
                                    withinIfdef = false;
                                }
                            } else if (macroStack.size() == 1 && (line.contains("#else"))) {
                                macroStack.remove(macroStack.size() - 1);
                                if (macroStack.size() == 0) {
                                    withinIfdef = false;
                                }
                            }

                            if (startLine <= lineNum && withinIfdef) {
                                String nodeId = newFileName + "-" + lineNum + " ";

                                if (!forkAddedNodeString.toString().contains(nodeId)) {
                                    forkAddedNodeString.append(nodeId + "\n");
                                    expectedClusterString.append(nodeId + currentCommunityNum + "\n");
                                } else {

                                    String tmp = expectedClusterString.toString();
                                    expectedClusterString = new StringBuffer();
                                    expectedClusterString.append(tmp.replace(nodeId, nodeId  + currentCommunityNum + "/"));

                                }


                            }
                            lineNum++;
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                    }

                }
            }
        }
        iof.writeTofile(forkAddedNodeString.toString(), analysisDir + forkAddedNodeTxt);
        iof.writeTofile(expectedClusterString.toString(), analysisDir + expectTxt);

    }


}
