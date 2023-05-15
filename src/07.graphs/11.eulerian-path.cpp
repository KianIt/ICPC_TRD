// Theme: Eulerian Path (All Edges)
// Algorithm: Iterative Method
// Complexity: O(M)

vector<vector<int>> g;          // Graph, Matrix
vector<int> eul;                // Eulerian Path

// 0 - path not exist
// 1 - cycle exits
// 2 - path exists
int euler_path(int n) {
    vector<int> deg;            // Vertex Degrees
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; ++j)
            deg[i] += g[i][j];

    int v1 = -1, v2 = -1;
    for (int i = 0; i < n; i++)
        if (deg[i] & 1)
            if (v1 == -1) v1 = i;
            else if (v2 == -1) v2 = i;
            else return 0;

    if (v1 != -1) { g[v1][v2]++; g[v2][v1]++; }

    int first = 0; while (!deg[first]) first++;

    stack<int> st; st.push(first);

    while (!st.empty()) {
        int v = st.top();
        int i; for (i = 0; i < n && !g[v][i]; i++);
        if (i == n) {
            eul.push_back(v);
            st.pop();
        }
        else {
            g[v][i]++; g[i][v]++;
            st.push(i);
        }
    }

    int res = 2;

    if (v1 != -1) {
        res = 1;

        for (int i = 0; i + 1 < eul.size(); i++)
            if (eul[i] == v1 && eul[i + 1] == v2 || eul[i] == v2 && eul[i + 1] == v1) {
                vector<int> t_eul;
                for (int j = i + 1; j < eul.size(); j++) t_eul.push_back(eul[j]);
                for (int j = 1; j <= i; j++) t_eul.push_back(eul[j]);
                eul = t_eul;
                break;
            }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (g[i][j]) return 0;

    return res;
}