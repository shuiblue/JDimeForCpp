package de.fosd.jdime.dependencyGraph;

/**
 * Created by shuruiz on 11/5/15.
 */
public class Edge {
    private final String name;
    private String fromVertex;
    private String toVertex;

    public Edge(String name, String fromVertex, String toVertex) {
        this.name = name;
        this.fromVertex = fromVertex;
        this.toVertex = toVertex;
    }


    public String getFromVertex() {
        return fromVertex;
    }

    public String getName() {
        return name;
    }

    public String getToVertex() {
        return toVertex;
    }

    @Override
    public String toString() {
        return name;
    }

    public boolean compare(Edge e1,Edge e2){
        if(e1.toVertex.equals(e2.toVertex)
                &&e1.fromVertex.equals(e2.fromVertex)
                &&e1.getName().equals(e2.getName())){
            return  true;
        }
        else{
            return false;
        }
    }
}
