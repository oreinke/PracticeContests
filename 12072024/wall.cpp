#include <bits/stdc++.h>

using namespace std;
int main() {
    int k, n;
    string cur;
    cin >> k >> n >> cur;

    map<int, char> rules;
    for (int i = 0; i < 8; i++) {
        if (k & (1 << i)) {
            rules[i] =  'X';
        }
        else {
            rules[i] = '.';
        }
    }


    for (int gen = 0; gen < n; gen++) {
        // cout << "CUR : " << cur << endl;
        string result = "";
        if (cur.length() == 1) {
            int curNum = 0;
            if (cur[0] == 'X') {
                curNum = 1;
            }
            result += rules[curNum * 2];
        }
        else {
            int cell1, cell2, cell3;
            
            cell1 = 0;
            if (cur[0] == 'X') {
                cell2 = 1;
            }
            else {
                cell2 = 0;
            }

            if (cur[1] == 'X') {
                cell3 = 1;
            }
            else {
                cell3 = 0;
            }
            result += rules[cell1 * 4 + cell2 * 2 + cell3];
            // cout << "Rules: " << cell1 * 4 + cell2 * 2 + cell3;

            for (int i = 1; i < cur.length() - 1; i++) {

                cell1 = cell2;
                cell2 = cell3;
                cell3 = 0;
                if (cur[i + 1] == 'X') {
                    cell3 = 1;
                }
                // cout << " " << cell1 * 4 + cell2 * 2 + cell3;
                result += rules[cell1 * 4 + cell2 * 2 + cell3];                
            }
            cell1 = cell2;
            cell2 = cell3;
            cell3 = 0;
            // cout << " " << cell1 * 4 + cell2 * 2 + cell3 << endl;
            result += rules[cell1 * 4 + cell2 * 2 + cell3];
        }
        cout << result <<endl;
        cur = result;


    }
    
}