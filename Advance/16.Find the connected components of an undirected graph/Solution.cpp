#include <iostream>
#include <vector>
using namespace std;

// DFS function to explore a connected component
void dfs(int vertex, const vector<vector<int>> &graph, vector<bool> &visited, vector<int> &component) {
    visited[vertex] = true;
    component.push_back(vertex);
    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, component);
        }
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    
    // Create an adjacency list for the graph
    vector<vector<int>> graph(V);
    cout << "Enter the edges (u v) for each edge (0-indexed):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        // Since the graph is undirected, add edges in both directions.
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<bool> visited(V, false);
    int componentCount = 0;
    
    cout << "Connected Components:" << endl;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, graph, visited, component);
            componentCount++;
            cout << "Component " << componentCount << ": ";
            for (int node : component) {
                cout << node << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
