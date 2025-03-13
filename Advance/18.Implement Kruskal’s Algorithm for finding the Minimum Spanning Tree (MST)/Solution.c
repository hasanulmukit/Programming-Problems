#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, weight;
} Edge;

// Comparator function for qsort
int compare(const void *a, const void *b) {
    Edge *edge1 = (Edge *)a;
    Edge *edge2 = (Edge *)b;
    return edge1->weight - edge2->weight;
}

// Find function for union-find
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

// Union function for union-find
void unionSet(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

// Kruskal's algorithm
void kruskal(Edge edges[], int V, int E) {
    qsort(edges, E, sizeof(Edge), compare);

    int parent[V];
    int rank[V];
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int mstWeight = 0;
    printf("Edges in the MST:\n");
    for (int i = 0, count = 0; i < E && count < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        int setU = find(parent, u);
        int setV = find(parent, v);

        if (setU != setV) {
            printf("%d -- %d == %d\n", u, v, edges[i].weight);
            mstWeight += edges[i].weight;
            unionSet(parent, rank, setU, setV);
            count++;
        }
    }

    printf("Total weight of MST: %d\n", mstWeight);
}

int main() {
    int V, E;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    Edge edges[E];
    printf("Enter the edges (u, v, weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    kruskal(edges, V, E);
    return 0;
}
