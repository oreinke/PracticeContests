#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    
    for (int tc = 1; tc <= t; ++tc) {
        int n; cin >> n;
        vector<int> cars, members;
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            cars.push_back(num);
            cars.push_back(num);
            cars.push_back(num);
            cars.push_back(num);
        }

        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            members.push_back(num);
            cin >> num;
            members.push_back(num);
            cin >> num;
            members.push_back(num);
            cin >> num;
            members.push_back(num);
        }
        sort(cars.begin(), cars.end());
        sort(members.rbegin(), members.rend());
        int worst = 0;
        for (int i = 0; i < n * 4; ++i) {
            worst = max(worst, cars[i] + members[i]);
        }
        printf("Trip #%d: %d\n", tc, worst);

    }
}