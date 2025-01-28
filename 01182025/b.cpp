#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi cakes(n);
        ull total = 0;
        for (auto &x : cakes) {
            cin >> x;
            total += x;
        } 
        
        int turns = n / 2 - 1;
        ull elsie = 0;
        for (int i = 0; i < turns; i++) {
            elsie += cakes[i];
        }
        turns--;
        int end = n - 1;
        ull curEls = elsie;
        while (turns >= 0) {
            curEls -= cakes[turns];
            curEls += cakes[end];
            elsie = max(elsie, curEls);
            turns--;
            end--;
        }
        cout << total - elsie << " " << elsie << endl;





        /*vector<ull> pre(n), suf(n + 1);
        pre[0] = cakes[0];
        suf[n] = 0;
        suf[n - 1] = cakes[n - 1];
        ull total = cakes[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1] + cakes[i];
            total += cakes[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] + cakes[i];
        }

        ull elise = 0;
        int turns = n / 2 - ((n % 2 == 1) ? 0 : 1);
        for (int i = 0; i < turns; ++i) {
            elise = max(elise, pre[i] + suf[n - (turns - (i + 1))]);
        } 
        elise = max(elise, suf[n - turns]);
        cout << (total - elise) << " " << elise << endl; */
    }
}