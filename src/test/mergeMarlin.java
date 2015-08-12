package test;

import de.fosd.jdime.common.CppNodeArtifact;
import de.fosd.jdime.common.Revision;
import nu.xom.Document;
import org.apache.commons.io.FileUtils;
import org.junit.Test;

import java.io.File;
import java.util.HashSet;
import java.util.List;

import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;

/**
 * Created by shuruiz on 7/26/15.
 */
public class mergeMarlin {
    String path = "testcpp/originMarlin/";
    TestInitial testInitial = new TestInitial(path);
    HashSet<String> config = new HashSet<>();
    HashSet<String> forkName = new HashSet<>();

    public HashSet<String> inputFileInit(String mergedFile) {
        File dir = new File(path);
        String[] names = dir.list();
        for (String name : names) {
            if (new File(path + name).isDirectory()) {
                forkName.add(name);

            }

        }
        return forkName;
    }


    public void afterTest() {
        try {
            Thread.sleep(10);                 //1000 milliseconds is one second.
        } catch (InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
        testInitial.clearTmpFile();
    }



    @Test
    public void testMarlinMain() {
        String mergedFile = "Marlin_main";
        HashSet<String> forkNames = inputFileInit(mergedFile);

        // ----------------check Merged result equal to expect result
        for (String fork : forkNames) {
            System.out.println("2way : merge fork '" + fork + "' " + mergedFile + ".cpp file with upstream repo");


            if (!fork.equals("upstream")) {
                System.out.print(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile)!=null);
                assertNotNull(testInitial.checkMerge_wrapper4Marlin(path, fork, mergedFile));
            }
        }
    }
}
