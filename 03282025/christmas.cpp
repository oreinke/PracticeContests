#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<unsigned long long> dp (1000001);
    dp[0] = 0;
    for (unsigned long long i = 1; i <= 1000000; ++i) {
        dp[i] = ((i + 1) * i) / 2;
        dp[i] += dp[i - 1];
    }
    int n; cin >> n;
    while (n != 0) {
        cout << dp[n] << endl;
        cin >> n;
    }
}