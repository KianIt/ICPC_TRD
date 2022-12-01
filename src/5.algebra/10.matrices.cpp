vector<vector<int>> matrix_production(vector<vector<int>> &a, vector<vector<int>> &b, int mod=0) {
    vector<vector<int>> result(a.size(), vector<int>(b[0].size()));
    
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                if (mod) result[i][j] = (result + a[i][k] * b[k][j] % mod) % mod;
                else result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    
    return result;
}

// recursive pow
vector<vector<int>> fast_pow(vector<vector<int>> &a, int n, int mod) {
    if (n == 0) {
        vector<vector<int>> temp(a.size(), vector<int>(a[0].size()));
        for (int i = 0; i < a.size(); i++) {
            temp[i][i] = 1;
        }
        return temp;
    }
    if (n % 2 == 1) {
        vector<vector<int>> temp = fast_pow(a, n - 1, mod);
        return matrix_production(temp, a, mod);
    }
    else {
        vector<vector<int>> b = fast_pow(a, n / 2, mod);
        return matrix_production(b, b, mod);
    }
}

// iterative pow
vector<vector<int>> fast_pow(vector<vector<int>> &a, int n, int mod = 0) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) res[i] = 1;
    
    while (n) {
        if (n & 1) res = matrix_production(res, a, mod);
        a = matrix_production(a, a, mod);
        n >>= 1;
    }

    return res;
}