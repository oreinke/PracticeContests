#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int n, f; cin >> n >> f;
    string str; cin >> str;
    map<string, int> moos;
    for (int i = 0; i < n - 2; ++i) {
        if (str[i] != str[i + 1] && str[i + 1] == str[i + 2]) {
            string moo = str.substr(i, 3);
            moos[moo]++;
    
            // cout << "Cur Moo: |" << moo << "|\n";
            // fflush(stdout);
        }
    }

    if (f == 1) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (j == i) continue;
                string moo({char('a' + i), char('a' + j), char('a' + j)});
                moos[moo];
            }
        }
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (j == i) continue;
            string moo({char('a' + i), char('a' + j), char('a' + j)});
            if (moos[moo] == f - 1) {
                bool notFound = true;
                // cout << "in here, moo: |" << moo << "|\n"; 
                for (int k = 0; k < n - 2 && notFound; ++k) {
                    // wrong first letter
                    //cout << "|" << str[k] << "| |" << str[k + 1] << "| |" << str[k + 2] << "|\n";
                    //cout << "|" << moo[0] << "| |" << moo[1] << "| |" << moo[2] << "|\n";
                    if (str[k] != moo[0] && str[k + 1] == moo[1] && str[k + 2] == moo[2]) {
                        //cout << "in here \n";
                        if (k > 0) {
                            if (!(str.substr(k - 1, 3) == moo) && (k < 2 || !(str.substr(k - 2, 3) == moo))) {
                                moos[moo]++;
                                // cout << "dupMoo, fl, " << moo << endl;
                                notFound = false;
                                break;
                            }
                        }
                        else {
                            moos[moo]++;
                            notFound = false;
                            // cout << "dupMoo, fl, " << moo << endl;
                            break;
                        }
                    }
                    // wrong second letter
                    if (str[k] == moo[0] && str[k + 1] != moo[1] && str[k + 2] == moo[2]) {
                        if (k < (n - 3) && !(str.substr(k + 1, 3) == moo)) {
                            moos[moo]++;
                            notFound = false;
                            // cout << "dupMoo, sl, " << moo << endl;
                            break;
                        }

                    }
                    // wrong last letter
                    if (str[k] == moo[0] && str[k + 1] == moo[1] && str[k + 2] != moo[2]) {
                        if (k < (n - 4) ) {
                            if (!(str.substr(k + 2, 3) == moo)) {
                                moos[moo]++;
                                notFound = false;
                                // cout << "dupMoo, ll, " << moo <<", k: " << k << endl;
                                break;
                            }
                            
                        }
                        else {
                            moos[moo]++;
                            notFound = false;
                            // cout << "dupMoo, ll, " << moo <<", k: " << k << endl;
                            break;
                        }
                    }
                }
            }
        }
    }
    // cout << "HIT!" <<endl;
    fflush(stdout);

    vector<string> w;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (j == i) continue;
            string moo({char('a' + i), char('a' + j), char('a' + j)});
            if (moos[moo] >= f) {
                w.push_back(moo);
            }
        }
    }
    cout << w.size() << endl;
    sort(w.begin(), w.end());
    for (string s : w) cout << s << endl;




}