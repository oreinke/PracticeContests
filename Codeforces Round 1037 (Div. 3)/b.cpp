#include <bits/stdc++.h>

using namespace std;


int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int cnt = 0;
        int seg = 0;
        bool skip = false;
        for (int i = 0; i < n; ++i) {
            int w; cin >> w;
            if (skip) {
                skip = false;
            }
            else {
                if (w == 1) {
                    seg = 0;
                }
                else {
                    seg++;
                    if (seg >= k) {
                        seg = 0;
                        cnt++;
                        skip = true;
                    }
                }
            }
        }
        cout << cnt << endl;
    }
}