#include <bits/stdc++.h>

using namespace std;

// void mark ()

int dfs (int u, vector<bool> &visited, vector<bool> &reaches, vector<vector<int>> &adjL) {
    int cnt = 1;
    if (reaches[u]) {
        return 1e7;
    }

    visited[u] = true;
    for (int v : adjL[u]) {
        if (visited[v]) continue;
        cnt += dfs(v, visited, reaches, adjL);
        if (cnt >= 1e7) break;
    }

    if (cnt >= 1e7) {
        reaches[u] = true;
    }

    return cnt;
}

int main() {
    int n, e; cin >> n >> e;
    vector<vector<int>> adjL(n);

    for (int i = 0; i < e; ++i) {
        int u, cnt; cin >> u >> cnt;
        u--;
        while (cnt--) {
            int v; cin >> v;
            v--;
            adjL[u].push_back(v);
        }
    }

    int cnt = 0;
    vector<bool> reaches (n, false);
    for (int i = 0; i < n; ++i) {
        if (reaches[i]) {
            cnt++;
            continue;
        }
        vector<bool> visited (n, false);
        if (dfs(i, visited, reaches, adjL) >= n) {
            reaches[i] = true;
            cnt++;            
        }
    }

    cout << cnt << endl;
}