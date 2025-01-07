#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, char>>> rooms(n + 1);
    
    while (m--) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        
        rooms[a].emplace_back(b, c);
        rooms[b].emplace_back(a, c);


    }
    
    string seq;
    cin >> seq;
    vector<double> cnt (n + 1, 0);
    
    cnt[1] = 1.0;
    for (int i = 0; i < seq.size(); ++i) {
        vector<double> frontier (n + 1, 0);
        frontier[n] = cnt[n];
        for (int j = 1; j < n; ++j)
        {
            if (cnt[j] > 0) {
                vector<int> nextRooms;
                for (auto &[x, y] : rooms[j]) {
                    if (y == seq[i]) {
                        nextRooms.push_back(x);
                    }
                }
                if (nextRooms.size() > 0) {
                    for (int room : nextRooms) {
                        frontier[room] += cnt[j] / nextRooms.size();
                    }
                }
                else {
                    frontier[j] += cnt[j];
                }

            }
            
        }
        cnt = frontier;        
    }
    cout << fixed << setprecision(9) << (cnt[n] * 100.0) << endl;    

}