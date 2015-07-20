package test;

import de.fosd.jdime.Main;
import org.apache.commons.cli.ParseException;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
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

    TestInitial(String p) {
        this.prefix = p;
        output_prefix = prefix + "Result/";
    }


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

    public String compileCpp(HashSet<String> config, String file, String filePath) {
        String originPath = filePath + file + suffix;
        String compiledPath = filePath + compile_path + file + "_";

        String cmd_compiling = "g++,-E,-P";

        if (config != null) {
            for (String s : config) {
                compiledPath += s;
                cmd_compiling += ",-D" + s;

            }
        }
        compiledPath += suffix;
        cmd_compiling += "," + originPath + ",-o," + compiledPath;

        File f = new File(compiledPath);
        f.getParentFile().mkdirs();
        try {
            f.createNewFile();
            try {
                Thread.sleep(10);                 //1000 milliseconds is one second.
            } catch (InterruptedException ex) {
                Thread.currentThread().interrupt();
            }
            ProcessBuilder process = new ProcessBuilder();
            process.command(cmd_compiling.split(","));
            Process p = process.start();
        } catch (IOException e) {
            e.printStackTrace();
        }

        return compiledPath;
    }

}
