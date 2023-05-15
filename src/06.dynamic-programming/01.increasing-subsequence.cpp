// Theme: Longest Increasing Subsequence
// Alrotihm: Binary Search Algorithm
// Complexity: O(N)

auto inc_seq(const vector<int> &a) {
    int n = a.size();
    vector<int> dp(n + 1, inf), pos(n + 1), prev(n), path;

    int len = 0;
    dp[0] = -inf;
    pos[0] = -1;

    for (int i = 0; i < n; i++) {
        int j = distance(dp.begin(), upper_bound(all(dp), a[i]));
        if (dp[j - 1] < a[i] && a[i] < dp[j]) {
            dp[j] = a[i];
            pos[j] = i;
            prev[i] = pos[j - 1];
            len = max(len, j);
        }
    }

    int p = pos[len];
    while (p != -1) {
        path.push_back(a[p]);
        p = prev[p];
    }
    reverse(path.begin(), path.end());

    return path;
}