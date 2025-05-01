#include <bits/stdc++.h>

using namespace std;

bool check (double c, double t, vector<pair<int, double>> &arr) {
    double total= 0;
    for (auto [d, s] : arr) {
        if (s + c <= 0.0) return true;
        total += d / (s + c);
        if (total >= t) {
            //cout << "Bigger than speed\n";
             return true;
             
        }
    }
   // cout << "lower than speed\n";

    return false;
}

int main () {
    int n;
    double t;
    cin >> n>> t;
    double l = -10000, h = 100000000;
    vector<pair<int, double>> arr (n);
    for (int i = 0; i < n; ++i) {
        int d;
        double s;
        cin >> d >> s;
        arr[i] = {d, s};
    }
    //printf("t: %f, l: %f, h: %\n", t, l, h);
    while (h - l > .000000001) {
        double c = (l + h) / 2;
        //printf("c: %f, l: %f, h: %f\n", c, l, h);
        if (check(c, t, arr)) {
            l = c;
            //cout << "big\n";
        }
        else {
            h = c;
            //cout << "low\n";
        }
    }
    printf("%.6f\n", l);

}