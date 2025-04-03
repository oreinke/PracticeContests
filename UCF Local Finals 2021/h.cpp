#include <bits/stdc++.h>

using namespace std;

// void mark ()
vector<bool> visited;
void dfs (int u, vector<int> &out, vector<vector<int>> &adjL) {
    visited[u] = true;
    for (int v : adjL[u]) {
        if (!visited[v]) dfs(v, out, adjL);
    }
    out.push_back(u);
}

void dfs (int u, vector<int> &out, vector<set<int>> &adjL) {
    visited[u] = true;
    for (int v : adjL[u]) {
        if (!visited[v]) dfs(v, out, adjL);   
    }
    out.push_back(u);
}


int main() {
    int n, e; cin >> n >> e;
    vector<vector<int>> adjL(n), adjLT(n);

    for (int i = 0; i < e; ++i) {
        int u, cnt; cin >> u >> cnt;
        u--;
        while (cnt--) {
            int v; cin >> v;
            v--;
            adjL[u].push_back(v);
            adjLT[v].push_back(u);
            // printf("%d -> %d\n", u, v);
        }
    }

    visited.assign(n, false);
    vector<int> out;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) dfs(i, out, adjL);
    }
    // for (int i : out) cout << i << ", ";
    // cout << endl;

    visited.assign(n, false);
    reverse(out.begin(), out.end());
    vector<vector<int>> comps;
    vector<int> roots (n);
    int root = -1;
    for (int u : out) {
        if (!visited[u]) {
            vector<int> comp;
            dfs(u, comp, adjLT);
            for (int v : comp) roots[v] = comp[0];
            if (root == -1) root = comp[0];
            comps.push_back(comp);
            // for (int c : comp) cout << c << ", ";
            // cout << endl;
            // printf("root: %d\n", root);
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     printf("%d has root %d\n",i, roots[i]);
    // }

    vector<set<int>> adjLcond (n);
    for (int u = 0; u < n; ++u) {
        for (int v : adjL[u]) {
            if (roots[u] != roots[v]) {
                adjLcond[roots[u]].insert(roots[v]);
                //cout << "added edge from " << roots[u] << " to " << roots[v] << endl;
            }
        }
    }

    visited.assign(n, false);
    vector<int> res;
    dfs(root, res, adjLcond);
    //printf("res size: %d, comps size: %d\n", res.size(), comps.size());
    if (res.size() == comps.size()) {
        cout << comps[0].size() << endl;
    }
    else {
        cout << "0\n";
    }
}