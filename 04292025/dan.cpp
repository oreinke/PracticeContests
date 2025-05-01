#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, d; cin >> n >> d;
        vector<int> parents (n);
        vector<bool> visited (n, false);
        visited[0] = true;
        parents[0] = 0;
        for (int i = 0; i < n - 1; ++i) {
            int p; cin >> p;
            parents[i + 1] = p - 1;
        }

        int cnt = 1;
        for (int i = 0; i < d; ++i) {
            int deliv; cin >> deliv;
            deliv--;
            while (!visited[deliv]) {
                cnt++;
                visited[deliv] = true;
                deliv = parents[deliv];
            }
        }
        cout << cnt - 1 << endl;
    }
}