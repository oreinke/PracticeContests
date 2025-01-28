#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (auto &x : arr) cin >> x;

        unsigned long long ops = 0;
        int i = 0;
        while (i < n - 1) {
            sort(arr.begin() + i, arr.end());
            //cout << arr[i] << ", " << arr[arr.size() - 1] <<endl;
            arr[i + 1] += arr[i];
            ops += arr[i + 1];
            i++;
        }
        cout << ops << endl;

    }
}