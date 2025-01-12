#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cnt = 0;
        while (n--) {
            int w1, w2;
            cin >> w1 >> w2;
            if (w2 - w1 == 19) cnt++;
        }
        cout << cnt << endl;
    }
}