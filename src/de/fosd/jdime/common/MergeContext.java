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
 */
package de.fosd.jdime.common;

import java.io.StringWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;

import de.fosd.jdime.stats.Stats;
import de.fosd.jdime.strategy.LinebasedStrategy;
import de.fosd.jdime.strategy.MergeStrategy;
import de.fosd.jdime.strategy.NWayStrategy;

/**
 * @author Olaf Lessenich
 *
 */
public class MergeContext implements Cloneable {

	/**
	 * Default value of benchmark runs.
	 */
	private static final int BENCHMARKRUNS = 10;

	/**
	 * Returns the median of a list of long values.
	 *
	 * @param values
	 *            list of values for which to compute the median
	 * @return median
	 */
	public static long median(final ArrayList<Long> values) {
		Collections.sort(values);

		if (values.size() % 2 == 1) {
			return values.get((values.size() + 1) / 2 - 1);
		} else {
			double lower = values.get(values.size() / 2 - 1);
			double upper = values.get(values.size() / 2);

			return Math.round((lower + upper) / 2.0);
		}
	}

	/**
	 * Performs benchmarks with several runs per file to get average runtimes.
	 */

	private boolean benchmark = false;

	/**
	 * Whether we are in bug-fixing mode.
	 */
	private boolean bugfixing = false;

	/**
	 * Whether merge inserts choice nodes instead of direct merging.
	 */
	private boolean conditionalMerge = false;

	/**
	 * Whether conditional merge should be performed outside of methods.
	 */
	private boolean conditionalOutsideMethods = true;

	/**
	 * Whether to run only the diff.
	 */
	private boolean diffOnly = false;

	/**
	 * Whether to treat two input versions as consecutive versions in the
	 * revision history.
	 */
	private boolean consecutive = false;

	/**
	 * Whether to dump files instead of merging.
	 */
	private boolean dumpFiles = false;

	/**
	 * Whether to dump ASTs instead of merging.
	 */
	private boolean dumpTree = false;

	/**
	 * Force overwriting of existing output files.
	 */
	private boolean forceOverwriting = false;

	/**
	 * Whether to use graphical output while dumping.
	 */
	private boolean guiDump = false;

	/**
	 * Input Files.
	 */
	private ArtifactList<FileArtifact> inputFiles;

	/**
	 * If true, merging will be continued after exceptions.
	 */
	private boolean keepGoing = false;

	/**
	 * Strategy to apply for the merge.
	 */
	private MergeStrategy<?> mergeStrategy = new LinebasedStrategy();

	/**
	 * Output file.
	 */
	private FileArtifact outputFile;

	/**
	 * Timestamp of program start.
	 */
	private long programStart;

	/**
	 * If true, the output is quiet.
	 */
	private boolean quiet = false;

	/**
	 * If true, output is not written to an output file.
	 */
	private boolean pretend = true;

	/**
	 * Merge directories recursively. Can be set with the '-r' argument.
	 */
	private boolean recursive = false;

	/**
	 * Number of runs to perform for each file.
	 */
	private int runs = BENCHMARKRUNS;

	/**
	 * Save statistical data.
	 */
	private boolean saveStats = false;

	/**
	 * Statistical data are stored in a stats object.
	 */
	private Stats stats = null;

	/**
	 * StdOut of a merge operation.
	 */
	private StringWriter stdErr = new StringWriter();

	/**
	 * StdIn of a merge operation.
	 */
	private StringWriter stdIn = new StringWriter();

	/**
	 * How many levels to keep searching for matches in the subtree if the
	 * currently compared nodes are not equal. If there are no matches within
	 * the specified number of levels, do not look for matches deeper in the
	 * subtree. If this is set to LOOKAHEAD_OFF, the matcher will stop looking
	 * for subtree matches if two nodes do not match. If this is set to
	 * LOOKAHEAD_FULL, the matcher will look at the entire subtree.
	 * The default ist to do no look-ahead matching.
	 */
	private int lookAhead = MergeContext.LOOKAHEAD_OFF;

	/** TODO: This is only for debugging and messing around with the look-ahead feature. */
	private HashMap<String, Integer> elements = new HashMap<>();
	/** TODO: This is only for debugging and messing around with the look-ahead feature. */
	private HashMap<String, Integer> matchedElements = new HashMap<>();
	/** TODO: This is only for debugging and messing around with the look-ahead feature. */
	private HashMap<String, Integer> skippedLeftElements = new HashMap<>();
	/** TODO: This is only for debugging and messing around with the look-ahead feature. */
	private HashMap<String, Integer> skippedRightElements = new HashMap<>();
	/** TODO: This is only for debugging and messing around with the look-ahead feature. */
	private List<Tuple<String, Double>> skippedElements = new ArrayList<>();

	/**
	 * Do look at all nodes in the subtree even if the compared nodes are not
	 * equal.
	 */
	public static final int LOOKAHEAD_FULL = -1;

	/**
	 * Stop looking for subtree matches if the two nodes compared are not equal.
	 */
	public static final int LOOKAHEAD_OFF = 0;

	/**
	 * Class constructor.
	 */
	public MergeContext() {
		programStart = System.currentTimeMillis();
	}

	/**
	 * Adds statistical data to already collected data.
	 *
	 * @param other
	 *            statistical data to add
	 */
	public final void addStats(final Stats other) {
		assert (stats != null);
		assert (other != null);
		stats.add(other);
	}

	/**
	 * Append a String to stdIN.
	 *
	 * @param s
	 *            String to append
	 */
	public final void append(final String s) {
		if (stdIn != null) {
			stdIn.append(s);
		}
	}

	/**
	 * Append a String to stdERR.
	 *
	 * @param s
	 *            String to append
	 */
	public final void appendError(final String s) {
		if (stdErr != null) {
			stdErr.append(s);
		}
	}

	/**
	 * Appends a line to the saved stderr buffer.
	 *
	 * @param line
	 *            to be appended
	 */
	public final void appendErrorLine(final String line) {
		if (stdErr != null) {
			stdErr.append(line);
			stdErr.append(System.getProperty("line.separator"));
		}
	}

	/**
	 * Appends a line to the saved stdin buffer.
	 *
	 * @param line
	 *            to be appended
	 */
	public final void appendLine(final String line) {
		if (stdIn != null) {
			stdIn.append(line);
			stdIn.append(System.lineSeparator());
		}
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.lang.Object#clone()
	 */
	@Override
	public final Object clone() {
		MergeContext clone = new MergeContext();
		clone.forceOverwriting = forceOverwriting;
		clone.mergeStrategy = mergeStrategy;
		clone.inputFiles = inputFiles;
		clone.outputFile = outputFile;
		clone.quiet = quiet;
		clone.recursive = recursive;
		clone.saveStats = saveStats;
		clone.keepGoing = keepGoing;
		clone.diffOnly = diffOnly;
		clone.lookAhead = lookAhead;
		return clone;
	}

	/**
	 * Returns the number of benchmark runs.
	 *
	 * @return the number of benchmark runs
	 */
	public final int getBenchmarkRuns() {
		return runs;
	}

	/**
	 * @return the inputFiles
	 */
	public final ArtifactList<FileArtifact> getInputFiles() {
		return inputFiles;
	}

	/**
	 * Returns the merge strategy.
	 *
	 * @return the merge strategy
	 */
	public final MergeStrategy<?> getMergeStrategy() {
		return mergeStrategy;
	}

	/**
	 * @return the outputFile
	 */
	public final FileArtifact getOutputFile() {
		return outputFile;
	}

	/**
	 * @return timestamp of program start
	 */
	public final long getProgramStart() {
		return programStart;
	}

	/**
	 * Retrieves the statistical data.
	 *
	 * @return statistical data
	 */
	public final Stats getStats() {
		return stats;
	}

	/**
	 * Returns the saved stderr buffer.
	 *
	 * @return stderr
	 */
	public final String getStdErr() {
		assert (stdErr != null);
		return stdErr.toString();
	}

	/**
	 * Returns the saved stdin buffer.
	 *
	 * @return stdin
	 */
	public final String getStdIn() {
		assert (stdErr != null);
		return stdIn.toString();
	}

	/**
	 * Returns true if stderr is not empty.
	 *
	 * @return true if stderr is not empty
	 */
	public final boolean hasErrors() {
		return stdErr != null && stdErr.toString().length() != 0;
	}

	/**
	 * Returns true if stdin is not empty.
	 *
	 * @return true if stdin is not empty
	 */
	public final boolean hasOutput() {
		return stdIn != null && stdIn.toString().length() != 0;
	}

	/**
	 * @return the saveStats
	 */
	public final boolean hasStats() {
		return saveStats;
	}

	/**
	 * @return the benchmark
	 */
	public final boolean isBenchmark() {
		return benchmark;
	}

	/**
	 * Returns whether bugfixing mode is enabled.
	 *
	 * @return true if bugfixing mode is enabled
	 */
	public final boolean isBugfixing() {
		return bugfixing;
	}

	/**
	 * @return the diffOnly
	 */
	public final boolean isDiffOnly() {
		return diffOnly;
	}

	/**
	 * @return the dumpFiles
	 */
	public final boolean isDumpFile() {
		return dumpFiles;
	}

	/**
	 * @return the dumpTree
	 */
	public final boolean isDumpTree() {
		return dumpTree;
	}

	/**
	 * Returns true if overwriting of files in the output directory is forced.
	 *
	 * @return whether overwriting of output files is forced
	 */
	public final boolean isForceOverwriting() {
		return forceOverwriting;
	}

	/**
	 * @return the guiDump
	 */
	public final boolean isGuiDump() {
		return guiDump;
	}

	/**
	 * @return the keepGoing
	 */
	public final boolean isKeepGoing() {
		return keepGoing;
	}

	/**
	 * Returns true if the output is quiet.
	 *
	 * @return if output is quiet
	 */
	public final boolean isQuiet() {
		return quiet;
	}

	/**
	 * Returns true if the merge is only simulated but not written to an output file.
	 *
	 * @return true, if the merge is only simulated but not written to an output file.
	 */
	public final boolean isPretend() {
		return pretend;
	}

	/**
	 * Returns whether directories are merged recursively.
	 *
	 * @return true, if directories are merged recursively
	 */
	public final boolean isRecursive() {
		return recursive;
	}

	/**
	 * Resets the input streams.
	 */
	public final void resetStreams() {
		stdIn = new StringWriter();
		stdErr = new StringWriter();
	}

	/**
	 * @param benchmark
	 *            the benchmark to set
	 */
	public final void setBenchmark(final boolean benchmark) {
		this.benchmark = benchmark;
	}

	/**
	 * Sets the number of benchmark runs.
	 *
	 * @param runs
	 *            number of benchmark runs
	 */
	public final void setBenchmarkRuns(final int runs) {
		this.runs = runs;
	}

	/**
	 * Enables bugfixing mode.
	 */
	public final void setBugfixing() {
		bugfixing = true;
	}

	/**
	 * @param diffOnly
	 *            whether to run only diff
	 */
	public final void setDiffOnly(final boolean diffOnly) {
		this.diffOnly = diffOnly;
	}

	/**
	 * @param dumpFiles
	 *            the dumpFiles to set
	 */
	public final void setDumpFiles(boolean dumpFiles) {
		this.dumpFiles = dumpFiles;
	}

	/**
	 * @param dumpTree
	 *            the dumpTree to set
	 */
	public final void setDumpTree(final boolean dumpTree) {
		this.dumpTree = dumpTree;
	}

	/**
	 * Sets whether overwriting of files in the output directory is forced.
	 *
	 * @param forceOverwriting
	 *            overwrite files in the output directory
	 */
	public final void setForceOverwriting(final boolean forceOverwriting) {
		this.forceOverwriting = forceOverwriting;
	}

	/**
	 * @param guiDump
	 *            the guiDump to set
	 */
	public final void setGuiDump(final boolean guiDump) {
		this.guiDump = guiDump;
	}

	/**
	 * @param inputFiles
	 *            the inputFiles to set
	 */
	public final void
			setInputFiles(final ArtifactList<FileArtifact> inputFiles) {
		this.inputFiles = inputFiles;
	}

	/**
	 * @param keepGoing
	 *            the keepGoing to set
	 */
	public final void setKeepGoing(final boolean keepGoing) {
		this.keepGoing = keepGoing;
	}

	/**
	 * Sets the merge strategy.
	 *
	 * @param mergeStrategy
	 *            merge strategy
	 */
	public final void setMergeStrategy(final MergeStrategy<?> mergeStrategy) {
		this.mergeStrategy = mergeStrategy;

		if (mergeStrategy instanceof NWayStrategy) {
			conditionalMerge = true;
		}
	}

	/**
	 * @param outputFile
	 *            the outputFile to set
	 */
	public final void setOutputFile(final FileArtifact outputFile) {
		this.outputFile = outputFile;
	}

	/**
	 * Sets whether the output is quiet or not.
	 *
	 * @param quiet
	 *            do not print merge results to stdout
	 */
	public final void setQuiet(final boolean quiet) {
		this.quiet = quiet;
	}

	/**
	 * Sets whether the merge is only simulated and not written to an output file.
	 *
	 * @param pretend do not write the merge result to an output file
	 */
	public final void setPretend(final boolean pretend) {
		this.pretend = pretend;
	}

	/**
	 * Set whether directories are merged recursively.
	 *
	 * @param recursive
	 *            directories are merged recursively
	 */
	public final void setRecursive(final boolean recursive) {
		this.recursive = recursive;
	}

	/**
	 * @param saveStats
	 *            the saveStats to set
	 */
	public final void setSaveStats(final boolean saveStats) {
		this.saveStats = saveStats;

		if (saveStats) {
			stats = mergeStrategy.createStats();
		}
	}

	/**
	 * @return whether consecutive diffing
	 */
	public final boolean isConsecutive() {
		return consecutive;
	}

	/**
	 * @param consecutive consecutive diffing
	 */
	public final void setConsecutive(final boolean consecutive) {
		this.consecutive = consecutive;
	}

	/**
	 * Whether merge inserts choice nodes instead of direct merging.
	 */
	public boolean isConditionalMerge() {
		return conditionalMerge;
	}

	/**
	 * Whether merge inserts choice nodes instead of direct merging of artifact.
	 */
	public boolean isConditionalMerge(Artifact artifact) {
		return conditionalMerge && (conditionalOutsideMethods || artifact instanceof ASTNodeArtifact && ((ASTNodeArtifact) artifact).isWithinMethod());
	}

	public void setConditionalMerge(boolean conditionalMerge) {
		this.conditionalMerge = conditionalMerge;
	}

	/**
	 * Returns how many levels to keep searching for matches in the subtree if
	 * the currently compared nodes are not equal. If there are no matches
	 * within the specified number of levels, do not look for matches deeper in
	 * the subtree. If this is set to LOOKAHEAD_OFF, the matcher will stop
	 * looking for subtree matches if two nodes do not match. If this is set to
	 * LOOKAHEAD_FULL, the matcher will look at the entire subtree. The default
	 * ist to do no look-ahead matching.
	 *
	 * @return number of levels to look down for subtree matches if the
	 * currently compared nodes do not match
	 */
	public int getLookAhead() { return lookAhead; }

	/**
	 * Sets how many levels to keep searching for matches in the subtree if
	 * the currently compared nodes are not equal. If there are no matches
	 * within the specified number of levels, do not look for matches deeper in
	 * the subtree. If this is set to LOOKAHEAD_OFF, the matcher will stop
	 * looking for subtree matches if two nodes do not match. If this is set to
	 * LOOKAHEAD_FULL, the matcher will look at the entire subtree. The default
	 * ist to do no look-ahead matching.
	 *
	 * @param lookAhead number of levels to look down for subtree matches if the
	 * currently compared nodes do not match
	 */
	public void setLookAhead(int lookAhead) {
		this.lookAhead = lookAhead;
	}

	public boolean isLookAhead() {
		return lookAhead != MergeContext.LOOKAHEAD_OFF;
	}

	/** TODO: This is only for debugging and messing around with the look-ahead feature. */
	public HashMap<String, Integer> getElements() {
		return elements;
	}

	/** TODO: This is only for debugging and messing around with the look-ahead feature. */
	public void addElements(ASTNodeArtifact element) {
		HashMap<String, Integer> elementStats = element.getLanguageElementStatistics();

		for (String key : elementStats.keySet()) {
			Integer value = elements.get(key);
			value = value == null ? elementStats.get(key) : value + elementStats.get(key);
			elements.put(key, value);
		}
	}

	/** TODO: This is only for debugging and messing around with the look-ahead feature. */
	public void addElements(CppNodeArtifact element) {
		HashMap<String, Integer> elementStats = element.getLanguageElementStatistics();

		for (String key : elementStats.keySet()) {
			Integer value = elements.get(key);
			value = value == null ? elementStats.get(key) : value + elementStats.get(key);
			elements.put(key, value);
		}
	}
	
	/** TODO: This is only for debugging and messing around with the look-ahead feature. */
	public HashMap<String, Integer> getMatchedElements() {
		return matchedElements;
	}

	/** TODO: This is only for debugging and messing around with the look-ahead feature. */
	public void matchedElement(Artifact<?> element) {
		String key = element.toString().split(" ")[0];
		key = key.startsWith("AST.") ? key.replaceFirst("AST.", "") : key;
		Integer value = matchedElements.get(key);
		value = value == null ? new Integer(1) : new Integer(value + 1);
		matchedElements.put(key, value);
	}

	/** TODO: This is only for debugging and messing around with the look-ahead feature. */
	public HashMap<String, Integer> getskippedLeftElements() {
		return skippedLeftElements;
	}

	/** TODO: This is only for debugging and messing around with the look-ahead feature. */
	public void skippedLeftElement(Artifact<?> element, int score) {
		String key = element.toString().split(" ")[0];
		key = key.startsWith("AST.") ? key.replaceFirst("AST.", "") : key;
		Integer value = skippedLeftElements.get(key);
		value = value == null ? new Integer(1) : new Integer(value + 1);
		skippedLeftElements.put(key, value);

		// subtreeSize should never be zero if this is a skipped element.
		skippedElements.add(Tuple.of(key, (double) score / (double) element.getSubtreeSize()));
	}

	/** TODO: This is only for debugging and messing around with the look-ahead feature. */
	public HashMap<String, Integer> getskippedRightElements() {
		return skippedRightElements;
	}

	/** TODO: This is only for debugging and messing around with the look-ahead feature. */
	public void skippedRightElement(Artifact<?> element, int score) {
		String key = element.toString().split(" ")[0];
		key = key.startsWith("AST.") ? key.replaceFirst("AST.", "") : key;
		Integer value = skippedRightElements.get(key);
		value = value == null ? new Integer(1) : new Integer(value + 1);
		skippedRightElements.put(key, value);
		skippedElements.add(Tuple.of(key, (double) score/(double) element.getSubtreeSize()));
	}

	/** TODO: This is only for debugging and messing around with the look-ahead feature. */
	public List<Tuple<String, Double>> getSkippedElements() {
		return skippedElements;
	}

	/**
	 * Returns whether conditional merging is used outside of methods.
	 *
	 * @return true if conditional merging is used outside of methods
	 */
	public boolean isConditionalOutsideMethods() {
		return conditionalOutsideMethods;
	}

	/**
	 * Sets whether conditional merging is used outside of methods.
	 *
	 * @param conditionalOutsideMethods use conditional merging outside of methods
	 */
	public void setConditionalOutsideMethods(boolean conditionalOutsideMethods) {
		this.conditionalOutsideMethods = conditionalOutsideMethods;
	}
}
