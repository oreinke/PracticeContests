#include <bits/stdc++.h>

using namespace std;


int main() {
    int n = 8;
    int cnt = 0;
    bool invalid = false;
    vector<vector<bool>> board (n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        string str; cin >> str;
        for (int j = 0; j < n; ++j) {
            if (str[j] == '*') {
                board[i][j] = true;
                cnt++;
                for (int k = i - 1; k >= 0; k--) {
                    if (board[k][j]) {
                        //cout << "hit0, " << i << " " << j << endl;
                        invalid = true;
                    }
                }
                for (int k = j - 1; k >= 0; k--) {
                    if (board[i][k]) {
                        //cout << "hit1, " << i << " " << j << endl;
                        invalid = true;
                    }
                }
                for (int k = i - 1,  p = j - 1; k >= 0 && p >= 0; k--, p--) {
                    if (board[k][p]) {
                        //cout << "hit2, " << i << " " << j << endl;
                        invalid = true;
                    }
                }
                for (int k = i - 1,  p = j + 1; k >= 0 && p < n; k--, p++) {
                    if (board[k][p]) {
                        //cout << "hit3, " << i << " " << j << endl;
                        invalid = true;
                    }
                }
            }
        }


    }
    if (invalid || cnt < 8) {
        cout << "in"; 
    }
    cout << "valid\n";


}