package de.fosd.jdime.dependencyGraph;

import java.util.HashSet;

/**
 * Created by shuruiz on 11/5/15.
 */
public class DeclarationNode {

    int lineNumber;
    String type;
    String name;
    String localName;
    HashSet<DependenceNode> dependencies;

    DeclarationNode(String name, String type,String localName,int lineNumber) {
        this.name = name;
        this.type = type;
        this.localName=localName;
        this.lineNumber=lineNumber;
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

    public String getLocalName() {
        return localName;
    }

    public HashSet<DependenceNode> getDependencies() {
        return dependencies;
    }
}
