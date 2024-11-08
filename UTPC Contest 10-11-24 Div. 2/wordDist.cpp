#include <bits/stdc++.h>

using namespace std;

int main() {
    // idk the actual i/o specifications.
    // assuming n (num words) give and then words are space seperated
    int n;
    cin >> n;

    string str1, str2;
    cin >> str1 >> str2;

    int index1 = -1;
    int index2 = -1;
    int max = -1;

    for (int i = 0; i < n; i++) {
        string newStr;
        cin >> newStr;
        if (newStr == str1) {
            index1 = i;
            if (index2 != -1 && (index1 - index2 < max || max == -1)) {
                max = index1 - index2;
            }
        }
        else if (newStr == str2) {
            index2 = i;
            if (index1 != -1 && (index2 - index1 < max || max == -1)) {
                max = index2 - index1;
            }
        }
    }

    cout << max << "\n";
}