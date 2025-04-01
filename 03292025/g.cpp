#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() {
    int n; cin >> n;
    map<pair<ull, ull>, int> pointCounts;
    vector<pair<ull, ull>> points (n);
    for (int i = 0; i < n; ++i) {
        ull x, y; cin >> x >> y;
        points[i] = {x, y};
        pointCounts[{x, y}]++;
    }

    vector<pair<int, int>> validDiffs;
    for (int i = 0; i <= 2018; ++i) {
        int b = (int) sqrt((2018 * 2018) - (i * i));
        if (i * i + b * b == 2018 * 2018) validDiffs.push_back({i, b});
    }

    int cnt = 0;
    for (auto [x, y] : points) {
        for (auto [w, z] : validDiffs) {
            if (w == 0 || z == 0) {
                int num = 0;
                num += pointCounts[{x + w, y + z}];
                num += pointCounts[{x + w, y - z}];
                num += pointCounts[{x - w, y + z}];
                num += pointCounts[{x - w, y - z}];
                cnt += num / 2;

            }
            else {
                cnt += pointCounts[{x + w, y + z}];
                cnt += pointCounts[{x + w, y - z}];
                cnt += pointCounts[{x - w, y + z}];
                cnt += pointCounts[{x - w, y - z}];
            }
        }
    }

    cout << cnt / 2 << endl;
}