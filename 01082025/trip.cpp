#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        double a, c, ta, tc;
        cin >> a >> c >> ta >> tc;
        printf("%.2f\n", a * ta + c * tc);
    }
}