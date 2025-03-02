#include <stdio.h>
#include <stdlib.h>

void topologicalSortUtil(int v, int visited[], int *stack, int *top, int graph[][100], int vertices) {
    visited[v] = 1;

    for (int i = 0; i < vertices; i++) {
        if (graph[v][i] && !visited[i]) {
            topologicalSortUtil(i, visited, stack, top, graph, vertices);
        }
    }

    stack[++(*top)] = v;
}

void topologicalSort(int graph[][100], int vertices) {
    int visited[vertices];
    int stack[vertices];
    int top = -1;

    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, stack, &top, graph, vertices);
        }
    }

    printf("Topological Sort: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
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

    topologicalSort(graph, vertices);

    return 0;
}
