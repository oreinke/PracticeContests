#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    string empty;
    getline(cin, empty);
    while (t--) {
        string str;
        getline(cin, str);
        str.pop_back();
        stringstream ss(str);
        string buf;
        char delim = ' ';
        int cnt = 0;
        string noSpaces = "";
        while (getline(ss, buf, delim)) {
            noSpaces += buf; 
            if (buf.size() >= 3) {
                int start = 0, end = buf.size() - 1;
                while (start < end) {
                    if (buf[start] == buf[end]) {
                        start++;
                        end--;
                    }
                    else {
                        start = -1;
                        end = -1;
                        break;
                    }
                }
                if (start != -1) {
                    cnt++;
                }
            }

        }
        // cout << noSpaces.size() << endl;
        // cout << noSpaces << endl;
        // noSpaces stores last \n or empty char for some reason? will check later
        if (true) //noSpaces.size() >= 2
        {
            int start = 0, end = noSpaces.size() - 1;
            while (start < end) {
                if (noSpaces[start] == noSpaces[end]) {
                    start++;
                    end--;
                }
                else {
                    // cout << noSpaces[start] << endl;
                    // cout << noSpaces[end] << endl;
                    // cout << "Hit! s: " << start << endl;
                    start = -1;
                    end = -1;
                    break;
                }
            }
        
            if (start != -1) {
                cnt += 2;
            }
        }
        // cout << "size : " << noSpaces.size() << ", |" << noSpaces << "|\n";
        if (cnt > 1) {
            cout << "Ay\n";
        }
        else {
            cout << "Nap\n";
        }
    }
}

