#include <bits/stdc++.h>

using namespace std;

int perm (int step, vector<int> &square, vector<int> &nums, vector<bool> &used, int d) {
    if (step == 9) {
        
        int low = square[0] + square[1] + square[2];      
        low = min(low, square[3] + square[4] + square[5]);      
        low = min(low, square[6] + square[7] + square[8]);      
        low = min(low, square[0] + square[3] + square[6]);      
        low = min(low, square[1] + square[4] + square[7]);      
        low = min(low, square[2] + square[5] + square[8]);      
        low = min(low, square[0] + square[4] + square[8]);      
        low = min(low, square[6] + square[4] + square[2]);
        
        int high = square[0] + square[1] + square[2];      
        high = max(high, square[3] + square[4] + square[5]);      
        high = max(high, square[6] + square[7] + square[8]);      
        high = max(high, square[0] + square[3] + square[6]);      
        high = max(high, square[1] + square[4] + square[7]);      
        high = max(high, square[2] + square[5] + square[8]);      
        high = max(high, square[0] + square[4] + square[8]);      
        high = max(high, square[6] + square[4] + square[2]);
        if (high - low <= d) {
            return 1;
        }  
        return 0;
    }
    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        if (!used[i]) {
            used[i] = true;
            square[step] = nums[i];
            sum += perm(step + 1, square, nums, used, d);
            used[i] = false;
        }
    }
    return sum;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> nums;
        for (int i = 0; i < 9; ++i) {
            int num; cin >> num;
            nums.push_back(num);
        }
        vector<int> s (9);
        vector<bool> u (9, false);
        int res = perm(0, s, nums,u, n);
        cout << res << endl;

    }
}