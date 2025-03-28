#include <bits/stdc++.h>

using namespace std;

int main() {
    int r, c; cin >> r >> c;
    vector<vector<int>> grid (r + 1, vector<int> (c, 0));
    string str; cin >> str;
    for (int i = 0; i < c; ++i) {
        if (str[i] == '1') grid[1][i]++;
    }
    for (int i = 2; i <= r; ++i) {
        cin >> str;
        for (int j = 0; j < c; ++j) {
            if (str[j] == '1') {
                grid[i][j] += grid[i - 1][j] + 1;
            }
        }
    }

    int best = 0;
    for (int i = 1; i <= r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (grid[i][j] == 0) continue;
            int height = grid[i][j];
            int area = 0;
            int right = j;
            // printf("at i: %d, j: %d\n", i, j);
            while (right < c && grid[i][right]) {
                height = min(height, grid[i][right]);
                area = max(area, height * (right - j + 1));
                // printf("h: %d, area: %d\n", height, area);
                right++;
            }
            if (area > best) {
                best = area;
                // printf("new best, i: %d, j: %d, right: %d\n", i, j ,right);
                // fflush(stdout);
            }
        }
    }

    cout << best << endl;
    // cout << "------------------------\n";
    // for (vector<int> row : grid) {
    //     for (int num : row) cout << num;
    //     cout << endl;
    // }
}