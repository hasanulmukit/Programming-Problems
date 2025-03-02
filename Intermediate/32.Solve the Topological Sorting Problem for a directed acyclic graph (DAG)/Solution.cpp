#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Recursive DFS function to process a vertex and its neighbors
void dfs(int v, const vector<vector<int>> &graph, vector<bool> &visited, stack<int> &order) {
    visited[v] = true;
    for (int neighbor : graph[v]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, order);
        }
    }
    // Push vertex onto stack after all its neighbors are processed
    order.push(v);
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;
    
    // Initialize graph as an adjacency list (0-indexed vertices)
    vector<vector<int>> graph(vertices);
    cout << "Enter each edge (source destination):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        // For a directed graph, add an edge from u to v
        graph[u].push_back(v);
    }
    
    // To keep track of visited vertices
    vector<bool> visited(vertices, false);
    stack<int> order;
    
    // Perform DFS for each vertex that hasn't been visited
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, order);
        }
    }
    
    // Output the topologically sorted order by popping from the stack
    cout << "Topological Order: ";
    while (!order.empty()) {
        cout << order.top() << " ";
        order.pop();
    }
    cout << endl;
    
    return 0;
}
