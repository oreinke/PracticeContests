#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, char> a, pair<int, char> b) {
  if (a.first > b.first) {
    return true;
  }
  else if (a.first < b.first) {
    return false;
  }
  else if (a.second < b.second) {
    return true;
  }
  return false;
}

int main() {
    string str; cin >> str;
    vector<pair<int, char>> freq (26);
    for (int i = 0; i < 26; ++i) {
        freq[i].first = 0;
        freq[i].second = 'a' + i;
    }
    for (char c : str) freq[c - 'a'].first++;
    sort(freq.begin(), freq.end(), comp);
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < freq[i].first; ++j) cout << freq[i].second;
    }
    cout << endl;

}