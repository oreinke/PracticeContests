#include <bits/stdc++.h>

using namespace std;

int perm (int num, int n, int step, int s, int k, int permNum, vector<bool> &difs, vector<int> &nums) {
    if (step == s) {
        permNum++;
        if (permNum == k) {
            cout<< nums[0];
            for (int i = 1; i < s; ++i) cout << " " << nums[i];
            cout << endl;
        }
        return permNum;
    }

    if (permNum >= k) return permNum;

    for (int i = num; i <= n && permNum < k; ++i) {
        bool bad = false;
        for (int j = 0; j < step && !bad; ++j) {
            bad = difs[i - nums[j]];
        }
        if (!bad) {
            for (int j = 0; j < step; ++j) {
                difs[i - nums[j]] = true;
            }
            nums[step] = i;
            permNum = perm(i + 1, n, step + 1, s, k, permNum, difs, nums);
            for (int j = 0; j < step; ++j) {
                difs[i - nums[j]] = false;
            }
        }
    }
    return permNum;

}


int main() {
    int t; cin >> t;
    while (t--) {
        int n, s, k; cin >> n >> s >> k;
        vector<bool> difs (n, false);
        vector<int> nums (s);
        perm (1, n, 0, s, k, 0, difs, nums);
    }
}