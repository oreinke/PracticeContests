#include <bits/stdc++.h>

using namespace std;

int main() {
    string str; cin >> str;
    vector<int> prev(26, -1);
    vector<int> freq(26, 0);
    bool bad = false;
    for (int i = 0; i < str.size(); ++i) {
        if (prev[str[i] - 'a'] != -1) {
            if ((i - prev[str[i] - 'a']) % 2 == 0) {
                bad = true;
                break;
            }
        }
        prev[str[i] - 'a'] = i;
        freq[str[i] - 'a']++;
        if (freq[str[i] - 'a'] > 2) {
            bad = true;
            break;
        }
    }

    if (bad) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
}