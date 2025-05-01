#include <bits/stdc++.h>

using namespace std;

bool served (long long n, long long time, vector<long long> &barbers) {
    long long total = barbers.size();
    for (auto b : barbers) {
        total += time / b;
        if (total >= n) return true;
    }
    return false;
}

int main() {
    int t; cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        long long b, n; cin >> b >> n;
        vector<long long> barbers (b);
        for (auto &x : barbers) cin >> x;

        long long l = -1, h = LONG_MAX - 1;
        while (h - l > 1) {
            long long m = (l + h) / 2;
            if (served(n, m, barbers)) {
                h = m;
            }
            else {
                l = m;
            }
        }
        // printf("l: %d, h: %d\n",l, h); fflush(stdout);
        long long cnt = 0;
        if (h != 0) {
            cnt += b;
            for (auto num : barbers) {
                cnt += l / num;
            }
        }
        // cout << cnt << endl;
        for (int i = 0; i < b; ++i) {
            if (h % barbers[i] == 0) {
                cnt++;
                if (cnt == n) {
                    printf("Case #%d: %d\n", tc, i + 1);
                    i = b;
                }
            }
        }
    }
}