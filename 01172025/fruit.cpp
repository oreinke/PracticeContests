#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int d; cin >> d;
        vector<int> days(d);
        for (auto &x : days) cin >> x;
        int cnt = 0;
        bool invalid = true;
        int maxLeft;
        while (invalid) {
            maxLeft = 0;
            invalid = false;
            int leftOver = 0;
            for (int i = 0; i < d; ++i) {
                leftOver += cnt;
                int sell = days[i];
                if (sell > leftOver) {
                    invalid = true;
                    cnt++;
                    break;
                }
                else {
                    leftOver -= sell;
                    maxLeft = max(maxLeft, leftOver);
                }
            }
        }
        cout << cnt << " " << maxLeft << endl;
    }
}