#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        unsigned long long n, p, g;
        cin >> n >> p >> g;
        cout << (n * (p - 1) + (n / g) + ((n % g == 0) ? 0 : 1)) << endl;
    }
}