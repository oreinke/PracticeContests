#include <bits/stdc++.h>

using namespace std;

int main() {

    int r; cin >> r;
    while (r != 0) {
        int c; cin >> c;

        vector<string> grid (r);
        for (auto &x : grid) cin >> x;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == '*') continue;
                int cnt = 0;
                if (i - 1 >= 0 && j - 1 >= 0 && grid[i - 1][j - 1] == '*') cnt++;
                if (i - 1 >= 0 && grid[i - 1][j] == '*') cnt++;
                if ( j - 1 >= 0 && grid[i][j - 1] == '*') cnt++;
                if (i - 1 >= 0 && j + 1 < c && grid[i - 1][j + 1] == '*') cnt++;
                if ( j + 1 < c && grid[i][j + 1] == '*') cnt++;
                if ( i + 1 < r && j - 1 >= 0 && grid[i + 1][j - 1] == '*') cnt++;
                if ( i + 1 < r && grid[i + 1][j] == '*') cnt++;
                if ( i + 1 < r && j + 1 < c && grid[i + 1][j + 1] == '*') cnt++;
                grid[i][j] = '0' + cnt;
            }
        }
        for (string str : grid) cout << str << endl;
        cin >> r;
    }
}