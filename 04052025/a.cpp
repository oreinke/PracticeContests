#include <bits/stdc++.h>

using namespace std;

int main() {
    long long cnt = 0;
    for (int i = 0; i < 6; ++i) {
        int num; cin >> num;
        cnt += num;
    }
    cout << cnt * 5 << endl;
}