// Theme: Shortest Paths From Vertex
// Alrotihm: Dijkstra's Algorithm
// Complexity: O(M*log(N))

const int inf = 1e18;                   // Infinity Value

vector<vector<pair<int, int>>> g;       // Graph <Vertex, Length>
vector<int> d;                          // Result Distances
vector<int> p;                          // Path Back

void dijkstra(int v, int n) {
    priority_queue<pair<int, int>> q;   // Priority Queue <-Distance, Vetex>
    
    d.assign(n, inf); d[v] = 0;
    p.assign(n, 0);
    
    q.push({ 0, v });

    while (q.size()) {
        int dist = -q.top().ff, w = q.top().ss; q.pop();
        if (dist > d[w]) continue;
        
        for (auto &to: g[w])
            if (d[w] + to.ss < d[to]) {
                d[to] = d[w] + to.ss;
                p[to] = w;
                q.push({ -d[to], to });
            }
    }
}