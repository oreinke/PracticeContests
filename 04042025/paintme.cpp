#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, w, l, h, a, m; cin >> n >> w >> l >> h >> a >> m;
    while (n) {
        unsigned long long cnt = 0;
        cnt += 2 * l * h;
        cnt += 2 * w * h;
        cnt += l * w;
        for (int i = 0; i < m; ++i) {
            int wH, wL; cin >> wH >> wL;
            cnt -= wH* wL;
        }
        cnt *= n;
        int res =  cnt / a + ((cnt % a == 0) ? 0 : 1);
        cout << res << endl;


        cin >> n >> w >> l >> h >> a >> m;
    }
}