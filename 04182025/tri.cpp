#include <bits/stdc++.h>

using namespace std;

long long dfs (long long i, long long j, long long n, vector<vector<long long>> &grid, vector<vector<long long>> &dp, vector<vector<bool>> &visited) {
    if (i == n - 1) {
        if (j == 2) return 2e10;
        if (j == 0) return grid[n - 1][0] + grid[n - 1][1];
        return grid[n - 1][1];
    }
    if (!visited[i][j]) {
        dp[i][j] = dfs(i + 1, j, n, grid, dp, visited);
        if (j != 0) dp[i][j] = min(dp[i][j],  dfs(i + 1, j - 1, n, grid, dp, visited));
        if (j != 2) dp[i][j] = min(dp[i][j],  dfs(i + 1, j + 1, n, grid, dp, visited));
        if (j != 2) dp[i][j] = min(dp[i][j],  dfs(i, j + 1, n, grid, dp, visited));
        dp[i][j] += grid[i][j];
        visited[i][j] = true;
    }

    return dp[i][j];
}


int main() {
    long long t = 1;
    long long n; cin >> n;
    while(n) {
        vector<vector<long long>> grid (n, vector<long long> (3, 0)), dp (n, vector<long long> (3, LONG_MAX));
        vector<vector<bool>> visited (n, vector<bool> (3, false));

        for (long long i = 0; i < n; ++i) {
            cin >> grid[i][0] >> grid[i][1] >> grid[i][2];
        }

        cout << t << ". " << dfs(0, 1, n, grid, dp, visited) << endl;
        t++;
        cin >> n;
    }
}