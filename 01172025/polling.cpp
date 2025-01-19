/* Original Code: 
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int nContestants = 0;
    map<string, int> mappings;
    set<string> names;
    vector<int> cnt;
    int max = 0;
    for (int i = 0; i < n; ++i) {
        string str; cin >> str;
        names.insert(str);
        if (mappings.find(str) == mappings.end()) {
            mappings[str] = nContestants;
            nContestants++;
            cnt.push_back(1);
        }
        else {
            cnt[mappings[str]]++;
        }

        if (cnt[mappings[str]] > max) {
            max = cnt[mappings[str]];
        }
    }

    vector<string> winners;
    for (string name : names) {
        if (cnt[mappings[name]] == max) {
            winners.push_back(name);
        }
    }
    sort(winners.begin(), winners.end());
    for (string name : winners) {
        cout << name << endl;
    }
}

simplied code:
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int max = 0;
    vector<string> winners;
    map<string, int> cnt;
    for (int i = 0; i < n; ++i) {
        string name; cin >> name;
        cnt[name]++;
        if (cnt[name] > max) {
            max = cnt[name];
            winners.clear();
            winners.push_back(name);
        }
        else if (cnt[name] == max) {
            winners.push_back(name);
        }
    }

    sort(winners.begin(), winners.end());
    for (string str : winners) {
        cout << str << endl;
    }
}