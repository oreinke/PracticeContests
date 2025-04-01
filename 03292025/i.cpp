#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> gnomes (n);
        for (auto &x : gnomes) cin >> x;
        for (int i = 1; i < n; ++i) {
            if (gnomes[i] != gnomes[i - 1] + 1) {
                cout << i + 1 << endl;
                break;
            }
        }
    }
}