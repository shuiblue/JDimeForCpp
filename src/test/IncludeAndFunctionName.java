package test;

import de.fosd.jdime.Main;
import org.apache.commons.cli.ParseException;
import org.junit.Test;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

import static org.junit.Assert.assertTrue;

/**
 * Created by shuruiz on 7/14/15.
 */
public class IncludeAndFunctionName {
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

    public void runMain(ArrayList<String> inputFilePaths, String outputPath) {
        String commandLine = "-mode,nway,-output," + outputPath + ",";
        for (int i = 0; i < inputFilePaths.size(); i++) {

            commandLine += inputFilePaths.get(i);
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
            result = readResult(outputPath);
            expect_result = readResult(expectResultPath);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return result.equals(expect_result);
    }

    //----------------2 WAY-----------------------------
    /*
     test1
     A: #include x.h | B:  #include x.h
        void a();    |     void b();
     */
    @Test
    public void test1() {
        String outputPath = "testcpp/Include_FuncName_1/AB.cpp";
        String expectResultPath = "testcpp/5/2_1/expect.cpp";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("testcpp/5/2_1/A.cpp");
        inputFilePaths.add("testcpp/5/2_1/B.cpp");

        assertTrue(checkMerge(inputFilePaths, outputPath, expectResultPath));
    }


    /*
   test1
   A: #include x.h | B:  #include x.h
      void a();    |     void b();
   */
    @Test
    public void test2() {
        String outputPath = "testcpp/IFDEF/AB.cpp";
        String expectResultPath = "testcpp/IFDEF/expect.cpp";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("testcpp/IFDEF/A.cpp");
        inputFilePaths.add("testcpp/IFDEF/B.cpp");

        assertTrue(checkMerge(inputFilePaths, outputPath, expectResultPath));
    }
}