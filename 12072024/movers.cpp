#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, p, q;
    cin >> n >> p >> q;
    vector<int> initDesks(n);
    vector<int> initMonitors(n);

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        initDesks[i] = num;
    }
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        initMonitors[i] = num;
    }
    
    vector<vector<int>> grouping(n);
    for (int i = 0; i < p; i++) {
        int s, d;
        cin >> s >> d;
        s--;
        d--;
        grouping[s].push_back(d);
        grouping[d].push_back(s);
    }

    

    

    vector<int> desks(n, 0);
    vector<int> monitors(n, 0);
    for (int i = 0; i < n; i++) {
        for (int neigh : grouping[i]) {
            desks[i] += initDesks[neigh];
            monitors[i] += initMonitors[neigh];
        }
    }
    
    for (int i = 0; i < n; i++) {
        desks[i] += initDesks[i];
        monitors[i] += initMonitors[i];
    }
    //cout << q << endl;
    //fflush(stdout);
    
    for (int query = 0; query < q; query++) {
        string cmd;
        cin >> cmd;     

        if (cmd[0] == 'c') {
            int check;
            cin >> check;
            check--;
            // cout << monitors[check] << " " << desks[check] << endl;
            if (desks[check] > monitors[check]) {
                cout << "desks\n";
            }
            else if (monitors[check] > desks[check]) {
                cout << "monitors\n";
            }
            else {
                cout << "same\n";
            }
        }
        else {
            int add, target;
            string type;
            add;
           
            cin >> add >> type >> target;
            target--;
            if (type == "monitor") {
                monitors[target] += add;
                for (int pair : grouping[target]) {
                    // cout << "adding " << add << " to " << pair + 1 << endl;
                    monitors[pair] += add;
                }
            }
            else {
                desks[target] += add;
                for (int pair : grouping[target]) {
                    desks[pair] += add;
                }
            }
        }
    }
    fflush(stdout);
}