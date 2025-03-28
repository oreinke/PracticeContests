#include <bits/stdc++.h>

using namespace std;

int main () {
    int n; cin >> n;
    while (n != 0) {
        cout << n;
        while (n > 9) {
            int next = 1;
            while (n > 9) {
                next *= n % 10;
                n /= 10;
            }
            next *= n;
            n = next;
            cout << " " << n;
        }
        cout << endl;
        cin >> n;
    }
}