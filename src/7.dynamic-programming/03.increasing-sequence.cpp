signed increasing_sequence() {
    int n = 0;
    cin >> n;
    vector <int> mass(n, 0), dp(n + 1, 10e8), path, pos(n), prev(n);

    for (int i = 0; i < n; i++) cin >> mass[i];
    dp[0] = -10e8;
    pos[0] = -1;
    int len = 0;
    
    for (int i = 0; i < n; i++) {
        int j = upper_bound(dp.begin(), dp.end(), mass[i]) - dp.begin();
        if (dp[j - 1] < mass[i] && mass[i] < dp[j]) {
            dp[j] = mass[i];
            pos[j] = i;
            prev[i] = pos[j - 1];
            len = max(len, j);
        }
    }
    
    cout << len << endl;
    int p = pos[len];
    while (p != -1) {
        path.push_back(mass[p]);
        p = prev[p];
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << ' ';
    }
    cout << '\n';
}