#include <bits/stdc++.h>

using namespace std;

int dfs(int u, vector<set<int>> &adj, vector<bool> &visited) {
    if (visited[u]) return 0;
    visited[u] = true;
    int sum = 1;
    for (int v : adj[u]) {
        sum += dfs(v, adj, visited);
    }
    return sum;
}

// 0 = unexplored, 1 = currently exploring, 2 = explored
bool hasCycle(int u, int p, vector<set<int>> &adj, vector<int> &exploring) {
    if (exploring[u] == 2) return false;
    if (exploring[u] == 1) return true;
    
    exploring[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (hasCycle(v, u, adj, exploring)) {
            return true;
        }
    }
    exploring[u] = 2;

    return false;
}

int main() {
    int t; cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int nodes, edges; cin >> nodes >> edges;
        vector<set<int>> adj (nodes);
        for (int i = 0; i < edges; ++i) {
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].insert(v);
            adj[v].insert(u);
        }

        int nComponents = 0;
        int cyclic = 0;
        vector<bool> visited (nodes, false);
        for (int i = 0; i < nodes; ++i) {
            if (visited[i]) continue;
            
            int cnt = dfs(i, adj, visited);
            if (cnt > 1) {
                nComponents++;
            }
            vector<int> exploring (nodes, 0);
            if (hasCycle(i, i, adj, exploring)) {
                cyclic++;
            }
        }
        printf("Night sky #%d: %d constellations, of which %d need to be fixed.\n\n", tc, nComponents, cyclic);
    }

}