#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;
    vector<int> current;
    // cout << str << endl;
    for (int i = 0; i < str.length(); i++) {
        // cout << "cur char: " << 
        if (str[i] == '(') {
            // cout << "hit?" << endl;
            current.push_back(-1);
        }
        else {
            current.push_back(0);
        }
        
    }

  
    while (current.size() > 1) {
        vector<int> next;
        
        for (int i = 0; i < current.size(); i++) {
            if (i == current.size() - 1) {
                next.push_back(current[i]);
            }
            else {
                if (current[i] == -1 && current[i + 1] == 0) {
                    next.push_back(1);
                    i++;
                }
                else if (i < current.size() - 2 && current[i] == -1 && current[i+ 1] > 0 && current[i + 2] == 0) {
                    next.push_back(current[i + 1] + 1);
                    i += 2;
                }
                else if (current[i] > 0 && current[i + 1] > 0) {
                    next.push_back(current[i] * current[i + 1]);
                    i++;
                }
                else {
                    next.push_back(current[i]);
                }
    
            }
        
            
        }
        current = next;
    }
    cout << current[0] << endl;
    

}