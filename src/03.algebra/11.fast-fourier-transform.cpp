// Theme: Discrete Fourier Transform
// Alrotihm: Fast Fourier Transform
// Complexity: O(N*log(N))

const int mod = 7340033;                        // Module (7 * (2 ^ 20) + 1)
const int proot = 5;                            // Primary Root (5 ^ (2 ^ 20) == 1 mod 7340033)
const int proot_1 = 4404020;                    // Inverse Primary Root (5 * 4404020 == 1 mod 7340033)
const int pw = 1 << 20;                         // Maximum Degree Of Two (2 ^ 20)

// const int mod = 998244353;                      // Module (7 * 17 * (2 ^ 23) + 1)
// const int proot = 31;                           // Primary Root (31 ^ (2 ^ 23) == 1 mod 998244353)
// const int proot_1 = 128805723;                  // Inverse Primary Root (31 * 128805723 == 1 mod 998244353)
// const int pw = 1 << 23;                         // Maximum Degree Of Two (2 ^ 23)

auto fft(vector<int> &a, bool invert = 0) { 
    int n = a.size();                           // n = 2 ^ x

    for (int i = 1, j = 0; i < n; i++) {        // Bit-Reversal Permutation (0000, 1000, 0100, 1100, 0010, ...)
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {    
        int lroot = invert ? proot_1 : proot;  // Prmary Root Or Inverse Root (Inverse Transform)

        for (int i = len; i < pw; i <<= 1)
            lroot = (lroot * lroot) % mod;     // Current Primary Root

        for (int i = 0; i < n; i += len) {
            int root = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i + j], v = a[i + j + len / 2] * root % mod;
                a[i + j] = (u + v) % mod;
                a[i + j + len / 2] = (u - v + mod) % mod;
                root = (root * lroot) % mod;
            }
            
        }
    }

    if (invert) {
        int _n = 1;
        for (int i = 1; i <= mod - 2; i++) _n = (_n * n) % mod;
        for (int i = 0; i < n; i++) a[i] = (a[i] * _n) % mod;
    }
}