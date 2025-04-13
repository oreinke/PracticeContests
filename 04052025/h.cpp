#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, p, s, display; cin >> n >> p >> s >> display;
    vector<vector<pair<int,int>>> teams (n);
    vector<vector<int>>  penalty(n, vector<int> (p, 0));
    vector<set<int>> solves (n);
    for (int i = 0; i < s; ++i) {
        int team, prob, time, solved; cin >> team >>  prob >>  time >>  solved;
        // printf("here! %d. %d %d %d %d\n", i, team, prob, time ,solved); fflush(stdout);

        if (time >= 300 || solves[team - 1].count(prob) > 0) continue;
        if (solved == 1) {
            teams[team - 1].push_back({prob, time});
            solves[team - 1].insert(prob);
        }
        else {
            penalty[team - 1][prob - 1]++;
        }
    }

    vector<vector<int>> board (n);
    for (int i = 0; i < n; ++i) {
        board[i].push_back(-1 * teams[i].size());
        board[i].push_back(0);
        for (int j = teams[i].size() - 1; j >= 0; --j) {
            board[i].push_back(teams[i][j].second + 20 * penalty[i][teams[i][j].first - 1]);
            board[i][1] += teams[i][j].second + 20 * penalty[i][teams[i][j].first - 1];
        }
        board[i].push_back(i + 1);   
    }
    sort(board.begin(), board.end());
    // for (auto team : board) {
    //     for (auto num : team) cout << num << " ";
    //     cout << endl;
    // }
    vector<int> prev = board[0];
    int prevR = 1;
    for (int i = 0; i < n; ++i) {
        board[i][0] *= -1;
        // rank

        bool same = true;
        for (int j = 0; j < prev.size() - 1; ++j) {
            if (prev[j] != board[i][j]) {
                same = false;
                break;
            }
        }
        prev = board[i];
        if (!same) prevR = i + 1;
        if (prevR > display) break;
        printf("%-4d%-4d%3d%5d\n",prevR, board[i][board[i].size() - 1], board[i][0], board[i][1]);
    }

}