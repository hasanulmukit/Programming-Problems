from collections import defaultdict, deque

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)  # For undirected graph

    def bfs(self, start):
        visited = set()
        queue = deque([start])
        visited.add(start)

        while queue:
            node = queue.popleft()
            print(node, end=" ")

            for neighbor in self.graph[node]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)

if __name__ == "__main__":
    g = Graph()

    n = int(input("Enter the number of nodes: "))
    edges = int(input("Enter the number of edges: "))

    print("Enter the edges (u v):")
    for _ in range(edges):
        u, v = map(int, input().split())
        g.add_edge(u, v)

    start = int(input("Enter the starting node: "))

    print("BFS Traversal: ", end="")
    g.bfs(start)
