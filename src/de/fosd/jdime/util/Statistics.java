package de.fosd.jdime.util;

import de.fosd.jdime.common.CppNodeArtifact;

import java.util.Iterator;

/**
 * Created by shuruiz on 9/3/15.
 */
public class Statistics {

    public void findUniqueBlock(CppNodeArtifact root) {
        String path = "testcpp/statistics/1.txt";
        String breakLine = "+++++++++++++++++++++++\n";
        IOFunctionSet io = new IOFunctionSet();

        if (root.getChildren() != null) {
            Iterator<CppNodeArtifact> it = root.getChildren().iterator();
            while (it.hasNext()) {
                CppNodeArtifact child = it.next();
                if (child.isChoice()) {
                    io.writeTofile(child.printChoice(child), path);
                    io.writeTofile(breakLine, path);
                } else if (child.hasMatches()) {
                    findUniqueBlock(child);
                }

            }
        }else if(root.isChoice()){
            io.writeTofile(root.printChoice(root), path);
            io.writeTofile(breakLine, path);

        }
    }

}
