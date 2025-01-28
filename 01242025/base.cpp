#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int k; cin >> k;
        string n; cin >> n;
        cout << tc << " ";
        int octDec = 0;
        for (int i = 0; i < n.length(); ++i) {
            if (n[n.size() - 1 - i] > '7') {
                octDec = 0;
                break;
            }
            else {
                //cout << n[n.size() - 1 - i] << ", " <<  n[n.size() - 1 - i] * pow(8, i) << endl;
                octDec += (n[n.size() - 1 - i] - '0') * pow(8, i);
            }
        }
        cout << octDec << " " << n << " ";
        
        int hex = 0;
        for (int i = 0; i < n.length(); ++i) {
            hex += (n[n.size() - 1 - i] - '0') * pow(16, i);
        }
        cout << hex << endl;
        
    }
}