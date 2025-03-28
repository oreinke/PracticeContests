#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> times (n, 0);

    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        times[i] += (s[0] - '0') * 60;
        times[i] += (s[2] - '0') * 10;
        times[i] += (s[3] - '0');
    }

    bool found = false;
    for (int i = 2; i < n && !found; ++i) {
        if (times[i] - times[i - 2] <= 10) found = true;
    }
    if (found) {
        cout << "0\n";
    }
    else {
        for (int i = 1; i < n && !found; ++i) {
            if (times[i] - times[i - 1] <= 10) found = true;
        }

        if (found) {
            cout << "1\n";
        }
        else {
            cout << "2\n";
        }
    }

}