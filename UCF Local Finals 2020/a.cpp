#include <bits/stdc++.h>

using namespace std;

int main() {
    int g, p, t; cin >> g >> p >> t;
    int gr = g + (t * p);

    if ((p * g) < gr) cout << "1\n";
    else if ((p * g) == gr) cout << "0\n";
    else cout << "2\n";
}