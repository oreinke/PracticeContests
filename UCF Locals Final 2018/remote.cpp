#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    set<char> bad;
    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        bad.insert('0' + num);
    }

    int t; cin >> t;
    int best = 1e9;
    for (int i = t; i < 1000; ++i) {
        bool valid = true;
        string num = to_string(i);
        for (char c : num) {
            if (bad.find(c) != bad.end()) valid = false;
        }
        if (valid) {
            best = i - t;
            break;
        }
    }

    for (int i = t; i >= 0; --i) {
        bool valid = true;
        string num = to_string(i);
        for (char c : num) {
            if (bad.find(c) != bad.end()) valid = false;
        }
        if (valid) {
            best = min(best, t - i);
            break;
        }
    }

    if (best == 1e9) cout << "0\n";
    else cout << best << endl;
}