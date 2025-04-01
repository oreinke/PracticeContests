#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> fib (2);
    cin >> fib[0] >> fib[1];
    bool found = false;
    // cout << fib[0] << ", " << fib[1];
    while (!found) {
        fib.push_back((fib[fib.size() - 2] + fib[fib.size() - 1] ) % 10);
        // cout << ", " << fib[fib.size() - 1];
        if (fib[0] == fib[fib.size() - 2] && fib[1] == fib[fib.size() - 1]) {
            // printf("%d == %d, %d == %d\n",fib[0], fib[fib.size() - 2], fib[1], fib[fib.size() - 1]);
            found = true;
        }
    }

    cout << fib.size() << endl;
}