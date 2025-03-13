from collections import deque

def snake_ladder_min_dice_throws(board, N):
    visited = [False] * N
    queue = deque()
    
    # Start from square 0 with 0 dice throws.
    visited[0] = True
    queue.append((0, 0))  # (vertex, distance)
    
    while queue:
        vertex, dist = queue.popleft()
        # If we've reached the last square, return the number of dice throws
        if vertex == N - 1:
            return dist
        
        # Try all possible dice throws from 1 to 6
        for dice in range(1, 7):
            next_vertex = vertex + dice
            if next_vertex < N and not visited[next_vertex]:
                visited[next_vertex] = True
                # If there is a snake or ladder, board[next_vertex] gives the final destination.
                queue.append((board[next_vertex], dist + 1))
    return -1

if __name__ == "__main__":
    N = int(input("Enter the number of squares in the board: "))
    
    # Initialize board: each cell maps to itself by default.
    board = [i for i in range(N)]
    
    T = int(input("Enter the number of snakes/ladders: "))
    print("Enter start and end positions for each snake/ladder (0-indexed):")
    for _ in range(T):
        start, end = map(int, input().split())
        board[start] = end
    
    result = snake_ladder_min_dice_throws(board, N)
    if result != -1:
        print("Minimum number of dice throws required:", result)
    else:
        print("Destination not reachable.")
