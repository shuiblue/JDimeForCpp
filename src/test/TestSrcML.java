package test;

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

    public static String getXmlFile(String inputFile)  {
        if (new File(inputFile).isFile()) {
            String outXmlFile = inputFile + ".xml";
            try {
                Process process = new ProcessBuilder("/usr/local/bin/src2srcml",
                        inputFile, "-o", outXmlFile).start();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return outXmlFile;
        } else {
            System.out.println("File does not exist: " + inputFile);
        }
        return null;
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
    @Test
    public void testSRCml() throws IOException {

        List<String> paths = new ArrayList<>();
        paths.add("testcpp/1/12.cpp");
        paths.add("testcpp/1_1/12.cpp");
        paths.add("testcpp/2/AB.cpp");
        paths.add("testcpp/2_1/AB.cpp");
        paths.add("testcpp/2_2/AB.cpp");
        paths.add("testcpp/3/ABC.cpp");
        paths.add("testcpp/3_1/ABC.cpp");
        paths.add("testcpp/3_3/ABC.cpp");
        paths.add("testcpp/4/ABCD.cpp");

        for(String s :paths){
            assertNotNull( readResult( getXmlFile(s)));
        }

    }
}
