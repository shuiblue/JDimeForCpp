package de.fosd.jdime.testJDimeCpp;

import org.junit.Test;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import static org.junit.Assert.assertNotNull;
/**
 * Created by shuruiz on 7/12/15.
 */
public class TestSrcML {

//    public static String getXmlFile(String inputFile)  {
//        if (new File(inputFile).isFile()) {
//            String outXmlFile = inputFile + ".xml";
//            try {
//                Process process = new ProcessBuilder("/usr/local/bin/src2srcml",
//                        inputFile, "-o", outXmlFile).start();
//            } catch (IOException e) {
//                e.printStackTrace();
//            }
//            return outXmlFile;
//        } else {
//            System.out.println("File does not exist: " + inputFile);
//        }
//        return null;
//    }

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
    @Test
    public void testSRCml() throws IOException {

        List<String> inputFilePaths = new ArrayList<>();

        inputFilePaths.add("testcpp/1/1.cpp");
        inputFilePaths.add("testcpp/1/2.cpp");

        inputFilePaths.add("testcpp/1_1/1.cpp");
        inputFilePaths.add("testcpp/1_1/2.cpp");

        inputFilePaths.add("testcpp/2/A.cpp");
        inputFilePaths.add("testcpp/2/B.cpp");

        inputFilePaths.add("testcpp/2_1/A.cpp");
        inputFilePaths.add("testcpp/2_1/B.cpp");

        inputFilePaths.add("testcpp/2_2/A.cpp");
        inputFilePaths.add("testcpp/2_2/B.cpp");

        inputFilePaths.add("testcpp/3/A.cpp");
        inputFilePaths.add("testcpp/3/B.cpp");
        inputFilePaths.add("testcpp/3/C.cpp");

        inputFilePaths.add("testcpp/3_1/A.cpp");
        inputFilePaths.add("testcpp/3_1/B.cpp");
        inputFilePaths.add("testcpp/3_1/C.cpp");

        inputFilePaths.add("testcpp/3_2/A.cpp");
        inputFilePaths.add("testcpp/3_2/B.cpp");
        inputFilePaths.add("testcpp/3_2/C.cpp");

        inputFilePaths.add("testcpp/3_2_1/A.cpp");
        inputFilePaths.add("testcpp/3_2_1/B.cpp");
        inputFilePaths.add("testcpp/3_2_1/C.cpp");

        inputFilePaths.add("testcpp/3_3/A.cpp");
        inputFilePaths.add("testcpp/3_3/B.cpp");
        inputFilePaths.add("testcpp/3_3/C.cpp");

        inputFilePaths.add("testcpp/3_4/A.cpp");
        inputFilePaths.add("testcpp/3_4/B.cpp");
        inputFilePaths.add("testcpp/3_4/C.cpp");


        inputFilePaths.add("testcpp/3_5/A.cpp");
        inputFilePaths.add("testcpp/3_5/B.cpp");
        inputFilePaths.add("testcpp/3_5/C.cpp");

        inputFilePaths.add("testcpp/4/A.cpp");
        inputFilePaths.add("testcpp/4/B.cpp");
        inputFilePaths.add("testcpp/4/C.cpp");
        inputFilePaths.add("testcpp/4/D.cpp");


        inputFilePaths.add("testcpp/4_1_1/A.cpp");
        inputFilePaths.add("testcpp/4_1_1/B.cpp");
        inputFilePaths.add("testcpp/4_1_1/C.cpp");
        inputFilePaths.add("testcpp/4_1_1/D.cpp");

        inputFilePaths.add("testcpp/4_1/A.cpp");
        inputFilePaths.add("testcpp/4_1/B.cpp");
        inputFilePaths.add("testcpp/4_1/C.cpp");
        inputFilePaths.add("testcpp/4_1/D.cpp");

        inputFilePaths.add("testcpp/4_2/A.cpp");
        inputFilePaths.add("testcpp/4_2/B.cpp");
        inputFilePaths.add("testcpp/4_2/C.cpp");
        inputFilePaths.add("testcpp/4_2/D.cpp");

        inputFilePaths.add("testcpp/4_3/A.cpp");
        inputFilePaths.add("testcpp/4_3/B.cpp");
        inputFilePaths.add("testcpp/4_3/C.cpp");
        inputFilePaths.add("testcpp/4_3/D.cpp");

        inputFilePaths.add("testcpp/4_4/A.cpp");
        inputFilePaths.add("testcpp/4_4/B.cpp");
        inputFilePaths.add("testcpp/4_4/C.cpp");
        inputFilePaths.add("testcpp/4_4/D.cpp");

        for(String s :inputFilePaths){
            assertNotNull( readResult( s+".xml"));
        }

    }
}
