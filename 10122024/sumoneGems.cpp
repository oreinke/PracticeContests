#include <bits/stdc++.h>

using namespace std;

int main() {
    int start = 24;
    int terms[] = {-150, -75, -38, 77, 169, 305};


    unordered_set<int> visited;
    visited.insert(start);

    vector<int> nums;
    nums.push_back(start);

    while (!nums.empty() && visited.find(0) == visited.end()) {
        vector<int> next;
        for (int proposed : nums) {
            for (int term : terms) {
                if (proposed + term >= 0 && proposed + term <= 1e3 && visited.find(proposed + term) == visited.end()) {
                    next.push_back(proposed + term);
                    visited.insert(proposed + term);
                }
            }
        }
        nums = next;
    }

    if (visited.find(0) != visited.end()) {
        cout << "Found!\n";
    }
    else {
        cout << "Not possible :(\n";
    }
}