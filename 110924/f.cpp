#include <bits/stdc++.h>
#include <bit>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> students;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        int num = 0;
        for (int j = 0; j < k; j++) {
            num = num << 1;
            if (str[j] == 'T') {
                num += 1;
            }
        }
        students.push_back(num);
    }

    int globalMin = 0;
    for (int i = 0; i < 1 << k + 1; i++) {
        int m = 9000000;
        // cout << i << endl;
        for (int j = 0; j < n; j++) {
            int key = i;
            int num = students[j];
            int count = 0;
            for (int z = 0; z < k; z++) {
                if ((num & 1) == (key & 1)) {
                    count++;
                }
                key = key >> 1;
                num = num >> 1;
            }
            m = min(m, count);
        }
        globalMin = max(m, globalMin);
    }
    cout << globalMin << "\n";
}