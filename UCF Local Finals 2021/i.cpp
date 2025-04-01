#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >>n >> k;
    deque<int> low, high;
    int num; cin >> num;
    low.push_back(num);
    high.push_back(num);
    for (int i = 1; i < n; ++i) {
        cin >> num;
        int size = low.size();
        for (int j = size - 2; j >= max(0, size - 100); --j) {
            if (abs(num - low[j]) >= k || abs(num - high[j]) >= k) {
                low[j + 1] = min(num, low[j + 1]);
                high[j + 1] = max(high[j + 1], num);
            }
        }

        if (abs(num - low[low.size() - 1]) >= k || abs(num - high[high.size() - 1]) >= k) {
            low.push_back(num);
            high.push_back(num);
        }

        low[0] = min(low[0], num);
        high[0] = max(high[0], num);        
    }
    cout << low.size() << endl;
}