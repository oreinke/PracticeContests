#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int r, c; cin >> r >> c;
        // printf("r: %d, c: %d\n",r, c);
        pair<int, int> s;
        vector<vector<char>> grid (r, vector<char> (c));
        // char buf; cin >> buf;
        // cout <<"HERE\n";
        // fflush(stdout);
        // printf("buf: %c\n", buf);
        // fflush(stdout);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> grid[i][j];
                // printf("i: %d, j: %d, char: %c\n", i, j, grid[i][j]);
                if (grid[i][j] == 'S') s = {i, j};
            }
        }

        map<pair<int, int>, bool> visited;
        queue<pair<int,int>> q;
        q.push(s);
        visited[s] = true;
        int steps = 0;
        bool found = false;
        
        while (!q.empty() && !found) {
            // cout << "HERE, qs: " << q.size() << endl;
            steps++;
            queue<pair<int,int>> next;
            while (!q.empty()) {
                pair<int, int> cur = q.front(); q.pop();
                
                // printf("in i: %d, j: %d, step: %d\n", cur.first, cur.second, steps);
                if (grid[cur.first][cur.second] == '~') {
                    found = true;
                    break;
                }
                if (grid[cur.first][cur.second] == 'X') {
                    continue;
                }

                if (!visited[{cur.first + 1, cur.second}]) {
                    visited[{cur.first + 1, cur.second}] = true;
                    next.push({cur.first + 1, cur.second});
                }
                if (!visited[{cur.first, cur.second + 1}]) {
                    visited[{cur.first, cur.second +1}] = true;
                    next.push({cur.first, cur.second + 1});
                }
                if (!visited[{cur.first, cur.second - 1}]) {
                    visited[{cur.first, cur.second - 1}] = true;
                    next.push({cur.first, cur.second - 1});
                }
                if (!visited[{cur.first - 1, cur.second}]) {
                    visited[{cur.first - 1, cur.second}] = true;
                    next.push({cur.first - 1, cur.second});
                }

            }
            q = next;
        }
        if (found) {
            cout << steps - 1 << endl;
        }
        else {
            cout << "-1\n";
        }
    }
}