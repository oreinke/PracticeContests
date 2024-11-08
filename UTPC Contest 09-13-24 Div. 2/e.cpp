#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n, d, x;
    cin >> n, d, x;
    vector<int> candies(n);

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        candies[i] = c;
    }

    map<int, ll, greater<long long>> taste;
    for (int i = 0; i < n; i++) {
        ll c;
        cin >> c;
        if (taste.find(c) != taste.end()) {
            c += (*taste.find(c)).second;
        }
        taste.insert({c, candies[i]});
    }

    ll sum = 0;
    while (d > 0 && !taste.empty()) {
        if (taste.size() < x) {
            x = taste.size();
        }
        auto it = taste.begin();
        for (int i = 0; i < x; i++) {
            sum += (*it).first;
            if ((*it).second == 1) {
                taste.erase((*it).first);
            }
            else {
                taste.insert({(*it).first, (*it).second - 1});
            }

            it++;
        }
        cout << sum << "\n";
    }

}