#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, w, d; cin >> l >> w >> d;
    l = l - d * 2;
    w = w - d * 2;
    if (l < 0 || w < 0) cout << "0\n";
    else
        cout << max(0, l * w) << endl;
}