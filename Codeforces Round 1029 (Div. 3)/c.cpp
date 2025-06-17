#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a (n);
        for (auto &x : a) cin >> x;
        set<int> prev, cur;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cur.insert(a[i]);
            prev.erase(a[i]);
            if (prev.size() == 0) {
                cnt++;
                prev = cur;
            }
        }

        cout << cnt << endl;
    }
}