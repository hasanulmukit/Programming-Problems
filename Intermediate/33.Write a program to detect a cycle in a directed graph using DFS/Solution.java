import java.util.*;

public class CycleDetectionDirectedGraph {
    static boolean detectCycleUtil(int v, boolean[] visited, boolean[] recStack, List<List<Integer>> graph) {
        visited[v] = true;
        recStack[v] = true;

        for (int neighbor : graph.get(v)) {
            if (!visited[neighbor] && detectCycleUtil(neighbor, visited, recStack, graph)) {
                return true;
            } else if (recStack[neighbor]) {
                return true;
            }
        }

        recStack[v] = false;
        return false;
    }

    static boolean detectCycle(List<List<Integer>> graph, int vertices) {
        boolean[] visited = new boolean[vertices];
        boolean[] recStack = new boolean[vertices];

        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && detectCycleUtil(i, visited, recStack, graph)) {
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of vertices and edges: ");
        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();

        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < vertices; i++) {
            graph.add(new ArrayList<>());
        }

        System.out.println("Enter the edges (u -> v):");
        for (int i = 0; i < edges; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            graph.get(u).add(v);
        }

        if (detectCycle(graph, vertices)) {
            System.out.println("Cycle detected in the graph.");
        } else {
            System.out.println("No cycle detected in the graph.");
        }

        scanner.close();
    }
}
