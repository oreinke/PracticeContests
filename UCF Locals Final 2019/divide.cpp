#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d; cin >> n >> d;
    vector<int> a (n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt += a[i];
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] * (d / cnt) << endl;
    }

}