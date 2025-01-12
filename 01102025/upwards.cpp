#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        bool valid = true;
        for (int i = 0; i < str.length() - 1; ++i) {
            if (str[i] >= str[i + 1]) {
                valid = false;
            }
        }
        if (valid) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}