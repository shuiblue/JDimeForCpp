package de.fosd.jdime.dependencyGraph;

/**
 * Created by shuruiz on 11/5/15.
 */
public class DependenceNode {
    String lineNumber;
    String fileName;
    String name;
    String tag;
    DeclarationNode declaration;

    DependenceNode(String name, String tag, String lineNumber, String fileName) {
        this.name = name;
        this.fileName = fileName;
        this.tag = tag;
        this.lineNumber = lineNumber;
    }


    public String getName() {
        return name;
    }

    public String getTag() {
        return tag;
    }

    public DeclarationNode getDeclaration() {
        return declaration;
    }

    public void setDeclaration(DeclarationNode declaration) {
        this.declaration = declaration;
    }

    public String getLineNumber() {
        return lineNumber;
    }

    public String getFileName() {
        return fileName;
    }

}
