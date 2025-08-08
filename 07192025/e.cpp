#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll k, n, L, a, b, g1; cin >> k >> n >> L >> a >> b >> g1;

    vector<ll> frames (n + 1);
    frames[0] = 0;
    frames[1] = g1;
    for (int i = 2; i <= n; ++i) frames[i] = (frames[i - 1] * a + b) % (L + 1);
    sort(frames.begin(), frames.end());
    map<ll, ll> pre;
    pre[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pre[frames[i]] = max(pre[frames[i - 1]], frames[i] - frames[i - 1] - 1);
    }
    for (int i = 0; i < k; ++i) {
        int w; cin >> w;
        w--;
        auto it = upper_bound(frames.begin(), frames.end(), w);
        it--;
        // printf("it: %d, w: %d, preit: %d\n", *it, w, pre[*it]);
        cout << max(pre[*it], w - *it) << endl;
    }


}