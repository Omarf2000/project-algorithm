#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

int find(vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
    int root_x = find(parent, x);
    int root_y = find(parent, y);

    if (root_x != root_y) {
        if (rank[root_x] < rank[root_y]) {
            parent[root_x] = root_y;
        } else if (rank[root_x] > rank[root_y]) {
            parent[root_y] = root_x;
        } else {
            parent[root_y] = root_x;
            rank[root_x]++;
        }
    }
}

void kruskalMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    vector<Edge> mst;

    for (Edge edge : edges) {
        int root_src = find(parent, edge.src);
        int root_dest = find(parent, edge.dest);

        if (root_src != root_dest) {
            mst.push_back(edge);
            unionSets(parent, rank, root_src, root_dest);
        }

        if (mst.size() == V - 1) {
            break;
        }
    }

    cout << "Edges in MST:" << endl;
    for (Edge edge : mst) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);

    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    kruskalMST(edges, V);

    return 0;
}
