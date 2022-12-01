signed main() {
    int inf = 1e18;
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    
    for (int i = 0; i < m; i++) {
        int to = 0, from = 0, len = 0;
        cin >> from >> to >> len;
        g[from - 1].push_back({ to - 1, len });
        g[to - 1].push_back({ from - 1, len });
    }
    
    vector<int> d(n, inf);
    vector<int> p(n);
    int from = 0, to = 0;
    d[0] = 0;
    priority_queue<pair<int, int>> q;
    q.push({ 0, 0 });
    
    while (!q.empty()) {
        int v = q.top().second;
        int cur_d = -q.top().first;
        q.pop();
        if (cur_d > d[v]) continue;
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i].first;
            int length = g[v][i].second;
            if (d[v] + length < d[to]) {
                d[to] = d[v] + length;
                p[to] = v;
                q.push({ -d[to], to });
            }

        }
    }
    
    if (d[n - 1] == inf) {
        cout << -1 << endl;
        return 0;
    }
    if (!d[n - 1]) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> way;
    for (int v = n - 1; v != 0; v = p[v])
        way.push_back(v + 1);
    way.push_back(1);
    
    for (int i = way.size() - 1; i >= 0; i--)
        cout << way[i] << " ";
}