#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int vertex;  // current cell number (vertex)
    int dist;    // number of dice throws needed to reach this cell
};

int snakeLadderMinDiceThrows(const vector<int>& board, int N) {
    vector<bool> visited(N, false);
    queue<Node> q;
    
    // Start from cell 0 with 0 throws.
    visited[0] = true;
    q.push({0, 0});
    
    while (!q.empty()) {
        Node node = q.front();
        q.pop();
        int v = node.vertex;
        int d = node.dist;
        
        // If reached last cell
        if (v == N - 1)
            return d;
        
        // Try all possible dice throws (1 to 6)
        for (int dice = 1; dice <= 6 && v + dice < N; dice++) {
            int next = v + dice;
            if (!visited[next]) {
                visited[next] = true;
                // If there's a snake or ladder, board[next] contains the destination
                q.push({board[next], d + 1});
            }
        }
    }
    return -1;  // Should not happen if board is valid
}

int main() {
    int N;
    cout << "Enter the number of squares in the board: ";
    cin >> N;
    
    // Initialize board: by default, each cell maps to itself.
    vector<int> board(N);
    for (int i = 0; i < N; i++) {
        board[i] = i;
    }
    
    int T;
    cout << "Enter the number of snakes/ladders: ";
    cin >> T;
    cout << "Enter start and end positions for each snake/ladder (0-indexed):\n";
    for (int i = 0; i < T; i++) {
        int start, end;
        cin >> start >> end;
        board[start] = end;
    }
    
    int result = snakeLadderMinDiceThrows(board, N);
    if (result != -1)
        cout << "Minimum number of dice throws required: " << result << endl;
    else
        cout << "Destination not reachable." << endl;
        
    return 0;
}
