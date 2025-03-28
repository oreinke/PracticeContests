#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    vector<bool> visited(2e6,false);
    vector<ll> sieve;
    for (ll i = 2; i < visited.size(); ++i) {
        if (!visited[i]) {
            sieve.push_back(i);
            for (ll j = i; j < visited.size(); j += i) {
                visited[j] = true;
            }
        }
    }
    while (t--) {
        ll n; cin >> n;
        //set<ll> nFact;
        ll cnt = n;
        vector<ll> factors;
        
        // ll i = 2; i <= n / 2 && num != 1; ++i
        for (ll prime : sieve) {
            if (prime * prime > n) break;
            if (n % prime == 0) {
                while (n % prime == 0) n /= prime;

                cnt -= cnt / prime;
            } 
        }
        if (n > 1)
            cnt -= cnt / n;
        
        cout << cnt << "\n";
        // ll cnt = 1;
        // for (ll i = 2; i <= n; ++i) {
        //     num = i;
        //     for (ll j = 2; j <= sqrt(i) && num != 1; ++j) {
        //         if (num % j == 0) {
        //             if (nFact.find(j) != nFact.end()) {
        //                 cnt++;
        //                 break;
        //             }
        //             while (num % i == 0) num /= i;
        //         } 
        //     }
        // }
        
    }
}   