#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k; cin >> n >> m >> k;
    while (n != 0) {
        vector<int> pattern(k);
        for (int i = 0; i < k; ++i) {
            cin >> pattern[i];
        }
        int total = n;
        m--;
        int prev = n;
        for (int i = 0; i < m; ++i) {
            prev += pattern[i % k];
            total += prev;
        }
        cout << total << endl;
        cin >> n >> m >> k;
    }
}