#include <bits/stdc++.h>

using namespace std;

bool pali (string s) {
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != s[s.length() - 1 - i]) {
            return false;
        }
    }

    return true;
}

int main() {
    bool running = true;
    while (running) {
        string n; cin >> n;
        if (n == "0") {
            running = false;
            break;
        }
        int num = stoi(n);
        int ops = 0;
       
        string next = to_string(num);
        while (next.length() < n.length()) {
            next = "0" + next;
        }
        while (!pali(next)) {
            ops++;
            num++;
            next = to_string(num);
             while (next.length() < n.length()) {
                next = "0" + next;
            }
        }
        cout << ops << endl;

    }
}