#include <bits/stdc++.h>

using namespace std;
unordered_map<long long, long long> nDiv (long long n) {
    unordered_map<long long, long long> primes;
    for (long long i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            primes[i]++;
            n /= i;
        }
    }
    if (n != 1) primes[n]++;
    return primes;

}



int main() {
    vector<unordered_map<long long, long long>> nDivisors (1e6 + 1);
    for (int i = 2; i < nDivisors.size(); ++i) {
        nDivisors[i] = nDiv(i);
    }
    


    int t; cin >> t;
    while (t--) {
        long long n, d; cin >> n >> d;
        unordered_map<long long, long long> div = nDiv(d);
        long long sum = 0;
        for (long long i = 1; i <= n; ++i) {
            unordered_map<long long, long long> curD = div;
            for (auto [x, y] : nDivisors[i]) {
                curD[x] += y;
            }
            long long divs = 1;
            for (auto [x, y] : curD) {
                // cout << x << "  " << y << endl;
                divs *= (y + 1);
            }
            // cout << "divs: " << divs << endl;
            sum += divs;
        }
        cout << sum << endl;
    }
}