struct max_sum_tree {
    //tree_min_count
    struct node {
        long long seg, pref, suf, sum;
    };
    node one_element(int x) {
        return {
            max(x,0LL),  //seg
            max(x,0LL),  //pref
            max(x,0LL),  //suf
            x            //sum
        };
    }
    node combine(node a, node b) {
        return {
            /*seg*/  max(a.seg, max(b.seg, a.suf + b.pref)),
            /*pref*/ max(a.pref, a.sum + b.pref),
            /*suf*/  max(b.suf, b.sum + a.suf),
            /*sum*/  a.sum + b.sum
        };
    }
    const node zero = { 0, 0, 0, 0 };
};