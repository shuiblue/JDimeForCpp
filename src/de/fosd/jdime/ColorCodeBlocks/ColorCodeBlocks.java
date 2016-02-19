package de.fosd.jdime.ColorCodeBlocks;

import de.fosd.jdime.util.IOFunctionSet;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

/**
 * Created by shuruiz on 2/9/16.
 */
public class ColorCodeBlocks {

    private static String filePath = "/Users/shuruiz/Work/JDIME/NWayJDime/jdime/html/";
    private static String headtxt = "head.txt";
    private static String endtxt = "end.txt";
    private static String html = "code.html";

//    public static void main(String[] args) {
//        String head="";
//        String end="";
//        IOFunctionSet ioFunctionSet = new IOFunctionSet();
//        try {
//            head = ioFunctionSet.readResult(filePath + headtxt);
//            end = ioFunctionSet.readResult(filePath + endtxt);
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
//        ioFunctionSet.writeTofile(head, html);
//
//
//        String csvFile = "/Users/shuruiz/Box Sync/igraph/output.csv";
//        BufferedReader br = null;
//        String line = "";
//        String cvsSplitBy = ",";
//
//        try {
//
//            br = new BufferedReader(new FileReader(csvFile));
//            while ((line = br.readLine()) != null) {
//                // use comma as separator
//                String[] cluster = line.split(cvsSplitBy);
//
//
//            }
//
//        } catch (FileNotFoundException e) {
//            e.printStackTrace();
//        } catch (IOException e) {
//            e.printStackTrace();
//        } finally {
//            if (br != null) {
//                try {
//                    br.close();
//                } catch (IOException e) {
//                    e.printStackTrace();
//                }
//            }
//        }
//
//
//    }

    static IOFunctionSet iofunc = new IOFunctionSet();

    public static void main(String[] args) {
        String  dirPath = "testcpp/dependencyGraph/";
        String testDir = "EmailSystem/test_16";
        String line = iofunc.readCertainLine(8,dirPath+ testDir + "/Client.c");

        System.out.print(line);
    }

}





