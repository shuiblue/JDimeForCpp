package de.fosd.jdime.common;

import java.io.File;
import java.io.IOException;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Objects;
import java.util.Set;

import nu.xom.Builder;
import nu.xom.Document;
import nu.xom.Element;
import nu.xom.Node;
import nu.xom.ParsingException;
import nu.xom.ValidityException;
import de.fosd.jdime.common.operations.ConflictOperation;
import de.fosd.jdime.common.operations.MergeOperation;
import de.fosd.jdime.common.operations.Operation;
import de.fosd.jdime.matcher.Color;
import de.fosd.jdime.matcher.Matching;
import de.fosd.jdime.strategy.CPPNodeStrategy;
import de.fosd.jdime.strategy.MergeStrategy;

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
	 * @aspect JDime
	 * @declaredat /local/ssd/lessenic/git/jastaddj/java4/frontend/JDime.jadd:47
	 */
	public boolean isConflict = false;

	/**
	 * Constructor class call c++ parser and create the AST, using this instance
	 * as the root node.
	 * 
	 * @param artifact
	 *            fileArtifact that can build CppNodeArtifact
	 */
	public CppNodeArtifact(final FileArtifact artifact) {
		if (artifact.isEmpty()) {
			astnode = null;
			return;
		}
		setRevision(artifact.getRevision());
		try {
			String filePath = artifact.getPath();
			if (filePath.contains(".cpp")) {
				xmlPath = getXmlFile(filePath);
				xmlDoc = getXmlDom(xmlPath);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		this.astnode = xmlDoc.getChild(0);
		this.initializeChildren();
		renumberTree();
	}

	/**
	 * constructor that build CppNodeArtifact from Node
	 * 
	 * @param astnode
	 *            Node type input
	 */
	public CppNodeArtifact(final Node astnode) {
		this.astnode = astnode;
		// this.initializeChildren();
		renumberTree();
	}

	public static String xmlToString(String inputFile) {
		if (new File(inputFile).isFile()) {
			String outXmlFile = inputFile + ".cpp";
			try {
				Process process = new ProcessBuilder("srcML/srcml2src",
						inputFile, "-o", outXmlFile).start();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			return outXmlFile;
		}
		return null;
	}

	/**
	 * constructor initialize an empty node
	 */
	public CppNodeArtifact() {
		this.astnode = null;
	}

	/**
	 * This function initialize children
	 */
	private void initializeChildren() {
		ArtifactList<CppNodeArtifact> children = new ArtifactList<>();
		if (astnode != null) {
			for (int i = 0; i < astnode.getChildCount(); i++) {
				if (!astnode.getChild(i).getValue().equals("\n")) {

					CppNodeArtifact child = new CppNodeArtifact(
							astnode.getChild(i));
					child.setParent(this);
					child.setRevision(getRevision());
					children.add(child);
					// child.initializeChildren();
				}
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
			Process process = new ProcessBuilder("/usr/local/bin/src2srcml",
					inputFile, "-o", outXmlFile).start();
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
	public static Document getXmlDom(String xmlFilePath) {
		try {

			Builder builder = new Builder();
			File file = new File(xmlFilePath);
			Document doc = builder.build(file);
			return doc;
		} catch (IOException ex) {
			ex.printStackTrace();
			System.err.println("io+" + ex);
		} catch (ValidityException e) {
			e.printStackTrace();
		} catch (ParsingException e) {
			e.printStackTrace();
		}
		return null;
	}

	public HashMap<String, Integer> getLanguageElementStatistics() {
		HashMap<String, Integer> elements = new HashMap<>();
		//
		// String key = this.toString().split(" ")[0];
		// key = key.startsWith("AST.") ? key.replaceFirst("AST.", "") : key;
		// elements.put(key, new Integer(1));
		//
		// for (int i = 0; i < getNumChildren(); i++) {
		// HashMap<String, Integer> childElements = getChild(i)
		// .getLanguageElementStatistics();
		// for (String childKey : childElements.keySet()) {
		// Integer value = elements.get(childKey);
		// value = value == null ? childElements.get(childKey) : value
		// + childElements.get(childKey);
		// elements.put(childKey, value);
		// }
		// }

		return elements;
	}

	@Override
	public Object clone() {
		assert (exists());
		CppNodeArtifact clone = null;
		clone = new CppNodeArtifact(astnode.copy());// --??
		clone.setRevision(getRevision());
		clone.setNumber(getNumber());
		clone.cloneMatches(this);

		assert (clone.exists());

		return clone;

	}

	@Override
	public int compareTo(CppNodeArtifact o) {
		return astnode.getValue().compareTo(o.astnode.getValue());
	}

	@Override
	public CppNodeArtifact addChild(CppNodeArtifact child) throws IOException {
		child.setParent(this);
		child.initializeChildren();
		if (children == null) {
			children = new ArtifactList<CppNodeArtifact>();
		}
		children.add(child);

		// ((Element) this.astnode).insertChild(child.astnode.copy(), 0);
		return child;
	}

	@Override
	public CppNodeArtifact createConflictArtifact(CppNodeArtifact left,
			CppNodeArtifact right) {
		CppNodeArtifact conflict = left != null ? new CppNodeArtifact(
				left.astnode.copy())
				: new CppNodeArtifact(right.astnode.copy());

		conflict.setRevision(new Revision("conflict"));
		conflict.setNumber(virtualcount++);
		conflict.setConflict(left, right);

		return conflict;
	}

	@Override
	public CppNodeArtifact createChoiceDummy(String condition,
			CppNodeArtifact artifact) throws IOException {
		CppNodeArtifact choice;

		choice = new CppNodeArtifact(artifact.astnode.copy());
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

			// sb.append(color);
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

			if (hasMatches()) {
				assert (m != null);
			}

			// children
			ArtifactList<CppNodeArtifact> children = getChildren();
			if (children != null) {
				for (CppNodeArtifact child : children) {
					sb.append(System.lineSeparator());
//					sb.append(child.dumpTree(indent + "  "));
					sb.append(child.getCppNode().getValue());
				}
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
		// return !astnode.getNodeName().equals("cpp:include");
		return false;
	}

	@Override
	public boolean isEmpty() {
		return !hasChildren();
	}

	@Override
	public boolean isLeaf() {
		return false;
	}

	@Override
	public boolean isOrdered() {
		return true;

	}

	@Override
	public boolean matches(CppNodeArtifact other) {
		assert (astnode != null);
		assert (other != null);
		assert (other.astnode != null);
		if (((Element) astnode).getLocalName().equals("function_decl")) {
			return astnode.getValue().equals((other.getCppNode()).getValue());
		} else if (((Element) astnode).getLocalName().equals("unit")) {
			return true;
		} else {
			return false;
		}

	}

	@Override
	public void merge(MergeOperation<CppNodeArtifact> operation,
			MergeContext context) throws IOException, InterruptedException {

		Objects.requireNonNull(operation, "operation must not be null!");
		Objects.requireNonNull(context, "context must not be null!");

		MergeStrategy<CppNodeArtifact> astNodeStrategy = new CPPNodeStrategy();

		MergeScenario<CppNodeArtifact> triple = operation.getMergeScenario();
		CppNodeArtifact left = triple.getLeft();
		CppNodeArtifact right = triple.getRight();
		CppNodeArtifact target = operation.getTarget();

		boolean safeMerge = true;

		// int numChildNoTransform;
		// try {
		// numChildNoTransform =
		// target.astnode.getClass().newInstance().getNumChildNoTransform();
		// } catch (InstantiationException | IllegalAccessException e) {
		// throw new RuntimeException();
		// }

		if (!isRoot()) {

			// this language element has a fixed number of children, we need to
			// be careful with this one
			boolean leftChanges = left.isChange();
			boolean rightChanges = right.isChange();

			for (int i = 0; !leftChanges && i < left.getNumChildren(); i++) {
				leftChanges = left.getChild(i).isChange();
			}

			for (int i = 0; !rightChanges && i < right.getNumChildren(); i++) {
				rightChanges = right.getChild(i).isChange();
			}

			if (leftChanges && rightChanges) {

				safeMerge = false;

				// to be safe, we will report a conflict instead of merging
				CppNodeArtifact targetParent = target.getParent();
				targetParent.removeChild(target);

				Operation<CppNodeArtifact> conflictOp = new ConflictOperation<>(
						left, right, targetParent,
						left.getRevision().getName(), right.getRevision()
								.getName());
				conflictOp.apply(context);
			}
		}

		if (safeMerge) {
			astNodeStrategy.merge(operation, context);
		}

		if (!context.isQuiet() && context.hasOutput()) {
			System.out.print(context.getStdIn());
		}

	}

	private void removeChild(CppNodeArtifact child) {

		Iterator<CppNodeArtifact> it = children.iterator();
		CppNodeArtifact elem;
		while (it.hasNext()) {
			elem = it.next();
			if (elem == child) {
				it.remove();
			}
		}

	}

	@Override
	public String toString() {
		if (astnode == null) {
			return "null";
		}
		return astnode.getValue();
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

	@Override
	public String prettyPrint() {
		String res = "";
		for (CppNodeArtifact child : getChildren()) {
			res += child.astnode.getValue() + "\n";
		}
		return res;
	}

	/**
	 * clone cppNodeArtifact
	 * 
	 * @param artifact
	 *            cppNodeArtifact
	 * @return cloned
	 */
	public static CppNodeArtifact createProgram(CppNodeArtifact artifact) {
		Node old = artifact.astnode;
		Node program;
		program = old.copy();
		CppNodeArtifact p = new CppNodeArtifact(program);
		try {
			((Element) p.astnode).removeChildren();
			p.deleteChildren();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return p;
	}

}
