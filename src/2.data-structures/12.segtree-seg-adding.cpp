struct seg_adding_tree_diff {
    long long get(int i, int x, int lx, int rx) {
        if (rx - lx == 1) return tree[x];
        int m = (lx + rx) / 2;
        if (i < m) return get(i, 2 * x + 1, lx, m) + tree[x];
        else return get(i, 2 * x + 2, m, rx) + tree[x];
    }
    long long get(int i) {
        return get(i, 0, 0, size);
    }
    void add(int l, int r, int v, int x, int lx, int rx) {
        if (l >= rx || lx >= r) return;
        if (lx >= l && rx <= r) {
            tree[x] += v;
            return;
        }
        int m = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, m);
        add(l, r, v, 2 * x + 2, m, rx);
    }
    void add(int l, int r, int v) {
        return add(l, r, v, 0, 0, size);
    }
};