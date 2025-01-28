#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, k; cin >> n >> k;
    vector<set<int>> toppings (k + 1);
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        if (a == b) continue;
        else {
            toppings[a].insert(b);
            toppings[b].insert(a);
        }
    }

    bool bad = false;
    for (int i = 0; i < k + 1 && !bad; ++i) {
        int cnt = 0;
        for (int num : toppings[i]) {
            if (toppings[num].size() > 1) {
                cnt++;
            }
            
        }
        if (cnt > 2) {
            bad = true;
        }
    }
    if (bad) {
        cout << "im";
    }
    cout << "possible\n";
}