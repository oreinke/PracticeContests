#include <bits/stdc++.h>

using namespace std;


int gcd(int a, int b) {
    if (b > a) {
        int temp = b;
        b = a;
        a = temp;
    }
    
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> p (n), s(n);
        for (auto &x : p) cin >> x;
        for (auto &x : s) cin >> x;
        bool valid = true;
        for (int i = 1; i < n; ++i) {
            if (gcd(p[i - 1], p[i]) != p[i] || p[i] > p[i - 1]) valid = false;
        }

        for (int i = n - 2; i >= 0; --i) {
            if (gcd(s[i + 1], s[i]) != s[i] || s[i] > s[i + 1]) valid = false;
        }

        for (int i = 0; i < n; ++i) {
            if (gcd(s[i], p[i]) != s[i] && gcd(s[i], p[i]) != p[i]) valid = false;
        }

        if (p[0] != s[s.size() - 1] && (p[0] == p[[p.size() - 1]]))


        if (valid) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}