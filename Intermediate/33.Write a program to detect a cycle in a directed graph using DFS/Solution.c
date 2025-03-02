#include <stdio.h>
#include <stdlib.h>

int detectCycleUtil(int v, int visited[], int recStack[], int graph[][100], int vertices) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < vertices; i++) {
        if (graph[v][i]) {
            if (!visited[i] && detectCycleUtil(i, visited, recStack, graph, vertices)) {
                return 1;
            } else if (recStack[i]) {
                return 1;
            }
        }
    }

    recStack[v] = 0;
    return 0;
}

int detectCycle(int graph[][100], int vertices) {
    int visited[vertices];
    int recStack[vertices];

    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < vertices; i++) {
        if (!visited[i] && detectCycleUtil(i, visited, recStack, graph, vertices)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    int graph[100][100] = {0};
    printf("Enter the edges (u -> v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    if (detectCycle(graph, vertices)) {
        printf("Cycle detected in the graph.\n");
    } else {
        printf("No cycle detected in the graph.\n");
    }

    return 0;
}
