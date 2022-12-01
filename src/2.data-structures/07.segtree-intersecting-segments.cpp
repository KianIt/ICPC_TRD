struct sum_tree {};
signed main() {
    sum_tree tr;
    int n; cin >> n;
    tr.init(2 * n);
    vector<int> pos(n, -1), ans(n, 0), A(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> A[i];
    for (int i = 0; i < 2 * n; i++) {
        int a = A[i] - 1;
        if (pos[a] == -1) {
            pos[a] = i;
            tr.set(pos[a], 1);
        }
        else {
            ans[a] = tr.sum(pos[a] + 1, i);
            tr.set(pos[a], 0);
            pos[a] = 0;
        }
    }
    pos.assign(n, -1); reverse(A.begin(), A.end());
    for (int i = 0; i < 2 * n; i++) {
        int a = A[i] - 1;
        if (pos[a] == -1) {
            pos[a] = i;
            tr.set(pos[a], 1);
        }
        else {
            ans[a] += tr.sum(pos[a] + 1, i);
            tr.set(pos[a], 0);
            pos[a] = 0;
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}