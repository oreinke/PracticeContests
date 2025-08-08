#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int small = 10;
        while (n > 0) {
            small = min(small, n % 10);
            n /= 10;
        }
        cout << small << endl;
    }

}