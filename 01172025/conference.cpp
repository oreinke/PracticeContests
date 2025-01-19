#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<pair<int, int>> bookings;
        for (int i = 0; i < n; ++i) {
            int s, e; cin >> s >> e;
            e = e + s - 1;
            if (e < 30) {
                bookings.emplace_back(s, e);
            }
        }
        sort(bookings.begin(), bookings.end());
        int end = -1;
        ull sum = 0;
        for (int i = 0; i < bookings.size(); ++i) {
            if (end < bookings[i].first) {
                end = bookings[i].second;
                for (int j = bookings[i].first; j <= bookings[i].second; ++j ) {
                    sum += pow(2, 29 - j);
                }
                
            }
        }
        // cout << "SUM: " << sum << endl;
        cout << sum << endl;

    }
}