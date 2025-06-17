#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k; cin >> n >> k;
    k -= 1;
    
    
    if (k >= pow(2, n - 1)) {
        cout << "-1" << endl;
    }
    else {
        deque<int> nodes;
        for (int i = 1; i <= n; ++i) nodes.push_back(i);

        string bRep = "";
        while (k > 0) {
            bRep.append(to_string(k % 2));
            k /= 2;
        }
        while (bRep.size() < n - 1) bRep.push_back('0');
        reverse(bRep.begin(), bRep.end());

        for (int i = 0; i < n - 1; ++i) {
            if (bRep[i] == '0') {
                cout << nodes.front() << " ";
                nodes.pop_front();
            }
            else {
                cout << nodes.back() << " ";
                nodes.pop_back();
            }
        }
        cout << nodes.front() << endl;
    }
    
}