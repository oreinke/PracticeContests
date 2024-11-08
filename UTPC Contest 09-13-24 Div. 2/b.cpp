#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    k++;
    string num;
    cin >> num;
    int i = 0, j = 0;

    int max = 0;
    int cur = 1;
    int count = 0;
    if (num[0] == '2') {
        count++;
    }
    while (i < n) {
        // case where no k allowed and we're on a k w/ length 1
        if (i == j && count == k) {
            count--;
            i++;
            j++;
            if (num[i] == '2') {
                count++;
            }
        }

        if (count < k && j < n - 1) {
            j++;
            cur++;
            if (num[j] == '2') {
                count++;
            }
            if (cur > max && count < k) {
                max = cur;
            }
        }
        else {
            cur--;
            if (num[i] == '2') {
                count--;
            }
            i++;
            if (cur > max && count < k) {
                max = cur;
            }
        }
    }
    cout << max;
}