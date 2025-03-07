import java.util.*;

public class DFSGraph {
    private Map<Integer, List<Integer>> graph = new HashMap<>();
    private Set<Integer> visited = new HashSet<>();

    public void addEdge(int u, int v) {
        graph.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
        graph.computeIfAbsent(v, k -> new ArrayList<>()).add(u); // For undirected graph
    }

    public void DFS(int v) {
        System.out.print(v + " ");
        visited.add(v);

        for (int u : graph.getOrDefault(v, new ArrayList<>())) {
            if (!visited.contains(u)) {
                DFS(u);
            }
        }
    }

    public static void main(String[] args) {
        DFSGraph dfsGraph = new DFSGraph();
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of nodes: ");
        int n = scanner.nextInt();

        System.out.print("Enter the number of edges: ");
        int edges = scanner.nextInt();

        System.out.println("Enter the edges (u v):");
        for (int i = 0; i < edges; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            dfsGraph.addEdge(u, v);
        }

        System.out.print("Enter the starting node: ");
        int start = scanner.nextInt();

        System.out.println("DFS Traversal: ");
        dfsGraph.DFS(start);
    }
}
