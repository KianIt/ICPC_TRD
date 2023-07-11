// Theme: Euler's Totient Function
// Alrotihm: Euler's Product Formula
// Complexity: O(sqrt(N))

// Idea: 
// phi = n(1 - 1 / pi), i = 1,...

int phi(int n) {
    if (n == 1) return 1;
    
    auto f = factors(n);

    int res = n;
    for (auto &p : f)
        res -= res / p;

    return res;
}