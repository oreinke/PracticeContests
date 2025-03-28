#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    while (n != 0) {
        int profit; cin >> profit;
        int rT = profit;
        for (int i = 1; i < n; ++i) {
            if (rT < 0) rT = 0;
            int day; cin >> day;
            rT += day;
            profit = max(profit, rT);
        }
        cout << profit << endl;


        cin >> n;
    }   


}