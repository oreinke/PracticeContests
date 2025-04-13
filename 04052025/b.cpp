#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<double> arr (10);
    for (auto &x : arr) cin >> x;
    double cnt = 0;
    for (double x : arr) cnt += x;

    cnt /= 10.0;

    double sum = 0;
    for (double x : arr) {
        sum += (x - cnt) * (x - cnt);
    }

    double ans = sqrt(sum / 9);
    if (ans > 1.0) {
        cout << "NOT ";
    }
    cout << "COMFY\n";


}