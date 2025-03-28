#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    while (n != 0) {
        vector<int> inD (n, 0);
        vector<set<int>> adjL (n);

        for (int i = 0; i < m; ++i) {
            int u, v; cin >> u >> v;
            u--; v--;
            // printf("u: %d, v: %d\n", u, v);
            adjL[u].insert(v);
            inD[v]++;
        }

        queue<int> next;
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (inD[i] == 0) {
                next.push(i);
                res.push_back(i);
            }
        }

        bool two = false;
        if (next.size() > 1) two = true;
        
        while (!next.empty()) {
            queue<int> zeros;
            while (!next.empty()) {
                int u = next.front(); next.pop();
                // cout << "HIT, popping: " << u << endl;
                for (int v : adjL[u]) {
                    inD[v]--;
                    if (inD[v] == 0) {
                        
                        res.push_back(v);
                        zeros.push(v);
                    }
                }
            }

            if (zeros.size() > 1) two = true;
            next = zeros;
        }
        //cout << "res size: " << res.size() << endl;
        if (res.size() < n) {
            cout << "0\n";
        }
        else if (two) {
            cout << "2\n";
        }
        else {
            cout << "1\n";
        }
        

        cin >> n >> m;
    }

}