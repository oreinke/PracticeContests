#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned __int128 x, y, z, w;
    cin >> x >> y >> z >> w;
    string res = "";
    while (!(x == 1 && y == 0 && z == 0 && w == 1)) {
        if (x > y) {
            res = "0" + res;
            x -= y;
            z -= w;
        }
        else  {
            res = "1" + res;
            y -= x;
            w -= z;
        }
    }
    cout << res << endl;
}