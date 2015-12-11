package de.fosd.jdime.dependencyGraph;

/**
 * Created by shuruiz on 12/10/15.
 */
public interface Visitable {
    public void accept(Visitor visitor);
}
