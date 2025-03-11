import java.util.*;

public class ConnectedComponents {
    static void dfs(int[][] graph, boolean[] visited, int current) {
        visited[current] = true;
        System.out.print(current + " ");

        for (int i = 0; i < graph.length; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                dfs(graph, visited, i);
            }
        }
    }

    public static void findConnectedComponents(int[][] graph) {
        boolean[] visited = new boolean[graph.length];
        int component = 0;

        for (int i = 0; i < graph.length; i++) {
            if (!visited[i]) {
                component++;
                System.out.print("Component " + component + ": ");
                dfs(graph, visited, i);
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of vertices and edges: ");
        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();

        int[][] graph = new int[vertices][vertices];

        System.out.println("Enter the edges (u v):");
        for (int i = 0; i < edges; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            graph[u][v] = 1;
            graph[v][u] = 1; // Because the graph is undirected
        }

        System.out.println("Connected components of the graph are:");
        findConnectedComponents(graph);

        scanner.close();
    }
}
