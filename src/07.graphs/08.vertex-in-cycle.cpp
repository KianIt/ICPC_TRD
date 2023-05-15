// Theme: Vertex In Cycle
// Algorithm: DFS Based Algorithm
// Complexity: O(N + M)

vector<vector<int>> g;        // Graph
vector<int> u;                // Used
vector<int> c;                // Cycle Vertices
vector<int> p;                // Path Back

int vs = -1;                  // Start Vertex
int ve = 0;                   // End Vertex

bool dfs(int v, int p = -1) {
    u[v] = 1;

    for (auto &to : g[v]) {
        if (to == p) continue;
        if (u[to] == 0 && dfs(to)) {
            p[to] = v;
            return true;
        }
        else if (u[to] == 1) {
            vs = to;
            ve = v;
            return true;
        }
    }
    
    u[v] = 2;
    return false;
}

bool find_cycle(int v) {
    if (dfs(v)) {
        for (int w = ve; w != vs; w = p[w])
            c.push_back(w);
        c.push_back(vs);
        reverse(all(c));
        return true;
    }
    else
        return false;
}