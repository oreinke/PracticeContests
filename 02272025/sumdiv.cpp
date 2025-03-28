#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
int main() { 
    int t; cin >> t;
    while (t--) {
        ull n; cin >> n;
        ull res = 1;
        for (int i = 0; i < n; ++i) {
            ull num, e; cin >> num >> e;
            ull prev = res;
            ull cur = 1;
            for (int j = 0; j < e; ++j) {

                cur = (cur * num) % ((ull)1e9 + 7);
                res = (res + (prev * cur) % ((ull)1e9 + 7)) % ((ull)1e9 + 7);
                cout << "new res: " << res << endl;
            }
        }
        cout << res << endl;
    }
}