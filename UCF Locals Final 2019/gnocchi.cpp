#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int lim = 10000000;
    vector<int> sieve (lim, -1);
    for (int i = 2; i <= sqrt(lim); ++i) {
        if (sieve[i] != -1) continue;
        sieve[i] = i;
        for (int j = i; j < lim; j += i) {
            if (sieve[j] == -1) sieve[j] = i;
        }
    }

    int last = 0;
    for (int i = n; i < lim && k; ++i) {
        if (sieve[i] > n && sieve[i] != i) {
            last = i;
            k--;
        }
    }
    cout << last << endl;
}