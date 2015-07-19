package test;

import de.fosd.jdime.common.CppNodeArtifact;
import de.fosd.jdime.common.FileArtifact;
import de.fosd.jdime.common.Revision;
import org.junit.Ignore;
import org.junit.Test;

import java.io.File;
import java.io.IOException;

import static org.junit.Assert.*;

/**
 * Created by shuruiz on 7/16/15.
 */
public class TestParseCondition {

    public CppNodeArtifact testParseCondition(String inputFilePath) {
        FileArtifact fileArtifact = null;
        try {
            fileArtifact = new FileArtifact(new File(inputFilePath));
            fileArtifact.setRevision(new Revision("A"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        CppNodeArtifact c = new CppNodeArtifact(fileArtifact);
//        c.parseCondition();
        return c;

    }


    /*
        #ifdef X
        void x();
        #endif
    */
    @Test
    public void test1() {
        CppNodeArtifact c = testParseCondition("testcpp/testParseCondition/1/A.cpp");
        // root revision
        assertEquals(c.getRevision().getName(), "A");
        assertEquals(c.getRevision().conditions.size(), 0);

        assertEquals(c.getChildren().get(0).getRevision().getName(), "A");
        assertEquals(c.getChildren().get(0).getRevision().conditions.size(), 0);

        assertEquals(c.getChildren().get(1).getRevision().getName(), "A");
        assertEquals(c.getChildren().get(1).getRevision().conditions.size(), 1);

        assertEquals(c.getChildren().get(2).getRevision().getName(), "A");
        assertEquals(c.getChildren().get(2).getRevision().conditions.size(), 0);

    }


}
