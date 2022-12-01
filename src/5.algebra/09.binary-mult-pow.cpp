int binmult(int a, int b) {
    int res = 0;
    while (b) {
        if (b & 1)
            res += a;
        a *= 2;
        b >>= 1;
    }
    return res;
}

int binpow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1)
            res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}