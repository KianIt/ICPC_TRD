struct addsum_tree {
    struct node {
        int set;
        int sum;
    };
    const int MOD = 1e9 + 7;
    const int NETRAL = 0;
    int operat_modify(int a, int b, int len) {
        return a + len * b;
    }
    int operat_min(int a, int b) {
        return (a + b);
    }
    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        tree.assign(2 * size - 1, { 0, 0 });
    }
    int suma(int l, int r, int x, int lx, int rx) {
        if (l >= rx || lx >= r) {
            return NETRAL;
        }
        if (lx >= l && rx <= r) {
            return tree[x].sum;
        }
        int m = (lx + rx) / 2;
        int m1 = suma(l, r, 2 * x + 1, lx, m);
        int m2 = suma(l, r, 2 * x + 2, m, rx);
        int res = operat_min(m1, m2);
        return operat_modify(res, tree[x].set, min(rx, r) - max(lx, l));
    }

    int suma(int l, int r) {
        return suma(l, r, 0, 0, size);
    }
    void modify(int l, int r, int v, int x, int lx, int rx) {
        if (l >= rx || lx >= r) {
            return;
        }
        if (lx >= l && rx <= r) {
            tree[x].set = operat_modify(tree[x].set, v, 1);
            tree[x].sum = operat_modify(tree[x].sum, v, (rx - lx));
            return;
        }
        int m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);
        tree[x].sum = operat_min(tree[2 * x + 1].sum, tree[2 * x + 2].sum);
        tree[x].sum = operat_modify(tree[x].sum, tree[x].set, (rx - lx));
    }
    void modify(int l, int r, int v) {
        return modify(l, r, v, 0, 0, size);
    }
};