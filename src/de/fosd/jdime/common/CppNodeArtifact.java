package de.fosd.jdime.common;

import java.io.File;
import java.io.IOException;
import java.util.Objects;
import java.util.Set;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.xml.sax.SAXException;

import de.fosd.jdime.common.operations.ConflictOperation;
import de.fosd.jdime.common.operations.MergeOperation;
import de.fosd.jdime.common.operations.Operation;
import de.fosd.jdime.matcher.Color;
import de.fosd.jdime.matcher.Matching;
import de.fosd.jdime.strategy.ASTNodeStrategy;
import de.fosd.jdime.strategy.MergeStrategy;
import de.fosd.jdime.strategy.NWayStrategy;

/**
 * 
 * @author shuruiz
 *
 */
public class CppNodeArtifact extends Artifact<CppNodeArtifact> {

	private Node astnode = null;
	private String xmlPath = null;
	private Document xmlDoc = null;

	/**
	 * Constructor class call c++ parser and create the AST, using this instance
	 * as the root node.
	 * 
	 * @param artifact
	 */
	public CppNodeArtifact(String path) {
		try {

			xmlPath = getXmlFile(path);
			xmlDoc = getXmlDom(xmlPath);
		} catch (IOException e) {
			e.printStackTrace();
		} catch (ParserConfigurationException e) {
			e.printStackTrace();
		} catch (SAXException e) {
			e.printStackTrace();
		}
		this.astnode = xmlDoc.getChildNodes().item(1);
		renumberTree();
	}
	
	public CppNodeArtifact(final FileArtifact artifact) {
		setRevision(artifact.getRevision());

		Node astnode;
//		if (artifact.isEmpty()) {
//			astnode = new Node();
//		} else {
//			Program p = initProgram();
//			p.addSourceFile(artifact.getPath());
//			astnode = p;
			astnode = (Node) new CppNodeArtifact(artifact.getPath());
//		}

		this.astnode = astnode;
		this.initializeChildren();
		renumberTree();
	}
	public CppNodeArtifact(final Node astnode) {
		this.astnode = astnode;
		this.initializeChildren();
	}

	public CppNodeArtifact() {
		// this.astnode = new NODE;
		//
		// this.initializeChildren();
		System.out.println("fix me");
	}

	private void initializeChildren() {
		ArtifactList<CppNodeArtifact> children = new ArtifactList<>();
		for (int i = 0; i < astnode.getChildNodes().getLength(); i++) {
			if (astnode != null) {
				CppNodeArtifact child = new CppNodeArtifact(astnode
						.getChildNodes().item(i));
				child.setParent(this);
				child.setRevision(getRevision());
				children.add(child);
				child.initializeChildren();
			}
		}
		setChildren(children);
	}

	/**
	 * Returns the encapsulated cpp ASTNode
	 *
	 * @return encapsulated ASTNode object from DOM
	 */
	public final Node getCppNode() {
		return astnode;
	}

	/**
	 * 
	 * @param inputFile
	 *            file that need to be parsed by srcML
	 * @return path of XML file
	 * @throws IOException
	 *             e
	 */
	public static String getXmlFile(String inputFile) throws IOException {
		if (new File(inputFile).isFile()) {
			String outXmlFile = inputFile + ".xml";
			Process process = new ProcessBuilder("srcML/src2srcml", inputFile,
					"-o", outXmlFile).start();
			return outXmlFile;
		} else {
			System.out.println("File does not exist: " + inputFile);
		}
		return null;
	}

	/**
	 * parse xml file to DOM.
	 * 
	 * @param xmlFilePath
	 *            path of xml file
	 * @return dom
	 * @throws ParserConfigurationException
	 *             e
	 * @throws SAXException
	 *             e
	 */
	public static Document getXmlDom(String xmlFilePath)
			throws ParserConfigurationException, SAXException {
		try {
			DocumentBuilderFactory docFactory = DocumentBuilderFactory
					.newInstance();
			DocumentBuilder docBuilder = docFactory.newDocumentBuilder();
			Document doc = docBuilder.parse(xmlFilePath);

			return doc;
		}

		catch (IOException ex) {
			ex.printStackTrace();
			System.err.println("io+" + ex);
		}
		return null;
	}

	@Override
	public Object clone() {
		assert (exists());
		CppNodeArtifact clone = null;
		clone = new CppNodeArtifact(astnode.cloneNode(astnode.hasChildNodes()));// --??
		clone.setRevision(getRevision());
		clone.setNumber(getNumber());
		clone.cloneMatches(this);

		assert (clone.exists());

		return clone;

	}

	@Override
	// --to do
	public int compareTo(CppNodeArtifact o) {
		return astnode.getNodeName().compareTo(o.astnode.getNodeName());
	}

	@Override
	public CppNodeArtifact addChild(CppNodeArtifact child) throws IOException {
		child.setParent(this);
		child.initializeChildren();
		children.add(child);

		return child;
	}

	@Override
	public CppNodeArtifact createConflictArtifact(CppNodeArtifact left,
			CppNodeArtifact right) {
		CppNodeArtifact conflict = left != null ? new CppNodeArtifact(
				left.astnode.cloneNode(true)) : new CppNodeArtifact(
				right.astnode.cloneNode(true));

		conflict.setRevision(new Revision("conflict"));
		conflict.setNumber(virtualcount++);
		conflict.setConflict(left, right);

		return conflict;
	}

	@Override
	public CppNodeArtifact createChoiceDummy(String condition,
			CppNodeArtifact artifact) throws IOException {
		CppNodeArtifact choice;

		choice = new CppNodeArtifact(artifact.astnode.cloneNode(true));
		choice.setRevision(new Revision("choice"));
		choice.setNumber(virtualcount++);
		choice.setChoice(condition, artifact);
		return choice;
	}

	@Override
	public CppNodeArtifact createEmptyArtifact() throws IOException {
		CppNodeArtifact emptyArtifact = new CppNodeArtifact();
		emptyArtifact.setRevision(getRevision());
		return emptyArtifact;
	}

	@Override
	protected String dumpTree(String indent) {

		assert (astnode != null);
		StringBuilder sb = new StringBuilder();

		// node itself
		Matching<CppNodeArtifact> m = null;

		// color
		if (!isConflict() && hasMatches()) {

			Set<Revision> matchingRevisions = matches.keySet();

			// print color code
			String color = "";

			for (Revision rev : matchingRevisions) {
				m = getMatching(rev);
				color = m.getHighlightColor().toShell();
			}

			sb.append(color);
		}

		if (isConflict()) {
			sb.append(Color.RED.toShell());
			sb.append(indent).append("(").append(getId()).append(") ");
			sb.append(this);
			sb.append(System.lineSeparator());
			sb.append(Color.RED.toShell());
			sb.append("<<<<<<< ");
			sb.append(System.lineSeparator());
			// children
			if (left != null) {
				sb.append(left.dumpTree(indent));
			}
			sb.append(Color.RED.toShell());
			sb.append("======= ");
			sb.append(System.lineSeparator());
			// children
			if (right != null) {
				sb.append(right.dumpTree(indent));
			}

			sb.append(Color.RED.toShell());
			sb.append(">>>>>>> ");
			sb.append(System.lineSeparator());
		} else if (isChoice()) {
			Set<String> conditions = getVariants().keySet();
			sb.append(Color.RED.toShell());
			sb.append(indent).append("(").append(getId()).append(") ");
			sb.append(this);
			sb.append(System.lineSeparator());

			for (String condition : conditions) {
				sb.append(Color.RED.toShell());
				sb.append("#ifdef " + condition);
				sb.append(System.lineSeparator());
				// children
				CppNodeArtifact variant = getVariants().get(condition);
				if (variant != null) {
					sb.append(variant.dumpTree(indent));
				}
				sb.append(Color.RED.toShell());
				sb.append("#endif");
				sb.append(System.lineSeparator());

			}
		} else {
			sb.append(indent).append("(").append(getId()).append(") ");
			sb.append(this);

			if (hasMatches()) {
				assert (m != null);
				sb.append(" <=> (").append(m.getMatchingArtifact(this).getId())
						.append(")");
				sb.append(Color.DEFAULT.toShell());
			}
			sb.append(System.lineSeparator());

			// children
			for (CppNodeArtifact child : getChildren()) {
				sb.append(child.dumpTree(indent + "  "));
			}
		}

		return sb.toString();

	}

	@Override
	public boolean exists() {
		return astnode != null;
	}

	@Override
	public void deleteChildren() throws IOException {
		while (hasChildren()) {
			CppNodeArtifact child = getChild(0);
			child.astnode = null;
			children.remove(0);
		}
	}

	@Override
	public String getId() {
		return getRevision() + "-" + getNumber();
	}

	@Override
	public String getStatsKey(MergeContext context) {
		return "nodes";
	}

	@Override
	public boolean hasUniqueLabels() {
		System.out.println("unique lables");
		return false;
	}

	@Override
	public boolean isEmpty() {
		return !hasChildren();
	}

	@Override
	public boolean isLeaf() {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean isOrdered() {
		return !astnode.getNodeName().equals("cpp:include")
				&& !astnode.getNodeName().equals("decl_stmt")
				&& !astnode.getNodeName().equals("comment")
				&& !astnode.getNodeName().equals("cpp:define")
				&& !astnode.getNodeName().equals("function");

	}

	@Override
	public boolean matches(CppNodeArtifact other) {
		assert (astnode != null);
		assert (other != null);
		assert (other.astnode != null);

		return astnode.isEqualNode(other.getCppNode());
	}

	@Override
	public void merge(MergeOperation<CppNodeArtifact> operation,
			MergeContext context) throws IOException, InterruptedException {
		Objects.requireNonNull(operation, "operation must not be null!");
		Objects.requireNonNull(context, "context must not be null!");

		MergeStrategy<CppNodeArtifact> strategy = null; // new MergeStrategy<>();
		strategy.merge(operation, context);

		if (!context.isQuiet() && context.hasOutput()) {
			System.out.print(context.getStdIn());
		}
	}

	@Override
	public String toString() {
		return astnode.getTextContent();
	}
	/**
	 * Returns statistical data of the tree. stats[0]: number of nodes stats[1]:
	 * tree depth stats[2]: maximum number of children
	 *
	 * @return statistics
	 */
	public final int[] getStats() {
		// 0: number of nodes, 1: tree depth, 2: max children
		int[] mystats = new int[3];
		mystats[0] = 1;
		mystats[1] = 0;
		mystats[2] = getNumChildren();

		for (int i = 0; i < getNumChildren(); i++) {
			int[] childstats = getChild(i).getStats();
			mystats[0] += childstats[0];
			if (childstats[1] + 1 > mystats[1]) {
				mystats[1] = childstats[1] + 1;
			}
			if (childstats[2] > mystats[2]) {
				mystats[2] = childstats[2];
			}
		}

		return mystats;
	}

}
