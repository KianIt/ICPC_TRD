// Theme: Maximum Matching 
// Algorithm: Kuhn's Algorithm
// Complexity: O(N^3)

vector<vector<int>> g;  // Graph, N -> K 
vector<int> u;          // Used

bool kuhn(int v) {
    if (u[v]) return false;
    u[v] = true;
    for (auto &to : g[v]) {
        if (mt[to] == -1 || kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

auto maxmatch(int n, int k) {    
    vector<int> mt;           // Edges, From Right Ro Left
    mt.assign(k, -1);

    for (int i = 0; i < n; i++) {
        u.assign(n, 0);
        kuhn(i);
    }

    return mt;
}