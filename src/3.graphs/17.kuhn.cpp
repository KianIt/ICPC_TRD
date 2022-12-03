int n, k;
vector < vector<int> > g;
vector<int> mt;
vector<bool> used;
bool kuhn(int v) {
    if (used[v])  return false;
    used[v] = true;
    for (auto i : g[v]) {
        int to = i;
        if (mt[to] == -1 || kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}
signed main() {
    cin >> n >> m >> k;
    g.resize(n);
    for (int i = 0; i < k; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        g[temp1 - 1].push_back(temp2 - 1);

    }
    mt.assign(m, -1);
    for (int v = 0; v < n; ++v) {
        used.assign(n, false);
        kuhn(v);
    }
}