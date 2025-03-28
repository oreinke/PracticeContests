#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        ll sum = 1;
        for (ll i = 2; i <= sqrt(n); ++i) {
            
            if (n % i == 0) {
                // cout << "adding: " << i << endl;
                sum += i;
                if (i != n / i) sum += n / i;
                    
            }
        }
        // cout <<  sum << "\n";
        if (sum < n) {
            cout << "defective\n";
        }
        else if (sum == n) {
            cout << "perfect\n";
        }
        else {
            cout << "abundant\n";
        }
    }
    
}