#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;
    vector<int> trie(26, 0);
    for (int i = 0; i < str.size(); i++) {
        trie[str[i] - 'a']++;
    }

    char chr;
    vector<char> wordBack;
    for (int i = 0; i < 26; i++) {
        if (trie[i] > 1) {
            for (int j = 0; j < trie[i] / 2; j++) {
                chr = ('a' + i);
                cout << chr;
                wordBack.push_back(chr);
            }

            trie[i] %= 2;
        }
    }

    // check for single chars, we are garunteed there is only 1 odd letter
    for (int i = 0; i < 26; i++) {
        if (trie[i] == 1) {
            chr = ('a' + i);
            cout << chr;
            break;
        }
    }

    for (int i = wordBack.size() - 1; i >= 0; i--) {
        cout << wordBack[i];
    }
}