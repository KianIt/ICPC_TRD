// Theme: Minimum Spanning Tree
// Algorithm: Binary Lifting Method
// Complexity: O(N * log(N) + log(N))

vector<vector<int>> g;      // Graph
vector<vector<int>> up;     // Ancestors
vector<int> tin, tout;      // Enter And Exit Time

int timer;                  // Timer

int l;                      // l == log(N) (~20)

void dfs(int v, int p = -1) {
    tin[v] = timer++;
    
    up[v][0] = p;
    for (int i = 1; i <= l; i++)
        up[v][i] = up[up[v][i - 1]][i - 1];

    for (auto &to : g[v]) {
        if (to == p) continue;
        dfs(to, v);
    }

    tout[v] = timer++;
}

void preprocess(int n, int r) {
    l = (int) ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    timer = 0;
    dfs(r, r);
}

bool is_anc(int v, int u) {
    return tin[v] <= tin[u] && tout[v] >= tout[u];
}

int lca(int v, int u) {
    if (is_anc(v, u))
        return v;
    if (is_anc(u, v))
        return u;
    for (int i = l; i >= 0; --i) {
        if (!is_anc(up[v][i], u))
            v = up[v][i];
    }
    return up[v][0];
}