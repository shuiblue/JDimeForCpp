package de.fosd.jdime;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.logging.Handler;
import java.util.logging.Level;
import java.util.logging.LogManager;
import java.util.logging.Logger;

import de.fosd.jdime.common.ArtifactList;
import de.fosd.jdime.common.FileArtifact;
import de.fosd.jdime.common.MergeContext;
import de.fosd.jdime.common.Revision;
import de.fosd.jdime.common.operations.MergeOperation;
import de.fosd.jdime.common.operations.Operation;
import de.fosd.jdime.strategy.MergeStrategy;
import de.fosd.jdime.strategy.NWayStrategy;
import de.fosd.jdime.strategy.StructuredStrategy;
import org.apache.commons.io.FilenameUtils;

public class JDimeWrapper {
	private static final Logger LOG = Logger.getLogger(JDimeWrapper.class.getCanonicalName());

	public static void main(String[] args) throws IOException, InterruptedException {
		// setup logging
		Logger root = Logger.getLogger(JDimeWrapper.class.getPackage().getName());
		root.setLevel(Level.WARNING);

		for (Handler handler : root.getHandlers()) {
			handler.setLevel(Level.WARNING);
		}

		// setup JDime using the MergeContext
		MergeContext context = new MergeContext();
		context.setPretend(true);
		context.setQuiet(false);

		// prepare the list of input files
		ArtifactList<FileArtifact> inputArtifacts = new ArtifactList<>();

		for (Object filename : args) {
			try {
				FileArtifact newArtifact = new FileArtifact(new File((String) filename));

				// set the revision name, this will be used as condition for ifdefs
				// as an example, I'll just use the filenames
				newArtifact.setRevision(new Revision(FilenameUtils.getBaseName(newArtifact.getPath())));

				inputArtifacts.add(newArtifact);
			} catch (FileNotFoundException e) {
				System.err.println("Input file not found: " + (String) filename);
			}
		}

		context.setInputFiles(inputArtifacts);

		// setup strategies
		MergeStrategy<FileArtifact> structured = new StructuredStrategy();
		MergeStrategy<FileArtifact> conditional = new NWayStrategy();

		// run the merge first with structured strategy to see whether there are conflicts
		context.setMergeStrategy(structured);
		context.setSaveStats(true);
		Operation<FileArtifact> merge = new MergeOperation<>(context.getInputFiles(), context.getOutputFile(), null, null, context.isConditionalMerge());
		merge.apply(context);

		// if there are no conflicts, run the conditional strategy
		if (context.getStats().getConflicts() == 0) {
			context = (MergeContext) context.clone();
			context.setSaveStats(false);
			context.setMergeStrategy(conditional);
			// use regular merging outside of methods
			context.setConditionalOutsideMethods(false);
			// we have to recreate the operation because now we will do a conditional merge
			merge = new MergeOperation<>(context.getInputFiles(), context.getOutputFile(), null, null, context.isConditionalMerge());
			merge.apply(context);
		}
	}
}
