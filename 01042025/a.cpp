#include <bits/stdc++.h>

using namespace std;
bool cycleCheck(int u, vector<int> &visited, vector<vector<int>> &adj) {
    visited[u] = 1;

    for (int v : adj[u]) {
        if (visited[v] == 1)
            return true;
        else if (visited[v] == 0 && cycleCheck(v, visited, adj))
            return true;
    }

    visited[u] = 2;
    return false;
}

int main () {
    int n;
    cin >> n;
    map<string, int> ind;
    vector<vector<int>> adj(2 * n);
    int cnt = 0;
    
    for (int i = 0; i < n; ++i) {
        string d1, d2;
        char c;
        cin >> d1 >> c >> d2;
        if (ind.find(d1) == ind.end()) {
            ind[d1] = cnt;
            cnt++;
        }
        if (ind.find(d2) == ind.end()) {
            ind[d2] = cnt;
            cnt++;
        }
        if (c == '>') {
            adj[ind[d1]].push_back(ind[d2]);
        }
        else {
            adj[ind[d2]].push_back(ind[d1]);
        }
    }
    
    vector<int> visited(cnt, 0);
    bool result = false;
    for (int i = 0; i < cnt; ++i) {
        if (result) {
            break;
        }
        if (visited[i] == 0) {
            result = cycleCheck(i, visited, adj);
        }
    }
    if (result) {
        cout << "im";
    }   
    cout << "possible\n";
}