template<class T>
class prime {
private:
    std::vector<unsigned>pr;
    std::vector<T>lp;
public:
    prime() {};
    prime(unsigned limit) {
        lp.resize(++limit, 0);
        pr.clear();
        pr.push_back(1);
        for (unsigned i = 2;i < limit;++i) {
            register unsigned max_index = lp[i];
            if (max_index == 0) {
                max_index = pr.size();
                pr.push_back(i);
            }
            register unsigned d;
            for (unsigned j = 1;j <= max_index && (d = i * pr[j]) < limit;++j)
                lp[d] = j;
        }
    }
    bool is_prime(unsigned number) {
        return number < lp.size() && !lp[number];
    }
    unsigned sequence_number(unsigned prime_number) {
        if (!is_prime(prime_number))
            return 0;
        return std::lower_bound(pr.begin(), pr.end(), prime_number) - pr.begin();
    }
    unsigned return_prime(unsigned sequence_number) {
        if (sequence_number && sequence_number < pr.size())
            return pr[sequence_number];
        return 0;
    }
    unsigned least_divisor(unsigned number) {
        if (number >= lp.size())
            return 0;
        if (is_prime(number))
            return number;
        return pr[lp[number]];
    }
    unsigned limit() {
        return lp.size() - 1;
    }
    std::vector<unsigned> factorize(unsigned number) {
        std::vector<unsigned> v;
        if (number < lp.size()) {
            while (!is_prime(number)) {
                v.push_back(pr[lp[number]]);
                number /= pr[lp[number]];
            }
            v.push_back(number);
        }
        return v;
    }
};
//.....................................................................
signed main()
{
    int t = 1;
    cin >> t;
    int n = 1e7;
    vector<int>p(1e7 + 1, 0);
    vector<int>mass;
    for (int i = 2; i * i <= n; i++) {
        if (p[i] == 1) continue;
        if (i * i <= n) {
            for (int j = i * i; j <= n; j += i) {
                p[j] = 1;
            }
        }
    }
    for (int i = 2; i <= 1e7; ++i) {
        if (p[i] == 0) { // если 0 - число простое
            mass.push_back(i);
        }
    }
    while (t--)
    {
        int l = 0, r = 0;
        cin >> l >> r;
        int lx = lower_bound(mass.begin(), mass.end(), l) - mass.begin();
        int rx = lower_bound(mass.begin(), mass.end(), r + 1) - mass.begin();
        cout << rx - lx << endl;
    }
}
//.....................................................................
const int SQRT_MAXN = 10000; // корень из максимального значения N
const int S = 1e7+1;
bool nprime[SQRT_MAXN], bl[S];
int primes[SQRT_MAXN], cnt;

signed main() {

    int t = 1;
    cin >> t;
    int n = 1e7 + 1;
    int nsqrt = (int)sqrt(n + .0);
    for (int i = 2; i <= nsqrt; ++i)
        if (!nprime[i]) {
            primes[cnt++] = i;
            if (i * 1ll * i <= nsqrt)
                for (int j = i * i; j <= nsqrt; j += i)
                    nprime[j] = true;
        }

    int result = 0;
    vector<int> mass;
    for (int k = 0, maxk = n / S; k <= maxk; ++k) {
        memset(bl, 0, sizeof bl);
        int start = k * S;
        for (int i = 0; i < cnt; ++i) {
            int start_idx = (start + primes[i] - 1) / primes[i];
            int j = max(start_idx, (long long)2) * primes[i] - start;
            for (; j < S; j += primes[i])
                bl[j] = true;
        }
        if (k == 0)
            bl[0] = bl[1] = true;
        for (int i = 0; i < S && start + i <= n; ++i)
            if (!bl[i])
                mass.push_back(i);
    }
    while (t--) {
        int l = 0, r = 0;
        cin >> l >> r;
        int lx = lower_bound(mass.begin(), mass.end(), l) - mass.begin();
        int rx = lower_bound(mass.begin(), mass.end(), r + 1) - mass.begin();
        cout << rx - lx << endl;
    }
}