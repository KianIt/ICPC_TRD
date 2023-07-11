// Theme: Discrete Fourier Transform

// Module (7 * (2 ^ 20) + 1)
// Primiive Root (5 ^ (2 ^ 20) == 1 mod 7340033)
// Inverse Primitive Root (5 * 4404020 == 1 mod 7340033)
// Maximum Degree Of Two (2 ^ 20)

const int mod = 7340033;
const int proot = 5;
const int proot_1 = 4404020;                    
const int pw = 1 << 20;                                          

// Alrotihm: Fast Fourier Transform (Inverse Roots)
// Complexity: O(N*log(N))

auto fft(vector<int> a, bool invert = 0) {
    // n = 2 ^ x
    int n = a.size();

    // Bit-Reversal Permutation (0000, 1000, 0100, 1100, 0010, ...)
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
         // Primitive Root Or Inverse Root (Inverse Transform)
        int lroot = invert ? proot_1 : proot;

        // Current Primitive Root
        lroot = binpow(lroot, pw / len, mod);

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
        int _n = binpow(n, mod - 2, mod);
        for (int i = 0; i < n; i++) a[i] = (a[i] * _n) % mod;
    }

    return a;
}

// Alrotihm: Fast Fourier Transform
// Complexity: O(N*log(N))

auto fft(vector<int> &a, bool invert = 0) {
    // n = 2 ^ x
    int n = a.size();

    // Bit-Reversal Permutation (0000, 1000, 0100, 1100, 0010, ...)
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        // Current Primitive Root
        int lroot = binpow(proot, pw / len, mod);

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
        reverse(a.begin() + 1, a.end());
        int _n = binpow(n, mod - 2, mod);
        for (int i = 0; i < n; i++) a[i] = (a[i] * _n) % mod;
    }

    return a;
}