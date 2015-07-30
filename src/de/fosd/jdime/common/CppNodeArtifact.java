package de.fosd.jdime.common;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

import nu.xom.*;
import de.fosd.jdime.common.operations.ConflictOperation;
import de.fosd.jdime.common.operations.MergeOperation;
import de.fosd.jdime.common.operations.Operation;
import de.fosd.jdime.matcher.Color;
import de.fosd.jdime.matcher.Matching;
import de.fosd.jdime.strategy.CPPNodeStrategy;
import de.fosd.jdime.strategy.MergeStrategy;
import de.fosd.jdime.util.Entity;

/**
 * @author shuruiz
 */
public class CppNodeArtifact extends Artifact<CppNodeArtifact> {

    private Node astnode = null;
    private Document xmlDoc = null;
    Stack<String> conditionStack = new Stack<>();
    Entity entity = new Entity();
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
//            xmlDoc = getXmlDom(filePath );
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
        if (astnode.getClass().getName().contains("Element")) {
            String localName = ((Element) astnode).getLocalName();

            if (!entity.getTerminal().contains(localName)) {
                this.initializeChildren();
            }
        }
        renumberTree();
    }

    public CppNodeArtifact(final Node astnode, Revision revision) {
        this.astnode = astnode;
        this.setRevision(revision);
        if (astnode.getClass().getName().contains("Element")) {
            String localName = ((Element) astnode).getLocalName();

            if (!entity.getTerminal().contains(localName)) {
                this.initializeChildren();
            }
        }
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
        if (astnode != null) {

            for (int i = 0; i < astnode.getChildCount(); i++) {
                Node node = astnode.getChild(i);

                if (!node.getValue().replace("\n", "").replace(" ", "").equals("")) {
                    if (node.getClass().getName().contains("Element")) {

                        if (((Element) node).getLocalName().equals("endif")) {
                            conditionStack.pop();
                            continue;
                        }
                        if (((Element) node).getLocalName().equals("if")) {
                            if (((Element) node).getNamespacePrefix().equals("cpp")) {
                                String cond = node.getValue().substring(4);
                                conditionStack.push(cond);
                                continue;
                            }
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
                    }

                    if (node.getClass().getName().contains("Element")) {
                        String localName = ((Element) node).getLocalName();
                        if (!entity.getHeadEntity().contains(localName)) {
                            CppNodeArtifact child = new CppNodeArtifact(node, getRevision());
                            child.setParent(this);
                            child.setRevision(new Revision(getRevision().getName()));
                            if (conditionStack != null) {
                                child.getRevision().conditions.addAll(conditionStack.stream().collect(Collectors.toList()));
                                child.getRevision().conditions.addAll(child.getParent().getRevision().conditions);
                            }
                            children.add(child);

                            if (!entity.getTerminal().contains(localName)) {
                                child.initializeChildren();
                            }
                        }
                    }

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
        clone = new CppNodeArtifact(astnode.copy(), getRevision());// --??
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

//        ((Element) this.astnode).insertChild(child.astnode.copy(), 0);
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
        choice = new CppNodeArtifact(artifact.astnode.copy(), getRevision());
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
        String clear_astnodeValue = astnode.getValue().replace("\n", "").replace(" ", "").replace("\t", "");
        String clear_otherValue = other.getCppNode().getValue().replace("\n", "").replace(" ", "").replace("\t", "");
        Boolean match = clear_astnodeValue.equals(clear_otherValue);

        String astnode_Class = astnode.getClass().getName();
        String ast_localName = ((Element) astnode).getLocalName();
        String other_localName = ((Element) other.getCppNode()).getLocalName();
        Boolean localEqual = ast_localName.equals(other_localName);

        if (astnode_Class.contains("Element")) {
            if (localEqual) {
                if (entity.getMatchedEntity().contains(ast_localName)) {
                    return true;
                } else if (ast_localName.equals("function")
                        || ast_localName.equals("constructor")) {
                    String astnode_type = astnode.getChild(0).getValue();
                    String astnode_func_name = (astnode).getChild(2).getValue();

                    String other_type = (other.getCppNode()).getChild(0).getValue();
                    String other_func_name = (other.getCppNode()).getChild(2).getValue();

                    return (astnode_type + astnode_func_name).equals(other_type + other_func_name);
                } else if (ast_localName.equals("while")) {

                    String ast_condition = clearBlank((astnode).getChild(1).getValue());
                    String other_condition = clearBlank((other.getCppNode()).getChild(1).getValue());
                    String ast_block = clearBlank((astnode).getChild(3).getValue());
                    String other_block = clearBlank((other.getCppNode()).getChild(3).getValue());
                    return ast_block.equals(other_block) || ast_condition.equals(other_condition);
                } else if (ast_localName.equals("for")) {
                    String ast_init = clearBlank((astnode).getChild(1).getValue());
                    String other_init = clearBlank((other.getCppNode()).getChild(1).getValue());
                    String ast_condition = clearBlank((astnode).getChild(3).getValue());
                    String other_condition = clearBlank((other.getCppNode()).getChild(3).getValue());

                    String ast_incr = clearBlank((astnode).getChild(5).getValue());
                    String other_incr = clearBlank((other.getCppNode()).getChild(5).getValue());


                    return (ast_init + ast_condition + ast_incr).equals(other_init + other_condition + other_incr);

                } else if (ast_localName.equals("class")) {
                    String ast_className = clearBlank((astnode).getChild(1).getValue());
                    String other_className = clearBlank((other.getCppNode()).getChild(1).getValue());
                    String ast_suffix = "";
                    String other_suffix = "";

                    if(astnode.getChild(3).getClass().getName().equals("super")||
                            other.getCppNode().getChild(3).getClass().getName().equals("super")  ){
                        ast_suffix=clearBlank((astnode).getChild(3).getValue());
                        other_suffix=clearBlank((other.getCppNode()).getChild(3).getValue());

                    }
                    return (ast_className+ast_suffix).equals(other_className+other_suffix);
                } else {
                    return match;
                }
            }
        } else if (astnode_Class.contains("Text")) {
            return match;
        }
        return false;
    }

    public String clearBlank(String s) {
        return s.replace("\n", "").replace(" ", "").replace("\t", "");
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

//            for (int i = 0; !leftChanges && i < left.getNumChildren(); i++) {
            for (int i = 0; i < left.getNumChildren(); i++) {
                leftChanges = left.getChild(i).isChange();
            }

            for (int i = 0; i < right.getNumChildren(); i++) {
//            for (int i = 0; !rightChanges && i < right.getNumChildren(); i++) {
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
                String child_localName = ((Element) child.astnode).getLocalName();

                if (entity.getNonTerminal().contains(child_localName)) {
                    res += printNonTerminalNode(child);
                } else if (child.variants != null) {
                    for (String key : child.variants.keySet()) {
                        CppNodeArtifact var = child.getVariants().get(key);
                        res += var.prettyPrint();
                    }
                } else if (child.matches != null) {
                    res += printMatchNode(child);
                    res += "----\n";
                }
            }
        } else if (this.isChoice()) {
            res += printChoice(this);
        } else if (this.matches != null) {
            res += printMatchNode(this);
        } else {
            res += printSingleNode();
        }
        return res + "----\n";
    }

    public String printNonTerminalNode(CppNodeArtifact c) {
        String res = "";
        if (c.hasMatches()) {
            res += printBlock(c);
        } else if (c.isChoice()) {
            res += printChoice(c) + "#endif";
        }
        res += "----\n";
        return res;
    }

    Stack<String> block_condStack = new Stack<>();

    private String printBlock(CppNodeArtifact cppNoArt) {
        String res = "";
        String blockCondition = printMatchCondition(cppNoArt);
        res += blockCondition;

        String nodeLocalName = ((Element) cppNoArt.astnode).getLocalName();
        if (nodeLocalName.equals("function") || nodeLocalName.equals("while")) {
            //get function return type and name
            //while (while +condition)
            String returnType = (cppNoArt.astnode.getChild(0)).getValue();
            String funcName = (cppNoArt.astnode.getChild(2)).getValue();
            res += returnType + " " + funcName;
        } else if (nodeLocalName.equals("for")) {
            String ast_init = clearBlank(( cppNoArt.astnode).getChild(1).getValue());
            String ast_condition = clearBlank(( cppNoArt.astnode).getChild(3).getValue());
            String ast_incr = clearBlank(( cppNoArt.astnode).getChild(5).getValue());
            res += "for(" + ast_init + ast_condition + ast_incr + ")\n";

        }else if(nodeLocalName.equals("class")){
            res+="class "+cppNoArt.astnode.getChild(1).getValue();
        }

        Iterator<CppNodeArtifact> it = cppNoArt.getChildren().iterator();
        while (it.hasNext()) {
            CppNodeArtifact c = it.next();
            String c_localName = ((Element) c.astnode).getLocalName();
            if (!nodeLocalName.equals("for")) {
                if (entity.getTerminal().contains(c_localName)) {
                    if (c.hasMatches()) {
                        res += c.astnode.getValue();
                    } else {

                        res += "\n" + printChoice(c) + "#endif\n";
                    }
                }
            }
            if (entity.getBlockEntity().contains(c_localName)) {
                res += "{\n";
                if (c.isChoice()) {
                    res += printChoice(c) + "#endif\n";
                } else {
                    Iterator<CppNodeArtifact> it4Block = c.getChildren().iterator();
                    while (it4Block.hasNext()) {
                        CppNodeArtifact c_block = it4Block.next();
                        String c_block_localName = ((Element) c_block.astnode).getLocalName();
                        String condition;
                        if (c_block.hasMatches()) {
                            condition = printMatchCondition(c_block);
                        } else {
                            condition = printChoice(c_block).split("\n")[0];
                        }
                        if (block_condStack.size() > 0) {
                            if (!condition.equals(block_condStack.lastElement())) {
                                res += "#endif\n";
                                if (!condition.equals(blockCondition)) {

                                    if (entity.getNonTerminal().contains(c_block_localName)) {
                                        String block = printNonTerminalNode(c_block);
                                        for (int i = 1; i < block.split("\n").length - 1; i++) {
                                            res += block.split("\n")[i] + "\n";
                                        }
                                        continue;
                                    }
                                    res += condition;
                                    block_condStack.pop();
                                    block_condStack.push(condition);
                                }
                                block_condStack.pop();
                                if (entity.getNonTerminal().contains(c_block_localName)) {
                                    res += printNonTerminalNode(c_block);
                                    continue;
                                }
                                if (c_block.hasMatches()) {
                                    res += c_block.astnode.getValue() + "\n";
                                } else {
                                    res += printChoice(c_block);
                                }
                            } else {
                                if (entity.getNonTerminal().contains(c_block_localName)) {
                                    String block = printNonTerminalNode(c_block);
                                    for (int i = 1; i < block.split("\n").length - 1; i++) {
                                        res += block.split("\n")[i] + "\n";
                                    }
                                    continue;
                                }
                                if (c_block.hasMatches()) {
                                    res += c_block.astnode.getValue() + "\n";
                                } else {
                                    res += "\n" + printChoice(c_block);
                                }
                            }
                        } else {
                            if (!condition.equals(blockCondition)) {
                                if (entity.getNonTerminal().contains(c_block_localName)) {
                                    res += printNonTerminalNode(c_block);
                                    continue;
                                }

                                block_condStack.add(condition);
                                if (c_block.hasMatches()) {
                                    res += "#endif";
                                    res += condition + "\n";
                                } else {
                                    res += printChoice(c_block);
                                }
                            } else {
                                if (entity.getNonTerminal().contains(c_block_localName)) {
                                    String block = printNonTerminalNode(c_block);
                                    for (int i = 1; i < block.split("\n").length - 1; i++) {
                                        res += block.split("\n")[i] + "\n";
                                    }
                                    continue;
                                }
                                if (c_block.hasMatches()) {
                                    res += c_block.astnode.getValue() + "\n";
                                } else {
                                    res += printChoice(c_block).substring(1, printChoice(c_block).length() - 1);
                                }
                            }
                        }
                    }
                    if (block_condStack.size() > 0) {
                        block_condStack.pop();
                        res += "#endif\n";
                    }
                }
                res += "}\n#endif";
            }
        }
        return res;
    }

    public String printSingleNode() {
        String res = "";
        String tmpCondition = "";
        tmpCondition += "#if " + "defined (" + getRevision() + ")";
        if (getRevision().conditions.size() > 0) {
            tmpCondition += " && ";
        }
        tmpCondition += printCondition(getRevision());
        res += tmpCondition;
        res += "\n" + toString() + "\n";
        res += "#endif\n";
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
            s += "#if defined (" + str + ")";
            if (((Element) c.astnode).getLocalName().equals("block")) {
                for (int t = 1; t < c.variants.get(str).astnode.getValue().split("\n").length - 1; t++) {
                    s += "\n" + c.variants.get(str).astnode.getValue().split("\n")[t] + "\n";
                }

            } else {
                s += "\n" + c.variants.get(str) + "\n";
            }
            s += printCondition(c.getRevision());
            if (i < var_size - 1) {
                s += "#endif\n";
            }
        }
        return s;
    }


    public String printMatchNode(CppNodeArtifact c) {
        String res = "";
        res += printMatchCondition(c);
        res += c.toString() + "\n";
        res += "#endif\n";
        return res;

    }

    public String printMatchCondition(CppNodeArtifact c) {
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
        CppNodeArtifact p = new CppNodeArtifact(program, artifact.getRevision());
        try {
            ((Element) p.astnode).removeChildren();
            p.deleteChildren();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return p;
    }


}
