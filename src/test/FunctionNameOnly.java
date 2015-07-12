package test;

import de.fosd.jdime.Main;
import org.apache.commons.cli.ParseException;
import org.junit.Ignore;
import org.junit.Test;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

import static org.junit.Assert.assertTrue;

/**
 * Created by shuruiz on 7/10/15.
 */
public class FunctionNameOnly {
    public String readResult(String filePath) throws IOException {

//        BufferedReader result_br = new BufferedReader(new FileReader("testcpp/1/1.cpp"));
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
       String commandLine ="-mode,nway,-output,"+outputPath+",";
            for(int i = 0;i<inputFilePaths.size();i++){

            commandLine += inputFilePaths.get(i);
                if(i<inputFilePaths.size()-1){
                    commandLine +=",";
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
        runMain(inputFilePaths,outputPath);
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
    @Test
    public void test1() {
        String outputPath = "testcpp/1/12.cpp";
        String expectResultPath = "testcpp/1/expect.cpp";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("testcpp/1/1.cpp");
        inputFilePaths.add("testcpp/1/2.cpp");

        assertTrue(checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

   @Ignore @Test
        public void test2() {
        String outputPath = "testcpp/1_1/12.cpp";
        String expectResultPath = "testcpp/1_1/expect.cpp";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("testcpp/1_1/1.cpp");
        inputFilePaths.add("testcpp/1_1/2.cpp");

        assertTrue(checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

    @Ignore@Test
    public void test3() {
        String outputPath = "testcpp/2/AB.cpp";
        String expectResultPath = "testcpp/2/expect.cpp";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("testcpp/2/A.cpp");
        inputFilePaths.add("testcpp/2/B.cpp");

        assertTrue(checkMerge(inputFilePaths, outputPath, expectResultPath));
    }
    @Ignore@Test
    public void test4() {
        String outputPath = "testcpp/2_1/AB.cpp";
        String expectResultPath = "testcpp/2_1/expect.cpp";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("testcpp/2_1/A.cpp");
        inputFilePaths.add("testcpp/2_1/B.cpp");

        assertTrue(checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

    @Ignore@Test
    public void test5() {
        String outputPath = "testcpp/2_2/AB.cpp";
        String expectResultPath = "testcpp/2_2/expect.cpp";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("testcpp/2_2/A.cpp");
        inputFilePaths.add("testcpp/2_2/B.cpp");

        assertTrue(checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

//----------------3 WAY-----------------------------
@Ignore@Test
    public void test6() {
        String outputPath = "testcpp/3/ABC.cpp";
        String expectResultPath = "testcpp/3/expect.cpp";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("testcpp/3/A.cpp");
        inputFilePaths.add("testcpp/3/B.cpp");
        inputFilePaths.add("testcpp/3/C.cpp");

        assertTrue(checkMerge(inputFilePaths, outputPath, expectResultPath));
    }

    @Ignore @Test
    public void test7() {
        String outputPath = "testcpp/3_3/ABC.cpp";
        String expectResultPath = "testcpp/3_3/expect.cpp";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("testcpp/3_3/A.cpp");
        inputFilePaths.add("testcpp/3_3/B.cpp");
        inputFilePaths.add("testcpp/3_3/C.cpp");

        assertTrue(checkMerge(inputFilePaths, outputPath, expectResultPath));
    }
}
