// Theme: Graph Connectivity Components

// Subtheme: Graph Connectivity Components Count
// Algorithm: DFS Based Algorithm
// Complexity: O(N + M)

vector<vector<int>> g;          // Graph
vector<int> u;                  // Used

void dfs(int v, int p = -1) {
    u[v] = 1;

    for (auto &to : g[v]) {
        if (to == p || u[to]) continue;
        dfs(to, v);
    }
}

int cc(int n) {
    int count = 0;
    
    for (int i = 0; i < n; i++)
        if (!u[i]) {
            dfs(i);
            count++;
        }
    
    return count;
}

// Subtheme: Graph Strong Connectivity Components
// Algorithm: DFS Based Algorithm
// Complexity: O(N + M)

vector<vector<int>> g;          // Graph
vector<vector<int>> gr;         // Reversed Edges Graph
vector<int> u;                  // Used
vector<int> order;              // Edges Order
vector<int> component;          // SCC

void dfs1(int v, int p = -1) {
    u[v] = 1;

    for (auto &to : g[v]) {
        if (to == p || u[to]) continue;
        dfs(to, v);
    }

    order.push_back(v);
}

void dfs2(int v, int p = -1) {
    u[v] = 1;

    component.push_back(v);
    for (auto &to : gr[v])
        if (to != p && !u[to]) dfs2(to, v);
}


void scc(int n) {
    u.assign(n, 0);
    for (int i = 0; i < n; i++)
        if (!u[i])
            dfs1(i);

    u.assign(n, 0);
    for (int i = 0; i < n; i++) {
        int v = order[n - i - 1];
        if (!u[i]) {
            dfs2(v);
            component.clear();
        }
    }
}