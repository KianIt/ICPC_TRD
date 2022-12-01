signed ribbon() {
    int n;
    cin >> n;
    int count_a = 0, count_b = 0, count_c = 0;
    vector<int> path(3), dp(n + 1, -10e8), mass(n + 1, -1);

    cin >> path[0] >> path[1] >> path[2];
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            if (i - path[j] >= 0) {
                dp[i] = max(dp[i], dp[i - path[j]] + 1);
                if (dp[i] == (dp[i - path[j]] + 1))
                    mass[i] = path[j];
            }
        }
    }
    if (dp[n] != -10e8)
        cout << dp[n] << endl;
    else {
        cout << 0 << endl;
        cout << 0 << " " << 0 << " " << 0 << endl;
        return 0;
    }
    for (int i = n; i >= 1;) {
        if (n <= 0)
            break;
        if (mass[i] == path[0])
            count_a++;
        if (mass[i] == path[1])
            count_b++;
        if (mass[i] == path[2])
            count_c++;
        
        n -= mass[i];
        i -= mass[i];
    }
    cout << count_a << " " << count_b << " " << count_c << '\n';
}