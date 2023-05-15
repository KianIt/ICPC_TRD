// Theme: Minimum Spanning Tree
// Algorithm: Kruskal's Algorithm
// Complexity: O(M * log(N))


struct dsu {                            // Disjoint Set Union
    // ...
};

vector<pair<int, pair<int, int>>> g;    // Graph <Weight, <Vertex, Vertex>>

auto kruskal(int n) {
    dsu d(n);
    vector<pair<int, pair<int, int>>> spt;

    sort(all(g));

    for (auto &e : g) {
        int w = e.ff, v = e.ss.ff, u = e.ss.ss;
        if (d.get(v) != d.get(u)) {
            res.push_back(e);
            d.unite(v, u);
        }
    }
    
    return spt;
}