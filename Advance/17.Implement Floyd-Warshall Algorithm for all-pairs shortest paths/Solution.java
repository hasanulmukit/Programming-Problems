import java.util.Scanner;

public class FloydWarshall {
    static final int INF = 99999;

    public static void floydWarshall(int[][] graph, int vertices) {
        int[][] dist = new int[vertices][vertices];

        // Initialize distance array
        for (int i = 0; i < vertices; i++) {
            System.arraycopy(graph[i], 0, dist[i], 0, vertices);
        }

        // Compute shortest paths
        for (int k = 0; k < vertices; k++) {
            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < vertices; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Print the result
        System.out.println("Shortest distances between every pair of vertices:");
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (dist[i][j] == INF)
                    System.out.print("INF ");
                else
                    System.out.print(dist[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of vertices and edges: ");
        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();

        int[][] graph = new int[vertices][vertices];
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                graph[i][j] = (i == j) ? 0 : INF;
            }
        }

        System.out.println("Enter the edges (u v w):");
        for (int i = 0; i < edges; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int w = scanner.nextInt();
            graph[u][v] = w;
        }

        floydWarshall(graph, vertices);

        scanner.close();
    }
}
