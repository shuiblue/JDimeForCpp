package de.fosd.jdime.strategy;

import java.util.logging.Logger;

import de.fosd.jdime.common.CppNodeArtifact;
import de.fosd.jdime.common.FileArtifact;
import de.fosd.jdime.common.MergeContext;
import de.fosd.jdime.stats.Stats;

public class CPPNodeStrategy extends AbstractNodeStrategy<CppNodeArtifact> {
	private static final Logger LOG = Logger.getLogger(StructuredStrategy.class.getCanonicalName());
	private static final String CONFLICT_START = "<<<<<<<";
	private static final String CONFLICT_DELIM = "=======";
	private static final String CONFLICT_END = ">>>>>>>";

	@Override
	public Stats createStats() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public String getStatsKey(CppNodeArtifact artifact) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "cppstructured";
	}
	

}
