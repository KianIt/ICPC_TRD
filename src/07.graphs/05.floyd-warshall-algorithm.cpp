// Theme: Shortest Paths From All Vertices
// Alrotihm: Floyd-Warshall's
// Complexity: O(N^3)

const int inf = 1e18;

vector<vector<int>> g;      // Graph, Matrix

auto fwa(int n) {
    vector<vector<int>> d(n, vector<int>(n, inf));

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (d[i][k] != inf && d[k][j] != inf)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    return d;
}