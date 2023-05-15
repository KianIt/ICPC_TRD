// Theme: Shortest Paths From Vertex
// Alrotihm: Belman-Ford's
// Complexity: O(N*M)

const int inf = 1e18;

vector<pair<int, <int, int>>> g;    // Graph <Weight, <Vertex, Vertex>>

auto bfa(int v, int n) {
    int m = g.size();

    vector<int> d(n, inf); d[v] = 0;

    for (;;) {
        bool any = false;
        for (int j = 0; j < m; ++j)
            if (d[g[j].ss.ff] < inf &&
                d[g[j].ss.ff] + g[j].ff < d[g[j].ss.ss]) {
                d[g[j].ss.ss] = d[g[j].ss.ff] + g[j].ff;
                any = true;
            }
        if (!any) break;
    }

    return d;
}