#include <bits/stdc++.h>
using namespace std;

bool validPath (int xT, int yT, vector<string> ins) {
    int x = 0, y = 0, d = 0;
    // d: 0 = N, 1 = E, 2 = S, 3 = W
    for (string s : ins) {
        if (s[0] == 'L') {
            d--;
            if (d == -1) d = 3;
        }
        else if (s[0] == 'R') {
            d = (d + 1) % 4;
        }
        else {
            if (d == 0) {
                y++;
            }
            else if (d == 1) {
                x++;
            }
            else if (d == 2) {
                y--;
            }
            else {
                x--;
            }
        }
    }
    if (x == xT && y == yT) return true;
    return false;
}

int main() {
    int xT, yT, n; cin >> xT >> yT >> n;
    vector<string> ins (n);
    for (auto &x : ins) cin >> x;
    bool found = false;
    for (int i = 0; i < n && !found; ++i) {
        string orig = ins[i];
        if (orig[0] != 'L') {
            ins[i] = "L";
            if (validPath(xT, yT, ins)) {
                found = true;
                printf("%d Left\n", i + 1);
            }
        }

        if (orig[0] != 'R') {
            ins[i] = "R";
            if (validPath(xT, yT, ins)) {
                found = true;
                printf("%d Right\n", i + 1);
            }
        }

        if (orig[0] != 'F') {
            ins[i] = "F";
            if (validPath(xT, yT, ins)) {
                found = true;
                printf("%d Forward\n", i + 1);
            }
        }

        ins[i] = orig;
    }
    
}