#include <bits/stdc++.h>

using namespace std;

int main () {
    int c << cin;
    while (c > 0) {
        int n << cin;
        vector<int> left;
        vector<int> right;

        for (int i= 0; i < n; i++) {
            if (i % 2 == 0) {
                int num;
                num << cin;
                left.push_back(num);
            }
            else {
                int num;
                num << cin;
                right.push_front(num);
            }
        }
        for (int i = 0; i < left.size(); i++) [
            cout << left[i] + " ";
        ]
        for (int i = 0; i < right.size(); i++) [
            cout << right[i];
            if (i != right.size() - 1) {
                cout <<  " ";
            }
        ]
        cout << "\n";

        c--;
    }
}