#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr (n);
    map<int, int> first, last;
    set<int> nums;
    for (int i = 0; i < n; ++i ) {
        int num; cin >> num;
        arr[i] = num;

        if (first.find(num) == first.end()) first[num] = i;
        last[num] = i;
        nums.insert(num);
    }
    vector<pair<int, int>> intervals;
    for (int num : nums) {
        intervals.push_back({last[num], first[num]});
    }
    int cnt = 0, prev = -1;
    sort(intervals.begin(), intervals.end());
    for (auto [e, s] : intervals) {
        if (s > prev) {
            cnt++;
            prev = e;
        }
    }

    cout << nums.size() - cnt << endl;

}