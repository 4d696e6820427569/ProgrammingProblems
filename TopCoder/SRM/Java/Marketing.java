package topcodersrm;

import java.util.ArrayList;
import java.util.Stack;

/**
 * TCCC '03 Round 2 DIV1 Level 2 - Marketing Type: Graph theory. DFS.
 *
 * @author Minh
 */
class Vertex {

    int name;
    ArrayList<Vertex> neighbors;

    Vertex(int name) {
        this.name = name;
        neighbors = new ArrayList<>();
    }
}

class Graph {

    Vertex[] vertices;

    Graph(int size) {
        vertices = new Vertex[size];
    }
}

public class Marketing {

    public static void main(String[] args) {
        String test = "";
        String[] splittedTest = test.split("");
        System.out.print("Testing");
        System.out.println("The size of the string array is: " + splittedTest.length);
        printStringArr(splittedTest);
        System.out.println("Finish testing.");

        // Testing null array.
        Graph g = new Graph(5);
        boolean isNull = (g.vertices[0] == null);

        System.out.println(isNull);

        // Test construct graph algorithm
        String[] testSArray = {"1","2","3","0","5","6","4"};
        System.out.println("Number of ways to market: " + howMany(testSArray));
    }

    public static long howMany(String[] compete) {
        int components = 0;
        int[] color = new int[compete.length];
        boolean[] visited = new boolean[compete.length];
        for (int i = 0; i < compete.length; i++)
            color[i] = 0;
        
        Graph g = constructGraph(compete);

        Stack<Vertex> s = new Stack<>();
        for (Vertex v : g.vertices) {
            if (!visited[v.name]) {
                visited[v.name] = true;
                components++;
                color[v.name] = 1;
                
                for (Vertex u : v.neighbors) {
                    if (color[u.name] == color[v.name])
                        return -1;
                    
                    if (!visited[u.name]) {
                        s.push(u);
                        color[u.name] = -color[v.name];
                    }
                }
                
                
                while(!s.empty()) {
                    Vertex c = s.pop();
                    visited[c.name] = true;
                    
                    for (Vertex u : c.neighbors) {
                        if (color[u.name] == color[c.name])
                            return -1;
                        
                        if (!visited[u.name]) {
                            s.push(u);
                            color[u.name] = -color[c.name];
                        }
                    }
                }
            }
        }

        return (long) (Math.pow(2, components));
    }
    

    /**
     * Given an array of string, construct a bi-direction non-weighted graph.
     * Each element will represent a node. A string in the string array
     * represent a list of vertices that are the current node's neighbor. For
     * example, a string array:
     *
     * {"1 4, "2", "3", "0", ""} will yield the following graph. Node 0: Connect
     * with 1, 4. Node 1: Connect with 0, 2. Node 2: Connect with 1, 3. Node 3:
     * Connect with 2, 0. Node 4: Connect with 0.
     *
     *
     * @param compete The string array.
     * @return A Graph representing the data.
     */
    public static Graph constructGraph(String[] compete) {
        Graph g = new Graph(compete.length);
        for (int i = 0; i < compete.length; i++) {
            Vertex v = null;
            if (g.vertices[i] == null) {
                v = new Vertex(i);
                g.vertices[i] = v;
            } else {
                v = g.vertices[i];
            }

            String[] nodeSArr = compete[i].split(" ");

            // Connecting nodes.
            for (String s : nodeSArr) {
                if (!s.equals("")) {
                    int vName = Integer.parseInt(s);

                    // If the vertice has not already been created.
                    if (g.vertices[vName] == null) {
                        Vertex u = new Vertex(vName);
                        g.vertices[vName] = u;
                        v.neighbors.add(u);
                        u.neighbors.add(v);
                    } else {
                        // Otherwise just add to the list of neighbor.
                        // Update the other vertex's neighbor list.
                        v.neighbors.add(g.vertices[vName]);
                        g.vertices[vName].neighbors.add(v);
                    }
                }
            }
        }
        return g;
    }

    public static void printStringArr(String[] strArr) {
        for (String s : strArr) {
            System.out.println(s);
        }
    }

    /**
     * Print a given graph in adjacency matrix format.
     *
     * @param g
     */
    public static void printGraph(Graph g) {
        for (Vertex v : g.vertices) {
            System.out.print("Node: " + v.name + " ");
            System.out.print("Neighbors: ");
            v.neighbors.stream().forEach((u) -> {
                System.out.print(u.name + ", ");
            });

            System.out.println();
        }
    }
}
