class DisjointSet:
    def __init__(self, vertices):
        self.parent = {v: v for v in vertices}
        self.rank = {v: 0 for v in vertices}

    def find(self, v):
        if self.parent[v] != v:
            self.parent[v] = self.find(self.parent[v])   Path compression
        return self.parent[v]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)

        if root_u != root_v:
            # Union by rank
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            elif self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1


def kruskal(graph):
    edges = graph['edges']
    vertices = graph['vertices']

    #Sort edges by weight
    edges.sort(key=lambda x: x[2])  # x[2] is the weight

    #  Initialize Disjoint Set
    ds = DisjointSet(vertices)

    mst = []  # List to store MST edges

    #  Process edges in sorted order
    for edge in edges:
        u, v, weight = edge
        if ds.find(u) != ds.find(v):
            mst.append((u, v, weight))
            ds.union(u, v)

        # Stop if we have V-1 edges
        if len(mst) == len(vertices) - 1:
            break

    return mst


# Example Usage
if __name__ == "__main__":
    graph = {
        'vertices': ['A', 'B', 'C', 'D', 'E'],
        'edges': [
            ('A', 'B', 1),
            ('B', 'C', 3),
            ('A', 'C', 5),
            ('B', 'D', 4),
            ('C', 'D', 2),
            ('D', 'E', 6)
        ]
    }

    mst = kruskal(graph)
    print("Edges in MST:")
    for u, v, weight in mst:
        print(f"{u} - {v} : {weight}")
