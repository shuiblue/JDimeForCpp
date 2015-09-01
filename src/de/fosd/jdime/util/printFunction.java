package de.fosd.jdime.util;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

/**
 * Created by shuruiz on 8/31/15.
 */
public class PrintFunction {


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


    public void writeTofile(String content, String fileName) {
        String path = "testcpp/Marlin/file/";
        try {
            File file = new File(path + fileName);
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
}
