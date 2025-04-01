#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, f, source, sink; cin >> n >> m >> f >> source >> sink;
    vector<vector<tuple<long long, int, int>>> adjL(n);
    for (int i = 0; i < m; ++i) {
        long long w;
        int u, v; cin >> u >> v >> w;
        adjL[u].push_back({v, w, 0});
        adjL[v].push_back({u, w, 0});
    }

    for (int i = 0; i < f; ++i) {
        int u, v; cin >> u >> v;
        adjL[u].push_back({v, 0, 1});
    }

    vector<vector<long long>> dist (2, vector<long long>(n, -1));
    dist[0][source] = 0;
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> q;
    q.push({0, source, 0});
    while (!q.empty()) {
        auto [d, u, b] = q.top(); q.pop();
        if (d > dist[b][u] && dist[b][u] != -1) continue;
        for (auto [v, w, p] : adjL[u]) {
            if (p + b >= 2 || (dist[b + p][v] != -1 && d + w >= dist[b + p][v])) continue;
            dist[p + b][v] = d + w;
            q.push({d + w, v, p + b});
        }
    }
    cout << min(dist[0][sink], dist[1][sink]) << endl;

}