package de.fosd.jdime.util;

import java.io.*;

/**
 * Created by shuruiz on 8/31/15.
 */
public class IOFunctionSet {


    public String printNodeWithoutHeadandEnd(String s, int head) {
        String blockString = "";
        if (s.endsWith(":")) {
            for (int i = head; i < s.split("\n").length - 2; i++) {
                blockString += s.split("\n")[i] + "\n";
            }
            blockString += ":";
        } else {
            for (int i = head; i < s.split("\n").length - 1; i++) {
                blockString += s.split("\n")[i] + "\n";
            }
        }
        return blockString;
    }


    public void writeTofile(String content, String filepath) {

        try {
            File file = new File(filepath);
            // if file doesnt exists, then create it
            if (!file.exists()) {
                file.createNewFile();
            }
            FileWriter fw = new FileWriter(file.getAbsoluteFile(), true);
            BufferedWriter bw = new BufferedWriter(fw);
            bw.write(content);
            bw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
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
    public void printEndif(String testPath){
        String tmpString = null;
        try {
            tmpString = readResult(testPath);
        } catch (IOException ex) {
            ex.printStackTrace();
        }
        if(!tmpString.endsWith("+\n")&&!tmpString.replace("\n","").endsWith("cpp")) {
            String countIfdef = "#endif\n++++++\n";
           writeTofile(countIfdef, testPath);
        }
    }

}
