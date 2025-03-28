#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, e; cin >> n >> e;
    set<char> lang;

    for (int i = 0; i < e; ++i) lang.insert('a' + i);

    vector<string> keys (n);
    for (int i = 0; i < n; ++i) {
        cin >> keys[i];
        set<char> letters;
        for (char c : keys[i]) letters.insert(c);
        if (letters.size() == 1) {
            if (lang.find(*letters.begin()) != lang.end()) {
                lang.erase(*letters.begin());
            }
        }
    }

    if (lang.empty()) cout <<"NO\n";
    else {
        int strokes = 1e9;
        char let = '0';
        for (char letter : lang) {
            int total = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < keys[i].size(); ++j) {
                    if (keys[i][j] != letter) break;
                    total++;
                }
            }
            if (total < strokes) {
                strokes = total;
                let = letter;
            }
        }

        for (int i = 0; i <= strokes; ++i) {
            cout << let;
        }
        cout << endl;
    } 


}