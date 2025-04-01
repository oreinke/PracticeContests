#include <bits/stdc++.h>
using namespace std;

map<int, int> primeFac (int num) {
    map<int, int> primes;
    for (int i = 2; i * i <= num; ++i) {
        while (num % i == 0) {
            primes[i]++;
            num /= i;
        }
    }
    if (num != 1) {
        primes[num]++;
    }
    return primes;
}

int main() {
    int n; cin >> n;
    vector<int> denom;

    for (int i = 0; i < n; ++i) {
        int coin; cin >> coin;
        if (coin != 1) denom.push_back(coin);
    }
    sort(denom.begin(), denom.end());

    map<int, int> prevP = primeFac(denom[0]);
    bool bad = false;
    for (int i = 1; i < denom.size() && !bad; ++i) {
        map<int, int> curP = primeFac(denom[i]);
        int dif = 0;
        for (auto [x, y] : curP) {
            dif += y;
        }
        for (auto [x, y] : prevP) dif -= y;
        if (abs(dif) > 1) bad = true;
    }
    if (bad) cout << "non-";
    cout << "canonical\n";


}