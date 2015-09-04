/*
 * Copyright (C) 2013-2014 Olaf Lessenich
 * Copyright (C) 2014-2015 University of Passau, Germany
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301  USA
 *
 * Contributors:
 *     Olaf Lessenich <lessenic@fim.uni-passau.de>
 *     Georg Seibt <seibt@fim.uni-passau.de>
 */
package de.fosd.jdime.strategy;

import java.io.*;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Stack;
import java.util.logging.Level;
import java.util.logging.Logger;

import de.fosd.jdime.common.ASTNodeArtifact;
import de.fosd.jdime.common.CppNodeArtifact;
import de.fosd.jdime.common.FileArtifact;
import de.fosd.jdime.common.MergeContext;
import de.fosd.jdime.common.MergeScenario;
import de.fosd.jdime.common.MergeType;
import de.fosd.jdime.common.Revision;
import de.fosd.jdime.common.operations.MergeOperation;
<<<<<<< origin/develop

import de.fosd.jdime.matcher.Matching;
<<<<<<< origin/develop
=======
import de.fosd.jdime.stats.MergeTripleStats;
import de.fosd.jdime.stats.Stats;
import de.fosd.jdime.util.PrintFunction;
>>>>>>> HEAD~51
import nu.xom.Document;
=======
import de.fosd.jdime.stats.MergeTripleStats;
import de.fosd.jdime.stats.Stats;
import de.fosd.jdime.util.IOFunctionSet;
<<<<<<< origin/develop
>>>>>>> HEAD~50

=======
import de.fosd.jdime.util.Statistics;
>>>>>>> HEAD~37

/**
 * Performs a structured merge on <code>FileArtifacts</code>.
 *
 * @author Olaf Lessenich
 */
public class NWayStrategy extends MergeStrategy<FileArtifact> {

    private static final Logger LOG = Logger.getLogger(NWayStrategy.class.getCanonicalName());
    IOFunctionSet ioFunctionSet = new IOFunctionSet();

    /**
     * The source <code>FileArtifacts</code> are extracted from the
     * <code>MergeOperation</code>, parsed by the <code>JastAddJ</code> parser
     * into abstract syntax trees, and on the fly encapsulated into
     * <code>ASTNodeArtifacts</code>.
     * <p>
     * A new <code>MergeOperation</code>, encapsulating
     * <code>ASTNodeArtifacts</code> as source and target nodes, is created and applied.
     * <p>
     * TODO: more high-level documentation.
     *
     * @param operation
     * @param context
     */
    @Override
    public final void merge(MergeOperation<FileArtifact> operation, MergeContext context) throws IOException {

        assert (operation != null);
        assert (context != null);

        MergeScenario<FileArtifact> scenario = operation.getMergeScenario();
        Map<Revision, FileArtifact> variants = scenario.getArtifacts();

        assert (variants.size() > 1);

        context.resetStreams();

        FileArtifact target = operation.getTarget();

        if (!context.isDiffOnly() && target != null) {
            assert (!target.exists() || target.isEmpty()) : "Would be overwritten: " + target;
        }
        
        /* ASTNodeArtifacts are created from the input files.
         * Then, a ASTNodeStrategy can be applied.
         * The result is pretty printed and can be written into the output file.
         */
		CppNodeArtifact merged, next, targetNode;
        MergeContext mergeContext;

        if (LOG.isLoggable(Level.FINE)) {
            LOG.fine("Merging:");
            for (Revision rev : variants.keySet()) {
                LOG.fine(String.format("%s: %s", rev, variants.get(rev).getPath()));
            }
        }

        Iterator it = variants.keySet().iterator();
        targetNode = new CppNodeArtifact(variants.get(it.next()));
        while (it.hasNext()) {
            merged = targetNode;
            next = new CppNodeArtifact(variants.get(it.next()));

            try {
                mergeContext = context;
                mergeContext.resetStreams();
                long cmdStart = System.currentTimeMillis();
				targetNode = CppNodeArtifact.createProgram(merged);
                targetNode.setRevision(merged.getRevision(), true);
                targetNode.renumberTree();

                if (LOG.isLoggable(Level.FINEST)) {
                    LOG.finest("target.dumpTree(:");
                    System.out.println(targetNode.dumpTree());
                }

				MergeScenario<CppNodeArtifact> astScenario = new MergeScenario<>(MergeType.TWOWAY, merged, merged.createEmptyArtifact(), next);
				MergeOperation<CppNodeArtifact> astMergeOp = new MergeOperation<>(astScenario, targetNode,
                        merged.getRevision().getName(), next.getRevision().getName());

                if (LOG.isLoggable(Level.FINEST)) {
                    LOG.finest("ASTMOperation.apply(context)");
                }

                astMergeOp.apply(mergeContext);

                HashSet<String> revSet = new HashSet<>();
                targetNode.getRevisions(revSet);
                targetNode.fixRevision(revSet);

                if (LOG.isLoggable(Level.FINEST)) {
                    LOG.finest("Structured merge finished.");

                    if (!context.isDiffOnly()) {
                        LOG.finest("target.dumpTree():");
                        System.out.println(targetNode.dumpTree());
                    }

//                    LOG.finest("Pretty-printing merged:");
//                    System.out.println(merged.prettyPrint());
//                    LOG.finest("Pretty-printing next:");
//                    System.out.println(next.prettyPrint());

//                    if (!context.isDiffOnly()) {
//                        LOG.finest("Pretty-printing target:");
//                        System.out.print(targetNode.prettyPrint());
//                    }
                }
            } catch (Throwable t) {
                LOG.severe("Exception while merging:");
                for (Revision rev : variants.keySet()) {
                    LOG.severe(String.format("%s: %s", rev, variants.get(rev).getPath()));
                }
                LOG.severe(t.toString());

                if (!context.isKeepGoing()) {
                    throw new Error(t);
                } else {
                    if (context.hasStats()) {
                        MergeTripleStats scenarioStats = new MergeTripleStats(scenario, t.toString());
                        context.getStats().addScenarioStats(scenarioStats);
                    }
                }
            }
        }
        //------------
        Statistics statistics = new Statistics();
        statistics.findUniqueBlock(targetNode);
        //-----------
        String prettyPrint = "";
//        String prettyPrint = targetNode.prettyPrint();

//        prettyPrint = ioFunctionSet.presicePrettyprint(prettyPrint);
        try (BufferedReader buf = new BufferedReader(new StringReader(prettyPrint))) {
                    String line;
                    while ((line = buf.readLine()) != null) {
                        context.appendLine(line);
                    }
        } catch (IOException e) {
            e.printStackTrace();
                }

                if (context.hasErrors()) {
                    System.err.println(context.getStdErr());
                }

                // write output
                if (!context.isPretend() && target != null) {
                    assert (target.exists());
            try {
                    target.write(context.getStdIn());
            } catch (IOException e) {
                e.printStackTrace();
            }
                }
                try {
            new ProcessBuilder("astyle/bin/astyle",
                            "--style=google","--indent-preproc-block","-xe",context.getOutputFile().getPath()).start();
                } catch (IOException e) {
                    e.printStackTrace();
                }
<<<<<<< origin/develop

<<<<<<< origin/develop
            } catch (Throwable t) {
                LOG.severe("Exception while merging:");
                context.addCrash(scenario, t);

                for (Revision rev : variants.keySet()) {
                    LOG.severe(String.format("%s: %s", rev, variants.get(rev).getPath()));
=======

>>>>>>> HEAD~50
                }

<<<<<<< origin/develop
<<<<<<< origin/develop
                if (!context.isKeepGoing()) {
                    throw new Error(t);
=======
    //-------------------
    public HashSet<String> forkNameSet = new HashSet<>();

    public void inputFileInit() {
//        String path = "testcpp/originMarlin/";
//        File dir = new File(path);
//        String[] names = dir.list();
//        for (String name : names) {
//            if (new File(path + name).isDirectory()) {
//                if (!name.equals("upstream")) {
//                    forkNameSet.add(name);
//                }
//            }
//
//        }

        forkNameSet.add("yuroller");
//        forkNameSet.add("marlin4Due");
        forkNameSet.add("upstream");
=======





    @Override
    public final String toString() {
        return "nway";
>>>>>>> HEAD~37
    }

    public void analysisIfdefBlock(String content) {
        String[] ifdefBlocks = content.split("\\+\\+\\+\\+\\+\\+");
        for (String block : ifdefBlocks) {
            for (String fork : forkNameSet) {
                if (block.contains("defined " + fork + ")")) {

>>>>>>> HEAD~50
                }
            }
        }
    }


    //-------------------

    public String presicePrettyprint(String res) {

        //-----------------------
        String testPath = "testcpp/mergedResult/countIfdef.txt";
        inputFileInit();
        //-----------------------

       while(res.contains("#endif+-+-+-")){
           res = res.replace("#endif+-+-+-","#endif");

       }
        String newResult = "";
        Stack<String> conditionStack = new Stack<>();
        String[] elements = res.split("\\+-\\+-\\+-\n");
        String s = "";
        for (String e : elements) {
            if (e.length() > 0) {
            String[] tmp = e.split("\n");
            if (conditionStack.size() > 0) {
                String lastCon = conditionStack.lastElement();
                if (lastCon.equals(tmp[0])) {
                    String x = "";
                    for (int i = 1; i < tmp.length - 1; i++) {
                        x += tmp[i]+"\n";
                    }
                    newResult += x;
                    continue;
                } else {
                    conditionStack.pop();
                    conditionStack.push(tmp[0]);
                    newResult +="#endif\n";

                        //-------------------
                       ioFunctionSet.printEndif(testPath);
                        //-------------------

                }
            }
            conditionStack.push(tmp[0]);
                newResult += ioFunctionSet.printNodeWithoutHeadandEnd(e, 0);

                //-------------------
                int i = 0;
                for (String fork : forkNameSet) {
                    if (tmp[0].contains("defined (" + fork + ")")) {
                        i++;
                    }
            }

                if (i < forkNameSet.size()) {
                    String countIfdef = ioFunctionSet.printNodeWithoutHeadandEnd(e, 0);
                    ioFunctionSet.writeTofile(countIfdef, testPath);
            }
        //-------------------


            }
        }
        //-----------------------
       ioFunctionSet.printEndif(testPath);
//-----------------------
        return newResult+"#endif\n";
=======
>>>>>>> HEAD~38
    }

    @Override
    public final String toString() {
        return "nway";
    }

    @Override
    public final String dumpTree(FileArtifact artifact, boolean graphical) throws IOException {
        return new ASTNodeStrategy().dumpTree(new ASTNodeArtifact(artifact), graphical);
    }

    @Override
    public String dumpFile(FileArtifact artifact, boolean graphical) throws IOException {
        return new ASTNodeStrategy().dumpFile(new ASTNodeArtifact(artifact), graphical);
    }
}
