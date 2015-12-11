package de.fosd.jdime.dependencyGraph;

import java.util.Hashtable;
import java.util.List;

/**
 * Created by shuruiz on 12/10/15.
 */
public class CppNode {
    String type;
    String name;
    String kind;
    String fileName;
    String lineNumber;


    CppNode(String name, String type, String lineNumber, String kind, String fileName) {

        this.name = name;
        this.type = type;
        this.lineNumber = lineNumber;
        this.kind = kind;
        this.fileName = fileName;
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


    public String getFileName() {
        return fileName;
    }

    public String getKind() {
        return kind;
    }

    //key: symbol  value : filename+#line
    Hashtable<Symbol, String> symbolTable;

    List<CppNode> children;
    
    public void accept(Visitor visitor) {
        visitor.visit(this);
    }
}
