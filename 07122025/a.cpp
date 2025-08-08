#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k; cin >> n >> m >> k;
    while (n) {
        int req = n / 2 + 1;
        if (k >= n / 2 + (n % 2)) cout << "-1\n";
        else cout << max(0 ,req - m) << endl;
        cin >> n >> m >> k;
    }
}