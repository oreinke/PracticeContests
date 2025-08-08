#include<bits/stdc++.h>

using namespace std;

int main() {
    long long cnt = 0;
    for (int x = 0; x < 100; ++x) {
        for (int y = 0; y < 100 && ((x * x + y * y) < 10000); ++y) cnt++;
    }
    cout << cnt - 1 << endl;
}