#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int curEgg = 1;
    int count = 1;
    for (int i = 2; i <= n; i++) {
        curEgg = ((curEgg * 4) ^ (i - 1)) % 6; 
        if (curEgg == 1) {
            count++;
        }
    }

    cout << count << "\n";

}