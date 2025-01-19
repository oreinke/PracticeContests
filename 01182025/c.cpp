#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    if (n % 2 == 1) {
        n -= 3;

        cnt++;
    }
    cout << n / 2 + cnt << endl;
    if (cnt == 1) {
        cout <<"3 ";
    }
    for (int i = 0; i < n / 2; ++i) {
        cout << "2 ";
    }
    cout << endl;
}