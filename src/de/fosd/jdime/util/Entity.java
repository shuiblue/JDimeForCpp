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
    Set<String> headEntity = null;


    public Entity() {
        nonTerminal = new HashSet<>();
        nonTerminal.add("function");
        nonTerminal.add("constructor");
        nonTerminal.add("while");
        nonTerminal.add("for");

        terminal = new HashSet<>();
        terminal.add("name");
        terminal.add("parameter_list");
        terminal.add("type");
        terminal.add("define");
        terminal.add("return");
        terminal.add("decl_stmt");
        terminal.add("expr_stmt");
        terminal.add("init");
        terminal.add("incr");
        terminal.add("condition");
        terminal.add("do");

/* head entity of
 function : (return type+function name)
 for loop : init+ condition+incr


 */
        headEntity = new HashSet<>();
        headEntity.add("name");
        headEntity.add("type");
        headEntity.add("function_decl");

        matchedEntity = new HashSet<>();
        matchedEntity.add("unit");
        matchedEntity.add("block");

        blockEntity = new HashSet<>();
        blockEntity.add("block");

    }

    public Set<String> getNonTerminal() {
        return nonTerminal;
    }

    public Set<String> getTerminal() {

        return terminal;
    }

    public Set<String> getHeadEntity() {

        return headEntity;
    }

    public Set<String> getMatchedEntity() {
        return matchedEntity;
    }

    public Set<String> getBlockEntity() {
        return blockEntity;
    }
}
