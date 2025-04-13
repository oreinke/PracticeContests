#include <bits/stdc++.h>

using namespace std;

map<int, long long> memo;

long long rec (int n) {
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    long long cnt = 0;
    if (n >= 2) {
        cnt += rec (n - 2);
    }

    if (n >= 5) {
        cnt += rec (n - 5);

    }

    if (n >= 10) {
        cnt += rec (n - 10);

    }
    memo[n] = cnt;
    return cnt;
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n; cin >> n;
        memo[0] = 1;
        cout << "Dinner #" << i << ": " << rec(n) << endl;
    }
}