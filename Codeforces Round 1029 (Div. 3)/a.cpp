#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        int first = -1, last = -1;
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            if (num == 1) {
                last = i;
                if (first == -1) first = i;
            }
        }
        if (last - first + 1 > x) cout << "NO\n";
        else cout << "YES\n";
    }
}