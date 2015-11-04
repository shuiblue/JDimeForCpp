package de.fosd.jdime.util;

import de.fosd.jdime.common.CppNodeArtifact;
import test.TestInitial;

import java.util.HashSet;
import java.util.Iterator;
import java.util.List;

/**
 * Created by shuruiz on 9/3/15.
 */
public class Statistics {
IOFunctionSet ioFunctionSet = new IOFunctionSet();
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

    /**
     *
     * @param c choice node c
     * @param cRev c's Revision
     *
     */
    public void coundIfdefs(CppNodeArtifact c,CppNodeArtifact choiceNode, String cRev, String nodeString) {


        CppNodeArtifact parent = c.getParent();
        if (parent.hasMatches()) {
            String parentRev = c.printMatchCondition(parent);

            List<String> forks = c.printMatchConditionList(parent);
            String childRev = ioFunctionSet.clearBlank(cRev.replace("#if ", ""));

            String fileName = "";
            String forkName = "";
            for (String f : forks) {
                if (!f.contains("pstream")) {
                    forkName = f.replace("defined(", "").replace(")", "");
                }
                f = f.replace("defined", "").replace(" ", "");
                if (f.indexOf("(") < 0 || f.indexOf(")") < 0) {
                    System.out.print("aa");
                }
                f = f.substring(f.indexOf("(") + 1, f.indexOf(")"));

                fileName += f + "_";
            }
         String   path = "testcpp/statistics/" + fileName + ".txt";
            ioFunctionSet.writeTofile("\n+-+-+-\n", path);
            ioFunctionSet.writeTofile(nodeString, path);


            if (cRev.contains(forkName) && !cRev.contains("Upstream")) {
                String forIfdefPath = "testcpp/statistics/" + fileName + "Ifdef.txt";

                HashSet<String> choiceNodeConditions = choiceNode.getRevision().conditions;
                String parentConditions = parent.printMatchCondition(parent);

                if (choiceNodeConditions.size() > 0) {
                    for (String choiceCon : choiceNodeConditions) {
                        if (parentConditions.contains(choiceCon)) {
                            parentConditions = parentConditions.replace(choiceCon, "");
                        } else {
                            ioFunctionSet.writeTofile("(IFDEF)", path);
                            ioFunctionSet.writeTofile("\n+-+-+-\n", forIfdefPath);
                            ioFunctionSet.writeTofile(nodeString, forIfdefPath);

                            ioFunctionSet.writeTofile("\n+-+-+-\n", forIfdefPath);
                            ioFunctionSet.writeTofile("++++additional ifdef+++\n", forIfdefPath);
                            ioFunctionSet.writeTofile("+++parent:" + parent.printMatchCondition(parent) + "\n", forIfdefPath);
                            ioFunctionSet.writeTofile("+++child:" + childRev + "\n", forIfdefPath);
                            ioFunctionSet.writeTofile("+-+-+-\n", forIfdefPath);
                        }
                    }
                }
            }

        }
    }


}
