#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main()
{

    // Number of vertices in the polygon
    ll n = 4;

    // Array to store the vertices of the polygon
    vector<pair<ll, ll>> vertices (n);

    // Variable to store the area of the polygon
    ll area = 0;

    // Calculating the area of the polygon using the
    // shoelace formula
    for (ll i = 0; i < n; i++) {
        area += (vertices[i].first
                    * vertices[(i + 1) % n].second
                - vertices[(i + 1) % n].first
                    * vertices[i].second);
    }

    // Printing the absolute value of the area
    cout << abs(area);

    return 0;
}
