// Theme: Graph Traversing

vector<vector<int>> g;  // Graph
vector<int> u;          // Used

// Algorithm: Breadth-First Search
// Complexity: O(N + M)

void bfs(int v) {
    queue<int> q;       // Queue

    u[v] = 1;
    q.push(v);

    while (q.size()) {
        int w = q.front(); q.pop();

        for (auto &to : g[w]) {
            if (u[to]) continue;
            u[to] = 1;
            q.push(to);
        }
    }
}

// Algorithm: Depth-First Search
// Complexity: O(N + M)

void dfs(int v, int p = -1) {
    u[v] = 1;

    for (auto &to : g[v]) {
        if (to == p || u[to]) continue;
        dfs(to, v);
    }
}