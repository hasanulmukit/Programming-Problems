#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

void printSolution(int board[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[MAX][MAX], int row, int col, int n) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j])
            return false;
    return true;
}

bool solveNQueensUtil(int board[MAX][MAX], int col, int n) {
    if (col >= n)
        return true;

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            if (solveNQueensUtil(board, col + 1, n))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

void solveNQueens(int n) {
    int board[MAX][MAX] = {0};
    if (!solveNQueensUtil(board, 0, n)) {
        printf("No solution exists.\n");
        return;
    }
    printSolution(board, n);
}

int main() {
    int n;
    printf("Enter the size of the board (N): ");
    scanf("%d", &n);
    solveNQueens(n);
    return 0;
}
