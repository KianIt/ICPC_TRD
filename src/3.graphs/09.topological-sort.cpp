vector<bool> used;
vector<int> ans;
vector<vector<int>>g;

void dfs(int v) {
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to]) dfs(to);
    }
    ans.push_back(v);
}

void topological_sort(int n) {
    used.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i)
        if (!used[i]) dfs(i);
    reverse(ans.begin(), ans.end());
}

signed main() {
    int n; // число вершин
    cin >> n;
    used.assign(n, false);
    g.resize(n);
    topological_sort(n);
}