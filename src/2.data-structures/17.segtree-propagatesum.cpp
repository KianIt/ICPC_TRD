struct propagatesum_tree {
    struct node {
        int set;
        int sum;
    };
    int MOD = 1e9 + 7;
    int NETRAL = 0;
    int NO_OPERATION = LLONG_MIN;
    int operat_modify(int a, int b, int len) {
        if (b == NO_OPERATION) return a;
        return b * len;
    }
    int operat_min(int a, int b) {
        return a + b;
    }
    void propagate(int x, int lx, int rx) {
        if (tree[x].set == NO_OPERATION || rx - lx == 1) return;
        int m = (lx + rx) / 2;
        tree[2 * x + 1].set = operat_modify(tree[2 * x + 1].set, tree[x].set, 1);
        tree[2 * x + 1].sum = operat_modify(tree[2 * x + 1].sum, tree[x].set, m - lx);
        tree[2 * x + 2].set = operat_modify(tree[2 * x + 1].set, tree[x].set, 1);
        tree[2 * x + 2].sum = operat_modify(tree[2 * x + 1].sum, tree[x].set, rx - m);
        tree[x].set = NO_OPERATION;
    }
    int suma(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (l >= rx || lx >= r) return NETRAL;
        if (lx >= l && rx <= r) return tree[x].sum;
        int m = (lx + rx) / 2;
        int m1 = suma(l, r, 2 * x + 1, lx, m);
        int m2 = suma(l, r, 2 * x + 2, m, rx);
        int res = operat_min(m1, m2);
        return res;
    }

    int suma(int l, int r) {
        return suma(l, r, 0, 0, size);
    }
    void modify(int l, int r, int v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (l >= rx || lx >= r) return;
        if (lx >= l && rx <= r) {
            tree[x].set = operat_modify(tree[x].set, v, 1);
            tree[x].sum = operat_modify(tree[x].sum, v, (rx - lx));
            return;
        }
        int m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);
        tree[x].sum = operat_min(tree[2 * x + 1].sum, tree[2 * x + 2].sum);
    }

    void modify(int l, int r, int v) {
        return modify(l, r, v, 0, 0, size);
    }
};