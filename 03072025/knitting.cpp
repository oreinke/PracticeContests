#include <bits/stdc++.h>

using namespace std;

int main () {
    long long n, m, k; cin >> n >> m >> k;
    while (n != 0) {
        long long cur = n;
        m--;
        long long prevRow = n;
        vector<int> pattern (k);
        for (auto &x : pattern) cin >> x;
        for (long long i = 0; i < m; ++i) {
            prevRow += pattern[i % k];
            n += prevRow;
        }
        cout << n << endl;


        cin >> n >> m >> k;
    }
}