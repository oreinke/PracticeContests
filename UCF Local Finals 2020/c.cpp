#include <bits/stdc++.h>

using namespace std;

int main() {
    string str; cin >> str;
    int h = stoi(str.substr(0, 2));
    int m = stoi(str.substr(3, 2));
    int t = h * 60 * 60 + m * 60 - (h *60 + m);
    h = t / (60 * 60);
    t %= 60 * 60;
    m = t / 60;
    t %= 60;
    printf("%02d:%02d:%02d\n", h, m, t);
}