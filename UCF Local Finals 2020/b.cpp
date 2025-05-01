#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int c1e = 0, c1p = 0, c2e = 0, c2p = 0;
    for (int i =0; i < n; ++i) {
        int e, v1, v2; cin >> e >> v1 >> v2;
        c1p += v1;
        c2p += v2;
        if (v1 > v2) c1e += e;
        else c2e += e;
    }

    if (c1e == c2e || c1p == c2p) cout << "0\n";
    else if (c1p > c2p && c1e > c2e) cout << "1\n";
    else if (c1p < c2p && c1e < c2e) cout << "2\n";
    else cout << "0\n";

}