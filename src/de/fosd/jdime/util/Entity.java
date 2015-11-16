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


    Set<String> oneLayerEntity = null;
    Set<String> stmtEntity = null;

    Set<String> declarationEntity = null;
    Set<String> dependencyEntity = null;

    Set<String> funcionDeclarationEntity = null;
    Set<String> funcionEntity = null;
    Set<String> funcionBodyEntity = null;

    Set<String> consDestructorEntity = null;

    public Set<String> getConsDestructorEntity() {
        return consDestructorEntity;
    }

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
        nonTerminal.add("switch");
        nonTerminal.add("case");
        nonTerminal.add("do");
        nonTerminal.add("extern");
        nonTerminal.add("block");
        nonTerminal.add("macro");

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
        terminal.add("function_decl");
        terminal.add("constructor_decl");
        terminal.add("destructor_decl");
        terminal.add("template");
        terminal.add("super");
        terminal.add("expr");
        terminal.add("break");
        terminal.add("continue");
        terminal.add("comment");
        terminal.add("return");
        terminal.add("define");
        terminal.add("undef");
        terminal.add("error");
        terminal.add("include");
        terminal.add("member_list");
        terminal.add("argument_list");
        terminal.add("empty_stmt");

        terminal.add("argument_list");
        terminal.add("empty_stmt");


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

        oneLayerEntity = new HashSet<>();

        oneLayerEntity.add("function");
        oneLayerEntity.add("function_decl");
        oneLayerEntity.add("class_decl");
        oneLayerEntity.add("constructor_decl");
        oneLayerEntity.add("destructor");
        oneLayerEntity.add("constructor");
        oneLayerEntity.add("call");
        oneLayerEntity.add("expr");


        stmtEntity = new HashSet<>();
        stmtEntity.add("decl");

        declarationEntity = new HashSet<>();
        declarationEntity.add("function_decl");
        declarationEntity.add("class_decl");
        declarationEntity.add("constructor_decl");
        declarationEntity.add("decl");

        dependencyEntity = new HashSet<>();
        dependencyEntity.add("call");
        dependencyEntity.add("expr");
        dependencyEntity.add("function");
        dependencyEntity.add("constructor");
        dependencyEntity.add("destructor");

        funcionEntity = new HashSet<>();
        funcionEntity.add("function_decl");
        funcionEntity.add("function");
        funcionEntity.add("constructor");
        funcionEntity.add("constructor_decl");
        funcionEntity.add("destructor");
        funcionEntity.add("destructor_decl");

        funcionBodyEntity = new HashSet<>();
        funcionBodyEntity.add("function");
        funcionBodyEntity.add("constructor");
        funcionBodyEntity.add("destructor");

        funcionDeclarationEntity = new HashSet<>();
        funcionDeclarationEntity.add("function_decl");
        funcionDeclarationEntity.add("constructor_decl");
        funcionDeclarationEntity.add("destructor_decl");

        consDestructorEntity = new HashSet<>();
        consDestructorEntity.add("constructor");
        consDestructorEntity.add("destructor");


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

    public Set<String> getOneLayerEntity() {
        return oneLayerEntity;
    }

    public Set<String> getStmtEntity() {
        return stmtEntity;
    }

    public Set<String> getDeclarationEntity() {
        return declarationEntity;
    }

    public Set<String> getDependencyEntity() {
        return dependencyEntity;
    }

    public Set<String> getFuncionDeclarationEntity() {
        return funcionDeclarationEntity;
    }
    public Set<String> getFuncionBodyEntity() {
        return funcionBodyEntity;
    }

    public Set<String> getFuncionEntity() {
        return funcionEntity;
    }

}
