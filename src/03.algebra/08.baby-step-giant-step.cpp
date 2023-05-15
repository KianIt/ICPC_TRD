// Theme: Descrete Logarithm
// Alrotihm: Baby-Step Giant-Step Algorithm
// Complexity: O(sqrt(p)*log(p))
// Idea: 
// a ^ (x) = b (mod p), (a, p) = 1
// a ^ (i * m + j) = b (mod p), m = ceil(sqrt(p))
// a ^ (i * m) = b * a ^ (-j) (mod p)

int baby_giant_step(int a, int b, int p) {
    int m = ceil(sqrt(p)), _a = binpow(a, p - 2, p);                  // a ^ (-1) = a ^ (p - 2) mod p       

    unordered_map<int, int> s;
    for (int j = 0, t = b; j < m; j++, t = t * _a % p) s[t] = j;      // s[b * a ^ (-j)] = j

    for (int i = 0; i < m; i++) {                                      
        auto f = s.find(binpow(a, i * m, p));                         // s.find(a ^ (i * m))
        if (f != s.end()) return i * m + f->ss;                       // i * m + j
    }

    return -1;
}