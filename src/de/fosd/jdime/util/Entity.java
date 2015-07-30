package de.fosd.jdime.util;

import java.util.HashSet;
import java.util.Set;

/**
 * Created by shuruiz on 7/29/15.
 */
public class Entity {
    Set<String> nonTerminal = null;
    Set<String> terminal = null;
    Set<String> blockEntity = null;


    Set<String> matchedEntity = null;


    public Entity() {
        nonTerminal = new HashSet<>();
        nonTerminal.add("function");
        nonTerminal.add("constructor");
        nonTerminal.add("while");

        terminal = new HashSet<>();
        terminal.add("name");
        terminal.add("parameter_list");
        terminal.add("condition");
        terminal.add("type");
        terminal.add("define");
        terminal.add("for");
        terminal.add("return");
        terminal.add("decl_stmt");
        terminal.add("expr_stmt");

        blockEntity = new HashSet<>();
        blockEntity.add("name");
        blockEntity.add("type");
        blockEntity.add("function_decl");

        matchedEntity = new HashSet<>();
        matchedEntity.add("unit");
        matchedEntity.add("block");
        matchedEntity.add("while");

    }

    public Set<String> getNonTerminal() {
        return nonTerminal;
    }

    public Set<String> getTerminal() {

        return terminal;
    }

    public Set<String> getBlockEntity() {

        return blockEntity;
    }

    public Set<String> getMatchedEntity() {
        return matchedEntity;
    }

}
