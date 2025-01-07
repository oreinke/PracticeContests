#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int find (int u, vector<int> &parent) {
    if (parent[u] != parent[parent[u]]) {
        parent[u] = find(parent[u], parent);
    }
    return parent[u];
}

void unionize (int u, int v, vector<int> &parent) {
    int p1 = find(u, parent);
    int p2 = find(v, parent);

    parent[p1] = p2;
}


int main() {
    int n, m, l;
    cin >> n >> m >> l;
    ull track = 0;
    vector<tuple<int, int, int>> eL;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (l > 0) {
            track += c;
            l--;
        }
        eL.emplace_back(c, a, b);
    }
    // cout << "track: " << track << endl;
    sort(eL.begin(), eL.end());
    // cout << "sorted eL:" <<endl;
    // for (auto [c, a, b] : eL) {
    //     cout << "Length: " << c << ". " << a << " -> " << b <<endl;
    // }
    vector<int> parent(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    int edges = 0;

    for (auto [c, a, b] : eL) {
        if (track < c || edges == n - 1) {
            break;
        }
        // cout << "Parents\n";
        // for (int num : parent) cout << num << " ";
        // cout << endl;
        if (find(a - 1, parent) != find(b - 1, parent)) {
            // cout << "adding edge from " << a << " to " << b << endl;
            edges++;
            track -= c;
            unionize(a - 1, b - 1, parent);
        }
    }
    // cout << "Parents\n";
    // for (int num : parent) cout << num << " ";
    // cout << endl;


    // cout << "track: " << track << ", size: " << edges << endl;
    if (edges != n - 1) {
        cout << "im";
    }
    cout <<"possible\n";
}