vector <int> result;

void getResult(int k, int s, vector<vector<int>> &dp, vector<int> &mass) {
    if (dp[k][s] == 0)
        return;
    if (dp[k][s - 1] == dp[k][s])
        getResult(k, s - 1, dp, mass);
    else {
        getResult(k - mass[s - 1], s - 1, dp, mass);
        result.push_back(s);
    }
}

signed backpack() {
    int n, w;
    cin >> n >> w;
    vector<int> m(n + 1), c(n + 1);

    int min_w = 0;
    for (int i = 0; i < n; ++i) {
        cin >> m[i] >> c[i];
        min_w += m[i];
    }
    min_w = min(min_w, w); // чтобы не было ml
    
    vector<vector<int>> dp(min_w + 1, vector<int>(n + 1, 0));
    for (int k = 1; k < n + 1; k++) {
        for (int i = 0; i < min_w + 1; i++) {
            // цикл до count <= (min(kolvo_predm[k (возможно сделать - 1)], min_w / c[i]) + 1) - с огранич. количеством предметов
            for (int count = 0; count <= 1; count++) {
                // если неограниченное количество предметов за O(nW)
                // dp[i][k] = dp[i][k - 1]
                // if (m[k] <= i) {
                //     dp[i][k] = max(dp[i][k], dp[i][j - m[k]] + c[k - 1]);
                // }
                if (i - m[k - 1] * count >= 0) {
                    dp[i][k] = max(dp[i][k], dp[i - m[k - 1] * count][k - 1] + c[k - 1] * count);
                }
            }
        }
    }
    
    cout << dp[min_w][n] << endl;
    getResult(min_w, n, dp, m);
    for (int i = 0; i < result.size(); i++) {
        if (result[i] != 0) {
            cout << result[i] << ' ';
        }
    }
}