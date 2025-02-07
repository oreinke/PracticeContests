#include <bits/stdc++.h>

using namespace std;

int main() {
    int r, c; cin >> r >> c;
    while (r != 0) {
        vector<vector<int>> grid (r, vector<int> (c));
        for (int i = 0; i < r; ++i) {
            string row; cin >> row;
            for (int j = 0; j < c; ++j) {
                if (row[j] == '.') {
                    grid[i][j] = 0;
                }
                else {
                    grid[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 0) {
                    int cnt = 0;
                    if (i - 1 >= 0 && j - 1 >= 0 && grid[i - 1][j - 1] == 1) cnt++;
                    if (i + 1 < r && j + 1 < c  && grid[i + 1][j + 1] == 1) cnt++;
                    if (i - 1 >= 0 && j + 1 < c && grid[i - 1][j + 1] == 1) cnt++;
                    if (i + 1 < r && j - 1 >= 0 && grid[i + 1][j - 1] == 1) cnt++;
                    if (i - 1 >= 0 && grid[i - 1][j] == 1) cnt++;
                    if (i + 1 < r && grid[i + 1][j] == 1) cnt++;
                    if ( j - 1 >= 0 && grid[i][j - 1] == 1) cnt++;
                    if ( j + 1 < c && grid[i][j + 1] == 1) cnt++;




                    cout << cnt;
                }
                else {
                    cout << '*';
                }
            }
            cout << endl;
        }
        
        cin >> r >> c;
    }
}