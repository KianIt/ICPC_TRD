// Theme: Graph Topological Sorting
// Algorithm: DFS Based Algorithm
// Complexity: O(N + M)

vector<vector<int>> g;  // Graph
vector<int> u;          // Used
vector<int> ans;        // Sorted Vertices

void dfs(int v, int p = -1) {
    u[v] = 1;

    for (auto &to : g[v]) {
        if (to == p || u[to]) continue;
        dfs(to, v);
    }

    ans.push_back(v);
}

void topsort(int n) {
    for (int i = 0; i < n; i++)
        if (!u[i])
            dfs(i);

    reverse(all(ans));
}