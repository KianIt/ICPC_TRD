// Theme: Fibonacci Sequence
// Alrotihm: Fibonacci Numbers With Matrix Exponentiation
// Complexity: O(log(N))

int fibonacci(int n) {
    row<int> first_three = { 0, 0, 1 };
    if (n <= 3) return first_three[n - 1];

    matrix<int> fib(2, row<int>(2, 0));
    fib[0][0] = 0; fib[0][1] = 1;
    fib[1][0] = 1; fib[1][1] = 1;

    row<int> last_two = { first_three[1], first_three[2] };

    fib = m_binpow(fib, n - 3);

    last_two = m_prod(fib, last_two);

    return last_two[1];
}