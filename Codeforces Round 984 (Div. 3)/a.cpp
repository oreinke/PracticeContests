#include <bits/stdc++.h>

using namespace std;

int main () {
    int c;
    scanf("%d", &c);
    
    while (c > 0) {
        int notes;
        scanf("%d", &notes);
        int prev, cur;
        cin >> prev;
        notes--;
        bool valid = true;
        while (notes > 0) {
            cin >> cur;
            if (abs(cur - prev) != 5 && abs(cur - prev) != 7) {
                valid = false;
            }
            // cout << abs(cur - prev) << "\n";
            prev = cur;
            notes--;
        }
        if (valid) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

        c--;
    }
}