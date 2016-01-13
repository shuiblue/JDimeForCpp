package de.fosd.jdime.dependencyGraph;

/**
 * Created by shuruiz on 11/5/15.
 */
public class Edge {


    private final String label;
    private String fromVertex;
    private String toVertex;



    public String getLabel() {
        return label;
    }
    public Edge(String label, String fromVertex, String toVertex) {
        this.label = label;
        this.fromVertex = fromVertex;
        this.toVertex = toVertex;
    }


    public String getFromVertex() {
        return fromVertex;
    }



    public String getToVertex() {
        return toVertex;
    }



    public boolean compare(Edge e1,Edge e2){
        if(e1.toVertex.equals(e2.toVertex)
                &&e1.fromVertex.equals(e2.fromVertex)
                &&e1.getLabel().equals(e2.getLabel())){
            return  true;
        }
        else{
            return false;
        }
    }
}
