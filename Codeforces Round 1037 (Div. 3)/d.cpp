#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n>> k;
        vector<tuple<int, int, int>> casinos (n);
        for (int i = 0; i < n; ++i) {
            int l, r, coin; cin >> l >> r >> coin;
            casinos[i] = make_tuple(l, r, coin);
        }

        sort(casinos.begin(), casinos.end());

        for (int i = 0; i < n && k >= get<0>(casinos[i]); ++i) {
            k = max(k, get<2>(casinos[i]));
        }

        cout << k <<endl;
    }
}