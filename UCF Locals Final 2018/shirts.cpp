#include <bits/stdc++.h>

using namespace std;

set<pair<int, string>> checked;
set<pair<int, string>> checkedSkip;

bool rec (int cur, string used, string target, vector<string> friends) {
    if (cur >= target.length()) return true;
    if (target[cur] == '0' || checked.count({cur, used})) return false;

    string curChunk;
    if (cur == target.length() - 1) curChunk = target.substr(cur, 1);
    else curChunk = target.substr(cur, 2);

    for (int i = 0; i < friends.size(); ++i) {
        if (used[i] != '0' && friends[i] == curChunk.substr(0, min(curChunk.size(), friends[i].size()))) {
            used[i]--;
            if (rec(cur + friends[i].size(), used, target, friends)) return true;
            used[i]++;
        }
    }

    checked.insert({cur, used});
    return false;
}

bool recSkip (int cur, string used, string target, vector<string> friends) {
    if (cur >= target.length()) return true;
    if (target[cur] == '0' || checkedSkip.count({cur, used})) return false;
    if (cur + 2 >= target.length()) return true;
    if (rec(cur + 1, used, target, friends)) return true;
    if (rec(cur + 2, used, target, friends)) return true;
    string curChunk;
    if (cur == target.length() - 1) curChunk = target.substr(cur, 1);
    else curChunk = target.substr(cur, 2);

    for (int i = 0; i < friends.size(); ++i) {
        if (used[i] != '0' && friends[i] == curChunk.substr(0, min(curChunk.size(), friends[i].size()))) {
            used[i]--;
            if (recSkip(cur + friends[i].size(), used, target, friends)) return true;
            used[i]++;
        }
    }

    checkedSkip.insert({cur, used});
    checked.insert({cur, used});
    return false;
}

int main() {
    string target; cin >> target;
    int n; cin >> n;
    vector<string> friends (n);
    for (auto &x : friends) cin >> x;
    string used = "";
    for (int i = 0; i < n; ++i) used += "0";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (friends[i] == friends[j]) {
                used[j]++;
                break;
            }
        }
    }

    if (recSkip(0, used, target, friends)) cout << "1\n";
    else cout << "0\n";
}