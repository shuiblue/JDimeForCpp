package de.fosd.jdime.dependencyGraph;

/**
 * Created by shuruiz on 11/5/15.
 */
public class Edge {
    private final String name;

    public Edge(String name)
    {
        this.name = name;
    }

    @Override
    public String toString()
    {
        return name;
    }
}
