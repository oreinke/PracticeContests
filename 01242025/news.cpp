#include <bits/stdc++.h>

using namespace std;



int bfs(int root, vector<int> &parents, vector<bool> visited, map<int, int> &memo) {
    queue<int> frontier;
    frontier.push(root);
    visited[root] = true;
    int steps = 0;
    while (!frontier.empty()) {
        steps++;
        // cout << "Hit, steps: " << steps << endl;
        queue<int> next;
        while (!frontier.empty()) {
            int node = frontier.front();
            frontier.pop();
            int spread = -1;
            int deep = -1;
            int children = -1;;
            for (int i = 0; i < parents.size(); ++i) {
                if (visited[i] || parents[i] != node) continue;
                // cout << "hit, pnode: " << node << ", cnode: " << i << endl;
                fflush(stdout);
                if (memo.find(i) == memo.end()) {
                    memo[i] = bfs(i, parents, visited, memo); 
                }
                int offer = memo[i];
                // cout << "Not hit\n";
                fflush(stdout);
                if (offer > deep) {
                    spread = i;
                    deep = offer;
                }

            }
            if (spread != -1) {
                next.push(node );
                next.push(spread);
                visited[spread] = true;
            }
        }
        frontier = next;
    }
    return steps - 1;
 
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> parent (n);
        vector<bool> visited (n, false);
        parent[0] = 0;
        visited[0] = true;
        map<int, int> memo;
        for (int i = 1; i < n; ++i) cin >> parent[i];
        // queue<int> frontier;
        // frontier.push(0);
        // int steps = 0;
        // while (!frontier.empty()) {
        //     steps++;
        //     // cout << "Hit, steps: " << steps << endl;
        //     queue<int> next;
        //     while (!frontier.empty()) {
        //         int node = frontier.front();
        //         frontier.pop();
        //         int spread = -1;
        //         int deep = -1;
        //         int children = -1;;
        //         for (int i = 0; i < n; ++i) {
        //             if (visited[i] || parent[i] != node) continue;
        //             // cout << "hit, pnode: " << node << ", cnode: " << i << endl;
        //             fflush(stdout);
        //             int offer = depth(i, parent, visited);
        //             // cout << "Not hit\n";
        //             fflush(stdout);
        //             if (offer > deep) {
        //                 spread = i;
        //                 deep = offer;
        //             }
        //             else if (offer == deep && (nChildren(i, parent) > nChildren(spread, parent))) {
        //                 spread = i;
        //                 deep = offer;
        //             }
        //         }
        //         if (spread != -1) {
        //             next.push(node );
        //             next.push(spread);
        //             visited[spread] = true;
        //         }
        //     }
        //     frontier = next;
        // }
        cout << bfs(0, parent, visited, memo) <<endl;
    }



}