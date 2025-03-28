#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, q; cin >> n >> m >> q;
        // tuple : distance, destination, color
        vector<vector<tuple<int, int, char>>> adjL (n);
        for (int i = 0; i < m; ++i) {
            long long u, v, d; cin >> u >> v >> d;
            string c; cin >> c;
            // printf("u: %d, v: %d, d: %d\n", u,v,d);
            // cout << "Char: " <<c << endl;
            // fflush(stdout);
            u--;
            v--;
            adjL[u].push_back({d, v, c[0]});
            adjL[v].push_back({d, u, c[0]});
        }

        for (int i = 0; i < q; ++i) {
            // printf("here! t: %d, i: %d\n",t ,i);
            int sink; cin >> sink;
            sink--;
            string str; cin >> str;
            set<char> allowed;
            for (char c : str) allowed.insert(c);
            vector<long long> dist (n, -1);
            priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
            pq.push({0, 0});
            dist[0] = 0;
            int cnt = 1;
            while (!pq.empty()) {
                
                auto [w, u] = pq.top(); pq.pop();
                if (w > dist[u]) continue;
                if (!pq.empty()) {
                    printf("%d, %d\n", w, pq.top().first);
                }
                // printf("!%d!\n", cnt);
                // cnt++;
                // fflush(stdout);
                int cnt2 = 1;
                for (auto [d, v, c] : adjL[u]) {
                    
                //     printf("!%d!, u: %d, v: %d\n", cnt2,u, v);
                // cnt2++;
                // fflush(stdout);
                    if (allowed.count(c) == 0 || (dist[v] != -1 && d + w >= dist[v])) continue;
                    // cout << "hit\n" << endl;
                    // fflush(stdout);
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
                
            }
            // printf("here\n");
            // fflush(stdout);
            cout << dist[sink] << endl;
        }
    }
}