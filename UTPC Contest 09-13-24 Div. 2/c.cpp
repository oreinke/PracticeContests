#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string hallway;
    cin >> hallway;
    char prev = 'a';
    int flipO = 0;
    int flipZ = 0;
    for (int i = 0; i < n; i++) {
        if (hallway[i] != prev) {
            if (hallway[i] == '1') {
                flipO++;
                prev = '1';
            }
            else {
                flipZ++;
                prev = '0';
            }
        }
    }
    flipO = min(flipO, flipZ);
    cout << flipO << "\n";

}