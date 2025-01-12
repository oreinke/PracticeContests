#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
int caseNum = 0;

void shift (vector<vector<int>> &hexs, int curHex, int target, int face) {
    // for (int x : hexs[curHex]) cout << x << " ";
    // cout << endl;
    // cout << "t: " << target << ", f: " << face <<endl;
    // fflush(stdout);
    int cnt = 0;
    while (hexs[curHex][face] != target) {
        // cout << "cnt: " << cnt << endl;
        //cnt++;
        //fflush(stdout);

        int first = hexs[curHex][0];
        for (int i = 0; i < 5; i++) {
            hexs[curHex][i] = hexs[curHex][i + 1];
        }
        hexs[curHex][5] = first;
    }
}
bool hexCheck (vector<vector<int>> &hexs, vector<int> &curPerm) {
    if (hexs[curPerm[0]][1] == hexs[curPerm[2]][4]
        && hexs[curPerm[0]][2] == hexs[curPerm[3]][5]
        && hexs[curPerm[0]][3] == hexs[curPerm[4]][0]
        && hexs[curPerm[0]][4] == hexs[curPerm[5]][1]
        && hexs[curPerm[0]][5] == hexs[curPerm[6]][2]
        && hexs[curPerm[1]][4] == hexs[curPerm[6]][1]) {
            return true;
    }
    return false;
    
}

bool perm (vector<vector<int>> &hexs, vector<int> &curPerm, set<int> &used, int step) {
        if (step == 7) {
            string res = "No Solution";
            if (hexCheck(hexs, curPerm)) {
                cout << "Case " << caseNum << ":";
                for (int i = 0; i < 7; i++) {
                    cout << " " << curPerm[i];
                }
                cout << endl;
                return true;
            }
            return false;
        }
        int shiftNum = 0;
        int face = 0;
        if (step == 0) {
            shiftNum = 1;
            face = 0;
        }
        else if (step == 1) {
            shiftNum = hexs[curPerm[step - 1]][0];
            face = 3;
        }
        else if (step == 2) {
            shiftNum = hexs[curPerm[step - 1]][2];
            face = 5;
        } 
        else if (step == 3) {
            shiftNum = hexs[curPerm[step - 1]][3];
            face = 0;
        } 
        else if (step == 4) {
            shiftNum = hexs[curPerm[step - 1]][4];
            face = 1;
        } 
        else if (step == 5) {
            shiftNum = hexs[curPerm[step - 1]][5];
            face = 2;
        } 
        else if (step == 6) {
            shiftNum = hexs[curPerm[step - 1]][0];
            face = 3;
        } 
        string res = "No Solution";
        for (int i = 0; i < 7; ++i) {
            if (used.find(i) == used.end()) {
                shift(hexs, i, shiftNum, face);
                curPerm[step] = i;
                used.insert(i);
                if (perm(hexs, curPerm, used, step + 1)) {
                    return true;
                }
                used.erase(i);
            }
        }
        return false;
    }



int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        caseNum = tc;
        vector<vector<int>> hexs(7);
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 6; j++) {
                int num;
                cin >> num;
    
                hexs[i].push_back(num);
            }
        }
        set<int> used;
        vector<int> curPerm(7);
        if (!perm(hexs, curPerm, used, 0)) {
            cout << "Case " << caseNum << ": No solution\n";
        }
    }
}