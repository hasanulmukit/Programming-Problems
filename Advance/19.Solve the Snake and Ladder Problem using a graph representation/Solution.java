import java.util.*;

class SnakeAndLadder {

    static class Node {
        int vertex, distance;

        Node(int vertex, int distance) {
            this.vertex = vertex;
            this.distance = distance;
        }
    }

    public static int minDiceThrows(int[] board, int N) {
        boolean[] visited = new boolean[N];
        Queue<Node> queue = new LinkedList<>();

        queue.add(new Node(0, 0)); // Start from the first cell
        visited[0] = true;

        while (!queue.isEmpty()) {
            Node current = queue.poll();

            int v = current.vertex;

            if (v == N - 1) {
                return current.distance; // Reached the last cell
            }

            for (int dice = 1; dice <= 6 && v + dice < N; dice++) {
                int next = v + dice;

                if (!visited[next]) {
                    visited[next] = true;

                    int nextVertex = board[next] != -1 ? board[next] : next;
                    queue.add(new Node(nextVertex, current.distance + 1));
                }
            }
        }
        return -1; // No solution
    }

    public static void main(String[] args) {
        int N = 30;
        int[] board = new int[N];
        Arrays.fill(board, -1);

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

        System.out.println("Minimum dice throws required: " + minDiceThrows(board, N));
    }
}
