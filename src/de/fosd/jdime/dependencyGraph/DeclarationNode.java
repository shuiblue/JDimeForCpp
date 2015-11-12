package de.fosd.jdime.dependencyGraph;

import java.util.HashSet;

/**
 * Created by shuruiz on 11/5/15.
 */
public class DeclarationNode {
    String fileName;
    int lineNumber;
    String type;
    String name;
    String decl_tag;
    HashSet<DependenceNode> dependencies;

    DeclarationNode(String name, String type, int lineNumber, String decl_tag) {
        this.name = name;
        this.type = type;
        this.lineNumber = lineNumber;
        this.decl_tag = decl_tag;
        dependencies = new HashSet<>();
    }

    public int getLineNumber() {
        return lineNumber;
    }

    public String getType() {
        return type;
    }

    public String getName() {
        return name;
    }

    public String getDecl_tag() {
        return decl_tag;
    }

    public HashSet<DependenceNode> getDependencies() {
        return dependencies;
    }
}
