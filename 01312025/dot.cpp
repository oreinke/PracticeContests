#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int size, n; cin >> size >> n;
        vector<int> other(n);
        for (auto &x : other) cin >> x;
        sort(other.begin(), other.end());
        int target = other[n - 1];
        int eaten = 0;
        while (!(size > target)) {
            auto offer = lower_bound(other.begin(), other.end(), size);
            if (offer == other.begin()) {
                eaten = -1;
                break;
            }
            else {
                size += *(offer - 1);
                other.erase((offer - 1));
                eaten++;
            }
        }
        cout << eaten <<endl;
    }
}