struct min_count_tree {
    struct node {
        int min;
        int count;
    };
    node combine(node a, node b) {
        if (a.min < b.min) return a;
        if (a.min > b.min) return b;
        return { a.min, a.count + b.count };
    }
    const node zero = { inf, 0 };
    vector<node> tree;
    int size;
    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size - 1, { 0, 0 });
    }
    void build(vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size())
                tree[x] = { a[lx], 1 };
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
    }
    void build(vector<int> &a) {
        init(a.size());
        build(a, 0, 0, size);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = { v, 1 };
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) set(i, v, 2 * x + 1, lx, m);
        else set(i, v, 2 * x + 2, m, rx);
        tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }
    node calc(int l, int r, int x, int lx, int rx) {
        if (rx <= l || r <= lx) return zero;
        if (l <= lx && rx <= r) return tree[x];
        int m = (lx + rx) / 2;
        node calc1 = calc(l, r, 2 * x + 1, lx, m);
        node calc2 = calc(l, r, 2 * x + 2, m, rx);
        return combine(calc1, calc2);
    }
    node calc(int l, int r) {
        return calc(l, r, 0, 0, size);
    }
};