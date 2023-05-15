// Theme: Combination Number

// Alrotihm: Online Multiplication-Division
// Complexity: O(k)

int C(int n, int k) {               // C_n^k - from n by k
    int res = 1;
    
    for (int i = 1; i <= k; i++) {
        res *= n - k + i;
        res /= i;
    }
    
    return res;
}

// Alrotihm: Pascal Triangle Preprocessing
// Complexity: O(N^2)

auto pascal(int n) {
    vector<vector<int>> C(n + 1, vector<int>(n + 1, 1));    // C[i][j] = C_i+j^i
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < n + 1; j++)
            C[i][j] = C[i - 1][j] + C[i][j - 1];

    return C;
}