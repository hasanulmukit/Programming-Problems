def floyd_warshall(dist, V):
    # Compute all pairs shortest paths using Floyd-Warshall algorithm.
    for k in range(V):
        for i in range(V):
            for j in range(V):
                if dist[i][k] != INF and dist[k][j] != INF:
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

if __name__ == "__main__":
    INF = 10**9  # A large number to represent "infinity"
    
    V = int(input("Enter the number of vertices: "))
    E = int(input("Enter the number of edges: "))
    
    # Initialize the graph as a V x V matrix.
    dist = [[INF] * V for _ in range(V)]
    for i in range(V):
        dist[i][i] = 0
    
    print("Enter each edge in the format: u v weight")
    for _ in range(E):
        u, v, w = map(int, input().split())
        # Assuming vertices are 0-indexed.
        dist[u][v] = w
        # If the graph is undirected, uncomment the following line:
        # dist[v][u] = w
    
    floyd_warshall(dist, V)
    
    print("\nShortest distances between every pair of vertices:")
    for i in range(V):
        for j in range(V):
            if dist[i][j] == INF:
                print("INF", end=" ")
            else:
                print(dist[i][j], end=" ")
        print()
