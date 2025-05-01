#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        double n, m, p; cin >> n >> m >> p;
        p *= .01;
        if (m / n >= p) cout << "1\n";
        else cout << "0\n";
    }
}