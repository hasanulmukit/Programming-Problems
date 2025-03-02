def dfs(v, graph, visited, stack):
    """Recursive DFS that marks visited nodes and appends vertices to stack."""
    visited[v] = True
    for neighbor in graph[v]:
        if not visited[neighbor]:
            dfs(neighbor, graph, visited, stack)
    stack.append(v)

def topological_sort(graph, vertices):
    """Returns a list of vertices in topologically sorted order."""
    visited = [False] * vertices
    stack = []
    for i in range(vertices):
        if not visited[i]:
            dfs(i, graph, visited, stack)
    # Reverse stack to get the correct topological order.
    return stack[::-1]

def main():
    vertices = int(input("Enter the number of vertices: "))
    edges = int(input("Enter the number of edges: "))
    
    # Initialize the graph as a list of lists
    graph = [[] for _ in range(vertices)]
    print("Enter each edge (source destination) separated by space:")
    for _ in range(edges):
        u, v = map(int, input().split())
        graph[u].append(v)  # Directed edge from u to v
    
    order = topological_sort(graph, vertices)
    print("Topological Order:", " ".join(map(str, order)))

if __name__ == "__main__":
    main()
