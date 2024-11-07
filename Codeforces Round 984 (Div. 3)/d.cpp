#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        int n, m;
        cin >> n;
        cin >> m;
        long long count = 0;

        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            string num;
            cin >> num;
            for (int j = 0; j < m; j++) {
                grid[i][j] = num[j] - '0';
            }
        }

        int i = 0;
        int j = 0;
        while (i < (n / 2) && j < (m / 2)) {
            vector<int> q;

            // read strip

            for (int k = j; k < m - j; k++) {
                q.push_back(grid[i][k]);
            }
            // cout << "REACHED!!\n";
            for (int k = i + 1; k < n - i; k++) {
                q.push_back(grid[k][m - 1 - j]);
            }
            // cout << "REACHED!!!\n";

            for (int k = m - 2 - j; k >= j; k--) {
                q.push_back(grid[n - 1 - i][k]);
            }
            // cout << "REACHED!!!!\n";

            for (int k = n - 2 - i; k > i; k--) {
                q.push_back(grid[k][j]);
            }
            // cout << "REACHED!\n";
            /* for (int k = 0; k < q.size(); k++){
                cout << q[k] << " ";
            }
            cout << "\n"; */

            int length = q.size();
            for (int c = 0; c < length; c++) {
                if (q[0] == 1 && q[1] == 5 && q[2] == 4 && q[3] == 3) {
                    count++;
                }
                q.push_back(q[0]);
                q.erase(q.begin());
            }

            i++;
            j++;
        }
        cout << count << "\n";
        t--;
    }

}

