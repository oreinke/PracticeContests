#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int main () {
    int n, k; cin >> n >> k;
    vector<pair<ll, ll>> b (n);
    for (int i = 0; i < n; ++i) {
        ll w, h; cin >> w >> h;
        b[i].first = w;
        b[i].second = h;
    }

    vector<vector<ll>> dp (k, vector<ll> (n + 1, 1e16));
    for (int i = 0; i < k; ++i) dp[i][n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        ll h = b[i].second;
        ll w = 0;
        for (int j = i; j < n; ++j) {
            w += b[j].first;
            h = max(h, b[j].second);
            for (int boxes = 1; boxes < k; ++boxes) {
                //printf("i: %d, j: %d, b: %d, cur: %d, offer: %d", i, j, boxes, )
                dp[boxes][i] = min(dp[boxes][i], w * h + dp[boxes - 1][j + 1]);

            }
            dp[0][i] = w * h;
        }
    }

    cout << dp[k - 1][0] << endl;
    
}