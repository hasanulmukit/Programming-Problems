#include <iostream>
#include <vector>
using namespace std;

void printSolution(vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] ? 'Q' : '.') << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
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

bool solveNQueensUtil(vector<vector<int>>& board, int col, int n) {
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
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (!solveNQueensUtil(board, 0, n)) {
        cout << "No solution exists.\n";
        return;
    }
    printSolution(board, n);
}

int main() {
    int n;
    cout << "Enter the size of the board (N): ";
    cin >> n;
    solveNQueens(n);
    return 0;
}
