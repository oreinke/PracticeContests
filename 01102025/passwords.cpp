#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<string> choices(m);
        for (auto &x : choices) cin >> x;
        int rank;
        cin >> rank;
        // for (string str : choices) cout << str << endl;
        
        vector<int> perms(m);
        perms[m - 1] = choices[m - 1].length();
        for (int i = m - 2; i >= 0; i--) {
            perms[i] = choices[i].length() * perms[i + 1];
        }
        rank--;
        for (int i = 0; i < m - 1; i++) {
            // cout <<"rank: " << rank << ", calc: "<<  (rank / perms[i + 1] - ((rank % perms[i + 1] == 0) ? 1 : 0)) << endl;
            // cout << "cur choices: " << choices[i] << endl;
            cout << choices[i][rank / perms[i + 1]];
            rank = rank % perms[i + 1];            
        }
        // cout << rank << endl;
        cout << choices[m - 1][rank] << endl;
    }
}