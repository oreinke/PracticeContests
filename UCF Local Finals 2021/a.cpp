#include <bits/stdc++.h>

using namespace std;

int main() {
    string str; cin >> str;
    vector<int> freq (26, 0);
    for (char c : str) freq[c - 'a']++;

    bool odd = false, even = false;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] == 0) continue;
        if (freq[i] % 2 == 0) {
            even = true;
        }
        else {
            odd = true;
        }
    }

    if (odd && even) {
        cout << "0/1\n";
    }
    else if (odd) {
        cout << "1\n";
    }
    else {
        cout << "0\n";
    }

}