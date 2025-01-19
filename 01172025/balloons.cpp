#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    bool endOfInput = false;
    while (!endOfInput) {
        int n, a, b; cin >> n >> a >> b;
        if (n == 0 && a == 0 && b == 0) {
            endOfInput = true;
            break;
        }
        vector<int> teamC;
        vector<pair<int, int>> teamD;
        vector<pair<int, int>> disA, disB;
        for (int i = 0; i < n; ++i) {
            int num, aR, bR; cin >> num >> aR >> bR;
            teamC.push_back(num);
            teamD.emplace_back(aR, bR);
            disA.emplace_back(bR - aR, i);
            disB.emplace_back(aR - bR, i);
        }
        sort(disA.begin(), disA.end());
        sort(disB.begin(), disB.end());

        ull dist = 0;
        for (int i = disA.size() - 1; i >= 0; i--) {
            if (disA[i].first < 0) continue;
            if (a == 0) break;
            while (a > 0 && teamC[disA[i].second] > 0) {
                teamC[disA[i].second]--;
                a--;
                dist += teamD[disA[i].second].first;
            }
            // cout << "Ballon taken from A for group " << disA[i].second << ", c now: " << teamC[disA[i].second] << endl;


        }

        for (int i = disB.size() - 1; i >= 0; i--) {
            if (disB[i].first <= 0) continue;
            if (b == 0) break;
            while (b > 0 && teamC[disB[i].second] > 0) {
                teamC[disB[i].second]--;
                b--;
                dist += teamD[disB[i].second].second;
                // cout << "Ballon taken from B for group " << disB[i].second << ", c now: " << teamC[disB[i].second] << endl;

            }
        }

        for (int i = disA.size() - 1; i >= 0; i--) {
            if (a == 0) break;
            while (a > 0 && teamC[disA[i].second] > 0) {
                teamC[disA[i].second]--;
                a--;
                dist += teamD[disA[i].second].first;
            }
            // cout << "Ballon taken from A for group " << disA[i].second << ", c now: " << teamC[disA[i].second] << endl;


        }

        for (int i = disB.size() - 1; i >= 0; i--) {
            if (b == 0) break;
            while (b > 0 && teamC[disB[i].second] > 0) {
                teamC[disB[i].second]--;
                b--;
                dist += teamD[disB[i].second].second;
                // cout << "Ballon taken from B for group " << disB[i].second << ", c now: " << teamC[disB[i].second] << endl;

            }
        }
        /*
        for (int i = 0; i < teamC.size(); ++i) {
            while (teamC[i] > 0) {
                if (teamD[i].first < teamD[i].second) {
                    if (a > 0) {
                        a--;
                        teamC[i]--;
                        dist += teamD[i].first;
                        // cout << "Ballon taken from A for group " << disA[i].second << ", c now: " << teamC[disA[i].second] << endl;

                    }
                    else {
                        b--;
                        teamC[i]--;
                        dist += teamD[i].second;
                        // cout << "Ballon taken from B for group " << disB[i].second << ", c now: " << teamC[disB[i].second] << endl;

                    }
                }
                else {
                    if (b > 0) {
                        b--;
                        teamC[i]--;
                        dist += teamD[i].second;
                        // cout << "Ballon taken from B for group " << disB[i].second << ", c now: " << teamC[disB[i].second] << endl;

                    }
                    else {
                        a--;
                        teamC[i]--;
                        dist += teamD[i].first;
                        // cout << "Ballon taken from A for group " << disA[i].second << ", c now: " << teamC[disA[i].second] << endl;

                    }
                }
            }
        }
        */
        cout << dist << endl;
    }
}