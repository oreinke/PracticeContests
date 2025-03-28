#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int n, m; cin >> n >> m;
        vector<set<pair<int, int>>> adjL(n);
        for (int i = 0; i < m; ++i) {
            int u, v, w; cin >> u >> v >> w;
            u--; v--;
            adjL[u].insert({w, v});
            adjL[v].insert({w, u});
        }

        vector<bool> visited (n, false);
        int cost = 0;
        int numConnected = 1;
        visited[0] = true;
        priority_queue<pair<int, int>> pq;
        for (auto [w, v] : adjL[0]) {
            pq.push({-w, v});
        }

        while (!pq.empty()) {
            auto [w, u] = pq.top(); pq.pop();
            if (!visited[u]) {
                cost += -1 * w;
                visited[u] = true;
                numConnected++;
                for (auto [d, v] : adjL[u]) {
                    pq.push({-d, v});
                }
            }
        }

        if (numConnected < n) {
            printf("Campus #%d: I'm a programmer, not a miracle worker!\n", tc);
        }
        else {
            printf("Campus #%d: %d\n", tc, cost);

        }

    }
}