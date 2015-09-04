package de.fosd.jdime.util;


import de.fosd.jdime.common.CppNodeArtifact;
import de.fosd.jdime.common.FileArtifact;
import de.fosd.jdime.common.Revision;
import nu.xom.Builder;
import nu.xom.Document;
import nu.xom.ParsingException;
import org.apache.commons.io.FileUtils;

import javax.print.Doc;
import java.io.File;
import java.io.IOException;
import java.util.List;

/**
 * Created by shuruiz on 8/9/15.
 */
public class CheckUndeciplinedAnnotation {

        public static void main (String[]args)throws IOException {

            File dir = new File("/Users/shuruiz/Work/originMarlin");
            String[] extensions = new String[]{"cpp"};
//            String[] extensions = new String[]{"cpp", "h"};
            System.out.println("Getting all .cpp files in " + dir.getCanonicalPath()
                    + " including those in subdirectories");
            List<File> files = (List<File>) FileUtils.listFiles(dir, extensions, true);
            for (File file : files) {
                System.out.println("file: " + file.getCanonicalPath());
                Document doc = getXmlDom(getXmlFile(file.getPath()));
                CppNodeArtifact cppNodeArtifact = new CppNodeArtifact(doc,new Revision("a"));
            }
        }



    public static String getXmlFile(String inputFile) {
        String outXmlFile = inputFile + ".xml";
        if (new File(inputFile).isFile()) {
            try {
                Process process = new ProcessBuilder("/usr/local/bin/src2srcml",
                        inputFile, "-o", outXmlFile).start();
                sleep();
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            System.out.println("File does not exist: " + inputFile);
        }
        return outXmlFile;
    }

    /**
     * parse xml file to DOM.
     *
     * @param xmlFilePath path of xml file
     */
    public static Document getXmlDom(String xmlFilePath) {
        Document doc = null;
        try {
            Builder builder = new Builder();
            File file = new File(xmlFilePath);
            sleep();
            doc = builder.build(file);

        } catch (ParsingException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return doc;
    }

    public static void sleep() {
        try {
            Thread.sleep(50);                 //1000 milliseconds is one second.
        } catch (InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
    }
}
