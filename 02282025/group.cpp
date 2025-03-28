#include <bits/stdc++.h>

using namespace std;
map<int, int> nDiv (long long n) {
    map<int, int> primes;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            primes[i]++;
            n /= i;
        }
    }
    if (n != 1) primes[n]++;
    return primes;

}



int main() {
    vector<map<int, int>> nDivisors (1e6 + 1);
    for (int i = 2; i < nDivisors.size(); ++i) {
        nDivisors[i] = nDiv(i);
    }
    
    int t; cin >> t;
    while (t--) {
        long long n, d; cin >> n >> d;
        map<int, int> div = nDiv(d);
        long long sum = 0;
        for (int i = 1; i <= n; ++i) {
            map<int,int> curD = div;
            for (auto [x, y] : nDivisors[i]) {
                curD[x] += y;
            }
            int divs = 1;
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


// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//     int t; cin >> t;
//     while (t--) {
//         int n, q; cin >> n >> q;
//         map<string, int> names;
//         for (int i = 0; i < n; ++i) {
//             string str; cin >> str;
//             int num; cin >> num;
//             names[str] = num;
//         }

//         for (int i = 0; i < q; ++i) {
//             string str; cin >> str;
//             if (names[str] == 0) {
//                 cout << "-1\n";
//             }
//             else {
//                 cout << names[str] << endl;
//             }
//         }

//     }
// }