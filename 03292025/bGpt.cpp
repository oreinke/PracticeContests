#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX;

int main() {
    int n, m, f, source, sink; 
    cin >> n >> m >> f >> source >> sink;
    
    vector<vector<tuple<long long, int, int>>> adjL(n);
    for (int i = 0; i < m; ++i) {
        long long w;
        int u, v; 
        cin >> u >> v >> w;
        adjL[u].push_back({v, w, 0});
        adjL[v].push_back({u, w, 0});
    }
    for (int i = 0; i < f; ++i) {
        int u, v; 
        cin >> u >> v;
        adjL[u].push_back({v, 0, 1});
    }
    
    vector<vector<long long>> dist(2, vector<long long>(n, INF));
    dist[0][source] = 0;  // Start with no flight used, cost 0.
    
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> q;
    q.push({0, source, 0});
    
    while (!q.empty()) {
        auto [d, u, b] = q.top(); 
        q.pop();
        if (d > dist[b][u]) continue;
        for (auto [v, w, p] : adjL[u]) {
            if (b + p >= 2) continue;  
            int ns = b + p; 
            long long nd = d + w;
            if (nd >= dist[ns][v]) continue;
            dist[ns][v] = nd;
            q.push({nd, v, ns});
        }
    }
    
    long long ans = min(dist[0][sink], dist[1][sink]);
    cout << (ans == INF ? -1 : ans) << endl;  

    return 0;
}
