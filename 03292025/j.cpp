#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    int t; cin >> t;
    getline(cin, str);
    while (t--) {
        getline(cin, str);
        if (str[0] == 'e') {
            str = str.substr(2);
            string res = "";
            int sum = 0;
            if (!str.empty() && str.back() == '\r') {
                str.pop_back();
            }
            for (char c : str) {
                // if (c == str[str.length() - 1]) break;
                int newC = ' ';

                if (c != ' ') {
                    sum += c + 1 - 'a';
                }
                if (sum % 27 != 0) {
                    newC = 'a' - 1 + (sum % 27);
                }
                // printf("C: %c, sum: %d, newChar: %c\n", c, sum, newC);
                res += newC;
            }
            // cout << "|";
            for (char c : res) {
                printf("%c", c);
            }
            
            cout << "\n";
        }
        else {
            str = str.substr(2);
            string res = "";
            int prev = 0;
            if (!str.empty() && str.back() == '\r') {
                str.pop_back();
            }
            for (char c : str) {
                // if (c == str[str.length() - 1]) break;
                int newC = ' ';
                int cur = 0;
                if (c != ' ') {
                    cur = c - 'a' + 1;
                }
                if ((27 + cur - prev) % 27 != 0) {
                    newC = 'a' - 1 + ((27 + cur - prev) % 27);
                }
                // printf("C: %c, sum: %d, newChar: %c\n", c, sum, newC);
                res += newC;
                prev = cur;
            }
            // cout << "|";
            for (char c : res) {
                printf("%c", c);
            }
            cout << "\n";
        }
    }
}