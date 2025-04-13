#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> cows (n), dp(n);
        for (auto &x : cows) cin >> x;
        dp[n - 1] = cows[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            int bigC = cows[i];
            dp[i] = cows[i] + dp[i + 1];
            for (int j = i; j < n && (j - i + 1) <= k; ++j) {
                bigC = max(bigC, cows[j]);
                if (j != n - 1) {
                    
                    dp[i] = max(dp[i], (j - i + 1) * bigC + dp[j + 1]);
                }
                else {
                    dp[i] = max(dp[i], (j - i + 1) * bigC);
                    // printf("i: %d, size: %d, big: %d\n", i, j - i + 1, bigC);
                }
            }
        } 
        // for (int i = 0; i < n; ++i) cout << dp[i] <<" ";
        // cout << endl;
        cout << dp[0] << endl;
    }
}