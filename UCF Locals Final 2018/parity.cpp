#include <bits/stdc++.h>

using namespace std;

int main() {
    string str; cin >> str;
    vector<int> freq (26, 0);
    for (char c : str) freq[c - 'a']++;
    bool e = true;
    bool o = true;
    for (int num : freq) {
        if (num == 0) continue;
        if (num % 2 == 1) e = false;
        if (num % 2 == 0) o = false;
    }
    if (e) {
        cout << 0 << endl;
    }
    else if (o) {
        cout << "1\n";
    }
    else cout << "2\n";
}