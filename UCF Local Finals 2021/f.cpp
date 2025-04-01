#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, p; cin >> n >> p;
    int cnt = 0;~
    while (p > 1 && n > 1) {
        n = n / 2;
        p--;
        cnt++;
    }
    cnt += n - 1;
    cout << cnt << endl;
}