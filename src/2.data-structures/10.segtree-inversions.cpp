struct sum_tree { };
signed main() {
    sum_tree tree;
    int n; cin >> n;
    tree.init(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        cout << tr.sum(a, n) << endl;
        tr.set(a - 1, 1);
    }
}