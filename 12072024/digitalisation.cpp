#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m , c;
    cin >> n >> m >> c;
    vector<int> schools (m + 1, c);
    int fc = 0;
    int sc = 0;
    for (int i = 0; i < n; i++) {
        int s1, s2;
        cin >> s1 >> s2;
        if (schools[s1] > 0) {
            fc++;
            schools[s1]--;
        }
        else if (schools[s2] > 0) {
            sc++;
            schools[s2]--;
        }
    }
    cout << fc << " " << sc << endl;

}