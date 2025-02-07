#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc = 1;
    string a, b; cin >> a >> b;
    while (a != "END") {
        if (a.size() != b.size()) {
            printf("Case %d: different\n", tc);
        }
        else {
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            bool bad = false;
            for (int i = 0; i < a.size() && !bad; ++i) {
                if (a[i] != b[i]) bad = true;
            }
            if (bad) {
                printf("Case %d: different\n", tc);

            }
            else {
                printf("Case %d: same\n", tc);

            }
        }


        tc++;
        cin >> a >> b;
    }
}