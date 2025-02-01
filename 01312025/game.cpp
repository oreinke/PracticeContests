#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string str; cin >> str;
        int max = 0;
        int cur = 0;
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == '^' && cur != 0) {
                cur--;
            }
            else if (str[i] == 'v') {
                cur++;
                if (cur > max) {
                    max = cur;
                }
            }
        }
        cout << max << endl;
    }
}