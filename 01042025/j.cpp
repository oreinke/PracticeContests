#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    int c, m;
    cin >> c >> m;
    vector<ull> bag (c + 1, 0);

    while (m--) {
        vector<ull> newBag (c + 1);
        for (int i = 0; i < c + 1; ++i) {
            newBag[i] = bag[i];
        }
        for (int i = 1; i <= c; ++i) {
            ull val;
            cin >> val;

            for (int j = i; j <= c; ++j) {
                newBag[j] = max(newBag[j], bag[j - i] + val);
            }
        }   
         
        for (int i = 0; i < c + 1; ++i) {
            bag[i] = newBag[i];
        } 
    }
    ull best = 0;
    for (ull num : bag) {
        best = max(best, num);
    } 
    cout << best << endl;
}