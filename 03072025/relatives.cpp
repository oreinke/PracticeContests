#include <bits/stdc++.h>

using namespace std;

int dfs (int u, vector<vector<int>> &adjL, vector<bool> &visited) {
    if (visited[u]) return 0;
    visited[u] = true;
    int cnt = 1;
    for (int v : adjL[u]) cnt += dfs (v, adjL, visited);
    return cnt;
}

int main () {
    int n, e; cin >> n >> e;
    int network = 0;
    while (n != 0) {
        network++;
        vector<vector<int>> adjL (n);
        map<string, int> mapping;

        for (int i = 0; i < e; ++i) {
            string uS, vS; cin >> uS >> vS;
            int u, v;
            if (mapping.find(uS) == mapping.end()) {
                mapping[uS] = mapping.size();
            }

            if (mapping.find(vS) == mapping.end()) {
                mapping[vS] = mapping.size();
            }

            u = mapping[uS];
            v = mapping[vS];
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }

        vector<bool> visited (n, false);
        int res = dfs(0, adjL, visited);
        if (res < n) {
            printf("Network %d: DISCONNECTED\n\n", network);
        }
        else {
            // find outlier
            int step = 0;
            deque<int> q;
            q.push_back(0);
            vector<bool> seen (n, false);
            seen[0] = true;
            int lastSeen = 0;
            while (!q.empty()) {
                deque<int> next;
                while (!q.empty()) {
                    int u = q.front(); q.pop_front();
                    for (int v : adjL[u]) {
                        if (!seen[v]) {
                            seen[v] = true;
                            next.push_back(v);
                            lastSeen = v;
                        }
                    }
                }
                q = next;
                step++;
            }

            step = 0;
            // cout << lastSeen << endl;
            q.push_back(lastSeen);
            for (int i = 0; i < n; ++i) seen[i] = false;
            seen[lastSeen] = true;
            while (!q.empty()) {
                // cout << "here!\n";
                deque<int> next;
                while (!q.empty()) {
                    int u = q.front(); q.pop_front();
                    for (int v : adjL[u]) {
                        // cout << "u: " << u << endl;
                        if (!seen[v]) {
                            seen[v] = true;
                            next.push_back(v);
                            lastSeen = v;
                            // cout << "adding v: " << v << endl;
                        }
                    }
                }
                q = next;
                step++;
            }
            printf("Network %d: %d\n\n", network, step - 1);


        }
        cin >> n >> e;
    }

    



}

