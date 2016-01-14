package de.fosd.jdime.testJDimeCpp;

import de.fosd.jdime.dependencyGraph.DependencyGraph;
import org.junit.Ignore;
import org.junit.Test;

import java.util.*;

import static org.junit.Assert.assertTrue;

/**
 * Created by shuruiz on 11/5/15.
 */
public class testDependencyGraphForEmail {
    HashSet<String> expect_edges;
    DependencyGraph dependencyGraph = new DependencyGraph();
    public boolean compareTwoGraphs(HashSet<String> result) {
        boolean compare = true;
        for (String edge : expect_edges) {
            compare = compare && result.contains(edge);
            if (result.contains(edge) == false) {
                System.out.print(edge + "\n");
            }
        }
        return compare;
    }

    public void expect_10() {
        expect_edges.add("13-Client.c->8-Client.c");//mail function block->param
        expect_edges.add("14-Client.c->8-Client.c");
        expect_edges.add("16-Client.c->8-Client.c");

        //struct children
        expect_edges.add("12-Client.h->10-Client.h");
        expect_edges.add("13-Client.h->10-Client.h");

        //outgoingBuffer -> struct client. outgoingbuffer
        expect_edges.add("13-Client.c->13-Client.h");
        expect_edges.add("14-Client.c->13-Client.h");
        expect_edges.add("16-Client.c->13-Client.h");

        //block->function
        expect_edges.add("13-Client.c->8-Client.c");
        expect_edges.add("14-Client.c->8-Client.c");
        expect_edges.add("16-Client.c->8-Client.c");

        //block->if condition
        expect_edges.add("14-Client.c->13-Client.c");
        expect_edges.add("16-Client.c->13-Client.c");



    }

//        @Ignore
    @Test
    public void test10() {
        expect_edges = new HashSet<>();
        expect_10();

        String fileName = "EmailSystem/test_10";
        HashSet<String> result = dependencyGraph.createDependencyGraph(fileName);
        assertTrue(compareTwoGraphs(result));
    }

    public void expect_11() {
        expect_edges.add("21-Client.c->16-Client.h");//outgoing func->func_decl
        expect_edges.add("23-Client.c->21-Client.c"); //outgoing block -> outgoing function
        expect_edges.add("24-Client.c->21-Client.c");//outgoing block -> outgoing function
        expect_edges.add("24-Client.c->8-Client.c");//mail call->function

        //struct name
        expect_edges.add("23-Client.c->12-Client.h");

    }

    public void expect_children_11(){
        //block->function
        expect_edges.add("23-Client.c->21-Client.c");
        expect_edges.add("24-Client.c->21-Client.c");

    }
//        @Ignore
    @Test
    public void test11() {
        expect_edges = new HashSet<>();
        String fileName = "EmailSystem/test_11";
        expect_10();
        expect_11();
        expect_children_11();
        HashSet<String> result = dependencyGraph.createDependencyGraph(fileName);
        assertTrue(compareTwoGraphs(result));

    }

    public void expect_12() {
        expect_edges.add("38-Client.c->18-Client.h");//incoming func->func_decl
        expect_edges.add("40-Client.c->29-Client.c");//deliver call->function
        expect_edges.add("40-Client.c->38-Client.c");//incoming block param->function param
    }

    public void expect_children_12(){
        //block->function
        expect_edges.add("40-Client.c->38-Client.c");
    }

//        @Ignore
    @Test
    public void test12() {
        String fileName = "EmailSystem/test_12";
        expect_edges = new HashSet<>();
        expect_10();
        expect_11();
        expect_children_11();
        expect_12();
        expect_children_12();

        HashSet<String> result = dependencyGraph.createDependencyGraph(fileName);
        assertTrue(compareTwoGraphs(result));
    }

    public void expect_13() {
        expect_edges.add("7-Email.c->10-Email.h"); //cloneEmail function->decl
        expect_edges.add("24-Email.c->12-Email.h");//printMail function->decl
        expect_edges.add("35-Email.c->14-Email.h");//isReadable  function->decl
        expect_edges.add("20-Email.c->9-Email.c");//return clone ->local var def


        //id  var->struct var
        expect_edges.add("10-Email.c->3-Email.h");
        expect_edges.add("11-Email.c->3-Email.h");
        //from  var->struct var
        expect_edges.add("23-Client.c->4-Email.h");
        expect_edges.add("12-Email.c->4-Email.h");
        expect_edges.add("13-Email.c->4-Email.h");
        //to  var->struct var
        expect_edges.add("14-Email.c->5-Email.h");
        expect_edges.add("15-Email.c->5-Email.h");
        //subject  var->struct var
        expect_edges.add("16-Email.c->6-Email.h");
        expect_edges.add("17-Email.c->6-Email.h");
        //body  var->struct var
        expect_edges.add("18-Email.c->7-Email.h");
        expect_edges.add("19-Email.c->7-Email.h");


    }
    public void expect_children_13(){
        //clone email child->function
        expect_edges.add("9-Email.c->7-Email.c");
        expect_edges.add("10-Email.c->7-Email.c");
        expect_edges.add("11-Email.c->7-Email.c");
        expect_edges.add("20-Email.c->7-Email.c");

        //if child=>parent
        expect_edges.add("11-Email.c->10-Email.c");
        expect_edges.add("13-Email.c->12-Email.c");
        expect_edges.add("19-Email.c->18-Email.c");


        //printmail child->function
        expect_edges.add("26-Email.c->24-Email.c");
        expect_edges.add("27-Email.c->24-Email.c");
        expect_edges.add("31-Email.c->24-Email.c");
        expect_edges.add("37-Email.c->35-Email.c");
    }

//        @Ignore
    @Test
    public void test13() {
        String fileName = "EmailSystem/test_13";
        expect_edges = new HashSet<>();
        expect_10();
        expect_11();
        expect_12();
        expect_13();
        expect_children_11();
        expect_children_12();
        expect_children_13();

        HashSet<String> result = dependencyGraph.createDependencyGraph(fileName);
        assertTrue(compareTwoGraphs(result));
    }

    public void expect_14() {
        expect_edges.add("14-Client.h->10-Client.h");//Node addressBook->struct client
        expect_edges.add("19-Client.h->17-Client.h");//struct addressBookEntry
        expect_edges.add("20-Client.h->17-Client.h");

        expect_edges.add("24-Client.c->21-Client.c");//outgoing block -> outgoing function
        expect_edges.add("27-Client.c->21-Client.c");//outgoing block -> outgoing function
        expect_edges.add("28-Client.c->21-Client.c");//outgoing block -> outgoing function
        expect_edges.add("44-Client.c->42-Client.c");//incoming block param->function param

        expect_edges.add("28-Client.c->8-Client.c"); //mail call->function
        expect_edges.add("44-Client.c->33-Client.c");//deliver call->function
        expect_edges.add("77-Client.c->21-Client.c");//outgoing call->function

        expect_edges.add("67-Client.c->66-Client.c");// NODE *address use->def
        expect_edges.add("72-Client.c->66-Client.c");// NODE *address use->def
        expect_edges.add("75-Client.c->74-Client.c");// struct email *newmsg use->def

        expect_edges.add("21-Client.c->23-Client.h"); //outgoing func->func_decl
        expect_edges.add("42-Client.c->25-Client.h");//incoming func->func_decl
        expect_edges.add("57-Client.c->28-Client.h");//resolveAlias func->func_decl

        expect_edges.add("7-Email.c->10-Email.h"); //cloneEmail function->decl
        expect_edges.add("24-Email.c->12-Email.h");//printMail function->decl
        expect_edges.add("35-Email.c->14-Email.h");//isReadable  function->decl
        expect_edges.add("20-Email.c->9-Email.c");//return clone ->local var def


        //id  var->struct var
        expect_edges.add("10-Email.c->3-Email.h");
        expect_edges.add("11-Email.c->3-Email.h");
        //from  var->struct var
        expect_edges.add("27-Client.c->4-Email.h");
        expect_edges.add("12-Email.c->4-Email.h");
        expect_edges.add("13-Email.c->4-Email.h");
        //to  var->struct var
        expect_edges.add("14-Email.c->5-Email.h");
        expect_edges.add("15-Email.c->5-Email.h");
        //subject  var->struct var
        expect_edges.add("16-Email.c->6-Email.h");
        expect_edges.add("17-Email.c->6-Email.h");
        //body  var->struct var
        expect_edges.add("18-Email.c->7-Email.h");
        expect_edges.add("19-Email.c->7-Email.h");

        //struct name
        expect_edges.add("27-Client.c->12-Client.h");
    }

    //addressBook feature
//    @Ignore
    @Test
    public void test14() {
        String fileName = "EmailSystem/test_14";
        expect_edges = new HashSet<>();
        expect_10();
        expect_14();

        HashSet<String> result = dependencyGraph.createDependencyGraph(fileName);
        assertTrue(compareTwoGraphs(result));
    }

    public void expect_15() {
        expect_edges.add("14-Client.h->10-Client.h");//Node addressBook->struct client
        expect_edges.add("15-Client.h->10-Client.h");//Node autoResponse->struct client
        expect_edges.add("21-Client.h->18-Client.h");//struct addressBookEntry
        expect_edges.add("20-Client.h->18-Client.h");
        expect_edges.add("44-Client.c->42-Client.c");//incoming block param->function param
        expect_edges.add("45-Client.c->42-Client.c");//incoming block param->function param
        expect_edges.add("52-Client.c->50-Client.c");//listdata block param->function param

        expect_edges.add("28-Client.c->8-Client.c"); //mail call->function
        expect_edges.add("45-Client.c->33-Client.c");//deliver call->function
        expect_edges.add("44-Client.c->85-Client.c");//autoRespond call->function
        expect_edges.add("78-Client.c->21-Client.c");//outgoing call->function
        expect_edges.add("97-Client.c->21-Client.c");//outgoing call->function
        expect_edges.add("68-Client.c->67-Client.c");// NODE *address use->def
        expect_edges.add("73-Client.c->67-Client.c");// NODE *address use->def
        expect_edges.add("76-Client.c->75-Client.c");// struct email *newmsg use->def

        expect_edges.add("21-Client.c->24-Client.h"); //outgoing func->func_decl
        expect_edges.add("78-Client.c->24-Client.h");//outgoing call->func_DECL
        expect_edges.add("97-Client.c->24-Client.h");//outgoing call->func_DECL
        expect_edges.add("42-Client.c->26-Client.h");//incoming func->func_decl
        expect_edges.add("58-Client.c->29-Client.h");//resolveAlias func->func_decl

        expect_edges.add("85-Client.c->31-Client.h");//autoRespond func->func_decl
        expect_edges.add("44-Client.c->85-Client.c");//autoRespond CALL->function
        expect_edges.add("44-Client.c->31-Client.h");//autoRespond CALL->function

        expect_edges.add("7-Email.c->10-Email.h"); //cloneEmail function->decl
        expect_edges.add("24-Email.c->12-Email.h");//printMail function->decl
        expect_edges.add("35-Email.c->14-Email.h");//isReadable  function->decl
        expect_edges.add("20-Email.c->9-Email.c");//return clone ->local var def

        //id  var->struct var
        expect_edges.add("10-Email.c->3-Email.h");
        expect_edges.add("11-Email.c->3-Email.h");
        //from  var->struct var
        expect_edges.add("27-Client.c->4-Email.h");
        expect_edges.add("12-Email.c->4-Email.h");
        expect_edges.add("13-Email.c->4-Email.h");
        //to  var->struct var
        expect_edges.add("14-Email.c->5-Email.h");
        expect_edges.add("15-Email.c->5-Email.h");
        //subject  var->struct var
        expect_edges.add("16-Email.c->6-Email.h");
        expect_edges.add("17-Email.c->6-Email.h");
        //body  var->struct var
        expect_edges.add("18-Email.c->7-Email.h");
        expect_edges.add("19-Email.c->7-Email.h");

        //struct name
        expect_edges.add("27-Client.c->12-Client.h");
    }

//autoResponder feature
//    @Ignore
    @Test
    public void test15() {
        String fileName = "EmailSystem/test_15";
        expect_edges = new HashSet<>();
        expect_10();
        expect_15();

        HashSet<String> result = dependencyGraph.createDependencyGraph(fileName);
        assertTrue(compareTwoGraphs(result));
    }

    public void expect_16() {
        //mail function block->param
        expect_edges.add("21-Client.c->8-Client.c");
        expect_edges.add("22-Client.c->8-Client.c");
        expect_edges.add("24-Client.c->8-Client.c");
        //struct client child->parent
        expect_edges.add("12-Client.h->10-Client.h");
        expect_edges.add("13-Client.h->10-Client.h");
        expect_edges.add("14-Client.h->10-Client.h");
        expect_edges.add("15-Client.h->10-Client.h");

        //struct addressBookEntry
        expect_edges.add("20-Client.h->18-Client.h");
        expect_edges.add("21-Client.h->18-Client.h");

        expect_edges.add("29-Client.c->24-Client.h");//outgoing func->func_decl
        expect_edges.add("39-Client.c->29-Client.c"); //outgoing block -> outgoing function
        expect_edges.add("40-Client.c->29-Client.c");//outgoing block -> outgoing function
        expect_edges.add("40-Client.c->8-Client.c");//mail call->function

        expect_edges.add("65-Client.c->106-Client.c");//autoRespond call->function
        expect_edges.add("99-Client.c->29-Client.c");//outgoing call->function
        expect_edges.add("118-Client.c->29-Client.c");//outgoing call->function

        expect_edges.add("54-Client.c->26-Client.h");//incoming func->func_decl
        expect_edges.add("40-Client.c->29-Client.c");//deliver call->function
        expect_edges.add("66-Client.c->45-Client.c");//incoming block param->function param

        expect_edges.add("7-Email.c->12-Email.h"); //cloneEmail function->decl
        expect_edges.add("29-Email.c->14-Email.h");//printMail function->decl
        expect_edges.add("44-Email.c->16-Email.h");//isReadable  function->decl
        expect_edges.add("25-Email.c->9-Email.c");//return clone ->local var def

        //outgoing block -> outgoing function
        expect_edges.add("32-Client.c->29-Client.c");
        expect_edges.add("36-Client.c->29-Client.c");//outgoing block -> outgoing function
        expect_edges.add("39-Client.c->29-Client.c");//outgoing block -> outgoing function
        expect_edges.add("40-Client.c->29-Client.c");//outgoing block -> outgoing function
        //incoming block param->function param
        expect_edges.add("58-Client.c->54-Client.c");//incoming block param->function param
        expect_edges.add("62-Client.c->54-Client.c");
        expect_edges.add("65-Client.c->54-Client.c");
        expect_edges.add("66-Client.c->54-Client.c");

        expect_edges.add("99-Client.c->24-Client.h");//outgoing call->func_DECL
        expect_edges.add("118-Client.c->24-Client.h");//outgoing call->func_DECL
        expect_edges.add("36-Client.c->79-Client.c");//resolveAlias call->function
        expect_edges.add("79-Client.c->29-Client.h");//resolveAlias func->func_decl

        expect_edges.add("65-Client.c->31-Client.h");//autoRespond call->func_decl
        expect_edges.add("65-Client.c->106-Client.c");//autoRespond CALL->function
        expect_edges.add("106-Client.c->31-Client.h");//autoRespond func->func_decl

        expect_edges.add("89-Client.c->88-Client.c");// NODE *address use->def
        expect_edges.add("94-Client.c->88-Client.c");// NODE *address use->def
        expect_edges.add("97-Client.c->96-Client.c");// struct email *newmsg use->def

        //encrypt
        expect_edges.add("32-Client.c->124-Client.c");
        expect_edges.add("124-Client.c->35-Client.h");
        expect_edges.add("128-Client.c->126-Client.c");
        expect_edges.add("47-Email.c->56-Email.c");
        expect_edges.add("56-Email.c->18-Email.h");

        //decrypt
        expect_edges.add("62-Client.c->141-Client.c");
        expect_edges.add("141-Client.c->40-Client.h");
        expect_edges.add("144-Client.c->141-Client.c");
        expect_edges.add("148-Client.c->141-Client.c");
    }

    //Encrypt feature
//   @Ignore
    @Test
    public void test16() {
        String fileName = "EmailSystem/test_16";
        expect_edges = new HashSet<>();
        expect_16();

        //control flow "if()"
        expect_edges.add("91-Client.c->89-Client.c");
        expect_edges.add("92-Client.c->91-Client.c");
        expect_edges.add("130-Client.c->128-Client.c");
        expect_edges.add("130-Client.c->128-Client.c");
        expect_edges.add("133-Client.c->130-Client.c");


        //control flow "while"
        expect_edges.add("96-Client.c->94-Client.c");
        expect_edges.add("97-Client.c->96-Client.c");
        expect_edges.add("98-Client.c->97-Client.c");


        HashSet<String> result = dependencyGraph.createDependencyGraph(fileName);
        assertTrue(compareTwoGraphs(result));
    }

    public void expect_17() {
        expect_edges.add("5-test12.c->4-test12.c");
        expect_edges.add("9-test12.c->1-test12.c");
        expect_edges.add("10-test12.c->2-test12.c");
        expect_edges.add("11-test12.c->1-test3.c");
    }

    //test local and global var
//   @Ignore
    @Test
    public void test17() {
        String fileName = "EmailSystem/test_17";
        expect_edges = new HashSet<>();
        expect_17();
        HashSet<String> result = dependencyGraph.createDependencyGraph(fileName);
        assertTrue(compareTwoGraphs(result));
    }
}