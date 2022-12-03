struct seg_adding_tree_diff {
    // sum_tree + difference array
    void add(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] += v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) add(i, v, 2 * x + 1, lx, m);
        else add(i, v, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
    void add(int l, int r, int v) {
        add(l, v, 0, 0, size);
        add(r, -v, 0, 0, size);
        return;
    }
    long long get(int i) {
        return sum(0, i + 1);
    }
};