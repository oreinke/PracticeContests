#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, x, y; cin >> n >> x >> y;
        vector<int> arr(n);
        for (auto &x : arr) cin >> x;
        bool bad1 = false, bad2 = false;
        if (arr[0] == x) bad1 = true;
        if (arr[n - 1] == y) bad2 = true;
        if (bad1) {
            if (bad2) {
                cout << "BOTH\n";
            }
            else {
                cout << "EASY\n";

            }
        }
        else if (bad2) {
            cout << "HARD\n";

        }
        else {
            cout << "OKAY\n";

        }
    }
}