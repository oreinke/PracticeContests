#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, s; cin >> n >> k >> s;
    vector<int> level (n), dp (n);
    for (auto &x : level) cin >> x;

    sort(level.begin(), level.end());


    for (int start = n - 1; start >= 0; --start) {
        int total = 0;
        for (int i = start; i < n && (i - start) < s && level[i] - level[start] <= k; ++i) {
            if (i == n - 1) {
                total++;
            }
            else {
                total = (total + dp[i + 1]) % (1000000007);
            }
        }
        dp[start] = total;
        // printf("%d set to %d\n", start, total);
    }
    cout << dp[0] << endl;
    // for (int i = 0; i < n; ++i) {
    //     cout << dp[i] << ", ";
    // }
    // cout << endl;
}