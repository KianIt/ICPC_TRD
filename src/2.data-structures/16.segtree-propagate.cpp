struct propagate_tree {
    long long get(int i, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (rx - lx == 1) return tree[x];
        int m = (lx + rx) / 2;
        if (i < m) return get(i, 2 * x + 1, lx, m);
        else return get(i, 2 * x + 2, m, rx);
    }
    long long get(int i) {
        return get(i, 0, 0, size);
    }
    void propagate(int x, int lx, int rx) {
        if (tree[x] == NO_OPERATION) return;
        if (rx - lx == 1) return;
        tree[2 * x + 1] = tree[x];
        tree[2 * x + 2] = tree[x];
        tree[x] = NO_OPERATION;
    }
    void modify(int l, int r, int v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (l >= rx || lx >= r) return;
        if (lx >= l && rx <= r) {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);
    }

    void modify(int l, int r, int v) {
        return modify(l, r, v, 0, 0, size);
    }
};