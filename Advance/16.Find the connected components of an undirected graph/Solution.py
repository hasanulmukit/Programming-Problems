def dfs(v, graph, visited, component):
    visited[v] = True
    component.append(v)
    for neighbor in graph[v]:
        if not visited[neighbor]:
            dfs(neighbor, graph, visited, component)

def main():
    V = int(input("Enter the number of vertices: "))
    E = int(input("Enter the number of edges: "))
    
    # Create the graph as an adjacency list
    graph = [[] for _ in range(V)]
    
    print("Enter the edges (u v) for each edge (0-indexed):")
    for _ in range(E):
        u, v = map(int, input().split())
        # Since the graph is undirected, add both directions.
        graph[u].append(v)
        graph[v].append(u)
    
    visited = [False] * V
    components = []
    
    for i in range(V):
        if not visited[i]:
            component = []
            dfs(i, graph, visited, component)
            components.append(component)
    
    print("Connected Components:")
    for idx, comp in enumerate(components, 1):
        print(f"Component {idx}: {' '.join(map(str, comp))}")

if __name__ == "__main__":
    main()
