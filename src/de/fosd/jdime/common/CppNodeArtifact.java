package de.fosd.jdime.common;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

import AST.MethodDecl;
import nu.xom.*;
import de.fosd.jdime.common.operations.ConflictOperation;
import de.fosd.jdime.common.operations.MergeOperation;
import de.fosd.jdime.common.operations.Operation;
import de.fosd.jdime.matcher.Color;
import de.fosd.jdime.matcher.Matching;
import de.fosd.jdime.strategy.CPPNodeStrategy;
import de.fosd.jdime.strategy.MergeStrategy;

/**
 * @author shuruiz
 */
public class CppNodeArtifact extends Artifact<CppNodeArtifact> {

    private Node astnode = null;
    //        private String xmlPath = null;
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
     * @param artifact fileArtifact that can build CppNodeArtifact
     */
    public CppNodeArtifact(final FileArtifact artifact) {
        if (artifact.isEmpty()) {
            astnode = null;
            return;
        }
        setRevision(artifact.getRevision());

        String filePath = artifact.getPath();
        if (filePath.contains(".cpp")) {
            xmlDoc = getXmlDom(getXmlFile(filePath));
        }
        this.astnode = xmlDoc.getChild(0);
        this.initializeChildren();

        renumberTree();
    }

    /**
     * constructor that build CppNodeArtifact from Node
     *
     * @param astnode Node type input
     */
    public CppNodeArtifact(final Node astnode) {
        this.astnode = astnode;
//        this.initializeChildren();
        renumberTree();
    }

    /**
     * constructor initialize an empty node
     */
    public CppNodeArtifact() {
        this.astnode = null;
    }

    Stack<String> conditionStack = new Stack<>();



    /**
     * This function initialize children
     */

    private void initializeChildren() {
        ArtifactList<CppNodeArtifact> children = new ArtifactList<>();
        if (astnode != null) {

            for (int i = 0; i < astnode.getChildCount(); i++) {
                if (((Element) astnode).getLocalName().equals("unit")) {
                    Node node = astnode.getChild(i);

                    if (!node.getValue().replace("\n", "").replace(" ","").equals("")) {
                        if (((Element) node).getLocalName().equals("endif")) {
                            conditionStack.pop();
                            continue;
                        }
                        if (((Element) node).getLocalName().equals("if")) {
                                String cond = node.getValue().substring(4);
                                    conditionStack.push(cond);
                            continue;
                        }


                        if (((Element) node).getLocalName().equals("ifndef")) {
                            String condition = astnode.getChild(i).getValue().substring(8);
                            conditionStack.push("!defined (" + condition + ")");
                            continue;
                        }
                        if (((Element) node).getLocalName().equals("ifdef")) {
                            String condition = astnode.getChild(i).getValue().substring(7);
                            conditionStack.push("defined (" + condition + ")");
                            continue;
                        }
                        if (((Element) node).getLocalName().equals("else")) {
                            if (((Element) node).getNamespacePrefix().equals("cpp")) {
                                String condition = conditionStack.pop();
                                if (condition.contains("!")) {
                                    conditionStack.push(condition.substring(1));
                                } else {
                                    conditionStack.push("!" + condition);
                                }
                                continue;
                            }
                        }

                        CppNodeArtifact child = new CppNodeArtifact(
                                astnode.getChild(i));
                        child.setParent(this);
                        child.setRevision(new Revision(getRevision().getName()));
                        if (conditionStack != null) {
                            child.getRevision().conditions.addAll(conditionStack.stream().collect(Collectors.toList()));
                        }
                        children.add(child);


                    }
//                    child.initializeChildren();
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
     * @param inputFile file that need to be parsed by srcML
     * @return path of XML file
     * @throws IOException e
     */
    public static String getXmlFile(String inputFile) {
        String outXmlFile = inputFile + ".xml";

        if (new File(inputFile).isFile()) {
            try {
                Process process = new ProcessBuilder("/usr/local/bin/src2srcml",
                        inputFile, "-o", outXmlFile).start();
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            System.out.println("File does not exist: " + inputFile);
        }
        return outXmlFile;
    }

    /**
     * parse xml file to DOM.
     *
     * @param xmlFilePath path of xml file
     */
    public static Document getXmlDom(String xmlFilePath) {

        Document doc = null;
        try {
            Builder builder = new Builder();
            File file = new File(xmlFilePath);
            try {
                Thread.sleep(10);                 //1000 milliseconds is one second.
            } catch (InterruptedException ex) {
                Thread.currentThread().interrupt();
            }
            doc = builder.build(file);
        } catch (ParsingException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

        return doc;
    }

    public HashMap<String, Integer> getLanguageElementStatistics() {
        HashMap<String, Integer> elements = new HashMap<>();
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

        ((Element) this.astnode).insertChild(child.astnode.copy(), 0);
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
        if (((Element) astnode).getLocalName().equals("function_decl") || ((Element) astnode).getLocalName().equals("include")) {
            return astnode.getValue().equals((other.getCppNode()).getValue());
        } else if (((Element) astnode).getLocalName().equals("unit")) {
            return true;
        } else if (((Element) astnode).getLocalName().equals("include")) {
            return astnode.getValue().equals((other.getCppNode()).getValue());
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
        if (this.children != null && this.children.size() > 0) {
            Iterator<CppNodeArtifact> it = getChildren().iterator();
            while (it.hasNext()) {
                CppNodeArtifact child = it.next();
                if (child.variants != null) {
                    for (String key : child.variants.keySet()) {
                        CppNodeArtifact var = child.getVariants().get(key);
                        res += var.prettyPrint();
                    }
                } else if (child.matches != null) {
                    res += printMatch(child);
                    res += child.toString() + "\n";
                    res += "#endif\n";
                }
            }

        } else if (this.isChoice()) {
            res += printChoice(this);
        } else if (this.matches != null) {
            res += printMatch(this);
            res += this.toString() + "\n";
            res += "#endif\n";
        } else {
            res += "#if " + "defined (" + getRevision() + ")";
            if (getRevision().conditions.size() > 0) {
                res += " && ";
            }
            res += printCondition(getRevision());
            res += "\n" + this.toString() + "\n";
            res += "#endif\n";
        }
        return res;
    }



    public String printCondition(Revision r) {
        String res = "";
        if (r.conditions.size() > 0) {
            for (String s : r.conditions) {
                if (s.contains("&&") || s.contains("||")) {
                    res += "(";
                }
                res += s;
            }
        }
        if (res.startsWith("(")) {
            res += ")";
        }
        return res;
    }

    public String printChoice(CppNodeArtifact c) {
        String s = "";
        int var_size = c.variants.size();
        for (int i = 0; i < var_size; i++) {
            String str = c.variants.keySet().toArray()[i].toString();
            s += "#if defined (" + str + ")\n";
            s += c.variants.get(str);
            s += printCondition(c.getRevision());
            s += "\n#endif\n";

        }
        return s;
    }


    public String printMatch(CppNodeArtifact c) {
        String s = "";
        String condition = "";
        Collection<Matching<CppNodeArtifact>> matcher = c.matches.values();
        ArrayList<String> var = new ArrayList<>();
        for (Matching<CppNodeArtifact> m : matcher) {
            Revision revision_1 = m.getMatchedArtifacts().getX().getRevision();
            String r1 = "defined (" + revision_1.toString() + ")";
            if (revision_1.conditions.size() > 0) {
                r1 += " && " + printCondition(revision_1);
            }
            if (!var.contains(r1)) var.add(r1);

            Revision revision_2 = m.getMatchedArtifacts().getY().getRevision();
            String r2 = "defined (" + revision_2.toString() + ")";
            if (revision_2.conditions.size() > 0) {
                r2 += " && " + printCondition(revision_2);
            }
            if (!var.contains(r2)) var.add(r2);
        }
        for (int i = 0; i < var.size(); i++) {
            condition += var.get(i);
            if (i < var.size() - 1) {
                condition += " || ";
            }
        }
        s += "#if " + condition + "\n";

        return s;

    }

    /**
     * clone cppNodeArtifact
     *
     * @param artifact cppNodeArtifact
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
