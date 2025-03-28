#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> cur(n);
        vector<tuple<int, int, int>> past (n);
        for (auto &x : cur) cin >> x;

        bool bad = false;
        int tallest = 0;
        for (int i = 0; i < n; ++i) {
            int m; cin >> m;
            if (m < cur[i]) {
                bad = true;
            }
            past[i] = {m, m - cur[i], cur[i]};
            tallest = max(tallest, m - cur[i]);
        }
        if (!bad) {
            sort(past.begin(), past.end());
            for (int i = 0; i < n - 1 && !bad; ++i) {
                if (get<1>(past[i]) > get<1>(past[i + 1]) 
                    || (get<0>(past[i]) == get<0>(past[i + 1]) && get<1>(past[i]) != get<1>(past[i + 1]))
                    || get<2>(past[i]) > get<2>(past[i + 1])) bad = true;
            }
        }
        if (bad) {
            cout << "-1\n";
        }
        else {
            cout << tallest << endl;
        }
    }
}