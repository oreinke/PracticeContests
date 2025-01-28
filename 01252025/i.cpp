#include <bits/stdc++.h>

using namespace std;


int main() {
    int a, b; cin >> a >> b;
    vector<string> nums (b - a + 1);
    for (auto &x : nums) cin >> x;
    
    int fizz =  a  + (b - a + 1);
    int first = -1, last = -1;
    for (int i = 0; i < nums.size() && last == -1; ++i) {
        if (nums[i] == "Fizz" || nums[i] == "FizzBuzz") {
            if (first == -1) {
                first = i;
            }
            else {
                last = i;
            }
        }
    }
    if (last != -1) {
        fizz = last - first;
    }
    int buzz = a  + (b - a + 1);
    first = -1;
    last = -1;
    for (int i = 0; i < nums.size() && last == -1; ++i) {
        if (nums[i] == "Buzz" || nums[i] == "FizzBuzz") {
            if (first == -1) {
                first = i;
            }
            else {
                last = i;
            }
        }
    }
    if (last != -1) {
        fizz = last - first;
    }
    cout << fizz << " " << buzz <<endl;


}