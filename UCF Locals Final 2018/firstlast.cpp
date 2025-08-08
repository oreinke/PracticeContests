#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr (n), index (n + 1, 1e9), dp (n + 1, 1);
    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        index[num] = i;
        arr[i] = num;
    }

    int best = 1;
    for (int i = 0; i < n; ++i) {
        if (index[arr[i] - 1] < i){
            dp[arr[i]] = dp[arr[i] - 1 ] + 1;
            best = max(best, dp[arr[i]]);
        }
    }

    cout << n - best << endl;
}