signed palindromes() {
    string s = "";
    cin >> s;
    vector <vector<int>> dp(s.length(), vector<int>(s.length(), 0));
    vector <vector<int>> pal(s.length(), vector<int>(s.length(), 1));

    for (int i = s.length() - 1; i >= 0; i--) {
        for (int j = i; j < s.length(); j++)
            if (i == j) {
                dp[i][j] = 1;
            }
            else {
                pal[i][j] = pal[i + 1][j - 1] & (s[i] == s[j]);
                dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + pal[i][j];
            }
    }
}
