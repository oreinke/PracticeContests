#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        printf("Case %d:\n", tc);
        int n; cin >> n;
        vector<int> lastSeen (187, 0);
        for (int d = 1; d <= n + 1; ++d) {
            for (int i = 1; i < 187; ++i) {
                if (d - lastSeen[i] > 10) {
                    printf("Day %d: Full Search %d\n", d, i);
                }
                else if (d - lastSeen[i] > 4){
                    printf("Day %d: Extra Ranger %d\n", d, i);
                }
            }
            if (d <= n) {
                int r; cin >> r;
                for (int i = 0; i < r; ++i) {
                    int k; cin >> k;
                    for (int j = 0; j < k; ++j) {
                        int rhino; cin >> rhino;
                        lastSeen[rhino] = d;
                    }
                }
            }
        }
    }
}