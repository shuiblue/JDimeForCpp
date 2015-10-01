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
import de.fosd.jdime.util.IOFunctionSet;


/**
 * @author shuruiz
 */
public class CppNodeArtifact extends Artifact<CppNodeArtifact> {
    IOFunctionSet ioFunctionSet = new IOFunctionSet();
    private Node astnode = null;
    private Document xmlDoc = null;
    Stack<String> conditionStack = new Stack<>();
    Entity entity = new Entity();
    String xmlns = "http://www.sdml.info/srcML/src";


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
        if (filePath.contains(".cpp") || filePath.contains(".h")) {
            xmlDoc = getXmlDom(getXmlFile(filePath));
        }
        if (xmlDoc != null) {
            this.astnode = xmlDoc.getChild(0);
        }
        if (checkIfEndifMatched(this.astnode)) {
            this.initializeChildren();
        }
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

    /**
     * constructor that build CppNodeArtifact
     *
     * @param astnode  node
     * @param revision revision of the node in case the father of this node has conditions
     */
    public CppNodeArtifact(final Node astnode, Revision revision) {
        this.astnode = astnode;
        this.setRevision(revision);
        if (astnode.getClass().getName().contains("Element")) {
            String localName = ((Element) astnode).getLocalName();

            if (!entity.getTerminal().contains(localName) && checkIfEndifMatched(astnode)) {
                this.initializeChildren();
            }
        }
        renumberTree();
    }


    /**
     * constructor that build CppNodeArtifact
     *
     * @param astnode    node
     * @param revision   revision of the node in case the father of this node has conditions
     * @param ifdefMatch if the node is un-deciplined annotation,which means ifdedMatch = false,
     *                   then do not initialize it child
     */
//    public CppNodeArtifact(final Node astnode, Revision revision, boolean ifdefMatch) {
//        this.astnode = astnode;
//        this.setRevision(revision);
//        if (astnode.getClass().getName().contains("Element")) {
//            String localName = ((Element) astnode).getLocalName();
//
//            if (ifdefMatch) {
//                if (!entity.getTerminal().contains(localName)) {
//                    this.initializeChildren(revision);
//                }
//            }
//        }
//        renumberTree();
//    }
    public CppNodeArtifact(final Node astnode, Revision revision, boolean ifdefMatch, Stack<String> parentConditionStack) {
        this.astnode = astnode;
        this.setRevision(revision);


        if (parentConditionStack.size() > 0) {
            conditionStack.addAll(parentConditionStack);
        }

        if (astnode.getClass().getName().contains("Element")) {
            String localName = ((Element) astnode).getLocalName();

            if (ifdefMatch) {
                if (!entity.getTerminal().contains(localName)) {
                    this.initializeChildren(revision);
                }
            }
        }
        renumberTree();
    }

    /**
     * constructor initialize an empty node
     */
    public CppNodeArtifact() {
        this.astnode = null;
        this.children = new ArtifactList<CppNodeArtifact>();
    }

    /**
     * check if the node has un-deciplined annotation
     *
     * @param node
     * @return false if un-deciplined annotation exists
     */
    public boolean checkIfEndifMatched(Node node) {
        int ifdef_num = ((Element) node).getChildElements("ifdef", "http://www.sdml.info/srcML/cpp").size();
        int ifndef_num = ((Element) node).getChildElements("ifndef", "http://www.sdml.info/srcML/cpp").size();
        int if_num = ((Element) node).getChildElements("if", "http://www.sdml.info/srcML/cpp").size();

        int endif_num = ((Element) node).getChildElements("endif", "http://www.sdml.info/srcML/cpp").size();
        int else_num = ((Element) node).getChildElements("else", "http://www.sdml.info/srcML/cpp").size();
        Boolean matched = (ifdef_num + ifndef_num + if_num == endif_num);
        Elements elements = ((Element) node).getChildElements();
        int ifLoc = 0;
        int endifLoc = 0;
        for (int i = 0; i < elements.size(); i++) {
            if (elements.get(i).getLocalName().equals("endif")) {
                endifLoc = i;
                break;
            }
        }

        for (int i = 0; i < elements.size(); i++) {
            if ((elements.get(i).getLocalName().equals("if") && elements.get(i).getNamespacePrefix().equals("cpp"))
                    || elements.get(i).getLocalName().equals("ifdef")
                    || (elements.get(i).getLocalName().equals("ifndef"))) {
                ifLoc = i;
                break;
            }
        }
        Boolean ifBeforeEndif = ifLoc <= endifLoc;

        //-----tricky way
        Boolean elseNum = (else_num <= (ifdef_num + ifndef_num + if_num));
        //----------

        return matched && elseNum && ifBeforeEndif;
    }

    /**
     * This function initialize children
     */

    private void initializeChildren() {
        ArtifactList<CppNodeArtifact> children = new ArtifactList<>();
        if (astnode != null) {

            for (int i = 0; i < astnode.getChildCount(); i++) {
                Node node = astnode.getChild(i);

                Boolean ifdef_endif_Matched;
                if (!node.getValue().replace("\n", "").replace(" ", "").equals("")) {
                    if (node.getClass().getName().contains("Element")) {
                        ifdef_endif_Matched = checkIfEndifMatched(node);
                        String localName = ((Element) node).getLocalName();
                        String namespace_prefix = ((Element) node).getNamespacePrefix();
                        String childValue = astnode.getChild(i).getValue();

                        if (ifdef_endif_Matched) {
                            if (localName.equals("endif")) {
                                conditionStack.pop();
                                continue;
                            }
                            if (localName.equals("if")) {
                                if (namespace_prefix.equals("cpp")) {
                                    String cond = node.getValue().substring(4);

                                    conditionStack.push(cond);
                                    continue;
                                }
                            }
                            if (localName.equals("ifndef")) {
                                String condition = childValue.substring(8);
                                conditionStack.push("!defined (" + condition + ")");
                                continue;
                            }
                            if (localName.equals("ifdef")) {
                                String condition = childValue.substring(7);
                                conditionStack.push("defined (" + condition + ")");
                                continue;
                            }

                            if (localName.equals("elif")) {
                                conditionStack.pop();
                                String condition = childValue.substring(6);
                                conditionStack.push(condition);
                                continue;
                            }

                            if (localName.equals("else")) {
                                if (namespace_prefix.equals("cpp")) {
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
                        if (!entity.getHeadEntity().contains(localName)) {
                            Revision revision = new Revision(getRevision().getName());

                            if (conditionStack != null && conditionStack.size() > 0) {
                                revision.conditions.addAll(conditionStack.stream().collect(Collectors.toList()));
                            }
                            CppNodeArtifact child = new CppNodeArtifact(node, revision, ifdef_endif_Matched, conditionStack);
                            child.setParent(this);
                            child.setRevision(new Revision(getRevision().getName()));
                            if (conditionStack != null && conditionStack.size() > 0) {
                                child.getRevision().conditions.addAll(conditionStack.stream().collect(Collectors.toList()));
                            }
                            children.add(child);
                        }
                    }
                }
            }
        }
        setChildren(children);
    }


    private void initializeChildren(Revision parentRevision) {
        ArtifactList<CppNodeArtifact> children = new ArtifactList<>();
        if (astnode != null) {
            for (int i = 0; i < astnode.getChildCount(); i++) {
                Node node = astnode.getChild(i);

                Boolean ifdef_endif_Matched;
                if (!node.getValue().replace("\n", "").replace(" ", "").equals("")) {
                    if (node.getClass().getName().contains("Element")) {
                        ifdef_endif_Matched = checkIfEndifMatched(node);
                        String localName = ((Element) node).getLocalName();
                        String namespace_prefix = ((Element) node).getNamespacePrefix();
                        String childValue = astnode.getChild(i).getValue();


                        if (ifdef_endif_Matched) {
                            if (localName.equals("endif")) {
                                conditionStack.pop();
                                continue;
                            }
                            if (localName.equals("if")) {
                                if (namespace_prefix.equals("cpp")) {
                                    String cond = node.getValue().substring(4);
                                    conditionStack.push(cond);
                                    continue;
                                }
                            }
                            if (localName.equals("ifndef")) {
                                String condition = childValue.substring(8);
                                conditionStack.push("!defined (" + condition + ")");
                                continue;
                            }
                            if (localName.equals("ifdef")) {
                                String condition = childValue.substring(7);
                                conditionStack.push("defined (" + condition + ")");
                                continue;
                            }

                            if (localName.equals("elif")) {
                                conditionStack.pop();
                                String condition = childValue.substring(6);
                                conditionStack.push(condition);
                                continue;
                            }

                            if (localName.equals("else")) {
                                if (namespace_prefix.equals("cpp")) {
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

                        if (!entity.getHeadEntity().contains(localName)) {
                            Revision revision = new Revision(getRevision().getName());
                            revision.conditions.addAll(parentRevision.conditions);

                            if (conditionStack != null && conditionStack.size() > 0) {
                                revision.conditions.addAll(conditionStack.stream().collect(Collectors.toList()));
                            }

//                            CppNodeArtifact child = new CppNodeArtifact(node, revision, ifdef_endif_Matched);
                            CppNodeArtifact child = new CppNodeArtifact(node, revision, ifdef_endif_Matched, conditionStack);
                            child.setParent(this);
                            child.setRevision(new Revision(getRevision().getName()));
                            if (conditionStack != null && conditionStack.size() > 0) {
                                child.getRevision().conditions.addAll(conditionStack.stream().collect(Collectors.toList()));

                            }
                            child.getRevision().conditions.addAll(parentRevision.conditions);
                            children.add(child);

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
        // create dir for store xml files
        String outXmlFile = "/Users/shuruiz/Work/tmpXMLFile" + inputFile.replace("testcpp", "") + ".xml";
        String[] paths = inputFile.replace("testcpp", "").split("/");
        String dir_suffix = "";
        for (int i = 1; i < paths.length - 1; i++) {
            dir_suffix += "/" + paths[i];
        }
        if (!new File(outXmlFile).exists()) {
            new File("/Users/shuruiz/Work/tmpXMLFile/" + dir_suffix).mkdirs();
        }

        //run srcML
        if (new File(inputFile).isFile()) {
            try {
                new ProcessBuilder("/usr/local/bin/src2srcml",
                        inputFile, "-o", outXmlFile).start();
                sleep();
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
            sleep();
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
        CppNodeArtifact clone;
        clone = new CppNodeArtifact(astnode.copy(), getRevision());
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
        if (checkIfEndifMatched(child.astnode)) {
            String localName = ((Element) child.astnode).getLocalName();
            if (!entity.getTerminal().contains(localName)) {
                child.initializeChildren();

            }
        }
        if (children == null) {
            children = new ArtifactList<CppNodeArtifact>();
        }
        children.add(child);
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
//                    if (this.children == null && other.children == null) {
                    if ((this.children == null && other.children == null)
                            || (this.children == null && other.children != null)
                            || (this.children != null && other.children == null)) {
                        return match;
                    }
                    return true;
                } else if (ast_localName.equals("function")
                        || ast_localName.equals("constructor")) {
                    String astnode_type = clearBlank(astnode.getChild(0).getValue());
                    String astnode_func_name = clearBlank((astnode).getChild(2).getValue());

                    String other_type = clearBlank((other.getCppNode()).getChild(0).getValue());
                    String other_func_name = clearBlank((other.getCppNode()).getChild(2).getValue());

                    return (astnode_type + astnode_func_name).equals(other_type + other_func_name);
                } else if (ast_localName.equals("switch") || ast_localName.equals("case")) {
                    String ast_condition = clearBlank((astnode).getChild(1).getValue());
                    String other_condition = clearBlank((other.getCppNode()).getChild(1).getValue());

                    return ast_condition.equals(other_condition);
                } else if (ast_localName.equals("if")) {

                    String ast_condition = clearBlank((astnode).getChild(1).getValue());
                    String other_condition = clearBlank((other.getCppNode()).getChild(1).getValue());

                    String ast_then = clearBlank((astnode).getChild(2).getValue());
                    String other_then = clearBlank((other.getCppNode()).getChild(2).getValue());


                    return ast_condition.equals(other_condition) || ast_then.equals(other_then);

                } else if (ast_localName.equals("while") || ast_localName.equals("do")) {
                    String ast_condition = clearBlank((((Element) astnode).getChildElements("condition", xmlns)).get(0).getValue());
                    String other_condition = clearBlank((((Element) other.getCppNode()).getChildElements("condition", xmlns)).get(0).getValue());
                    Boolean conditionMatch = ast_condition.equals(other_condition);

                    String ast_block;
                    String other_block;
                    Elements ast_block_elements = ((Element) astnode).getChildElements("block", xmlns);
                    Elements other_block_elements = ((Element) other.getCppNode()).getChildElements("block", xmlns);

                    Boolean blockMatch;
                    if (ast_block_elements.size() > 0 && other_block_elements.size() > 0) {
                        ast_block = clearBlank(ast_block_elements.get(0).getValue());
                        other_block = clearBlank(other_block_elements.get(0).getValue());
                        blockMatch = ast_block.equals(other_block);
                    } else {
                        blockMatch = false;
                    }
                    return blockMatch || conditionMatch;
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

                    if (astnode.getChild(3).getClass().getName().equals("super") ||
                            other.getCppNode().getChild(3).getClass().getName().equals("super")) {
                        ast_suffix = clearBlank((astnode).getChild(3).getValue());
                        other_suffix = clearBlank((other.getCppNode()).getChild(3).getValue());

                    }
                    return (ast_className + ast_suffix).equals(other_className + other_suffix);
                } else if (ast_localName.equals("extern")) {
                    String ast_externName = clearBlank((astnode).getChild(0).getValue());
                    String other_externName = clearBlank((other.getCppNode()).getChild(0).getValue());
                    return ast_externName.equals(other_externName);
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

        if (!isRoot() && !entity.getMatchedEntity().contains(((Element) this.astnode).getLocalName())) {
//        if (!isRoot()) {
            // this language element has a fixed number of children, we need to
            // be careful with this one
            boolean leftChanges = left.isChange();
            boolean rightChanges = right.isChange();

//            for (int i = 0; !leftChanges && i < left.getNumChildren(); i++) {
            for (int i = 0; i < left.getNumChildren(); i++) {
                leftChanges = left.getChild(i).isChange();
                if (leftChanges == false) break;
            }

            for (int i = 0; i < right.getNumChildren(); i++) {
//            for (int i = 0; !rightChanges && i < right.getNumChildren(); i++) {
                rightChanges = right.getChild(i).isChange();
                if (rightChanges == false) break;
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
        return "";
    }
//    public String prettyPrint() {
//        String res = "";
//        if (this.isChoice()) {
//            res += printChoice(this);
//        } else if (this.children != null) {     // matched node
//            Iterator<CppNodeArtifact> it = getChildren().iterator();
//            while (it.hasNext()) {
//                CppNodeArtifact child = it.next();
//                String c_localName = ((Element) child.astnode).getLocalName();
//                //print 'protected' and 'public' before there children
//                if (this.astnode.getClass().getName().contains("Element")) {
//                    String localName = ((Element) this.astnode).getLocalName();
//                    if ((localName.equals("public") || localName.equals("protected")) && !res.contains("protected") && !res.contains("public")) {
//                        res += localName + ":\n+-+-+-\n";
//                    }
//                }
//                if (child.variants != null) {
//                    res += child.prettyPrint();
//                } else if (child.hasMatches()) {
//                    if (entity.getNonTerminal().contains(c_localName)) {
//                        res += printBlock(child);
//                    } else {
//                        res += printMatchSingleNode(child);
//                        res += "+-+-+-\n";
//                    }
//                } else {    //single node
//                    res += printSingleNode(this);
//                }
//            }
//        } else {    //single node
//            res += printSingleNode(this);
//        }
//        res += "+-+-+-\n";
//        return res;
//    }


    /**
     * This function pretty print the non-terminal node.
     * if the node  has matched other node ,then printBlock(c)
     * if the node is a choice node, then printChoice(c)
     *
     * @param c
     * @return
     */
    public String printNonTerminalNode(CppNodeArtifact c) {
        String res = "";
        if (c.children != null && c.hasMatches()) {
            res += printBlock(c);
        } else if (c.isChoice()) {
            res += printChoice(c);
        } else {
            res += c.prettyPrint();
        }
        return res;
    }

    /**
     * this function add the prefix of element to the print result.
     *
     * @param cppNoArt
     * @return
     */
    public String addElementPrefix(CppNodeArtifact cppNoArt) {
        String res = "";
        String nodeLocalName = ((Element) cppNoArt.astnode).getLocalName();

        if (nodeLocalName.equals("function")) {
            String returnType = (((Element) cppNoArt.astnode).getChildElements("type", xmlns)).get(0).getValue();
            String funcName = (((Element) cppNoArt.astnode).getChildElements("name", xmlns)).get(0).getValue();
            res += returnType + " " + funcName;
        } else if (nodeLocalName.equals("constructor")) {
            String funcName = (((Element) cppNoArt.astnode).getChildElements("name", xmlns)).get(0).getValue();
            res += funcName;
        } else if (nodeLocalName.equals("while")) {
            res += "while ";
        } else if (nodeLocalName.equals("for")) {
            String ast_init = (((Element) cppNoArt.astnode).getChildElements("init", xmlns)).get(0).getValue();
            String ast_condition = (((Element) cppNoArt.astnode).getChildElements("condition", xmlns)).get(0).getValue();
            String ast_incr = (((Element) cppNoArt.astnode).getChildElements("incr", xmlns)).get(0).getValue();
            res += "for(" + ast_init + ast_condition + ast_incr + ")\n";
        } else if (nodeLocalName.equals("class")) {
            String ast_name = (((Element) cppNoArt.astnode).getChildElements("name", xmlns)).get(0).getValue();
            res += "class " + ast_name;
        } else if (nodeLocalName.equals("if")) {
            res += "if ";
        } else if (nodeLocalName.equals("switch")) {
            res += "switch";
        } else if (nodeLocalName.equals("case")) {
            res += "case ";
        } else if (nodeLocalName.equals("do")) {
            res += "do ";
        } else if (nodeLocalName.equals("extern")) {
            String ast_name = cppNoArt.astnode.getChild(0).getValue();
            res += ast_name;
        } else if (nodeLocalName.equals("macro")) {
            Element child = ((Element) cppNoArt.astnode).getChildElements().get(0);
            if (child.getLocalName().equals("name")) {
                res += child.getChild(0).getValue();
            }
        }


    return res;
}


    /**
     * This function print the  node that contains 'block'
     *
     * @param cppNoArt
     * @return print result of the node
     */
    private String printBlock(CppNodeArtifact cppNoArt) {
        String res = "";
        String blockCondition = printMatchCondition(cppNoArt);
        String nodeLocalName = ((Element) cppNoArt.astnode).getLocalName();
        res += addElementPrefix(cppNoArt);

        Iterator<CppNodeArtifact> it = cppNoArt.getChildren().iterator();
        while (it.hasNext()) {
            CppNodeArtifact c = it.next();
            String c_localName = ((Element) c.astnode).getLocalName();
            res += "+-+-+-\n";

            // print the node before block (e.g. condition..)
            res += printBlockRelatedEntity(c, nodeLocalName, blockCondition);

            // start to handle <block/> tag node
            String blockString = "";
            if (entity.getBlockEntity().contains(c_localName)) {
                //print "{"
                blockString += printLeftParenthesis(c);
                //print blockBody
                blockString += printBlockBody(c) + "+-+-+-\n";
                // print "}"
                blockString += printRightParenthesis(c, res);

                blockString += "+-+-+-\n";
            } else if (entity.getNonTerminal().contains(c_localName)) {
                blockString = printNonTerminalNode(c);
            }
            res += ioFunctionSet.precisePrettyprint(blockString, blockCondition);

        }
        res = "+-+-+-\n" + blockCondition + ioFunctionSet.precisePrettyprint(res, blockCondition) + "#endif\n";
        res += "+-+-+-\n";
        return res;
    }

    public String printBlockRelatedEntity(CppNodeArtifact c, String parentLocalName, String blockCondition) {
        String c_localName = ((Element) c.astnode).getLocalName();
        String c_value = c.astnode.getValue();
        String res = "";

        if (!parentLocalName.equals("for")) {
            if (entity.getTerminal().contains(c_localName)) {
                if (c.hasMatches()) {
                    //handle do while loop specifically
                    if (c_localName.equals("condition") && parentLocalName.equals("do")) {
                        res += "while " + c_value + ";";
                    } else {
                        res += printMatchSingleNode(c);
                    }
                } else if (c.isChoice()) {
                    res += ioFunctionSet.precisePrettyprint(printChoice(c), blockCondition) + "\n";
                } else {
                    res += c.prettyPrint();
                }
            }
            if (c_localName.equals("expr") && parentLocalName.equals("case")) {
                res += ":";
            }
        }
        return res;
    }

    public String printLeftParenthesis(CppNodeArtifact c) {
        String c_localName = ((Element) c.astnode).getLocalName();
        String child_localName = "";
        String blockString = "";
        if (c.isChoice()) {  // if c is a Choice Node, then the block will include 'else'
            //print "{"
            if (!c_localName.equals("else")) {
                blockString += "{\n";
            }
        } else if (c.hasMatches()) { // c has matched with other node
            if (c.children != null) {
                Elements child_Elements = ((Element) c.astnode).getChildElements();
                if (child_Elements.size() > 0) {
                    child_localName = child_Elements.get(0).getLocalName();
                }
                //print "{"
                if (!c_localName.equals("else")) {
                    if (!c_localName.equals("then") || child_localName.equals("block")) {
                        blockString += "{\n";
                    }
                } else {
                    blockString += "else ";
                    if (!child_localName.equals("if")) {
                        if (((Element) c.astnode).getChildElements("block", "http://www.sdml.info/srcML/src").size() > 0) {
                            blockString += "{\n";
                        }
                    }
                }
            }
        }
        return blockString;
    }

    public String printRightParenthesis(CppNodeArtifact c, String res) {
        String c_localName = ((Element) c.astnode).getLocalName();
        String child_localName = "";
        String blockString = "";
        Elements child_Elements = ((Element) c.astnode).getChildElements();
        if (child_Elements.size() > 0) {
            child_localName = child_Elements.get(0).getLocalName();
        }
        if (c.hasMatches()) {
            if (c_localName.equals("else")) {
                if (!child_localName.equals("if")) {
                    if (((Element) c.astnode).getChildElements("block", "http://www.sdml.info/srcML/src").size() > 0) {
                        blockString += "}\n";
                    }
                }
            } else {
                if (!c_localName.equals("then") || (child_localName.equals("block"))) {
                    blockString += "}\n";
                }
                if (res.startsWith("#if"))
                    blockString += "#endif\n";
            }
        } else {
            if (!c_localName.equals("else")) {
                blockString += "}";
            }
        }
        return blockString;
    }

    public String printBlockBody(CppNodeArtifact c) {
        String blockString = "";
        if (c.isChoice()) {  // if c is a Choice Node, then the block will include 'else'
            blockString += printChoice(c) + "\n";
        } else if (c.hasMatches()) { // c has matched with other node

            if (c.getChildren() != null) {
                Iterator<CppNodeArtifact> it4Block = c.getChildren().iterator();
                while (it4Block.hasNext()) {
                    blockString += "+-+-+-\n";
                    CppNodeArtifact c_block = it4Block.next();
                    String c_block_localName = ((Element) c_block.astnode).getLocalName();
                    if (entity.getClassBody().contains(c_block_localName)) {
                        blockString += c_block.prettyPrint();
                    } else if (c_block.children != null && c_block.hasMatches()) {
                        blockString += printBlock(c_block);
                    } else if (c_block.isChoice()) {
                        blockString += printChoice(c_block);
                    } else {
                        blockString += c_block.printSingleNode(c_block);
                    }
                }
            } else {
                blockString += c.prettyPrint();
            }
        }
        return blockString;
    }

    /**
     * This function print a single node with #ifdef and #endif
     *
     * @return node content
     */
    public String printSingleNode(CppNodeArtifact c) {
        String res = "";
        String tmpCondition = "";
        if (!c.getRevision().getName().equals("choice")) {
            tmpCondition += "#if " + "defined (" + c.getRevision() + ")";
            if (c.getRevision().conditions.size() > 0) {
                tmpCondition += " && ";
            }
            tmpCondition += printCondition(c.getRevision());
        } else {
            tmpCondition += "#if " + "defined (" + c.getRevision().alternatives.toArray()[0] + ")";
        }
        res += tmpCondition;
        res += "\n" + this.toString() + "\n";
        res += "#endif\n";
        return res;
    }


    /**
     * Print the condition of a {@link Revision}
     *
     * @param r
     * @return
     */
    public String printCondition(Revision r) {
        String res = "";
        if (r.conditions.size() > 0) {
            if (r.conditions.size() > 1) {
                res += "(";
            }
            for (String s : r.conditions) {

                if (s.contains("&&") || s.contains("||")) {
                    res += "(";
                }
                if (r.conditions.size() > 1) {
                    res += s + " && ";
                } else if (r.conditions.size() == 1) {
                    res += s;
                }
                if (s.contains("&&") || s.contains("||")) {
                    res += ")";
                }
            }
        }
        if (r.conditions.size() > 1) {
            res = res.substring(0, res.length() - 3) + ")";
        }
        return res;
    }

    /**
     * This function print the choice node
     *
     * @param c
     * @return
     */
    public String printChoice(CppNodeArtifact c) {

        String s = "";
        int var_size = c.variants.size();
        for (int i = 0; i < var_size; i++) {
            String nodeString = "";
            //str is the Revision of each variants
            String str = c.variants.keySet().toArray()[i].toString();
            String cRev = printRevAndCondition(c, str);
            nodeString += cRev;


            nodeString += "\n" + c.variants.get(str);

            //get parents' revision
//            s += printCondition(c.getRevision());
            nodeString += "\n#endif\n";

            //------------

            CppNodeArtifact parent = c.getParent();
            if (parent.hasMatches()) {
                String parentRev = c.printMatchCondition(parent);
                String[] forks = parentRev.replace("#if ", "").split("\\|\\|");
                String fileName = "";
                for (String f : forks) {
                    f = f.replace("defined", "").replace(" ", "");
                    fileName += f.substring(f.indexOf("(") + 1, f.indexOf(")")) + "_";
                }
                String path = "testcpp/statistics/" + fileName + ".txt";
                ioFunctionSet.writeTofile("+-+-+-\n", path);
                ioFunctionSet.writeTofile(nodeString, path);

                if (parent.hasMatches()) {

                    String[] parentRevisionSet = parentRev.split("\\|\\|");
//                    if(parentRevisionSet[i].length()>0) {
                    String rootRev = clearBlank(parentRevisionSet[i].replace("#if ", ""));
                    String childRev = clearBlank(cRev.replace("#if ", ""));
                    String rev = rootRev.split("&&")[0].replace("\n", "");
                    if (childRev.contains(rev)) {
                        if (!rootRev.equals(childRev)) {
                            if (childRev.replace(rev, "").contains("defined")) {
                                String fake_chileRev = childRev.replace(rev, "");

                                String[] rootConditons = rootRev.replace(rev, "").split("&&");
                                for (String con : rootConditons) {
                                    if (con.length() > 0) {
                                        fake_chileRev = fake_chileRev.replace(con, "");
                                    }
                                }

                                if (fake_chileRev.contains("defined")) {
                                    ioFunctionSet.writeTofile("+-+-+-\n", path);
                                    ioFunctionSet.writeTofile("++++additional ifdef+++\n\n", path);
                                    ioFunctionSet.writeTofile("+++parent:" + rootRev + "\n\n", path);
                                    ioFunctionSet.writeTofile("+++child:" + childRev + "\n\n", path);
                                    ioFunctionSet.writeTofile("[" + fake_chileRev + "]\n\n", path);
                                    ioFunctionSet.writeTofile("+-+-+-\n", path);
                                }
                            }
                        }
//                        }
                    }
                }


            }
            //------------

            if (var_size > 1) {
                nodeString += "+-+-+-\n";
            }
            s += nodeString;

        }
        return s;
    }

    /**
     * This function print the match node
     *
     * @param c
     * @return
     */
    public String printMatchSingleNode(CppNodeArtifact c) {
        String res = printMatchCondition(c);
        res += c.toString() + "\n";
        res += "#endif\n";
        return res;
    }


    public String printRevAndCondition(CppNodeArtifact c, String str) {
        String s = "";
        if (c.variants.get(str).hasMatches()) {
            s += printMatchCondition(c.variants.get(str));
        } else {
            s += "#if defined (" + str + ")";
            String condition = printCondition(c.variants.get(str).getRevision());
            if (condition.length() > 0) {
                s += " && " + condition;
            }
        }
        return s;
    }

    /**
     * If the nodes are matched, then print the match condition
     *
     * @param c
     * @return
     */
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


    public static void sleep() {
        try {
            Thread.sleep(300);                 //1000 milliseconds is one second.
        } catch (InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
    }
}
