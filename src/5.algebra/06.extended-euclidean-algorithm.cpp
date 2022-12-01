// ax + by = gcd(a,b)
void solve_eq(int a, int b, int &x, int &y, int &g) {
    if (b == 0) {
        x = 1;
        y = 0;
        g = a;
        return;
    }
    
    int xx, yy;
    solve_eq(b, a % b, xx, yy, g);
    
    x = yy;
    y = xx - yy * (a / b);
}

// ax + by = c
bool solve_eq(int a, int b, int c, int &x, int &y, int &g) {
    solve_eq(a, b, x, y, g);
    
    if (c % g != 0)
        return false;

    x *= c / g; y *= c / g;
    
    return true;
}

// finds a solution (x, y) so that x >= 0 and x is minimal
bool solve_eq_non_neg_x(int a, int b, int c, int &x, int &y, int &g) {
    if (!solve_eq(a, b, c, x, y, g))
        return false;
    
    int k = x * g / b;
    x = x - k * b / g;
    y = y + k * a / g;
    
    if (x < 0) {
        x += b / g;
        y -= a / g;
    }
    
    return true;
}