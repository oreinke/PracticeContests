#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, a, b; cin >> n >> a >> b;
        vector<int> rooms (n);
        vector<vector<pair<int, int>>> adjL (n);
        for (auto &x : rooms) cin >> x;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int w =  a * abs((rooms[i] % 100) - (rooms[j] % 100)) + b * abs((rooms[i] / 100) - (rooms[j] / 100));
                adjL[j].push_back({w, i});
                adjL[i].push_back({w, j});                
            }
        }

        vector<bool> connected (n, false);
        connected[0] = true;
        int cnt = 1, cost = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto [w, v] : adjL[0]) pq.push({w, v});
        while (cnt < n && !pq.empty()) {
            auto [w, v] = pq.top(); pq.pop();
            if (connected[v]) continue;
            cost += w;
            connected[v] = true;
            // printf("edge added to %d, w/ weight %d\n", v, w);
            for (auto [d, node] : adjL[v])  {
                if (connected[node]) continue;
                pq.push({d, node});
            }
        }

        cout << cost << endl;

    }
}