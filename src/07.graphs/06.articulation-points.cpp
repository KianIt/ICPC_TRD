// Theme: All Graph Articulation Points
// Algorithm: DFS Based Algorithm
// Complexity: O(N + M)

vector<vector<int>> g;          // Graph
vector<int> u;                  // Used
vector<int> tin, tup;           // Enter And Exit Time
vector<int> ap;                 // Articulation Points

int timer;                      // Timer

void dfs(int v, int p = -1) {
    u[v] = 1;
    tin[v] = tup[v] = timer++;
    
    int children = 0;

    for (auto &to: g[v]) {
        if (to == p) continue;
        if (u[to]) tup[v] = min(tup[v], tin[to]);
        else {
            dfs(to, v);
            tup[v] = min(tup[v], tup[to]);
            if (tup[to] >= tin[v] && p != -1) result.insert(v);
            children++;
        }
    }

    if (p == -1 && children > 1) result.insert(v);
}

void find_ap(int n) {
    timer = 0;
    for (int i = 0; i < n; i++)
        if (!u[i])
            dfs(i);
}