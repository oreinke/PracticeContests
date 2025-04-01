#include <bits/stdc++.h>

using namespace std;
bool perm (int step, vector<int> &order, vector<int> &vals, vector<bool> &used) {
    if (step == 5) {
        if (order[0] == (order[1] + order[2] + order[3]) && order[4] == (order[1] * 3 + order[2])) {
            printf("%d %d %d %d %d\n", order[0], order[1], order[2], order[3], order[4]);
            return true;
        }
        return false;
    }
    else {
        for (int i = 0; i < 5; ++i) {
            if (used[i]) continue;
            used[i] = true;
            order[step] = vals[i];
            if (perm (step + 1, order, vals, used)) return true;
            used[i] = false;
        }
    }
    return false;
}

int main() {
    vector<int> vals(5), order(5);
    vector<bool> used (5, false);
    for (auto &x : vals) cin >> x;
    perm(0, order, vals, used);

}