// C++ program to find GCD of two numbers using
// Euclidean Algorithm
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {

    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // If both numbers are equal
    if (a == b)
        return a;

    // If a is greater
    if (a > b)
      return gcd(a - b, b);


	// If b is greater
    return gcd(a, b - a);
}

  main() {
  
    int a = 12, b = 16;
    cout << gcd(a, b);
    return 0;
}
