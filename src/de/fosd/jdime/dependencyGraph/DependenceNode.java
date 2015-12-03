package de.fosd.jdime.dependencyGraph;

import java.util.HashSet;

/**
 * Created by shuruiz on 11/5/15.
 */
public class DependenceNode {


    String lineNumber;
    String fileName;
    String name;
    String type;
    String tag;
    DeclarationNode declaration;


    /* when there is no function_decl, add dependency between call->function
        //!Only one of declaration, dependList, dependOn could be not null;!
    */
    //add 'call' not to dependList
    HashSet<DependenceNode> dependList;
    //add 'function' to dependOn
    DependenceNode dependOn;


    DependenceNode(String name, String type, String tag, String lineNumber, String fileName) {

        this.type = type;
        this.name = name;
        this.fileName = fileName;
        this.tag = tag;
        this.lineNumber = lineNumber;
        dependList = new HashSet<>();

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

    public HashSet<DependenceNode> getDependList() {
        return dependList;
    }

    public DependenceNode getDependOn() {
        return dependOn;
    }

    public void setDependOn(DependenceNode dependOn) {
        this.dependOn = dependOn;
    }

}
