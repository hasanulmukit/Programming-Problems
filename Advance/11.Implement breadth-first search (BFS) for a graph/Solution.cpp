#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void BFS(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
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

    cout << "BFS Traversal: ";
    BFS(start);

    return 0;
}
