// Theme: All Graph Bridges
// Algorithm: DFS Based Algorithm
// Complexity: O(N + M)

vector<vector<int>> g;          // Graph
vector<int> u;                  // Used
vector<int> tin, tup;           // Enter And Exit Time
vector<pair<int, int>> b;       // Bridges <Vertex, Vertex>

int timer;                      // Timer

void dfs(int v, int p = -1) {
    u[v] = 1;
    tin[v] = tup[v] = timer++;

    for (auto &to: g[v]) {
        if (to == p) continue;
        if (u[to]) tup[v] = min(tup[v], tin[to]);
        else {
            dfs(to, v);
            tup[v] = min(tup[v], tup[to]);
            if (tup[to] > tin[v] && count(all(g[v]), to) == 1)
                b.push_back({ min(v, to), max(v, to) });
        }
    }
}

void bridges(int n) {
    timer = 0;
    for (int i = 0; i < n; i++)
        if (!u[i])
            dfs(i);
}