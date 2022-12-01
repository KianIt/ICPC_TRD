int main() {
    map <int, vector <pair<int, int>>> mass;
    vector <int> check;
    vector <int> result;
    vector <pair<int, int>> way;
    int n = 0, m = 0, third = 0, temp = 10e5, top = 10e5, sum = 0, count = 0, first = 0, second = 0, parent = 0, child = 0;
    cin >> n >> m;
    
    check.resize(n - 1);
    result.push_back(0);
    
    for (int i = 0; i < n - 1; i++)
        check[i] = i + 1;
    
    for (int i = 0; i < m; i++) {
        cin >> first >> second >> third;
        first--;
        second--;
        mass[first].push_back(make_pair(second, third));
        mass[second].push_back(make_pair(first, third));
    }
    
    while (!check.empty()) {
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < mass[result[i]].size(); j++) {
                if (mass[result[i]][j].second < temp && find(check.begin(), check.end(), mass[result[i]][j].first) != check.end()) {
                    temp = mass[result[i]][j].second;
                    top = mass[result[i]][j].first;
                    parent = result[i];
                }
            }
        }
        
        result.push_back(top);
        for (int k = 0; k < check.size(); k++) {
            if (check[k] == top) {
                count = k;
                break;
            }
        }
        
        check.erase(check.begin() + count);
        sum += temp;
        count = 0;
        temp = 10e5;
        top = 10e5;
    }
    cout << sum << endl;
}
