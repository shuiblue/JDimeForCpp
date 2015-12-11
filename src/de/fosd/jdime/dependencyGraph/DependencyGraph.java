package de.fosd.jdime.dependencyGraph;

import de.fosd.jdime.util.IOFunctionSet;
import nu.xom.Document;
import nu.xom.Element;
import nu.xom.Elements;
import org.apache.commons.io.FileUtils;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

/**
 * Created by shuruiz on 12/10/15.
 */
public class DependencyGraph {

    private static ArrayList<Visitable> cppNodeList;
    static IOFunctionSet ioFunctionSet = new IOFunctionSet();

    public static void createCppNodeAST(String testDir) {

        String dirPath = "testcpp/dependencyGraph/";
        String testDirPath = dirPath + testDir + "/";
        File dir = new File(testDirPath);
        String[] names = dir.list();
        for (String fileName : names) {
            if (fileName.endsWith(".cpp") || fileName.endsWith(".h") || fileName.endsWith(".c")) {
                String filePath = testDirPath + fileName;

                // src2srcml cannot parse .h file correctly, so change the suffix '+.cpp'
                if (fileName.endsWith(".h")) {
                    String newPath = "/Users/shuruiz/Work/tmpXMLFile" + filePath.replace("testcpp", "") + ".cpp";
                    try {
                        FileUtils.copyFile(new File(filePath), new File(newPath));
                        filePath = newPath;
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
                // get xml file using src2srcml
                String xmlFilePath = ioFunctionSet.getXmlFile(filePath);
                System.out.print(fileName + "\n");

                Element root = ioFunctionSet.getXmlDom(xmlFilePath).getRootElement();

                Elements elements = root.getChildElements();


                for (int i = 0; i < elements.size(); i++) {
                    createCppNode(elements.get(i), 1);
                }

            }
        }

    }

    public static void createCppNode(Element element, int scope) {


        System.out.print("");
    }


    public static void createDependencyGraph() {
        //create a visitor
        CppNodeVisitor visitor = new CppNodeVisitor();

        //iterate through all CppNodeList
        for (Visitable cppNode : cppNodeList) {
            cppNode.accept(visitor);
        }
    }

    public static void main(String[] args) {

        String testDir = "EmailSystem/test_10";
        createCppNodeAST(testDir);

    }
}
