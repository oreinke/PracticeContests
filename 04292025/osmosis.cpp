#include <bits/stdc++.h>

using namespace std;


__int128 rec(int i, int j, long long a, long long b, int pre, vector<long long>  &arr, vector<vector<vector<__int128>>> &dp) {
    if (i >= j) return 0;
    if (dp[i][j][pre] != -1) {
        return dp[i][j][pre];
    }

    long long res;
    int moved = 0;
    if (pre == 0) {
        // move right
        res = b * arr[i] * arr[j - 1] + rec(i, j - 1, a, b, 1, arr, dp);
        // m l
        if ((a * arr[i + 1] * arr[j] + rec(i + 1, j, a, b, 0, arr, dp)) > res) {
           moved = 1;
           res = a * arr[i + 1] * arr[j] + rec(i + 1, j, a, b, 0, arr, dp);
        }
    }
    else {
        // move right
        res = a * arr[i] * arr[j - 1] + rec(i, j - 1, a, b, 1, arr, dp);
        // m l
        if ((b * arr[i + 1] * arr[j] + rec(i + 1, j, a, b, 0, arr, dp)) > res) {
           moved = 1;
           res = b * arr[i + 1] * arr[j] + rec(i + 1, j, a, b, 0, arr, dp);
        }
    }
    dp[i][j][pre] = res;
    return res;
    
}

int main() {
    int t; cin >> t;
    while (t--) {
        long n, a, b; cin >> n >> a >> b;
        vector<long long> arr (n);
        for (auto &x : arr) cin >> x;
        vector<vector<vector<__int128>>> dp (n, vector<vector<__int128>> (n, vector<__int128> (2, -1)));
        
        if (n == 1) {
            cout << "0\n";
        }
        else {
            __int128 res = b * arr[1] * arr[n - 1] + rec(1, n - 1, a, b, 0, arr, dp);
            if (b * arr[0] * arr[n - 2] + rec(0, n - 2, a, b, 1, arr, dp) > res) res = b * arr[0] * arr[n - 2] + rec(0, n - 2, a, b, 1, arr, dp);
            printf("%llu\n", (unsigned long long)res);
        }

    }
}