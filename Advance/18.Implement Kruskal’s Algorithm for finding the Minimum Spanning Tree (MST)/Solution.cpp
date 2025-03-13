#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Structure to represent an edge in the graph.
struct Edge {
    int u, v, weight;
};

// Comparator function for sorting edges in non-decreasing order by weight.
bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

// Disjoint Set (Union-Find) class for cycle detection.
class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find the representative of the set containing x (with path compression).
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union the sets that contain x and y.
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return;

        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> edges(E);
    cout << "Enter each edge in the format: u v weight (vertices are 0-indexed):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Sort the edges by weight.
    sort(edges.begin(), edges.end(), compareEdges);

    DisjointSet ds(V);
    vector<Edge> mst;
    int totalWeight = 0;

    // Process each edge in order.
    for (Edge &edge : edges) {
        if (ds.find(edge.u) != ds.find(edge.v)) {
            ds.unionSets(edge.u, edge.v);
            mst.push_back(edge);
            totalWeight += edge.weight;
        }
    }

    cout << "\nEdges in the Minimum Spanning Tree (MST):" << endl;
    for (Edge &edge : mst) {
        cout << edge.u << " -- " << edge.v << " == " << edge.weight << endl;
    }
    cout << "Total weight of MST: " << totalWeight << endl;

    return 0;
}
