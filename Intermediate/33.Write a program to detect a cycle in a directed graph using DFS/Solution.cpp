#include <iostream>
#include <vector>
using namespace std;

// DFS function to detect cycle in a directed graph
bool dfsCycle(int v, const vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recStack) {
    visited[v] = true;
    recStack[v] = true;

    // Explore all neighbors
    for (int neighbor : graph[v]) {
        // If neighbor is not visited, do DFS on it
        if (!visited[neighbor]) {
            if (dfsCycle(neighbor, graph, visited, recStack))
                return true;
        }
        // If neighbor is in the recursion stack, cycle detected
        else if (recStack[neighbor]) {
            return true;
        }
    }

    // Remove vertex from recursion stack before returning
    recStack[v] = false;
    return false;
}

// Function to detect cycle in the entire graph
bool detectCycle(const vector<vector<int>>& graph, int V) {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsCycle(i, graph, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // Initialize graph as an adjacency list (0-indexed vertices)
    vector<vector<int>> graph(V);
    cout << "Enter each edge (u v) [directed edge from u to v]:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    if (detectCycle(graph, V))
        cout << "Cycle detected in the graph." << endl;
    else
        cout << "No cycle detected in the graph." << endl;

    return 0;
}
