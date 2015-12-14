package de.fosd.jdime.dependencyGraph;

import nu.xom.Node;

/**
 * Created by shuruiz on 12/10/15.
 */
public interface Visitor {
    public void visit(Node node);
}
