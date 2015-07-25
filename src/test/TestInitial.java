package test;

import de.fosd.jdime.Main;
import org.apache.commons.cli.ParseException;

import java.io.*;
import java.nio.file.*;
import java.nio.file.attribute.BasicFileAttributes;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

/**
 * Created by shuruiz on 7/19/15.
 */
public class TestInitial {
    public String prefix = "";
    public String suffix = ".cpp";
    public String output_prefix = "";
    String compile_path = "compiled/";

    /**
     * constructor
     *
     * @param p prefix
     */
    TestInitial(String p) {
        this.prefix = p;
        output_prefix = prefix + "Result/";
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

    /**
     * run main()
     *
     * @param inputFilePaths input files
     * @param outputPath     output merged file
     */
    public void runMain(ArrayList<String> inputFilePaths, String outputPath) {
        String commandLine = "-mode,nway,-output," + prefix + outputPath + suffix + ",";
        for (int i = 0; i < inputFilePaths.size(); i++) {

            commandLine += prefix + inputFilePaths.get(i) + suffix;
            if (i < inputFilePaths.size() - 1) {
                commandLine += ",";
            }
        }
        String[] arg = commandLine.split(",");
        try {
            Main.main(arg);
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ParseException e) {
            e.printStackTrace();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    /**
     * check merged file is equal to expect result
     *
     * @param inputFilePaths
     * @param outputPath
     * @param expectResultPath
     * @return true/false
     */
    public boolean checkMerge(ArrayList<String> inputFilePaths, String outputPath, String expectResultPath) {
        runMain(inputFilePaths, outputPath);
        String result = "";
        String expect_result = "";
        try {
            result = readResult(prefix + outputPath + suffix);
            expect_result = readResult(prefix + expectResultPath + suffix);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return result.equals(expect_result);
    }

    /**
     * wrapper for check Merge-- for new test cases
     *
     * @return
     */
    public boolean checkMerge_wrapper(HashSet<String> fileName, String testNum, String output) {
        ArrayList<String> inputFilePaths = new ArrayList<>();

        for (String s : fileName) {
            inputFilePaths.add(testNum + s);
        }

        String outputPath = testNum + output;
        String expectResultPath = testNum + "expect";

        return checkMerge(inputFilePaths, outputPath, expectResultPath);
    }

    /**
     * check if merged files after preprocessed under certain configuration is equal to preprocessed origin input file under same config
     *
     * @param config
     * @param merged
     * @param origin
     * @param path
     * @param testNum
     * @return
     */
    public boolean checkProprocessResult(HashSet<String> config, String merged, String origin, String path, String testNum) {
        String filePath = path + testNum;

        String r1 = compileCpp(config, merged, filePath);
        String r2 = compileCpp(config, origin, filePath);
        try {
            return readResult(r1).equals(readResult(r2));
        } catch (IOException e) {
            e.printStackTrace();
        }
        return false;
    }

    /**
     * preprocess cpp file
     *
     * @param config   configuration
     * @param file
     * @param filePath input file
     * @return output path
     */
    public String compileCpp(HashSet<String> config, String file, String filePath) {
        String originPath = filePath + file + suffix;
        String compiledPath = filePath + compile_path + file + "_";

        String cmd_compiling = "g++,-E,-P";

        if (config != null) {
            for (String s : config) {
            if (s.contains(">")||s.contains("<")||s.contains("=")) {
                   s= s.replace('<','l');
                   s= s.replace('>','b');
                   s= s.replace('=','e');

                }

                if (s.startsWith("!")) {
                    compiledPath += "not" + s.substring(1);
                    cmd_compiling += ",-U" + s.substring(1);

                } else{
                    compiledPath += s;
                    cmd_compiling += ",-D" + s;
                }
            }
        }

        compiledPath += suffix;
        cmd_compiling += "," + originPath + ",-o," + compiledPath;

        File f = new File(compiledPath);
        f.getParentFile().mkdirs();
        try {
            f.createNewFile();

            ProcessBuilder process = new ProcessBuilder();
            process.command(cmd_compiling.split(","));
            Process p = process.start();
        } catch (IOException e) {
            e.printStackTrace();
        }

        return compiledPath;
    }

    /**
     * test every possible configuration set
     *
     * @param config
     * @param fileName
     * @param output
     * @param path
     * @param testNum
     * @return true if all the comparation are true
     */
    boolean result = true;

    /**
     * test every possible configuration
     *
     * @param config
     * @param fileNameSet
     * @param output
     * @param path
     * @param testNum
     * @return
     */
    public boolean testEveryConfig(HashSet<String> config, HashSet<String> fileNameSet, String output, String path, String testNum) {
        Set<Set<String>> configuration = getAllConfigurations(config);
        Set<String> feature = new HashSet<>();
        for (String file : fileNameSet) {
            for (Set<String> c : configuration) {

                feature.addAll(c);
                feature.add(file);
                System.out.println("## running config " + feature.toString());
                System.out.println(checkProprocessResult((HashSet<String>) feature, output, file, path, testNum));
                result = result && checkProprocessResult((HashSet<String>) feature, output, file, path, testNum);
                feature = new HashSet<>();
            }
        }
        return result;
    }

    /**
     * get all the configuration
     *
     * @param features
     * @return
     */
    private Set<Set<String>> getAllConfigurations(HashSet<String> features) {
        Set<Set<String>> configurations = new HashSet<Set<String>>();
        configurations.add(new HashSet());
        for (String feature : features) {
            Set<Set<String>> newconfigurations = new HashSet<Set<String>>();
            for (Set<String> c : configurations) {
                HashSet<String> newConfig = new HashSet<String>(c);
                newConfig.add(feature);
                newconfigurations.add(newConfig);
            }
            configurations.addAll(newconfigurations);
        }

        return configurations;
    }

    /**
     * clean temp file ".xml" and compiled folders
     */
    public void clearTmpFile() {
        Path directory = Paths.get("testcpp/");
        try {
            Files.walkFileTree(directory, new SimpleFileVisitor<Path>() {
                @Override
                public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {
                    if (file.getFileName().toString().endsWith("xml") || file.getFileName().toString().contains("_")) {
                        Files.delete(file);
                    }
                    return FileVisitResult.CONTINUE;
                }

                @Override
                public FileVisitResult postVisitDirectory(Path dir, IOException exc) throws IOException {
                    if (dir.getFileName().toString().equals("compiled")) {
                        Files.delete(dir);
                    }
                    return FileVisitResult.CONTINUE;
                }

            });
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public HashSet<String> inputFileInit(int i) {
        HashSet<String> fileName = new HashSet<>();
        char A = 'A';
        fileName.add("A");
        for (int j = 1; j < i; j++) {
            fileName.add(String.valueOf(++A));
        }
        return fileName;
    }
}
