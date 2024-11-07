#include <bits/stdc++.h>

using namespace std;

int dfs(int node, stack<char> s, vector<bool> visited, vector<char> nodes, vector<vector<int>> adj) {
    if (visited[node]) {
        return 0;
    }
    visited[node] = true;

    int result = 0;

    if ('(' == nodes[node] || '[' == nodes[node] || '{' == nodes[node]) {
        s.push(nodes[node]);

        for (int d : adj[node]) {
            result += dfs(d, s, visited, nodes, adj);
        }

        s.pop();
    }
    else {
        if (!s.empty()) {
            char top = s.top();
            if (('(' == top && ')' == nodes[node]) || ('[' == top && ']' == nodes[node]) || ('{' == top && '}' == top)) {
                s.pop();

                if (s.empty()) {
                    result++;
                }

                for (int d : adj[node]) {
                    result += dfs(d, s, visited, nodes, adj);
                }

                s.push(top);
            }
        }
    }

    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    vector<char> nodes;
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {
        char buffer;
        scanf(" %c", &buffer);

        nodes.push_back(buffer);
    }

    for (int i = 0; i < n; i++) {
        int s, d;
        scanf(" %d %d", &s, &d);
        s--;
        d--;

        adj[s].push_back(d);
        adj[d].push_back(s);
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        vector<bool> visited(n, false);
        stack<char> q;

        result += dfs(i, q, visited, nodes, adj);
    }

    cout << result << "\n";
}