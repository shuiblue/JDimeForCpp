package de.fosd.jdime.common;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.io.StringWriter;
import java.util.HashMap;
import java.util.Objects;
import java.util.Set;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.TransformerFactoryConfigurationError;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import org.w3c.dom.Document;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;
import de.fosd.jdime.common.operations.MergeOperation;
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
		} catch (ParserConfigurationException e) {
			e.printStackTrace();
		} catch (SAXException e) {
			e.printStackTrace();
		}
		this.astnode = xmlDoc.getChildNodes().item(0);
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
		this.initializeChildren();
		renumberTree();
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

	public HashMap<String, Integer> getLanguageElementStatistics() {
		HashMap<String, Integer> elements = new HashMap<>();

		String key = this.toString().split(" ")[0];
		key = key.startsWith("AST.") ? key.replaceFirst("AST.", "") : key;
		elements.put(key, new Integer(1));

		for (int i = 0; i < getNumChildren(); i++) {
			HashMap<String, Integer> childElements = getChild(i)
					.getLanguageElementStatistics();
			for (String childKey : childElements.keySet()) {
				Integer value = elements.get(childKey);
				value = value == null ? childElements.get(childKey) : value
						+ childElements.get(childKey);
				elements.put(childKey, value);
			}
		}

		return elements;
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
	public int compareTo(CppNodeArtifact o) {
		return astnode.getNodeName().compareTo(o.astnode.getNodeName());
	}

	@Override
	public CppNodeArtifact addChild(CppNodeArtifact child) throws IOException {
		child.setParent(this);
		child.initializeChildren();
		children.add(child);
		// this.astnode.appendChild(child.astnode.cloneNode(true));
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
			sb.append(this);
			sb.append(" " + astnode.getTextContent());

			if (hasMatches()) {
				assert (m != null);
			}
			sb.append(System.lineSeparator());

			// children
			for (CppNodeArtifact child : getChildren()) {
				// if (child.getCppNode().getNodeName().equals("#text")) {
				// sb.append(" " + child.getCppNode().getTextContent());
				//
				// sb.append(System.lineSeparator());
				// }
				// sb.append(" " + child.getCppNode().getTextContent());
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
		boolean nodeNameMatch = astnode.getNodeName().equals(
				other.getCppNode().getNodeName());
		boolean nodeTextContentMatch = astnode.getTextContent().equals(
				other.getCppNode().getTextContent());
//if(astnode.getNodeName().equals("unit")){
//	return astnode.getTextContent().equals(other.getCppNode().getTextContent());
//}
		if (!astnode.getNodeName().equals("function_decl")) {
			return astnode.getNodeName().equals(
					other.getCppNode().getNodeName());
		} else {
			String signature = astnode.getNodeName() + "["
					+ astnode.getTextContent() + "]";
			String other_sig = other.getCppNode().getNodeName() + "["
					+ other.getCppNode().getTextContent() + "]";
			return signature.equals(other_sig);
		}
//return false;

	}

	@Override
	public void merge(MergeOperation<CppNodeArtifact> operation,
			MergeContext context) throws IOException, InterruptedException {
		Objects.requireNonNull(operation, "operation must not be null!");
		Objects.requireNonNull(context, "context must not be null!");

		MergeStrategy<CppNodeArtifact> strategy = new CPPNodeStrategy();
		strategy.merge(operation, context);

		if (!context.isQuiet() && context.hasOutput()) {
			System.out.print(context.getStdIn());
		}
	}

	@Override
	public String toString() {
		if (astnode == null) {
			return "null";
		}
		return astnode.getNodeName();
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

	/**
	 * print AST TREE.
	 * 
	 * @param nodeList
	 */
	private String printNote(NodeList nodeList) {
		StringBuilder sb = new StringBuilder();
		for (int count = 0; count < nodeList.getLength(); count++) {
			Node tempNode = nodeList.item(count);
			// make sure it's element node.
			if (tempNode.getNodeType() == Node.ELEMENT_NODE
					|| tempNode.getNodeType() == Node.TEXT_NODE) {
				if (!tempNode.getTextContent().equals(" ")) {
					sb.append(tempNode.getTextContent() + " ");
				}
				if (tempNode.hasAttributes()) {
					// get attributes names and values
					NamedNodeMap nodeMap = tempNode.getAttributes();
					for (int i = 0; i < nodeMap.getLength(); i++) {
						Node node = nodeMap.item(i);
					}
				}
				if (tempNode.hasChildNodes()) {
					// loop again if has child nodes
					printNote(tempNode.getChildNodes());
				}
			}
		}
		return sb.toString();
	}

	@Override
	public String prettyPrint() {
		String res = "";
		for (CppNodeArtifact child : getChildren()) {
			res += printNote(child.astnode.getChildNodes()) + "\n";
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
		Node old = (Node) artifact.astnode;
		Node program;
		program = old.cloneNode(true);
		CppNodeArtifact p = new CppNodeArtifact(program);
		try {
			p.deleteChildren();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return p;
	}

}
