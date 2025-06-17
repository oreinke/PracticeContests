#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<long long> a (n);
        for (auto &x : a) cin >> x;
        long long numerator = 2 * a[0] - a[1];

        if (numerator % (n + 1) == 0) {
            long long y = numerator / (n + 1);
            long long x = a[0] - y * n;
            if (y < 0 || x < 0) {
                cout << "NO\n";
                continue;
            }
            
            bool bad = false;
            for (int i = 1; i <= n && !bad; ++i) {
                if (x * i + y * (n - i + 1) != a[i - 1]) bad = true;
            }

            if (bad) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
        }
        else {
            cout << "NO\n";
        }
    }
}