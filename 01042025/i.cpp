#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    unsigned long long n1 = 1, n2 = 1;
    while (n--){
        n1 *= 2;
        n2 *= 4;
    }
    cout << n1 * n2 << endl;

}