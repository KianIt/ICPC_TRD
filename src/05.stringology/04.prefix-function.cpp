// Theme: Prefix function
// Alrotihm: Prefix Function Algoritms
// Complexity: O(N)

auto pref_func(const string &s) {
    int n = s.length();
    vector<int> pi(n);

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        
        if (s[i] == s[j]) j++;
        
        pi[i] = j;
    }

    return pi;
}