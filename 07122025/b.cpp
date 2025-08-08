#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    while (n--) {
        string str; cin >> str;
        if (str.length() == 8 && str[0] - '0' > 0 && str[0] - '0' <= 9 && str[0] == str[1] && str[2] - '0' > 0 && str[2] - '0' <= 9 && str[3] - '0' > 0 && str[3] - '0' <= 9 && str[4] - 'A' >= 0 && str[4] - 'A' <= 25 && str[5] - '0' > 0 && str[5] - '0' <= 9 && str[6] - '0' > 0 && str[6] - '0' <= 9 && str[7] - '0' > 0 && str[7] - '0' <= 9) cout << str << endl;
    }
}