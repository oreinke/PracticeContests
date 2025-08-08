#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, m; cin >> k >> m;
    while (k) {
        set<string> found;
        vector<pair<int, string>> arr(k);
        for (int i = 0; i < k; ++i) {
            int n; cin >> n;
            string str; cin >> str;  
            arr[i].first = n;
            arr[i].second = str;  
        }
        sort(arr.rbegin(), arr.rend());

        for (int i = 0; i < k; ++i) {
            string str = arr[i].second;
            int cnt = arr[i].first;
            while (cnt && str.length() >= m) {
                if (found.count(str) == 0) {
                    found.insert(str);
                    cnt--;
                }
                str.pop_back();
            }
        }
        cout << found.size() << endl;
        cin >> k >> m;
    }
}