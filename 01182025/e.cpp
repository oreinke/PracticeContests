#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int n, q; cin >> n >> q;
    vii xy(n);
    vii xz(n);
    vii yz(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            xy[i].push_back(n);
            xz[i].push_back(n);
            yz[i].push_back(n);
        }
    }

    int cnt = 0;
    for (int i = 0; i < q; ++i) {
        int x, y, z; cin >> x >> y >> z;

        xy[x][y]--;
        xz[x][z]--;
        yz[y][z]--;
        if (xy[x][y] == 0) {
            cnt++;
        }
        if (xz[x][z] == 0) {
            cnt++;
        }
        if (yz[y][z] == 0) {
            cnt++;
        }
        cout << cnt << endl;
    }
}