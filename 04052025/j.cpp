#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> grid (n, vector<int>(m));
    
    
    int cnt = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int num; cin >> num;
            grid[i][j] = num;
            if (grid[i][j] == 0) continue;
            if (j != 0 && grid[i][j - 1] == 1) cnt++;
            if (i != 0 && grid[i - 1][j] == 1) cnt++;
            if (j != m - 1 && i != 0 && grid[i - 1][j  + 1] == 1) cnt2++;
            if (j != 0 && i != 0 && grid[i - 1][j - 1] == 1) cnt2++;
            
        }
    }
    cout << cnt << " " << cnt + cnt2 << endl;
}