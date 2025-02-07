#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    while (n != 0) {
        int curBest = 0;
        int best = -1e9;
        for (int i = 0; i < n; ++i) {
            int day; cin >> day;
            curBest += day;
            best = max(best, curBest);
            if (curBest < 0) curBest = 0;
        }
        cout << best << endl;


        cin >> n;
    }
    
}