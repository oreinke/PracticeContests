#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int r; cin >> r;
        vector<vector<int>> dist;
        for (int i = 0; i < r; ++i) {
            int len; cin >> len;
            dist.push_back(vector<int> (len + 1, -1));
        }
        int x1, y1, x2, y2; cin >> y1 >> x1 >> y2 >> x2;
        y1--;
        y2--;
        dist[y1][x1] = 0;
        deque<pair<int, int>> q;
        q.push_back({y1, x1});
        int step = 1;
        while (!q.empty()) {
            // cout << step << endl; fflush(stdout);
            deque<pair<int, int>> frontier;
            while (!q.empty()) {
                auto [y, x] = q.front(); q.pop_front();
                // left
                if (x != 0 && dist[y][x - 1] == -1){ 
                    dist[y][x - 1] = step;
                    frontier.push_back({y, x - 1});
                }
                else if (x == 0 && y != 0 && dist[y - 1][dist[y - 1].size() - 1] == -1) {
                    dist[y - 1][dist[y - 1].size() - 1] = step;
                    frontier.push_back({y - 1, dist[y - 1].size() - 1});
                }

                // right
                if (x != dist[y].size() - 1 && dist[y][x + 1] == -1) {
                    dist[y][x + 1] = step;
                    frontier.push_back({y, x + 1});
                }
                else if (x == dist[y].size() - 1 && y != r - 1 && dist[y + 1][0] == -1) {
                    dist[y + 1][0] = step;
                    frontier.push_back({y + 1, 0});
                }
                
                // down
                if (y != r - 1) {
                    if (x >= dist[y + 1].size()) {
                        if (dist[y + 1][dist[y + 1].size() - 1] == - 1) {
                            dist[y + 1][dist[y + 1].size() - 1] = step;
                            frontier.push_back({y + 1, dist[y + 1].size() - 1});
                        }
                    }
                    else {
                        if (dist[y + 1][x] == - 1) {
                            dist[y + 1][x] = step;
                            frontier.push_back({y + 1, x});
                        }
                    }
                }

                // up
                if (y != 0) {
                    if (x >= dist[y - 1].size()) {
                        if (dist[y - 1][dist[y - 1].size() - 1] == - 1) {
                            dist[y - 1][dist[y - 1].size() - 1] = step;
                            frontier.push_back({y - 1, dist[y - 1].size() - 1});
                        }
                    }
                    else {
                        if (dist[y - 1][x] == - 1) {
                            dist[y - 1][x] = step;
                            frontier.push_back({y - 1, x});
                        }
                    }
                }
            }

            q = frontier;
            step++;
        }
        cout << dist[y2][x2] << endl;

    }
}