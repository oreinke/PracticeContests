#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    ull n, p; cin >> n >> p;
    ull half = n / 2;
    if (n % 2 == 1) {
        n--;
    }
    half -= p / 2;
    half %= p;
    if (half * 2 == p) {
        half = 0;
    }
    cout << half * 2 << endl;
}