#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, w, h; cin >> l >> w >> h;
    int x, y, a; cin >> x >>  y >> a;
    long double pi = acosl(-1);
    long double x2 = cosl(a * pi / 180) * h + x;
    long double y2 = sinl(a * pi / 180) * h + y;
    if (x2 < -.001  || x2 > w + .001 || y2 < -.001 || y2 > l + .001) cout << "NO\n";
    else cout << "YES\n";
    // printf("x2: %Lf, y2: %Lf\n", x2, y2);
}