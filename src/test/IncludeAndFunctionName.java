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

TestInitial testInitial = new TestInitial("testcpp/Include_FuncName_1/");
    //----------------2 WAY-----------------------------
    /*
     test1
     A: #include x.h | B:  #include x.h
        void a();    |     void b();
     */
    @Test
    public void test1() {
        String outputPath = "AB.cpp";
        String expectResultPath = "expect.cpp";

        //set input file paths
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add("A.cpp");
        inputFilePaths.add("B.cpp");

        assertTrue(testInitial.checkMerge(inputFilePaths, outputPath, expectResultPath));
    }



}
