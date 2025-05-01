#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int f, b, c, s ,e; cin >> f >> b >> c >> s >> e;
        for (int i = s; i <= e; ++i) {
            if (i % f == 0) cout << "FIZZ\n";
            else if (i % b == 0) cout << "BUZZ\n";
            else if (i % c == 0) cout << "CUZZ\n";
            else cout << i << "\n"; 
        }

    }
}