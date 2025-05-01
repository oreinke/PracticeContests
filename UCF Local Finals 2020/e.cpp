#include <bits/stdc++.h>

using namespace std;

long long find (long long u, vector<long long> &parents) {
    if (u != parents[u]) parents[u] = find(parents[u], parents);
    return parents[u];
}

long long gcd (long long a, long long b) {
    if ((a % b) == 0) return b;
    return gcd (b, a % b);
    
}

int main() {
    int n, m; cin >> n >> m;
    vector<long long> parents (n), size (n, 1);
    for (int i = 0; i < n; ++i) parents[i] = i;
    long long num = n;
    for (int i = 0; i < m; ++i) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int u, v; cin >> u >> v;
            u--; v--;
            if (find(u, parents) != find(v, parents)) {
                n--;
                num -= size[parents[u]] * size[parents[u]];
                num -= size[parents[v]] * size[parents[v]];
                size[parents[u]] += size[parents[v]];
                num += size[parents[u]] * size[parents[u]];

                parents[parents[v]] = parents[u];
            }
        }
        else {
            cout << num / gcd(num, n) << "/" << n / gcd (num, n) << endl;
        }
    }


}