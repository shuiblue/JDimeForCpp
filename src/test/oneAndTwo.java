package test;

import static org.junit.Assert.*;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import org.apache.commons.cli.ParseException;
import org.junit.Test;

import de.fosd.jdime.*;

;

public class oneAndTwo {
    public ArrayList<String> setInputFiles() {
        ArrayList<String> inputFilePaths = new ArrayList<String>();
        inputFilePaths.add("testcpp/1/1.cpp");
        inputFilePaths.add("testcpp/1/2.cpp");
        return inputFilePaths;
    }

    public String readResult(String filePath) throws IOException {
        BufferedReader result_br = new BufferedReader(new FileReader(filePath));
        String result = "";
        try {
            StringBuilder sb = new StringBuilder();
            String line = result_br.readLine();

            while (line != null) {
                sb.append(line);
                sb.append(System.lineSeparator());
                line = result_br.readLine();
            }
            result = sb.toString();
        } finally {
            result_br.close();
        }
        return result;
    }

    public void checkMerge(ArrayList<String> inputFilePaths, String outputPath, String expectResultPath) {
        String commandLine = " \"-mode\", \"nway\", \"-output\",\"";
        for (String s : inputFilePaths) {
            commandLine += s + "\",\"";
        }
        commandLine += "\"";

        try {
            Main.main(new String[]{commandLine});
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ParseException e) {
            e.printStackTrace();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }


    }

    @Test
    public void test1() {
        List<String> inputFilePaths = setInputFiles();
        String outputPath = "testcpp/1/12.cpp";
        String expectResultPath = "testcpp/1/expect.cpp";
        checkMerge(inputFilePaths, );
        String result, expect_result = "";
        try {
            result = readResult(outputPath);
            expect_result = readResult(expectResultPath);
        } catch (IOException e) {
            e.printStackTrace();
        }
        assertEquals(result, expect_result);
    }
}