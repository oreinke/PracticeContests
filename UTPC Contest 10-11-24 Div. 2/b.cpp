#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    vector<int> times;
    cin >> n >> t;

    while(n > 0) {
        int num;
        cin >> num;
        times.push_back(num);
        n--;
    }

    sort(times.begin(), times.end());

    int count = 0;
    for (int i = 0; i < times.size(); i++) {
        if (t - times[i] < 0) {
            break;
        }
        t -= times[i];
        count++;
    }

    cout << count << "\n";

}