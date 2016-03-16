package de.fosd.jdime.dependencyGraph;

import de.fosd.jdime.util.IOFunctionSet;

import java.io.IOException;

/**
 * Created by shuruiz on 3/15/16.
 */
public class CompareTwoCluster {


    public static void main(String[] args) {
        String dirPath = "testcpp/dependencyGraph/";
        String testDir = "test_13/";

        IOFunctionSet ioFunctionSet = new IOFunctionSet();
        String st1 = "",st2="";
        try {
             st1 = ioFunctionSet.readResult(dirPath + testDir + "1.txt").replace("[","").replace("]","");
             st2 = ioFunctionSet.readResult(dirPath + testDir + "2.txt").replace("[","").replace("]","");
        } catch (IOException e) {
            e.printStackTrace();
        }
        String[] array1 = st1.trim().split(",");
        String[] array2 = st2.trim().split(",");

        for(String s:array1){
            String s1 = ","+s.trim()+",";
            if(!st2.replace(" ","").contains(s1)){
               System.out.println(s1);
            }
        }

    }
}
