#include <bits/stdc++.h>

using namespace std;

map<pair<int,int>, bool> memo;
bool rec (int s1, int s2, vector<int> &str1, vector<int> &str2, vector<int> &target) {
    if (s1 == str1.size() && s2 == str2.size()) return true;
    if (memo.find({s1, s2}) != memo.end()) {
        return memo[{s1, s2}];
    }
    bool res = false;
    if (s1 != str1.size() && str1[s1] == target[s1 + s2] && rec(s1 + 1, s2, str1, str2, target)) res = true;
    if (s2 != str2.size() && str2[s2] == target[s1 + s2] && rec(s1, s2 + 1, str1, str2, target)) res = true;   

    memo[{s1, s2}] = res;
    return res;
}

int main() {

    int n1, n2; cin >> n1 >> n2;
    while (n1 + n2) {
        memo.clear();
        vector<int> str1(n1), str2(n2), target(n1 + n2);
        for (auto &x : str1) cin >> x;
        for (auto &x : str2) cin >> x;
        for (auto &x : target) cin >> x;
        

        if (!rec(0, 0, str1, str2, target)) {
            cout << "not ";
        }
        cout << "possible\n";

        cin >> n1 >> n2;
    }
}