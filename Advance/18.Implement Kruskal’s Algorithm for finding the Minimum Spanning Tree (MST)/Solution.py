class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX == rootY:
            return
        if self.rank[rootX] < self.rank[rootY]:
            self.parent[rootX] = rootY
        elif self.rank[rootX] > self.rank[rootY]:
            self.parent[rootY] = rootX
        else:
            self.parent[rootY] = rootX
            self.rank[rootX] += 1

def kruskal(V, edges):
    # Sort edges based on weight
    edges.sort(key=lambda edge: edge[2])
    ds = DisjointSet(V)
    mst = []
    total_weight = 0

    for u, v, w in edges:
        if ds.find(u) != ds.find(v):
            ds.union(u, v)
            mst.append((u, v, w))
            total_weight += w

    return mst, total_weight

if __name__ == "__main__":
    V = int(input("Enter the number of vertices: "))
    E = int(input("Enter the number of edges: "))
    
    edges = []
    print("Enter each edge in the format: u v weight (vertices are 0-indexed):")
    for _ in range(E):
        u, v, w = map(int, input().split())
        edges.append((u, v, w))
    
    mst, total_weight = kruskal(V, edges)
    
    print("\nEdges in the Minimum Spanning Tree (MST):")
    for u, v, w in mst:
        print(f"{u} -- {v} == {w}")
    print("Total weight of MST:", total_weight)
