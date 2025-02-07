#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, p, q; cin >> k >> p >> q;
    priority_queue<pair<int, int>> remaining;
    for (int i = 1; i <= k; ++i) {
        int cnt; cin >> cnt;
        if (i == p) {
            cnt--;
        }
        if (i == q) {
            cnt--;
        }
        if (cnt > 0) {
            remaining.push({cnt, i});
        }
    }

    vector<int> answer;
    answer.push_back(p);
    bool wompWomp = false;
    while (!remaining.empty() && !wompWomp) {
        auto top = remaining.top(); remaining.pop();
        if (top.second == answer.back()) {
            if (remaining.empty()) {
                wompWomp = true; 
                break;
            }
            auto sec = remaining.top(); remaining.pop();
            remaining.push({top.first, top.second});
            answer.push_back(sec.second);
            if (sec.first > 1) {
                remaining.push({sec.first, sec.second - 1});
            }
        }
    }

    if (!wompWomp) {
        if (answer[answer.size() - 1] == q) { // need to find replacement
            bool found = false;
            // try inserting
            if (answer[answer.size() - 2] != q) {
                for (int i = answer.size() - 2; i > 0 && !found; --i) {
                    int shimmy = answer[answer.size() - 1];
                    if (answer[i] != shimmy && answer[i - 1] != shimmy) {
                        answer.insert(answer.begin() + i, shimmy);
                        answer.pop_back();
                        found = true;
                    }
                }
            }
            if (!found) {
                // try swap
                // last 2
                if (answer[answer.size() - 1] != answer[answer.size() - 3] && answer[answer.size() - 2] != q) {
                    int temp = answer[answer.size() - 1];
                    answer[answer.size() - 1] = answer[answer.size() - 2];
                    answer[answer.size() - 2] = temp;
                }
                else {
                    for (int i = answer.size() - 3; i > 0; --i) {
                        if (answer[answer.size() - 1])
                    }
                }


            }

            if (!found) {
                wompWomp = true;
            }
        }

    }
}