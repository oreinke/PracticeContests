#include <bits/stdc++.h>

using namespace std;

int main() {
    int max1 = 0;
    int max2 = 0;
    vector<int> max1indices;
    vector<int> max2indices;
    vector<int> range;
    int n;
    cin >> n;

    if (n == 1) {
        cout << 0 << "\n";
    }
    

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        range.push_back(c);

        if (c > max1) {
            max2 = max1;
            max2indices = max1indices;
            max1 = c;
            max1indices.clear();
            max1indices.push_back(i);
        }
        else if (c == max1) {
            max1indices.push_back(i);
        }
        else if (c > max2) {
            max2 = c;
            max2indices.clear();
            max2indices.push_back(i);
        }
        else if (c == max2) {
            max2indices.push_back(i);
        }
    }
    long long sum = 0;
    if (max1indices.size() > 1) {
        for (int i = max1indices[0] + 1; i < max1indices[max1indices.size() - 1]; i++) {
            sum += max1 - range[i];
        } 
    }
    else if (max2indices.size() > 1) {
        int skip = max1indices[0];
        for (int i = max2indices[0] + 1; i < max2indices[max2indices.size() - 1]; i++) {
            if (i == skip) {
                continue;
            }
            sum += max2 - range[i];
        } 
    }
    else {
        int start, end;
        if (max1indices[0] > max2indices[0]) {
            start = max2indices[0];
            end = max1indices[0];
        }
        else {
            start = max1indices[0];
            end = max2indices[0];
        }
        for (int i = start + 1; i < end; i++) {
            sum += max2 - range[i];
        } 
    }

    printf("%d\n", sum);
}