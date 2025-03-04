import java.util.Scanner;

public class NQueens {
    static void printSolution(int[][] board, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(board[i][j] == 1 ? "Q " : ". ");
            }
            System.out.println();
        }
        System.out.println();
    }

    static boolean isSafe(int[][] board, int row, int col, int n) {
        for (int i = 0; i < col; i++)
            if (board[row][i] == 1)
                return false;
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 1)
                return false;
        for (int i = row, j = col; i < n && j >= 0; i++, j--)
            if (board[i][j] == 1)
                return false;
        return true;
    }

    static boolean solveNQueensUtil(int[][] board, int col, int n) {
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

    static void solveNQueens(int n) {
        int[][] board = new int[n][n];
        if (!solveNQueensUtil(board, 0, n)) {
            System.out.println("No solution exists.");
            return;
        }
        printSolution(board, n);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of the board (N): ");
        int n = scanner.nextInt();
        solveNQueens(n);
    }
}
