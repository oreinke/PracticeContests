#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, e; cin >> n >> e;
        int total = 0;
        for (int i = 0; i < e; ++i) {
            int u, v; cin >> u >> v;
            if (u < v) total++;
        }

        if (total >= ((e / 2) + ((e % 2 == 1) ? 1 : 0))) {
            for (int i = 1; i <= n; ++i) {
                cout << i << " ";
            }
        }
        else {
            for (int i = n; i > 0; --i) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    
//     }
// }


    //     queue<int> zero;
    //     vector<int> res;
        // vector<bool> visited (n, false);
        // for (int i = 0; i < n; ++i) {
        //     if (inD[i] <= ((n / 2) + ((n % 2 == 1) ? 1: 0))) {
        //         res.push_back(i);
        //         zero.push(i);
        //         visited[i] = true;
        //     }
        // }

        
        // while (!zero.empty()) {
        //     queue<int> next;
        //     while (!zero.empty()) {
        //         int u = zero.front(); zero.pop();
        //         for (int v : adj[u]) {
    //                 inD[v]--;
    //                 if (inD[v] <= ((n / 2) + ((n % 2 == 1) ? 1: 0)) && !visited[v]) {
    //                     res.push_back(v);
    //                     next.push(v);
    //                     visited[v] = true;
    //                 }
    //             }
    //         }
    //         zero = next;
    //     }

    //     // cout << "RES SIZE: " << res.size() << endl;
    //     if (res.size() == n) {
    //         for (int num : res) {
    //             cout << num + 1 << " ";
    //         }
    //     }
    //     else {
    //         cout << "-1";
    //     }
    //     cout << endl;
    // }

