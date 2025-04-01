#include <bits/stdc++.h>

using namespace std;



int main() {
    int n, m; cin >> n >> m;
    int caseNum = 0;
    while (n != 0) {
        caseNum++;
        vector<vector<unsigned long long>> dp (n, vector<unsigned long long>(m + 1, 0));
        for (int i = 1; i <= m; ++i) {
            dp[0][i] = 1;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int k = j * 2; k <= m; ++k) {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }

        unsigned long long cnt = 0;
        for (int i = 1; i <= m; ++i) {
            cnt += dp[n - 1][i];
        }
        printf("Case %ld: n = %ld, m = %ld, # lists = %ld\n", caseNum, n, m, cnt);

        cin >> n >> m;
    }
}