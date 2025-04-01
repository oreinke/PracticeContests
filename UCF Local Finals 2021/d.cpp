#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> heights (101, 0);
    for (int i = 0; i < n; ++i) {
        int x, w, h; cin >> x >> w >> h;
        for (int j = x; j < x + w; ++j) heights[j] = h;
    }
    int cnt = 0;
    for (int i = 1; i <= 100; ++i) {
        cnt += 1 + abs(heights[i] - heights[i - 1]);
    }
    cout << cnt << endl;
}