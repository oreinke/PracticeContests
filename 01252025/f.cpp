#include <bits/stdc++.h>

using namespace std;


int main() {
    bool running = true;
    while (running) {
        int n; cin >> n;
        if (n == 0) {
            running = false;
            break;
        }
        set<int> nums;
        for (int i = 0; i < n; ++i) {
            for (int j= 0; j < 6; ++j) {
                int offer; cin >> offer;
                nums.insert(offer);
                if (offer == 0) {
                    running = false;
                    break;
                }
            }
        }

        if (nums.size() == 49) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
}