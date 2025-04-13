#include <bits/stdc++.h>

using namespace std;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic (int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge (int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap == edges[id].flow) continue;
                if (level[edges[id].u] != -1) continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0) return 0;
        if (v == t) return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); ++cid) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u]) continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0) continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }
    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs()) break;
            fill(ptr.begin(), ptr.end(), 0);
            while(long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

void dfs (int r, int c, vector<string> &res, vector<string> &grid, vector<vector<bool>> &visited) {
    if (r >= grid.size() || r < 0 || c >= grid[0].size() || c < 0 || visited[r][c] ||  grid[r][c] == '#') return;
    if (grid[r][c] - 'A' >= 0 && grid[r][c] - 'A' < 26) {
        res[0] += grid[r][c];
    }
    else if (grid[r][c] - 'a' >= 0 && grid[r][c] - 'a' < 26) {
        res[1] += grid[r][c];
    }
    visited[r][c] = true;
    dfs(r - 1, c, res, grid, visited);
    dfs(r, c - 1, res, grid, visited);
    dfs(r, c + 1, res, grid, visited);
    dfs(r + 1, c, res, grid, visited);
}


int main() {
    int t; cin >> t;
    while (t--) {
        // cout << "-----------------------------\n";
        int r, c; cin >> r >> c;
        int s, v; cin >> s >> v;
        vector<string> grid (r), sci(s);
        for (auto &x : grid) cin >> x;
        for (auto &x : sci) cin >> x;
        // cout << "grid\n";
        // for (string str : grid) cout << str << endl;
        unsigned long long cnt = 0;
        vector<vector<bool>> visited (r, vector<bool> (c, false)); 
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (!visited[i][j] && grid[i][j] != '#') {
                    vector<string> res (2, "");
                    // printf("here!\n"); fflush(stdout);

                    dfs(i, j, res ,grid, visited);
                    // printf("i: %d, j: %d\n", i, j);
                    // cout << res[0] << endl;
                    // cout << res[1] << endl;
                    if (res[0].size() > 0 && res[1].size() > 0) {
                        vector<int> freq(26, 0);
                        for (char c : res[1]) {
                            freq[c - 'a']++;
                        }
                        
                        int numNodes = 2 + 26 + res[0].size();
                        Dinic g = Dinic(numNodes, 0, numNodes - 1);
                        for (int i = 0; i < res[0].size(); ++i) {
                            g.add_edge(0, i + 1, 1);
                            for (char c : sci[res[0][i] - 'A']) {
                                g.add_edge(i + 1, c - 'a' + 1 + res[0].size(), 1);
                            }
                        }

                        for (int i = 0; i < 26; ++i) {
                            g.add_edge(1 + res[0].size() + i, numNodes - 1, freq[i]);
                        }

                        cnt += g.flow();
                    }
                }
            
            }
        }
        cout << (int) cnt << endl;

    }
}