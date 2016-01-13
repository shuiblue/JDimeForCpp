package de.fosd.jdime.dependencyGraph;

import java.util.HashMap;
import java.util.HashSet;

/**
 * Created by shuruiz on 12/10/15.
 */
public class Symbol {
    String type;
    String name;
    String tag;
    String fileName;
    String lineNumber;
    int scope;

    Symbol(String name, String type, String lineNumber, String tag, String fileName, int scope) {
        this.name = name;
        this.type = type;
        this.lineNumber = lineNumber;
        this.tag = tag;
        this.fileName = fileName;
        this.scope = scope;

    }



    public String getLineNumber() {
        return lineNumber;
    }

    public int getScope() {
        return scope;
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

    public String getTag() {
        return tag;
    }


}
