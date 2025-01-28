#include <bits/stdc++.h>
#define _USE_MATH_DEFINES

using namespace std;


int main() {
    int h, w; cin >> h >> w;
    map<tuple<int, int, int>, set<tuple<int,int,int,double>>> adj;

    string prevRow;
    for (int i = 0; i < h; ++i) {
        string row; cin >> row;
        for (int j = 0; j < w; ++j) {
            adj[{i, j, 0}].insert({i, j, 1, 5});
            adj[{i, j, 0}].insert({i, j, 7, 5});
            adj[{i, j, 7}].insert({i, j, 6, 5});
            adj[{i, j, 6}].insert({i, j, 5, 5});
            adj[{i, j, 5}].insert({i, j, 4, 5});
            adj[{i, j, 3}].insert({i, j, 4, 5});
            adj[{i, j, 1}].insert({i, j, 2, 5});
            adj[{i, j, 2}].insert({i, j, 3, 5});
            if (row[j] == 'O') {
                adj[{i, j, 1}].insert({i, j, 7, M_PI * 2.5});
                adj[{i, j, 7}].insert({i, j, 1, M_PI * 2.5});
                adj[{i, j, 1}].insert({i, j, 3, M_PI * 2.5});
                adj[{i, j, 3}].insert({i, j, 1, M_PI * 2.5});
                adj[{i, j, 3}].insert({i, j, 5, M_PI * 2.5});
                adj[{i, j, 5}].insert({i, j, 3, M_PI * 2.5});
                adj[{i, j, 5}].insert({i, j, 7, M_PI * 2.5});
                adj[{i, j, 7}].insert({i, j, 5, M_PI * 2.5});
            }

            if (j - 1 >= 0) {
                adj[{i, j, 2}].insert({i, j - 1, 0, 0});
                adj[{i, j, 0}].insert({i, j - 1, 2, 0});
                adj[{i, j, 4}].insert({i, j - 1, 6, 0});
                adj[{i, j, 6}].insert({i, j - 1, 4, 0});
                if (row[j - 1] == 'O') {
                    adj[{i, j, 7}].insert({i, j - 1, 3, 0});
                    adj[{i, j, 3}].insert({i, j - 1, 7, 0});
                }
            }

            if (i - 1 >= 0) {
                adj[{i, j, 0}].insert({i - 1, j, 6, 0});
                adj[{i, j, 6}].insert({i - 1, j, 0, 0});
                adj[{i, j, 2}].insert({i - 1, j, 4, 0});
                adj[{i, j, 4}].insert({i - 1, j, 2, 0});
                if (prevRow[j] == 'O') {
                    adj[{i, j, 1}].insert({i - 1, j, 5, 0});
                    adj[{i, j, 5}].insert({i - 1, j, 1, 0});
                }
            }
        }
        prevRow = row;
    }

    map<tuple<int, int, int>, double> dist;
    priority_queue<tuple<double, int, int, int>, vector<tuple<double, int, int, int>>, greater<tuple<double, int, int, int>>> pq;
    pq.emplace(0, 0, 0, 0);
    dist[{0, 0, 0}] = 0;
    while (!pq.empty()) {
        auto [d, x, y, z] = pq.top(); pq.pop();
        if (dist.find({x, y, z}) != dist.end() && d > dist[{x, y, z}]) continue;
        for (auto &[x2, y2, z2, w] : adj[{x, y, z}]) {
            if (dist.find({x2, y2, z2}) != dist.end() && dist[{x, y, z}] + w >= dist[{x2, y2, z2}]) continue;
            dist[{x2, y2, z2}] = dist[{x, y, z}] + w;
            pq.emplace(dist[{x2, y2, z2}], x2, y2, z2);
            printf("added edge from %d %d %d to %d %d %d\n", x, y, z, x2, y2, z2);
        }
    }

    cout << dist[{h - 1, w - 1, 4}] << endl;



}