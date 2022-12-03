struct inversion_tree {
    // sum_tree
    int find(int k, int x, int lx, int rx) {
        if (rx == lx + 1) {
            return lx;
        }
        int m = (rx + lx) / 2;
        if (k < tree[2 * x + 2]) return find(k, 2 * x + 2, m, rx);
        else return find(k - tree[2 * x + 2], 2 * x + 1, lx, m);
    }
    int find(int k) {
        return find(k, 0, 0, size);
    }
};
signed main() {
    inversion_tree tree;
    int n, m;
    cin >> n;
    vector<int> A(n), P(n), E(n, 1);
    tree.build(E);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int pos = 0;
    for (int i = n - 1; i >= 0; i--) {
        pos = tree.find(A[i]);
        P[i] = pos + 1;
        tree.set(pos, 0);
    }
    for (int i = 0; i < n; i++) {
        cout << P[i] << " ";
    }
}