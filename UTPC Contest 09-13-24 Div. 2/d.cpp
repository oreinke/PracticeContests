#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    map<long long, int> sum;
    long long cur = 0;
    for (int i = 1; i <= n; i++) {
        int nm;
        cin >> nm;
        if (nm == 0) {
            continue;
        }
        cur += nm;
        sum.insert({cur, i});
    }

    for (int i = 0; i < m; i++) {
        long long curM;
        cin >> curM;
        
        if (0 == curM) {
            cout << 0 << "\n";
            continue;
        }

        auto it = sum.find(curM);
        if (it == sum.end()) {
            it = sum.upper_bound(curM);
        }

    
        if (it == sum.end()) {
            cout << "-1\n";
        }
        else {
            cout << (*it).second << "\n";
        }
    }
}