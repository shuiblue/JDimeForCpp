package test;

import de.fosd.jdime.Main;
import org.apache.commons.cli.ParseException;
import org.junit.Test;

import java.io.IOException;
import java.util.ArrayList;

import static org.junit.Assert.assertTrue;

/**
 * Created by shuruiz on 8/31/15.
 */
public class testMergeMain {

    String path = "testcpp/Marlin/file/";
    TestInitial testInitial = new TestInitial(path);
    String output = path+"output.cpp";

    @Test
    public void testMerge() {

        TestInitial testInitial = new TestInitial(path);
        ArrayList<String> inputFilePaths = new ArrayList<>();
        inputFilePaths.add(path+"A.cpp+A");
        inputFilePaths.add(path + "B.cpp+B");

        String commandLine = "-mode,nway,-output," +  output+ ",";
        for (int i = 0; i < inputFilePaths.size(); i++) {

            commandLine +=inputFilePaths.get(i);
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




}
