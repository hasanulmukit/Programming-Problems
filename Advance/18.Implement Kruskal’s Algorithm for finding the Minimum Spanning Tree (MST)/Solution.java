import java.util.*;

class KruskalAlgorithm {
    static class Edge implements Comparable<Edge> {
        int u, v, weight;

        Edge(int u, int v, int weight) {
            this.u = u;
            this.v = v;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge other) {
            return this.weight - other.weight;
        }
    }

    static class UnionFind {
        int[] parent, rank;

        UnionFind(int size) {
            parent = new int[size];
            rank = new int[size];
            for (int i = 0; i < size; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        void union(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX != rootY) {
                if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        }
    }

    static void kruskal(List<Edge> edges, int V) {
        Collections.sort(edges);

        UnionFind uf = new UnionFind(V);
        int mstWeight = 0;
        System.out.println("Edges in the MST:");

        for (Edge edge : edges) {
            int u = edge.u;
            int v = edge.v;

            if (uf.find(u) != uf.find(v)) {
                System.out.println(u + " -- " + v + " == " + edge.weight);
                mstWeight += edge.weight;
                uf.union(u, v);
            }
        }

        System.out.println("Total weight of MST: " + mstWeight);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of vertices and edges: ");
        int V = scanner.nextInt();
        int E = scanner.nextInt();

        List<Edge> edges = new ArrayList<>();
        System.out.println("Enter the edges (u, v, weight):");
        for (int i = 0; i < E; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int weight = scanner.nextInt();
            edges.add(new Edge(u, v, weight));
        }

        kruskal(edges, V);
    }
}
