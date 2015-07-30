package de.fosd.jdime.util;

import java.util.HashSet;
import java.util.Set;

/**
 * Created by shuruiz on 7/29/15.
 */
public class Entity {
    Set<String> nonTerminal = null;
    Set<String> terminal = null;

    public Set<String> getFunctionHead() {
        return functionHead;
    }

    Set<String> functionHead = null;

    public Entity() {
        nonTerminal = new HashSet<>();
        nonTerminal.add("function");
        nonTerminal.add("constructor");

        terminal = new HashSet<>();
        terminal.add("name");
        terminal.add("parameter_list");
        terminal.add("type");
        terminal.add("define");
        terminal.add("for");
        terminal.add("return");
        terminal.add("decl_stmt");
        terminal.add("expr_stmt");

        functionHead = new HashSet<>();
        functionHead.add("name");
        functionHead.add("type");
        functionHead.add("function_decl");

    }

    public Set<String> getNonTerminal() {
        return nonTerminal;
    }

    public Set<String> getTerminal() {
        return terminal;
    }
}
