#include <bits/stdc++.h>

using namespace std;

int main() {
    string str; cin >> str;
    int m; cin >> m;
    set<char> chars;
    for (char c : str) chars.insert(c);
    int longest = 0;
    for (char c : str) {
        int len = 0;
        int rem = 0;
        int left = 0;
        int right = 0;
        if (str[0] == c) {
            len++;
        }
        else {
            rem++;
        }

        while (right < str.size() - 1) {
            if (rem > m) {
                if (str[left] == c) {
                    len--;
                }
                else {
                    rem--;
                }
                left++;
            }
            else {
                right++;
                if (str[right] == c) {
                    len++;
                    longest = max(longest, len);
                }
                else {
                    rem++;
                }
            }
        }
    }
    cout << longest << endl;
}