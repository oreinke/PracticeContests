#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int r, c, p; cin >> r >> c >> p;
        int sX, sY; cin >> sX>> sY;
        sX--; sY--;
        vector<vector<int>> grid (r, vector<int> (c));
        vector<vector<int>> val (r, vector<int> (c));
        vector<vector<bool>> visited (r, vector<bool> (c, false));

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> grid[i][j];
            }
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> val[i][j];
            }
        }

        long long total = val[sX][sY];
        visited[sX][sY] = true;
        queue<pair<int, int>> q;
        q.push({sX, sY});
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (x != 0 && !visited[x - 1][y] && (grid[x][y] > grid[x - 1][y] || grid[x - 1][y] - grid[x][y] <= p)) {
                visited[x - 1][y] = true;
                total += val[x - 1][y];
                q.push({x -1, y});
            }

            if (y != 0 && !visited[x][y - 1] && (grid[x][y] > grid[x][y - 1] || grid[x][y - 1] - grid[x][y] <= p)) {
                visited[x][y - 1] = true;
                total += val[x][y - 1];
                q.push({x, y - 1});
            }

            if (x != r - 1 && !visited[x + 1][y] && (grid[x][y] > grid[x + 1][y] || grid[x + 1][y] - grid[x][y] <= p)) {
                visited[x + 1][y] = true;
                total += val[x + 1][y];
                q.push({x + 1, y});
            }

            if (y != c - 1 && !visited[x][y + 1] && (grid[x][y] > grid[x][y + 1] || grid[x][y + 1] - grid[x][y] <= p)) {
                visited[x][y + 1] = true;
                total += val[x][y + 1];
                q.push({x, y + 1});
            }
        }

        cout << total << endl;
    }
}