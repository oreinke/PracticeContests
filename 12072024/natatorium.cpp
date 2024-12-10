#include <bits/stdc++.h>

using namespace std;

int main() {
    long long c, n;
    cin >> c >> n;
    set<long long> validNums;
    for (int i = 0; i < n; i++) {
        long long offer;
        cin >> offer;
        // cout << offer << endl;
        if (c % offer == 0) {
            if (validNums.find(c / offer) != validNums.end()) {
                long long match = c / offer;
                if (offer < match) {
                    cout << offer << " " << match << endl;
                }
                else {
                    cout << match << " " << offer << endl;
                }
                break;
            }
            validNums.insert(offer);
        }
    }
}