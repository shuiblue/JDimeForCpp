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
    public CppNodeArtifact(final Node astnode, Revision revision, boolean ifdefMatch) {
        this.astnode = astnode;
        this.setRevision(revision);
        if (astnode.getClass().getName().contains("Element")) {
            String localName = ((Element) astnode).getLocalName();

            if (ifdefMatch) {
                if (!entity.getTerminal().contains(localName)) {
                    this.initializeChildren(revision);
//                    this.initializeChildren();
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
        Boolean matched = (ifdef_num + ifndef_num + if_num == endif_num);
        if (!matched) {
            System.out.println("warning!----------" + node.getBaseURI() + "\n");
//            System.out.println("warning!----------" + node.toXML() + "\n");
//            System.out.println("ifdef_num: "+ifdef_num);
//            System.out.println("ifndef_num: "+ifndef_num);
//            System.out.println("if_num: "+if_num);
//            System.out.println("endif_num: "+endif_num);

//            File log = new File("/Users/shuruiz/Work/originMarlin/log.txt");
//            try{
//                if(log.exists()==false){
//                    System.out.println("We had to make a new file.");
//                    log.createNewFile();
//                }
//                PrintWriter out = new PrintWriter(new FileWriter(log,true));
//                out.append("******* " + node.getBaseURI() +"******* " + "\n");
////                out.append(node.toXML());
//                out.close();
//            }catch(IOException e){
//                System.out.println("COULD NOT LOG!!");
//            }

        }
        return matched;
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
                            CppNodeArtifact child = new CppNodeArtifact(node, revision, ifdef_endif_Matched);
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

                            CppNodeArtifact child = new CppNodeArtifact(node, revision, ifdef_endif_Matched);
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
        String outXmlFile = inputFile + ".xml";
        if (new File(inputFile).isFile()) {
            try {
                Process process = new ProcessBuilder("/usr/local/bin/src2srcml",
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
            child.initializeChildren();
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

                    if (this.children == null && other.children == null) {
                        return false;
                    }
                    return true;
                } else if (ast_localName.equals("function")
                        || ast_localName.equals("constructor")) {
                    String astnode_type = astnode.getChild(0).getValue();
                    String astnode_func_name = (astnode).getChild(2).getValue();

                    String other_type = (other.getCppNode()).getChild(0).getValue();
                    String other_func_name = (other.getCppNode()).getChild(2).getValue();

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

        if (!isRoot()) {
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
//                if (leftChanges == false) break;
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
        String res = "";
        if (this.children != null && this.children.size() > 0) {
            Iterator<CppNodeArtifact> it = getChildren().iterator();
            while (it.hasNext()) {
                CppNodeArtifact child = it.next();
                String child_localName = ((Element) child.astnode).getLocalName();
                if (child.variants != null) {
                    if (entity.getNonTerminal().contains(child_localName)) {
                        res += printChoice(child) + "+-+-+-\n";
                        continue;
                    }
                    for (String key : child.variants.keySet()) {
                        CppNodeArtifact var = child.getVariants().get(key);
                        res += var.prettyPrint();
                    }
                } else if (child.matches != null) {
                    if (entity.getNonTerminal().contains(child_localName)) {
                        res += printBlock(child);
                        continue;
                    }
                    if (this.astnode.getClass().getName().contains("Element")) {
                        String localName = ((Element) this.astnode).getLocalName();

                        if (localName.equals("public") || localName.equals("protected")) {
                            res += localName + ":\n+-+-+-\n";
                        }
                    }
                    res += printMatchNode(child);
                    res += "+-+-+-\n";
                } else {
                    res += printChoice(this);
                }
            }
        } else if (this.isChoice()) {
            res += printChoice(this);
        } else if (this.matches != null) {
            res += printMatchNode(this);
        } else {
            res += printSingleNode(this);
        }
        res += "+-+-+-\n";
        return res;
    }


    /**
     * This function presice the pretty print result of a block when:
     * 1)neighbor lines have the same condition
     * 2) the element has the same condition with the block
     *
     * @param res            origin pretty print result
     * @param blockCondition condition of the block
     * @return presiced result
     */
    public String presicePrettyprint(String res, String blockCondition) {
        String newResult = "";
        Stack<String> conditionStack = new Stack<>();
        String[] elements = res.split("\\+-\\+-\\+-\n");
        for (int j = 0; j < elements.length; j++) {
            String e = elements[j];

            if (e.length() > 0 && !e.equals("\n")) {
                String[] tmp = e.split("\n");
                if (conditionStack.size() > 0) {
                    String lastCon = conditionStack.lastElement();
                    if (lastCon.equals(tmp[0])) {
                        String x = "";
                        for (int i = 1; i < tmp.length - 1; i++) {
                            x += tmp[i] + "\n";
                        }
                        newResult += x;
                        continue;
                    } else {
                        conditionStack.pop();
                        if (tmp[0].equals(blockCondition.replace("\n", ""))) {
                            newResult += "#endif\n";
                            if (tmp.length > 3) {
                                for (int i = 1; i < tmp.length - 1; i++) {
                                    newResult += tmp[i] + "\n";
                                }
                            } else {
                                newResult += tmp[1] + "\n";
                            }
                            continue;
                        } else {
                            newResult += "#endif\n";
                            if (!tmp[0].startsWith("#if defined")) {
                                newResult += e;
                            } else {
                                newResult += printNodeWithoutHeadandEnd(e, 0);
                                conditionStack.push(tmp[0]);
                            }
                        }
                    }
                } else {
                    if (tmp[0].startsWith("#if defined")) {
                        if (!tmp[0].equals(blockCondition.replace("\n", ""))) {
                            conditionStack.push(tmp[0]);
                            newResult += printNodeWithoutHeadandEnd(e, 0);
                        } else {
                            newResult += printNodeWithoutHeadandEnd(e, 1);
                        }
                    } else {
                        newResult += e + "\n";
                    }
                }
            }
        }
        if (conditionStack.size() > 0) {
            conditionStack.pop();
            newResult += "\n#endif\n";
        }
        return newResult;
    }

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
        if (c.hasMatches()) {
            res += printBlock(c);
        } else if (c.isChoice()) {
            res += printChoice(c);
        }
        return res;
    }

    /**
     * This function print the  content in a block
     *
     * @param cppNoArt
     * @return
     */
    private String printBlock(CppNodeArtifact cppNoArt) {
        String res = "";
        String blockCondition = printMatchCondition(cppNoArt);
        String nodeLocalName = ((Element) cppNoArt.astnode).getLocalName();
        if (nodeLocalName.equals("function") || nodeLocalName.equals("while")) {
            //get function return type and name
            //while (while +condition)
            String returnType = (cppNoArt.astnode.getChild(0)).getValue();
            String funcName = (cppNoArt.astnode.getChild(2)).getValue();
            res += returnType + " " + funcName;
        } else if (nodeLocalName.equals("for")) {
            String ast_init = clearBlank((cppNoArt.astnode).getChild(1).getValue());
            String ast_condition = clearBlank((cppNoArt.astnode).getChild(3).getValue());
            String ast_incr = clearBlank((cppNoArt.astnode).getChild(5).getValue());
            res += "for(" + ast_init + ast_condition + ast_incr + ")\n";
        } else if (nodeLocalName.equals("class")) {
            res += "class " + cppNoArt.astnode.getChild(1).getValue();
        } else if (nodeLocalName.equals("if")) {
            if (((Element) cppNoArt.getParent().astnode).getLocalName().equals("else")) {
                res += "else ";
            }
            res += "if ";
        } else if (nodeLocalName.equals("switch")) {
            res += "switch";
        } else if (nodeLocalName.equals("case")) {
            res += "case ";
        } else if (nodeLocalName.equals("do")) {
            res += "do ";
        } else if (nodeLocalName.equals("extern")) {
            res += cppNoArt.astnode.getChild(0).getValue();
        }

        Iterator<CppNodeArtifact> it = cppNoArt.getChildren().iterator();
        while (it.hasNext()) {
            CppNodeArtifact c = it.next();
            String c_localName = ((Element) c.astnode).getLocalName();
            String c_value = c.astnode.getValue();
            String c_parent_localName = ((Element) c.getParent().astnode).getLocalName();
            res += "+-+-+-\n";

            if (!nodeLocalName.equals("for")) {
                if (entity.getTerminal().contains(c_localName)) {
                    if (c.hasMatches()) {
                        if (c_localName.equals("condition") && c_parent_localName.equals("do")) {
                            res += "while ";
                            res += c_value + ";";
                        } else {
                            res += printMatchCondition(c);
                            res += c_value + "\n";
                            res += "#endif\n";
                        }
                        if (c_value.contains("break")) {
                            res += "";
                        }
                    } else {
                        res += "\n" + presicePrettyprint(printChoice(c), blockCondition) + "\n";
                    }
                }
            }
            if (c_localName.equals("expr") && c_parent_localName.equals("case")) {
                res += ":";
            }
            if (entity.getBlockEntity().contains(c_localName)) {
                String blockString = "";
                if (c.isChoice()) {  // if c is a Choice Node, then the block will include 'else'
                    if (!c_localName.equals("else")) {
                        blockString += "{\n";
                    }
                    blockString += printChoice(c) + "\n";
                } else { // c has matched with other node
                    String child_localName = ((Element) c.astnode).getChildElements().get(0).getLocalName();
                    if (c_localName.equals("else")) {
                        if (!child_localName.equals("if")) {
                            blockString += "else ";
                            if (((Element) c.astnode).getChildElements("block", "http://www.sdml.info/srcML/src").size() > 0) {
                                blockString += "{\n";
                            }
                        } else {
                            blockString += "";
                        }
                    } else {
                        if (c_localName.equals("then") && !child_localName.equals("block")) {
                            blockString += "";
                        } else {
                            blockString += "{\n";
                        }
                    }
                    Iterator<CppNodeArtifact> it4Block = c.getChildren().iterator();
                    while (it4Block.hasNext()) {
                        blockString += "+-+-+-\n";
                        CppNodeArtifact c_block = it4Block.next();
                        String c_block_localName = ((Element) c_block.astnode).getLocalName();
                        if (entity.getClassBody().contains(c_block_localName)) {
                            String s = c_block.prettyPrint();
                            blockString += s;
                            continue;
                        }
                        if (entity.getNonTerminal().contains(c_block_localName)) {
                            String block = printNonTerminalNode(c_block);
                            blockString += block;
                            continue;
                        }
                        if (c_block.hasMatches()) {
                            blockString += printMatchCondition(c_block) + c_block.astnode.getValue() + "\n#endif\n";
                        } else {
                            String choice = printChoice(c_block);
                            blockString += choice;
                        }
                    }
                }
                String child_localName = ((Element) c.astnode).getChildElements().get(0).getLocalName();
                blockString += "+-+-+-\n";
                if (c.hasMatches()) {
                    if (c_localName.equals("else")) {
                        if (child_localName.equals("if")) {
                            blockString += "";
                        } else {
                            if (((Element) c.astnode).getChildElements("block", "http://www.sdml.info/srcML/src").size() > 0) {
                                blockString += "}\n";
                            }
                            blockString += "";
                        }
                    } else {
                        if (((Element) c.astnode).getLocalName().equals("then")
                                &&
                                !((Element) c.astnode).getChildElements().get(0).getLocalName().equals("block")) {
                            blockString += "";
                        } else {
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
                blockString += "+-+-+-\n";
                res += presicePrettyprint(blockString, blockCondition);
            } else if (entity.getNonTerminal().contains(c_localName)) {
                String s = printNonTerminalNode(c);
                s = presicePrettyprint(s, blockCondition);
                res += s;
            }
        }
        res = "+-+-+-\n" + blockCondition + presicePrettyprint(res, blockCondition) + "#endif\n";
        res += "+-+-+-\n";
        return res;
    }

    /**
     * This function print a single node with #ifdef and #endif
     *
     * @return node content
     */
    public String printSingleNode(CppNodeArtifact c) {
        String res = "";
        String tmpCondition = "";
        tmpCondition += "#if " + "defined (" + c.getRevision() + ")";
        if (c.getRevision().conditions.size() > 0) {
            tmpCondition += " && ";
        }
        tmpCondition += printCondition(c.getRevision());
        res += tmpCondition;
        res += "\n" + toString() + "\n";
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
            String str = c.variants.keySet().toArray()[i].toString();
            s += "#if defined (" + str + ")";
            String c_local = ((Element) c.astnode).getLocalName();
            if (c_local.equals("block")) {
                String condition = printCondition(c.variants.get(str).getRevision());
                if (condition.length() > 0) {
                    s += " && " + condition + "\n";
                }
                s += "\n" + c.variants.get(str).astnode.getValue().substring(1, c.variants.get(str).astnode.getValue().length() - 1) + "\n";

            }
            else {
                String condition = printCondition(c.variants.get(str).getRevision());
                if (var_size == 1 && condition.length() > 0) {
                    s += " && " + condition;
                }
                s += "\n" + c.variants.get(str);
            }
            s += printCondition(c.getRevision());
            s += "\n#endif\n";

            if (var_size > 1) {
                s += "+-+-+-\n";
            }
        }
        return s;
    }


    public String printNodeWithoutHeadandEnd(String s, int head) {
        String blockString = "";
        if (s.endsWith(":")) {
            for (int i = head; i < s.split("\n").length - 2; i++) {
                blockString += s.split("\n")[i] + "\n";
            }
            blockString += ":";
        } else {
            for (int i = head; i < s.split("\n").length - 1; i++) {
                blockString += s.split("\n")[i] + "\n";
            }
        }
        return blockString;
    }

    /**
     * This function print the match node
     *
     * @param c
     * @return
     */
    public String printMatchNode(CppNodeArtifact c) {
        String res = "";
        res += printMatchCondition(c);
        res += c.toString() + "\n";
        res += "#endif\n";
        return res;

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
            Thread.sleep(50);                 //1000 milliseconds is one second.
        } catch (InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
    }
}
