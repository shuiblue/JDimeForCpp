package de.fosd.jdime.dependencyGraph;

import de.fosd.jdime.util.IOFunctionSet;
import org.rosuda.JRI.Rengine;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;

/**
 * Created by shuruiz on 4/3/16.
 */
public class mainForTestIfdef {

    static String projectPath = "/Users/shuruiz/Work/MarlinRepo/IfdefGroundTruth/";
    static ArrayList<String> commitList = new ArrayList<>();
    static AnalyzeMarlinRepo amr = new AnalyzeMarlinRepo();


    static IOFunctionSet iof = new IOFunctionSet();
    static ArrayList<String> macroList;
    static int numOfTargetMacro = 5;
    static String sourcecodeDir;
    static String analysisDir;


    public static void findIndependentMacros(String fileName) {
        int linenum = 1;
        ArrayList<String> macroStack = new ArrayList<>();
        String macro = "";
        File currentFile = new File(sourcecodeDir + "/" + fileName);
        boolean headerguard = false;
        int boundary;
        if (currentFile.isFile()) {
            if (fileName.endsWith(".cpp") || fileName.endsWith(".h") || fileName.endsWith(".c") || fileName.endsWith(".pde")) {
                try {
                    BufferedReader result = new BufferedReader(new FileReader(sourcecodeDir + "/" + fileName));
                    String line;
                    while ((line = result.readLine()) != null) {
                        if (line.contains("#if") || line.contains("#elif")) {
                            if (line.contains("if ENABLED(")) {
                                String[] conditions = line.split("\\|\\|");
                                for (String c : conditions) {
                                    if (c.contains("ENABLED(")) {

                                        int leftPare = c.indexOf("(");
                                        int rightPare = c.indexOf(")");
                                        macro = c.substring(leftPare + 1, rightPare).trim();
                                    }
                                }
                            } else if (line.contains("#ifdef")) {
                                macro = line.trim().substring(7);
                            } else if (line.contains("#ifndef")) {
                                if (fileName.trim().endsWith(".h")) {
                                    String name = line.trim().substring(8);
                                    String[] tmp = fileName.split("/");

                                    String file = tmp[tmp.length - 1].trim();
                                    file = file.split("\\.")[0].toUpperCase() + "_" + file.split("\\.")[1].toUpperCase();
                                    if (name.equals(file)) {
                                        headerguard = true;
                                    }
                                }
                            }

                            if (!headerguard) {
                                macroStack.add(macro);
                            }
                        } else if (line.contains("#endif")) {
                            if (macroStack.size() == 0) {
                                break;
                            }

                            if (headerguard) {
                                boundary = 1;
                            } else {
                                boundary = 0;
                            }


                            String removedMacro = macroStack.get(macroStack.size() - 1);

                            macroStack.remove(macroStack.remove(macroStack.size() - 1));
                            if (macroStack.size() == boundary && !macroList.contains(removedMacro) && !removedMacro.equals("") && !removedMacro.startsWith("#")) {
                                macroList.add(removedMacro);
                            }

                        }
                        linenum++;

                    }

                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        } else if (currentFile.isDirectory()) {
            String[] subNames = currentFile.list();
            for (String f : subNames) {
                findIndependentMacros(fileName + "/" + f);
            }
        }
    }


    public static void createMacroList() {

        macroList = new ArrayList<>();

        File dir1 = new File(sourcecodeDir);
        File dir2 = new File(analysisDir);
        String[] names = dir1.list();
        dir2.mkdirs();


        for (String fileName : names) {
//            if (fileName.endsWith(".cpp") || fileName.endsWith(".h") || fileName.endsWith(".c")) {
            findIndependentMacros(fileName);
        }
    }


    public static ArrayList<String> selectTargetMacros(int number) {
        ArrayList<String> targetMacros = new ArrayList<>();
        ArrayList<Integer> indexList = new ArrayList<>();
        while (indexList.size() < 5) {
            Random random = new Random();
            int index = random.ints(0, (macroList.size() - 1)).findFirst().getAsInt();
            if (!indexList.contains(index)) {

                indexList.add(index);
                System.out.println("macroList.size()"+macroList.size());
                System.out.println("index"+index);
                targetMacros.add(macroList.get(index));
            }
        }

        return targetMacros;

    }

    public static void main(String[] args) {
        //start import R library
        System.out.println("Creating Rengine (with arguments)");
        //If not started with --vanilla, funny things may happen in this R shell.

        String[] Rargs = {"--vanilla"};
        Rengine re = new Rengine(Rargs, false, null);
        System.out.println("Rengine created, waiting for R");
        // the engine creates R is a new thread, so we should wait until it's
        // ready
        if (!re.waitForR()) {
            System.out.println("Cannot load R");
            return;
        }


        ArrayList<String> repoList = new ArrayList<>();
        repoList.add("Clamav");
        repoList.add("Marlin");
        repoList.add("Apache");
        repoList.add("Cherokee");
        repoList.add("dia");
        repoList.add("BerkleyDB");
//        repoList.add("Email");


        for (String repo : repoList) {
            sourcecodeDir = projectPath + repo + "/" + repo;
            analysisDir = projectPath + repo + "/DPGraph/";

            createMacroList();
            StringBuffer macroListSB = new StringBuffer();
            for (String s : macroList) {
                macroListSB.append(s + "\n");
            }
            iof.rewriteFile(macroListSB.toString(), analysisDir + "macroList.txt");



            for (int dirNum = 2; dirNum < 3; dirNum++) {
//                ArrayList<String> macroList = selectTargetMacros(numOfTargetMacro);
                ArrayList<String> macroList = new ArrayList<>();

                macroList.add("CL_DEBUG");
                macroList.add("__cplusplus");
                macroList.add("IN_LIBXML");
                macroList.add("LT_DEBUG_LOADERS");
                macroList.add("HAVE_RINTF");

                StringBuffer sb = new StringBuffer();
                for (int i = 1; i <= macroList.size(); i++) {
                    sb.append("<h3>" + i + ") " + macroList.get(i - 1) + "</h3>\n");
                }
                new File(analysisDir + dirNum).mkdir();
                iof.rewriteFile(sb.toString(), analysisDir + dirNum + "/testedMacros.txt");
                commitList = new ArrayList<>();
                int numOfcut = 4;
                amr.analyzeRepository(repo, dirNum, projectPath, commitList, macroList, numOfcut, re);
            }
        }
    }
}
