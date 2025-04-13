#include <bits/stdc++.h>

using namespace std;

int main() {
    long long p, q, n, m; cin >> p >> q >> n >> m;

    long long bestR = -1, bestG = -1, size = -1;
    for (long long r = 1; r < m; ++r) {
        for (long long g = max(n - r, r); g + r <= m; ++g) {
            if (size != -1 && r + g > size) break;
            if ((g  * 2 * r * q) == p * (r * r + 2 * r * g + g * g - r - g)) {
                bestR = r;
                bestG = g;
                size = r + g;
            }
        }
    }
    if (size == -1) {
        cout << "NO SOLUTION\n";
    }
    else {
        cout << bestR << " " <<bestG << endl;
    }
}