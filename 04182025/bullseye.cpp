#include <bits/stdc++.h>

using namespace std;

int main() {
    int tn; cin >> tn;
    for (int tc = 1; tc <= tn; ++tc) {
        unsigned long long rB, tB; cin >> rB >> tB;
         __int128 r = rB;
         __int128 t = tB;
        __int128 l = 0, h = ((t + 1) / 2) - r;
        // printf("h: %ld, l: %ld\n",h, l);
        while (h - l > 1) {
            __int128 m = (h + l) / 2 + 1;
            // cout << (2 * m * (m + 1)) + 2 * r * m - 3 * m << endl;
            
            if (((2 * m * (m + 1)) + 2 * r * m - 3 * m) > t) {
                h = m - 1;
            }
            else {
                l = m - 1;
            }
            //printf("h: %ld, l: %ld\n",h, l);
        }
        unsigned long long num = (unsigned long long) h;
        cout << "Case #" << tc << ": " << num << endl;
    }
}