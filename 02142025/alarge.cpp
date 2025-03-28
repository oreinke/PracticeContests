#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int n, m, limit; cin >> n >> m >> limit;
        vector<set<tuple<int, long long, int>>> adjL (n);
        for (int i = 0; i < m; ++i) {
            int u, v, c, w; cin >> u >> v >> c >> w;
            u--; v--;
            adjL[u].insert({v, w, c});
            adjL[v].insert({u, w, c});
        }
        

        priority_queue<tuple<int, long long, int>, vector<tuple< int, long long, int>>, greater<tuple< int, long long, int>>> pq;
        // for (auto [w, k, u] : adjL[0]) {
        //     pq.emplace(w, k, u);
        // }
        pq.emplace(0, 0, 0);
        vector<vector<long long>> distance (n, vector<long long> (limit + 1, -1));
        for (int i = 0; i <= limit; ++i) {
            distance[0][i] = 0;
        }
        while (!pq.empty()) {
            auto [u, w, k] = pq.top(); pq.pop();
            if (distance[u][k] != -1 && distance[u][k] < w) {
                continue;
            }   
            for (auto [v, w2, k2] : adjL[u]) {
                int addi = -1;
                // printf("%d %d\n", k, k2);
                for (int i = k + k2; i <= limit; ++i) {
                    if (distance[v][i] == -1 || ((w + w2) < distance[v][i])) {
                        distance[v][i] = w + w2;
                        if (addi == -1) {
                            addi = i;
                        }
                        
                    }
                }
                if (addi != -1) {
                    // printf("Adding edge from %d to %d with w: %d and cnt: %d\n", u, v, w + w2, k + k2);
                    pq.emplace(v, w + w2, k + k2);
                }
            }
        }
        long long lowest = -1;
        for (int i = 0; i <= limit; ++i) {
            if (distance[n - 1][i] == -1) continue;
            else if (lowest = -1) {
                lowest = distance[n - 1][i];
            }
            else {
                lowest = min(lowest, distance[n - 1][i]);
            }
        }
        cout << lowest << endl;
    }
}