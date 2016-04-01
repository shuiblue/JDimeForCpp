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
                    System.out.println(newFileName + "-" + lineNum);
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


        for (String fileName : names) {
//            if (fileName.endsWith(".cpp") || fileName.endsWith(".h") || fileName.endsWith(".c")) {
            if (fileName.endsWith(".cpp") || fileName.endsWith(".h") || fileName.endsWith(".c") || fileName.endsWith(".pde")) {
                int lineNum = 1;
                int startLine = 0;
                boolean withinIfdef = false;
                String newFileName = "";

                try {
                    BufferedReader result = new BufferedReader(new FileReader(sourcecodeDir + fileName));
                    String line;
                    String macro = "";
                    int currentCommunityNum=-1;
                    while ((line = result.readLine()) != null) {

                        if (line.contains("#if")) {
                            if (line.contains("#if ENABLED")) {
//                        if (line.contains("#ifdef")) {
                                // this condition only consider the isolated ifdefs, ignores the nested one.
//                                if (macroStack.size() == 0) {

                                int leftPare = line.indexOf("(");
                                int rightPare = line.indexOf(")");
                                macro = line.substring(leftPare + 1, rightPare).trim();
//                                System.out.println(macro);
                                if (macroList.contains(macro)) {
                                    withinIfdef = true;
                                    startLine = lineNum + 1;
                                    macroStack.add(macro);
                                    currentCommunityNum=macroList.indexOf(macro) + 1;
                                    //Rewrite the file name for html purpose
                                    String suffix = fileName.split("\\.")[1];
                                    newFileName = fileName.replace("." + suffix, suffix.toUpperCase());
                                }else if(macroStack.size()>0){
                                    macroStack.add(line);
                                }
//                                }


                            } else if (line.contains("#if HAS_BUZZER")) {
                                withinIfdef = true;
                                startLine = lineNum + 1;
                                macro = "HAS_BUZZER";
                                currentCommunityNum=macroList.indexOf(macro) + 1;
                                macroStack.add(macro);
                                //Rewrite the file name for html purpose
                                String suffix = fileName.split("\\.")[1];
                                newFileName = fileName.replace("." + suffix, suffix.toUpperCase());

                            } else if(macroStack.size()>0){
                                macroStack.add(line);
                            }

                        } else if (macroStack.size() > 0 && (line.contains("#endif"))) {
                            macroStack.remove(macroStack.size() - 1);
                            if (macroStack.size() == 0) {
                                withinIfdef = false;
                            }
                        }else if( line.contains("#elif")){
                            boolean useful = false;
                            for(String s: macroList){
                                if(line.contains(s)){

                                    useful=true;
                                    break;
                                }
                            }
                            if(useful) {
                                System.out.print("alert: "+fileName+"-"+lineNum);
                            }
                        }else if (macroStack.size() ==1 && (line.contains("#else"))) {
                            macroStack.remove(macroStack.size() - 1);
                            if (macroStack.size() == 0) {
                                withinIfdef = false;
                            }
                        }

                        if (startLine <= lineNum && withinIfdef) {
                            iof.writeTofile(newFileName + "-" + lineNum + " \n", analysisDir + forkAddedNodeTxt);
                            iof.writeTofile(newFileName + "-" + lineNum + " " +currentCommunityNum  + "\n", analysisDir + expectTxt);


                        }
                        lineNum++;
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        System.out.print("");
    }
}
