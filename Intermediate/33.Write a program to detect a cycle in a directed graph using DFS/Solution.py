def dfs_cycle(v, graph, visited, rec_stack):
    # Mark current node as visited and add it to recursion stack
    visited[v] = True
    rec_stack[v] = True

    # Visit all neighbors
    for neighbor in graph[v]:
        if not visited[neighbor]:
            if dfs_cycle(neighbor, graph, visited, rec_stack):
                return True
        elif rec_stack[neighbor]:
            return True

    # Remove the vertex from recursion stack before returning
    rec_stack[v] = False
    return False

def detect_cycle(graph, V):
    visited = [False] * V
    rec_stack = [False] * V

    for i in range(V):
        if not visited[i]:
            if dfs_cycle(i, graph, visited, rec_stack):
                return True
    return False

def main():
    V = int(input("Enter the number of vertices: "))
    E = int(input("Enter the number of edges: "))

    # Initialize the graph as an adjacency list
    graph = [[] for _ in range(V)]
    print("Enter each edge (u v) [directed edge from u to v]:")
    for _ in range(E):
        u, v = map(int, input().split())
        graph[u].append(v)
    
    if detect_cycle(graph, V):
        print("Cycle detected in the graph.")
    else:
        print("No cycle detected in the graph.")

if __name__ == "__main__":
    main()
