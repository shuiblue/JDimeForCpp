package de.fosd.jdime.dependencyGraph;

import java.util.HashSet;

/**
 * Created by shuruiz on 11/5/15.
 */
public class DeclarationNode {


    String fileName;
    String lineNumber;
    String type;
    String name;
    String decl_tag;
    HashSet<DependenceNode> dependencies;

    DeclarationNode(String name, String type, String lineNumber, String decl_tag,String fileName) {
        this.name = name;
        this.type = type;
        this.lineNumber = lineNumber;
        this.decl_tag = decl_tag;
        this.fileName = fileName;
        dependencies = new HashSet<>();
    }

    public String getLineNumber() {
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
    public String getFileName() {
        return fileName;
    }
    public HashSet<DependenceNode> getDependencies() {
        return dependencies;
    }
}
