#include <bits/stdc++.h>

using namespace std;

int rec (int ind, int c, int remaining, vector<int> &bank, vector<int> &code, map<pair<int, int>, int> &dp) {
    // printf("ind: %d, c: %d\n", ind ,c); fflush(stdout);    
    if (c == code.size()) return 0;
    if (dp.count({ind, c})) return dp[{ind, c}];
    
    int best = 0;
    int len = code[c];
    for (int i = ind; i + remaining <= bank.size(); ++i) {
        // printf("i: %d\n", i);
        int res = 0;
        for (int j = i; j < i + len; ++j) res += bank[j];
        res += rec (i + len, c + 1, remaining - len, bank, code, dp);
        best = max(best, res);
    }
    // printf("ind: %d, c: %d, best: %d\n", ind ,c, best); fflush(stdout);    
    dp[{ind, c}] = best;
    return best;
}

int main() {
    string str, pattern; cin >> str >> pattern;
    map<pair<int, int>, int> dp;
    vector<int> bank (str.size()), code (pattern.size());
    for (int i = 0; i < str.size(); ++i) {
        bank[i] = str[i] - '0';
    }

    int remaining = 0;
    for (int i = 0; i < pattern.size(); ++i) {
        code[i] = pattern[i] - 'a' + 1;
        remaining += code[i];
    }

    cout << rec(0, 0, remaining, bank, code, dp) << endl;

}