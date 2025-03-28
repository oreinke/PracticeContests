#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;cin >> t;
    while (t) {
        int n, k; cin >> k >> n;
        set<string> cards;
        vector<string> cardArr;
        for (int i = 0; i < n; ++i) {
            string card = "";
            for (int j = 0; j < k; ++j) {
                
                string num; cin >> num;
                // cout << "!!" <<  num <<endl;
                card += num;
            }
            cardArr.push_back(card);
            cards.insert(card);
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                string str = "";
                for (int l = 0; l < k; ++l) {
                    if (cardArr[i][l] == cardArr[j][l]) {
                        str += cardArr[i][l];
                    }
                    else {
                        set<char> c;
                        c.insert(cardArr[i][l]);
                        c.insert(cardArr[j][l]);
                        if (c.count('0') == 0) {
                            str += '0';
                        }
                        else if (c.count('1') == 0) {
                            str += '1';
                        }
                        else {
                            str += '2';
                        }
                    }
                }
                if (cards.count(str)) cnt++;
            }
            
        }
        cout << cnt / 3 << endl;
        
        t--;
    }

}