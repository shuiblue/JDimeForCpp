package test;

import de.fosd.jdime.Main;
import org.apache.commons.cli.ParseException;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

/**
 * Created by shuruiz on 7/19/15.
 */
public class TestInitial {
    public String prefix = "";
    public String suffix = ".cpp";
    public String output_prefix = "";


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
                if(!line.isEmpty()) {
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

    public String checkCompiledResult(String config, String outputPath) {
        String testConfig = "g++,-E,-P," + config + suffix + ",-o," + outputPath + suffix + "";

        try {
            File file = new File(outputPath + suffix);
            file.getParentFile().mkdirs();
            file.createNewFile();
            ProcessBuilder process = new ProcessBuilder();
            String[] s = testConfig.split(",");
            process.command(s);
            Process p = process.start();


            return readResult(outputPath + suffix);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return "";

    }

}
