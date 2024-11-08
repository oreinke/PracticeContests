#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long sX, sY, nX, nY;
    cin >> sX >> sY;

    long long bestX, bestY;
    cin >> bestX >> bestY;
    n--;

    while (n > 0) {
        cin >> nX >> nY;
        long long dist =(sX - nX) * (sX - nX) + (sY - nY) * (sY - nY);
        if (((sX - nX) * (sX - nX) + (sY - nY) * (sY - nY)) < ((sX - bestX) * (sX - bestX) + (sY - bestY) * (sY - bestY)) || (((sX - nX) * (sX - nX) + (sY - nY) * (sY - nY)) == ((sX - bestX) * (sX - bestX) + (sY - bestY) * (sY - bestY)) && (nX < bestX || (nX == bestX && nY < bestY)))) {
            bestX = nX;
            bestY = nY;
        }
        n--;
    }

    cout << bestX << " " << bestY << "\n";

}