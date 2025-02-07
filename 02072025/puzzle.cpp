#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "123456780";
    map<string, int> visited;
    visited[s] = 0;
    queue<string> q;
    q.push(s);
    int step = 1;
    while (!q.empty()) {
        // printf("step: %d\n", step);
        queue<string> next;
        while (!q.empty()) {
            string cur = q.front(); q.pop();
            int ind = 0;
            for (int i = 0; i < 9; ++i) {
                if (cur[i] == '0'){
                    ind = i;
                    break;
                }
            }
            // cout << "HIT\n";
            vector<string> moves;
            if (ind + 3 < 9) {
                string move = cur;
                char temp = move[ind];
                move[ind] = move[ind + 3];
                move[ind + 3] = temp;
                moves.push_back(move);
            }
            if ((ind + 1 < 9) && (ind % 3 != 2)) {
                string move = cur;
                char temp = move[ind];
                move[ind] = move[ind + 1];
                move[ind + 1] = temp;
                moves.push_back(move);
            }
            if (ind - 3 >= 0) {
                string move = cur;
                char temp = move[ind];
                move[ind] = move[ind - 3];
                move[ind - 3] = temp;
                moves.push_back(move);
            }
            if ((ind - 1 >= 0) && (ind % 3 != 0)) {
                string move = cur;
                char temp = move[ind];
                move[ind] = move[ind - 1];
                move[ind - 1] = temp;
                moves.push_back(move);
            }

            for (string m : moves) {
                if (visited.find(m) == visited.end()) {
                    visited[m] = step;
                    next.push(m);
                }
            }
        }
        step++;
        q = next;        
    }

    int t; cin >> t;
    while (t--) {
        string check = "";
        for (int i = 0; i < 9; ++i) {
            char temp; cin >> temp;
            check += temp;
            // cout << temp <<endl;
            
        }
        // cout << "|" << check << "|";
        cout << visited[check] <<endl;

    }
}