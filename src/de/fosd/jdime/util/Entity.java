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


    Set<String> classBody = null;

    public Entity() {
        nonTerminal = new HashSet<>();
        nonTerminal.add("function");
        nonTerminal.add("constructor");
        nonTerminal.add("while");
        nonTerminal.add("for");
        nonTerminal.add("class");
        nonTerminal.add("private");
        nonTerminal.add("protected");
        nonTerminal.add("public");
        nonTerminal.add("if");
//        nonTerminal.add("then");
//        nonTerminal.add("else");
        nonTerminal.add("switch");
        nonTerminal.add("case");
//        nonTerminal.add("block");
        nonTerminal.add("do");

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
//        terminal.add("do");
        terminal.add("function_decl");
        terminal.add("constructor_decl");
        terminal.add("destructor_decl");
        terminal.add("template");
        terminal.add("super");
        terminal.add("expr");
        terminal.add("break");
        terminal.add("continue");
        terminal.add("comment");

/* head entity of
 function : (return type+function name)
 for loop : init+ condition+incr


 */
        headEntity = new HashSet<>();
        headEntity.add("name");
        headEntity.add("type");


        matchedEntity = new HashSet<>();
        matchedEntity.add("unit");
        matchedEntity.add("block");
        matchedEntity.add("private");
        matchedEntity.add("public");
        matchedEntity.add("protected");
        matchedEntity.add("then");
        matchedEntity.add("else");
        matchedEntity.add("switch");
        matchedEntity.add("case");

        blockEntity = new HashSet<>();
        blockEntity.add("block");
        blockEntity.add("then");
        blockEntity.add("else");
        blockEntity.add("do");

        classBody = new HashSet<>();
        classBody.add("private");
        classBody.add("public");
        classBody.add("protected");
//        classBody.add("then");

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

    public Set<String> getClassBody() {
        return classBody;
    }
}
