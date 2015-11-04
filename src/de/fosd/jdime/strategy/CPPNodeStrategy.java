package de.fosd.jdime.strategy;

import java.util.logging.Logger;

import de.fosd.jdime.common.CppNodeArtifact;

public class CPPNodeStrategy extends AbstractNodeStrategy<CppNodeArtifact> {
	private static final Logger LOG = Logger.getLogger(StructuredStrategy.class.getCanonicalName());
	private static final String CONFLICT_START = "<<<<<<<";
	private static final String CONFLICT_DELIM = "=======";
	private static final String CONFLICT_END = ">>>>>>>";

	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "cppstructured";
	}
	

}
