#include <bits/stdc++.h>

using namespace std;

int hex (int step, int sum, vector<int> &star, vector<int> &nums, vector<int> &used) {
    //cout << "s: " << step << endl; fflush(stdout);
    if (step == 3) {
        int cnt = 0;
        for (int i = 0; i < 12; ++i) {
            if (used[i]) continue;
            
            used[i] = true;
            star[step] = nums[i];
            if (star[0] + star[1] + star[2] + star[3] == sum) {
                cnt += hex(step + 1, sum, star, nums, used);
            }
            
            used[i] = false;
            
        }
        return cnt;
    }
    else if (step == 6) {
        int cnt = 0;
        for (int i = 0; i < 12; ++i) {
            if (used[i]) continue;
            used[i] = true;
            star[step] = nums[i];
            if (star[4] + star[2] + star[5] + star[6] == sum) {
                cnt += hex(step + 1, sum, star, nums, used);
            }
            used[i] = false;
            
        }
        return cnt;
    }
    else if (step == 9) {
        int cnt = 0;
        for (int i = 0; i < 12; ++i) {
            if (used[i]) continue;
            used[i] = true;
            star[step] = nums[i];
            if (star[6] + star[7] + star[8] + star[9] == sum) {
                cnt += hex(step + 1, sum, star, nums, used);
            }
            used[i] = false;
            
        }
        return cnt;
    }
    else if (step == 10) {
        int cnt = 0;
        for (int i = 0; i < 12; ++i) {
            if (used[i]) continue;
            used[i] = true;
            star[step] = nums[i];
            if (star[3] + star[5] + star[7] + star[10] == sum) {
                cnt += hex(step + 1, sum, star, nums, used);
            }
            used[i] = false;
        }
        return cnt;
    }
    else if (step == 11) {
        int cnt = 0;
        for (int i = 0; i < 12; ++i) {
            if (used[i]) continue;
            used[i] = true;
            star[step] = nums[i];
            
            if (star[0] + star[11] + star[8] + star[10] != sum || star[9] + star[11] + star[1] + star[4] != sum) {
                used[i] = false;
                return 0;
            }
            // cout <<"HIT\n"; fflush(stdout);
            used[i] = false;
            return 1;
        }
        return 0;
        
    }
    else {
        int cnt = 0;
        for (int i = 0; i < 12; ++i) {
            if (used[i]) continue;
            // if (step == 0 && nums[i] == 7) cout << "HERE!\n";
            used[i] = true;
            star[step] = nums[i];
            cnt += hex(step + 1, sum, star, nums, used);
            used[i] = false;
            
        }
        return cnt;
    }
}


int main () {
    vector<int> nums (12);
    for (auto &x : nums) cin >> x;
    while (nums[0] != 0) {
        int sum = 0;
        for (int num : nums) sum += num;
        int res = 0;
        if (sum % 3 == 0) {
            // cout << sum / 3<< endl;
            vector<int> star(12), used(12, false);
            res = hex(0, sum / 3, star, nums, used);
        }
        cout << res / 12 << endl;
        for (auto &x : nums) cin >> x;
    }
}