#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        deque<int> q;
        for (int i = n; i > 0; --i) {
            if (i % 2) {
                q.push_back(i);
            }
            else {
                q.push_front(i);
            }
        }

        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop_front();
        }
        cout << endl;
    }
}