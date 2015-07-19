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

import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.StringReader;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.logging.Level;
import java.util.logging.Logger;

import de.fosd.jdime.common.ASTNodeArtifact;
import de.fosd.jdime.common.CppNodeArtifact;
import de.fosd.jdime.common.FileArtifact;
import de.fosd.jdime.common.MergeContext;
import de.fosd.jdime.common.MergeScenario;
import de.fosd.jdime.common.MergeType;
import de.fosd.jdime.common.NotYetImplementedException;
import de.fosd.jdime.common.Revision;
import de.fosd.jdime.common.operations.MergeOperation;
import de.fosd.jdime.matcher.Matching;
import de.fosd.jdime.stats.MergeTripleStats;
import de.fosd.jdime.stats.Stats;

/**
 * Performs a structured merge on <code>FileArtifacts</code>.
 *
 * @author Olaf Lessenich
 */
public class NWayStrategy extends MergeStrategy<FileArtifact> {

    private static final Logger LOG = Logger.getLogger(NWayStrategy.class.getCanonicalName());

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
    public final void merge(MergeOperation<FileArtifact> operation, MergeContext context) {

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
        targetNode = new CppNodeArtifact(variants.get((Revision) it.next()));
        while (it.hasNext()) {


            merged = targetNode;

            next = new CppNodeArtifact(variants.get((Revision) it.next()));

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

                    LOG.finest("Pretty-printing merged:");
                    System.out.println(merged.prettyPrint());
                    LOG.finest("Pretty-printing next:");
                    System.out.println(next.prettyPrint());

                    if (!context.isDiffOnly()) {
                        LOG.finest("Pretty-printing target:");
                        System.out.print(targetNode.prettyPrint());
                    }
                }

                try (BufferedReader buf = new BufferedReader(new StringReader(targetNode.prettyPrint()))) {
                    String line;
                    while ((line = buf.readLine()) != null) {
                        context.appendLine(line);
                    }
                }

                long runtime = System.currentTimeMillis() - cmdStart;

                if (LOG.isLoggable(Level.FINE)) {
                    FileWriter file = new FileWriter(merged + ".dot");
                    file.write(new CPPNodeStrategy().dumpTree(targetNode, true));
                    file.close();
                }

                LOG.fine(() -> String.format("Structured merge time was %s ms.", runtime));

                if (context.hasErrors()) {
                    System.err.println(context.getStdErr());
                }

                // write output
                if (!context.isPretend() && target != null) {
                    assert (target.exists());
                    target.write(context.getStdIn());
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
    }

    @Override
    public final String toString() {
        return "nway";
    }

    @Override
    public final Stats createStats() {
        return new Stats(new String[]{"directories", "files", "lines", "nodes"});
    }

    @Override
    public final String getStatsKey(FileArtifact artifact) {
        // FIXME: remove me when implementation is complete!
        throw new NotYetImplementedException("StructuredStrategy: Implement me!");
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
