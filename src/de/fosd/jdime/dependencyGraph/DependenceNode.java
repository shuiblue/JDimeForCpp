package de.fosd.jdime.dependencyGraph;


/**
 * Created by shuruiz on 11/5/15.
 */
public class DependenceNode {
    int lineNumber;
//    String type;


    String name;
    String tag;
    DeclarationNode declaration;

    DependenceNode(String name,  String tag,int lineNumber ) {
        this.name = name;
//        this.type = type;
        this.tag = tag;
        this.lineNumber = lineNumber;
    }

//    public String getType() {
//        return type;
////    }

    public String getName() {
        return name;
    }

    public String getTag() {
        return tag;
    }

    public DeclarationNode getDeclaration() {
        return declaration;
    }

    public int getLineNumber() {
        return lineNumber;
    }
}
