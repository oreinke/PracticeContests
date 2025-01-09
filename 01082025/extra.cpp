#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        double d;
        cin >> n >> d;
        double distance = 0;
        for (int i = 0; i < n; ++i) {
            double step;
            cin >> step;

            distance += d / step;
            // cout << "d: " << d << ", step: " << step << ". distance: " << distance << ", i = " << i << endl; 
        }
        // if ((int (distance * 1000)) % 10 >= 5) {
        //     distance += .01;
        // }
        printf("%.2f\n", distance);

    }
}