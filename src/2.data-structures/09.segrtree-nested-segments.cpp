struct tree_sum {};
signed main() {
    tree_sum tree;
    int n, m;
    cin >> n;
    tree.init(2 * n);
    vector<int> pos(n, -1), otv(n, 0);
    for (int i = 0; i < 2 * n; i++) {
        int a; cin >> a; --a;
        if (pos[a] == -1) {
            pos[a] = i;
        }
        else {
            otv[a] = tree.sum(pos[a], i);
            tree.set(pos[a], 1);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << otv[i] << " ";
    }
}