#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> res (n - 1, 0);
        for (int i = 2; i <= n; ++i) {
            int num = i;
            for (int j = 2; j <= i && num != 1; ++j) {
                while (num % j == 0) {
                    res[j - 2]++;
                    num /= j;
                }
            }
        }

        for (int i = 0; i < n - 1; ++i) {
            if (res[i] != 0) printf("%d ", res[i]);
        }
        cout << endl;
    }

}