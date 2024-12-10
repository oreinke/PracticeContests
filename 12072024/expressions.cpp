#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    int num;
    cin >> num;
    nums[0] = num % 2;
    int start = 0;
    map<int, int> stoe;
    map<int, int> numE;
    int numO = 0;
    int curNumE = (num + 1) % 2;
    for (int i = 1; i < n; i++) {
        string str;
        cin >> str >> num;
        nums[i] = num % 2;
        if (str[0] == '+') {
            stoe[start] = i - 1;
            numE[start] = curNumE;
            if (curNumE == 0) {
                numO++;
            }
            curNumE = 0;
            start = i;
        }
        else {
            curNumE += (num + 1) % 2;
        }
    }
    stoe[start] = n - 1;
            numE[start] = curNumE;
            if (curNumE == 0) {
                numO++;
            }

    if (numO % 2 == 1) {
        cout << "odd\n";
    }
    else {
        cout << "even\n";
    }

    for (int i = 0; i < m; i++) {
        int index, val;
        cin >> index >> val;
        index--;
        val = val % 2;
        if (nums[index] != val) {
            nums[index] = val;
            auto it = stoe.upper_bound(index);
            it--;
            int lb = it->first;
            if (val == 1) {
                numE[lb]--;
                if (numE[lb] == 0) {
                    numO--;
                }
            }
            else {
                if (numE[lb] == 0) {
                    numO--;
                }
                numE[lb]++;
            }
        }
        if (numO % 2 == 1) {
            cout << "odd\n";
        }
        else {
            cout << "even\n";
        }
    }
}