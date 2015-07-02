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
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.logging.Logger;

import de.fosd.jdime.Util;
import de.fosd.jdime.common.FileArtifact;
import de.fosd.jdime.common.MergeContext;
import de.fosd.jdime.common.MergeScenario;
import de.fosd.jdime.common.operations.MergeOperation;
import de.fosd.jdime.stats.MergeTripleStats;
import de.fosd.jdime.stats.Stats;
import de.fosd.jdime.stats.StatsElement;

/**
 * Performs an unstructured, line based merge.
 * <p>
 * The current implementation uses the merge routine provided by <code>git</code>.
 *
 * @author Olaf Lessenich
 */
public class LinebasedStrategy extends MergeStrategy<FileArtifact> {

	private static final Logger LOG = Logger.getLogger(LinebasedStrategy.class.getCanonicalName());
	
	/**
	 * The command to use for merging.
	 */
	private static final String BASECMD = "git";
	
	/**
	 * The arguments for <code>BASECMD</code>.
	 */
	private static final String[] BASEARGS = { "merge-file", "-q", "-p" };

	/**
	 * This line-based <code>merge</code> method uses the merging routine of
	 * the external tool <code>git</code>.
	 * <p>
	 * Basically, the input <code>FileArtifacts</code> are passed as arguments to
	 * `git merge-file -q -p`.
	 * <p>
	 * In a common run, the number of processed lines of code, the number of
	 * conflicting situations, and the number of conflicting lines of code will
	 * be counted. Empty lines and comments are skipped to keep
	 * <code>MergeStrategies</code> comparable, as JDime does (in its current
	 * implementation) not respect comments.
	 * <p>
	 * In case of a performance benchmark, the output is simply ignored for the
	 * sake of speed, and the merge will be run the specified amount of times,
	 * aiming to allow the computation of a reasonable mean runtime.
	 *
	 * @param operation <code>MergeOperation</code> that is executed by this strategy
	 * @param context <code>MergeContext</code> that is used to retrieve environmental parameters
	 *
	 * @throws IOException
	 * @throws InterruptedException
	 */
	@Override
	public final void merge(final MergeOperation<FileArtifact> operation,
			final MergeContext context) throws IOException,
			InterruptedException {

		assert (operation != null);
		assert (context != null);

		MergeScenario<FileArtifact> triple = operation.getMergeScenario();
		assert (triple != null);
		assert (triple.isValid()) : "The merge triple is not valid!";
		assert (triple.getLeft() instanceof FileArtifact);
		assert (triple.getBase() instanceof FileArtifact);
		assert (triple.getRight() instanceof FileArtifact);
		assert (triple.getLeft().exists() && !triple.getLeft().isDirectory());
		assert ((triple.getBase().exists() && !triple.getBase().isDirectory()) || triple.getBase().isEmpty());
		assert (triple.getRight().exists() && !triple.getRight().isDirectory());

		context.resetStreams();
		FileArtifact target = null;

		if (operation.getTarget() != null) {
			assert (operation.getTarget() instanceof FileArtifact);
			target = operation.getTarget();
			assert (!target.exists() || target.isEmpty()) : "Would be overwritten: "
					+ target;
		}

        List<String> cmd = new ArrayList<>();
		cmd.add(BASECMD);
		cmd.addAll(Arrays.asList(BASEARGS));

		for (FileArtifact file : triple.getList()) {
			cmd.add(file.getPath());
		}

		ProcessBuilder pb = new ProcessBuilder(cmd);
		ArrayList<Long> runtimes = new ArrayList<>();
		int conflicts = 0;
		int loc = 0;
		int cloc = 0;

		// launch the merge process by invoking GNU merge (rcs has to be
		// installed)
		LOG.fine(() -> "Running external command: " + Util.joinToString(cmd, ' '));

		for (int i = 0; i < context.getBenchmarkRuns() + 1
				&& (i == 0 || context.isBenchmark()); i++) {
			long cmdStart = System.currentTimeMillis();
			Process pr = pb.start();

			if (i == 0 && (!context.isBenchmark() || context.hasStats())) {
				// process input stream
				BufferedReader buf = new BufferedReader(new InputStreamReader(
						pr.getInputStream()));
				boolean conflict = false;
				boolean comment = false;

				int tmp = 0;
				String line;
				while ((line = buf.readLine()) != null) {
					context.appendLine(line);

					if (context.hasStats()) {
						if (line.matches("^$") || line.matches("^\\s*$")
								|| line.matches("^\\s*//.*$")) {
							// skip empty lines and single line comments
							continue;
						} else if (line.matches("^\\s*/\\*.*")) {
							if (line.matches("^\\s*/\\*.*?\\*/")) {
								// one line comment
								continue;
							} else {
								// starting block comment
								comment = true;
								continue;
							}
						} else if (line.matches("^.*?\\*/")) {
							// ending block comment
							comment = false;
							continue;
						}
						if (line.matches("^\\s*<<<<<<<.*")) {
							LOG.fine(() -> "CONFLICT in " + triple);

							conflict = true;
							comment = false;
							tmp = cloc;
							conflicts++;
						} else if (line.matches("^\\s*=======.*")) {
							comment = false;
						} else if (line.matches("^\\s*>>>>>>>.*")) {
							conflict = false;
							comment = false;
							if (tmp == cloc) {
								// only conflicting comments or empty lines
								conflicts--;
							}
						} else {
							loc++;
							if (conflict && !comment) {
								cloc++;
							}
						}
					}
				}

				buf.close();

				// process error stream
				buf = new BufferedReader(new InputStreamReader(
						pr.getErrorStream()));
				while ((line = buf.readLine()) != null) {
					if (i == 0
							&& (!context.isBenchmark() || context.hasStats())) {
						context.appendErrorLine(line);
					}
				}

				buf.close();
			}
			pr.getInputStream().close();
			pr.getErrorStream().close();
			pr.getOutputStream().close();

			pr.waitFor();

			long runtime = System.currentTimeMillis() - cmdStart;
			runtimes.add(runtime);

			if (context.isBenchmark() && context.hasStats()) {
				if (i == 0) {
					LOG.fine(() -> String.format("Initial run: %d ms", runtime));
				} else {
					LOG.fine(String.format("Run %d of %d: %d ms", i, context.getBenchmarkRuns(), runtime));
				}
			}
		}

		if (context.isBenchmark() && runtimes.size() > 1) {
			// remove first run as it took way longer due to all the counting
			runtimes.remove(0);
		}

		Long runtime = MergeContext.median(runtimes);
		LOG.fine(() -> String.format("Linebased merge time was %d ms.", runtime));

		if (context.hasErrors()) {
			LOG.severe(() -> "Errors occurred while calling '" + cmd + "')");
			System.err.println(context.getStdErr());
		}

		// write output
		if (!context.isPretend() && target != null) {
			assert (target.exists());
			target.write(context.getStdIn());
		}

		// add statistical data to context
		if (context.hasStats()) {
			assert (cloc <= loc);

			Stats stats = context.getStats();
			StatsElement linesElement = stats.getElement("lines");
			assert (linesElement != null);
			StatsElement newElement = new StatsElement();
			newElement.setMerged(loc);
			newElement.setConflicting(cloc);
			linesElement.addStatsElement(newElement);

			if (conflicts > 0) {
				assert (cloc > 0);
				stats.addConflicts(conflicts);
				StatsElement filesElement = stats.getElement("files");
				assert (filesElement != null);
				filesElement.incrementConflicting();
			} else {
				assert (cloc == 0);
			}

			stats.increaseRuntime(runtime);

			MergeTripleStats scenariostats = new MergeTripleStats(triple,
					conflicts, cloc, loc, runtime, null, null, null);
			stats.addScenarioStats(scenariostats);
		}
	}

	@Override
	public final Stats createStats() {
		return new Stats(new String[] { "directories", "files", "lines" });
	}

	@Override
	public final String toString() {
		return "linebased";
	}

	@Override
	public final String getStatsKey(FileArtifact artifact) {
		return "lines";
	}

	/**
	 * Throws <code>UnsupportedOperationException</code>. You should use a structured strategy to dump a tree.
	 * 
	 * @param artifact
	 *            artifact to dump
	 * @param graphical
	 *            output option
	 */
	@Override
	public final String dumpTree(FileArtifact artifact, boolean graphical) {
		throw new UnsupportedOperationException("Use a structured strategy to dump a tree.");
	}

	@Override
	public String dumpFile(FileArtifact artifact, boolean graphical) throws IOException { //TODO: optionally save to outputfile
		List<String> lines = Files.readAllLines(artifact.getFile().toPath(), StandardCharsets.UTF_8);
		StringBuilder sb = new StringBuilder();

		for (String line : lines) {
			sb.append(line);
			sb.append(System.lineSeparator());
		}

		return sb.toString();
	}
}
