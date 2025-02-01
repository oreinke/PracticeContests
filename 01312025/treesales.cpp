#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "COMPANY " << tc << endl;
        int n; cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        map<string, string> boss;
        map<string, long long> sales;
        string line;
        getline(cin, line);
        istringstream iss(line);
        string token; iss >> token; iss >> token; iss >> token;
        boss[token] = token;

        
        for (int i = 1; i < n; ++i) {
            
            // Create a string stream from the line
            getline(cin, line);
            istringstream iss(line);
            iss >> token;
            if (token == "ADD") {
                iss >> token;
                string emp; iss >> emp;
                boss[emp] = token;
            }
            else if (token == "SALE") {
                iss >> token;
                string buf; iss >> buf;
                int sale = stoi(buf);
                sales[token] += sale;
                while (boss[token] != token) {
                    sales[boss[token]] += sale;
                    token = boss[token];
                }
            }
            else if (token == "QUERY") {
                iss >> token;
                cout << sales[token] << endl;
            }
        }


    }
}