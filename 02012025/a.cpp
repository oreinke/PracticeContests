#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    string str; cin >> str;
    int best = 0;
    int curTotal = 0;
    int curFruits = 0;
    char prev = '_';
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'o') {
            curTotal++;
            curFruits++;
            best = max(curTotal, best);
        }
        else if (str[i] == 'a') {
            if (curFruits == 0 || prev == 'a') {
                curTotal = 0;
            }
            else {
                curFruits--;
                curTotal++;
            }
        }
        prev = str[i];
    }

 
    cout << best << endl;


}