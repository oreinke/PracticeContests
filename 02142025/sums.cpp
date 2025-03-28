#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    vector<int> summation (302);
    summation[0] = 0;
    for (int i = 1; i < 302; ++i) {
        summation[i] = i + summation[i - 1];
    }

    for (int tc= 1; tc <= t; ++tc) {
        int n; cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += i * summation[i + 1];
        }
        printf("%d %d %d\n", tc, n, sum);
    }

    
}