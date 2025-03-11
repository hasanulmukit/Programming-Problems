#include <stdio.h>
#include <stdbool.h>
#define MAX 100

void dfs(int graph[MAX][MAX], int visited[MAX], int vertices, int current) {
    visited[current] = 1;
    printf("%d ", current);

    for (int i = 0; i < vertices; i++) {
        if (graph[current][i] == 1 && !visited[i]) {
            dfs(graph, visited, vertices, i);
        }
    }
}

void findConnectedComponents(int graph[MAX][MAX], int vertices) {
    int visited[MAX] = {0};
    int component = 0;

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            component++;
            printf("Component %d: ", component);
            dfs(graph, visited, vertices, i);
            printf("\n");
        }
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    int graph[MAX][MAX] = {0};

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // Because the graph is undirected
    }

    printf("Connected components of the graph are:\n");
    findConnectedComponents(graph, vertices);

    return 0;
}
