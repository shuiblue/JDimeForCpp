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
    StringBuffer forkAddedNodeString = new StringBuffer();
    StringBuffer expectedClusterString = new StringBuffer();

    public void identifyChangedCodeBySHA(String projectPath, String repo, ArrayList<String> commitSHAList) {
        String testDir = projectPath + repo;
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
        String newFileName = fileName.replace("." + suffix, suffix.toUpperCase()).replace("-", "~");;

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

    public void identifyChangedCodeFromFile(String fileName, ArrayList<String> macroList) {
        ArrayList<String> macroStack = new ArrayList<>();

        int startLine = 0;
        boolean withinIfdef = false;
        String newFileName = "";
        File currentFile = new File(sourcecodeDir + "/" + fileName);
        if (currentFile.isFile()) {
            if (fileName.endsWith(".cpp") || fileName.endsWith(".h") || fileName.endsWith(".c") || fileName.endsWith(".pde")) {

                for (String targetMacro : macroList) {
                    try {
                        BufferedReader result = new BufferedReader(new FileReader(sourcecodeDir + "/" + fileName));
                        String line;
                        int lineNum = 1;
                        String macro = "";
                        int currentCommunityNum = -1;
                        while ((line = result.readLine()) != null) {
//                            System.out.println(fileName + "-" + lineNum);
                            if (line.contains("#if") || line.contains("#elif")) {
                                if (line.contains("if ENABLED(") || line.contains("elif")) {
                                    if (macroStack.size() > 0 && line.contains("elif")) {
                                        macroStack.remove(macroStack.size() - 1);
                                        if (macroStack.size() == 0) {
                                            withinIfdef = false;
                                            macro = "";
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
                                } else{
                                    macro = line.trim();
                                }
                                if (targetMacro.equals(macro)) {
                                    withinIfdef = true;
                                    startLine = lineNum + 1;
                                    macroStack.add(macro);


                                    currentCommunityNum = macroList.indexOf(macro) + 1;
                                    //Rewrite the file name for html purpose
                                    newFileName = iof.changeFileName(fileName);
                                } else if (macroStack.size() > 0) {
                                    macroStack.add(line);
                                }

                            } else if (macroStack.size() > 0 && (line.contains("#endif"))) {
                                macroStack.remove(macroStack.size() - 1);
                                if (macroStack.size() == 0) {
                                    withinIfdef = false;
                                    macro = "";
                                }
                            } else if (macroStack.size() == 1 && (line.contains("#else"))) {
                                macroStack.remove(macroStack.size() - 1);
                                if (macroStack.size() == 0) {
                                    withinIfdef = false;
                                    macro = "";
                                }
                            }

                            if (startLine <= lineNum && withinIfdef && currentCommunityNum != -1) {
                                String nodeId = newFileName + "-" + lineNum + " ";

                                if (!forkAddedNodeString.toString().contains(nodeId)) {
                                    forkAddedNodeString.append(nodeId + "\n");
                                    expectedClusterString.append(nodeId + currentCommunityNum + "\n");
                                } else {

                                    String tmp = expectedClusterString.toString();
                                    expectedClusterString = new StringBuffer();
                                    expectedClusterString.append(tmp.replace(nodeId, nodeId + currentCommunityNum + "/"));

                                }


                            }
                            lineNum++;
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                    }

                }
            }
        } else if (currentFile.isDirectory()) {
            String[] subNames = currentFile.list();
            for (String f : subNames) {
                identifyChangedCodeFromFile(fileName+"/"+f, macroList);
            }
        }
    }

    public void identifyIfdefs(String projectPath, String repo, int dirNum, ArrayList<String> macroList) {
        String testDir = projectPath + repo;
        sourcecodeDir = testDir + "/" + repo;
        analysisDir = testDir + "/DPGraph/" + dirNum + "/";
        File dir1 = new File(sourcecodeDir);
        File dir2 = new File(analysisDir);
        dir2.mkdirs();
        String[] names = dir1.list();
        iof.rewriteFile("", analysisDir + forkAddedNodeTxt);
        iof.rewriteFile("", analysisDir + expectTxt);

        for (String fileName : names) {
            identifyChangedCodeFromFile(fileName, macroList);
        }
        iof.writeTofile(forkAddedNodeString.toString(), analysisDir + forkAddedNodeTxt);
        iof.writeTofile(expectedClusterString.toString(), analysisDir + expectTxt);

    }


}
