#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string str, sub; cin >> str >> sub;
        vector<vector<unsigned long long>> grid (sub.size(), vector<unsigned long long> (str.size(), 0));
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == sub[sub.size() - 1]) grid[0][i] = 1;
        }
        
        for (int i = 1; i < sub.size(); ++i) {
            // cout << i << endl; fflush(stdout);
            vector<unsigned long long> suf (str.size(), 0);

            suf[str.size() - 1] = grid[i - 1][str.size() - 1];
            for (int j = str.size() - 2; j >= 0; --j) {
                suf[j] = grid[i - 1][j] + suf[j + 1];
            }

            for (int j = 0; j < str.size() - 1; ++j) {
                if (str[j] == sub[sub.size() - 1 - i]) grid[i][j] = suf[j + 1];
            }
        }

        unsigned long long cnt = 0;
        for (unsigned long long num : grid[sub.size() - 1]) cnt += num;
        cout << cnt << endl;
    }

}