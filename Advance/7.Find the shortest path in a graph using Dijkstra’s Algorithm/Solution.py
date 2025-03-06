import sys

def find_min_distance(dist, visited, n):
    min_val = sys.maxsize
    min_index = -1
    for v in range(n):
        if not visited[v] and dist[v] <= min_val:
            min_val = dist[v]
            min_index = v
    return min_index

def dijkstra(graph, n, start):
    dist = [sys.maxsize] * n
    visited = [False] * n

    dist[start] = 0

    for _ in range(n - 1):
        u = find_min_distance(dist, visited, n)
        visited[u] = True

        for v in range(n):
            if not visited[v] and graph[u][v] and dist[u] != sys.maxsize and dist[u] + graph[u][v] < dist[v]:
                dist[v] = dist[u] + graph[u][v]

    print("Vertex\tDistance from Source")
    for i in range(n):
        print(f"{i}\t{dist[i]}")

if __name__ == "__main__":
    n = int(input("Enter the number of vertices: "))
    graph = []
    print("Enter the adjacency matrix:")
    for i in range(n):
        graph.append(list(map(int, input().split())))

    start = int(input("Enter the starting vertex: "))
    dijkstra(graph, n, start)
