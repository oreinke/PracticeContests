#include <bits/stdc++.h>

using namespace std;

int main() {
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double a = sqrt((y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2));
    double b = sqrt((y3 - y2) * (y3 - y2) + (x3 - x2) * (x3 - x2));
    double c = sqrt((y1 - y3) * (y1 - y3) + (x1 - x3) * (x1 - x3));
    double area = .25  * sqrt(4 * a * a * b * b - (a * a + b * b - c * c) * (a * a + b * b - c * c));
    double newRad = area * 2 / (a + b + c);
    double oldRad;
    cin >> oldRad;
    cout << ((oldRad - newRad) / oldRad) * -100;
}