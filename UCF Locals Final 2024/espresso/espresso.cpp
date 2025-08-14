#include <bits/stdc++.h>

using namespace std;

typedef __int128 ull;
int main() {
    long long c1l, m1l, c2l, m2l; cin >> c1l >> m1l >> c2l >> m2l;
    ull c1 = c1l, m1 = m1l, m2 = m2l, c2 = c2l;
    
    if (c1 == 0 || m1 == 0 || c2 == 0 || m2 ==0) {
        cout << "0\n";
    }
    else {
        c1 += m1;
        c2 += m2;
        if ((m1 * c2) > (m2 * c1)) {
            ull temp1 = m1, temp2 = c1;
            m1 = m2;
            c1 = c2;
            m2 = temp1;
            c2 = temp2;
        }
        

        ull denom = 2;
        int step = 1;
        while (true) {
            ull milk = (m2 * denom / c2);
            if ((milk  * c1) >= (m1 * denom)) break;
            denom *= 2;
            step++;
        }
        cout << step << endl;
    }
}