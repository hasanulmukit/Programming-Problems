#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void DFS(int v) {
    cout << v << " ";
    visited[v] = true;

    for (int u : graph[v]) {
        if (!visited[u]) {
            DFS(u);
        }
    }
}

int main() {
    int n, edges;
    cout << "Enter the number of nodes: ";
    cin >> n;

    graph.resize(n + 1);
    visited.resize(n + 1, false);

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // For undirected graph
    }

    int start;
    cout << "Enter the starting node: ";
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(start);

    return 0;
}
