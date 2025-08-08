#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<string> arr (n);
    map<string, int> cntName;
    map<char, int> cntFirst;
    for (int i = 0; i < n; ++i) {
        string str; cin >> str;
        arr[i] = str;
        cntName[str]++;
        cntFirst[str[0]]++;
    }

    long long cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += cntFirst[arr[i][0]] - cntName[arr[i]];
    }

    cout << cnt << endl;
    
}