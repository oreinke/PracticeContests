#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n>> k;
        set<int> heights;
        int h = 0;
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            heights.insert(num);
            if (i + 1 == k) h = num;
        }

        int water = 1;
        auto it = heights.begin(); 
        while (it != heights.end()) {
            if (*it <= h) {
                it++;
                continue;
            }
            if (*it - h > h - water + 1) break;
            else {
                water += *it - h;
                h = *it;
                it++;
            }
        }
        if (it == heights.end()) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}