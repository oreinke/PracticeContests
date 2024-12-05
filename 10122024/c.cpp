#include <bits/stdc++.h>

using namespace std;

static bool isPrime(long long num) {
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0)
                return false;
        }
        return true;
    }

int main() {
    int numCases;
    scanf("%d", &numCases);

    while (numCases > 0) {
        long long num;
        char start;
        scanf("%d %c", &num, &start);

        if (num ==1 || num == 3) {
            if ('V' == start) {
                cout << "Email\n";
            }
            else {
                cout << "Teams\n";
            }
        }
        else if (isPrime(num)) {
            if ('V' == start) {
                cout << "Teams\n";
            }
            else {
                cout << "Email\n";
            }
        }
        else
        {
            if ('V' == start) {
                cout << "Email\n";
            }
            else {
                cout << "Teams\n";
            }
        }

        numCases--;
    }
}


