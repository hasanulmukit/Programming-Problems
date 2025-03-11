#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int INF = 1e9; // A large number to represent "infinity"

void floydWarshall(vector<vector<int>> &dist, int V) {
    // Use each vertex as an intermediate point.
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    
    // Initialize the graph as a V x V matrix.
    vector<vector<int>> dist(V, vector<int>(V, INF));
    for (int i = 0; i < V; i++) {
        dist[i][i] = 0;
    }
    
    cout << "Enter each edge in the format: u v weight\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // Assuming 0-indexed vertices.
        dist[u][v] = w;
        // For directed graph, comment out the following line.
        // dist[v][u] = w; 
    }
    
    floydWarshall(dist, V);
    
    cout << "\nShortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
