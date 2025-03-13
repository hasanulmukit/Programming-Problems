#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A queue node
struct QueueNode {
    int vertex;
    int distance;
};

// Create a queue node
struct QueueNode createNode(int vertex, int distance) {
    struct QueueNode node;
    node.vertex = vertex;
    node.distance = distance;
    return node;
}

// Snake and ladder problem
int minDiceThrows(int board[], int N) {
    int visited[N];
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }

    struct QueueNode queue[N];
    int front = 0, rear = 0;

    queue[rear++] = createNode(0, 0); // Start from the first cell
    visited[0] = 1;

    while (front < rear) {
        struct QueueNode current = queue[front++];
        int v = current.vertex;

        if (v == N - 1) {
            return current.distance; // Reached the last cell
        }

        for (int dice = 1; dice <= 6 && v + dice < N; dice++) {
            int next = v + dice;

            if (!visited[next]) {
                visited[next] = 1;
                struct QueueNode nextNode = createNode(
                    board[next] == -1 ? next : board[next],
                    current.distance + 1);
                queue[rear++] = nextNode;
            }
        }
    }
    return INT_MAX; // No solution
}

int main() {
    int N = 30;
    int board[N];
    for (int i = 0; i < N; i++) {
        board[i] = -1;
    }

    // Example: Add ladders
    board[2] = 21;
    board[4] = 7;
    board[10] = 25;
    board[19] = 28;

    // Example: Add snakes
    board[26] = 0;
    board[20] = 8;
    board[16] = 3;
    board[18] = 6;

    printf("Minimum dice throws required: %d\n", minDiceThrows(board, N));
    return 0;
}
