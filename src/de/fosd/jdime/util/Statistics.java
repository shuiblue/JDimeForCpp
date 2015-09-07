package de.fosd.jdime.util;

import de.fosd.jdime.common.CppNodeArtifact;
import test.TestInitial;

import java.util.Iterator;

/**
 * Created by shuruiz on 9/3/15.
 */
public class Statistics {

    public void findUniqueBlock(CppNodeArtifact root) {
        if (root.getChildren() != null) {
            Iterator<CppNodeArtifact> it = root.getChildren().iterator();
            while (it.hasNext()) {
                CppNodeArtifact child = it.next();
                if (child.isChoice()) {
                    child.printChoice(child);
                } else if (child.hasMatches()) {
                    findUniqueBlock(child);
                }
            }
        } else if (root.isChoice()) {
            root.printChoice(root);
        }
    }




}
