package de.fosd.jdime.dependencyGraph;


/**
 * Created by shuruiz on 11/5/15.
 */
public class DependenceNode {
    int lineNumber;
    String type;


    String name;
    String localName;
    DeclarationNode declaration;

    DependenceNode(int lineNumber, String name, String type, String localName, DeclarationNode declaration) {
        this.name = name;
        this.type = type;
        this.localName = localName;
        this.lineNumber = lineNumber;
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

    public DeclarationNode getDeclaration() {
        return declaration;
    }

    public int getLineNumber() {
        return lineNumber;
    }
}
