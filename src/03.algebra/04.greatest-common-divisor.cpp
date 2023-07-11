// Theme: Greatest Common Divisor

// Alrotihm: Simple Euclidean Algorithm
// Complexity: O(log(N))

int gcd(int a, int b) {
    while (a && b)
        a > b ? a %= b : b %= a;
    return a + b;
}

// Alrotihm: Extended Euclidean Algorithm
// Complexity: O(log(N))

// Idea
// d = gcd(a, b)
// x * a + y * b = d
// returns {d, x, y}

vector<int> euclid(int a, int b) {
    if (!a) return { b, 0, 1 };
    auto v = euclid(b % a, a);
    int d = v[0], x = v[1], y = v[2];
    return { d, y - (b / a) * x, x };
}