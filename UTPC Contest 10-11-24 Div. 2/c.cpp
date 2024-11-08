#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> answer;
    for (int i = n; i > k; i--) {
        answer.push_back(i);
    }

    for (int i = 1; i <= k; i++) { 
        answer.push_back(i);
    }    

    for (int i = 0; i < n; i++) {
        cout << answer[i];
        if (i != n - 1) {
            cout << " ";
        }
    }


}