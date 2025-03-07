from collections import defaultdict

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)  # For undirected graph

    def dfs(self, v, visited):
        print(v, end=" ")
        visited.add(v)

        for u in self.graph[v]:
            if u not in visited:
                self.dfs(u, visited)

if __name__ == "__main__":
    g = Graph()

    n = int(input("Enter the number of nodes: "))
    edges = int(input("Enter the number of edges: "))

    print("Enter the edges (u v):")
    for _ in range(edges):
        u, v = map(int, input().split())
        g.add_edge(u, v)

    start = int(input("Enter the starting node: "))

    print("DFS Traversal: ", end="")
    g.dfs(start, set())
