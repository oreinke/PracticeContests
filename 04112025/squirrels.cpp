#include <bits/stdc++.h>

using namespace std;

struct pt {
    double x, y;
};

int main() {
    int t; cin >> t;
    
    for (int tc = 1; tc <= t; ++tc) {
        int n; cin >> n;
        vector<pt> pts;
        for (int i = 0; i < n; ++i) {
            double x, y; cin >> x >> y;
            pt newPt;
            newPt.x = x;
            newPt.y = y;
            pts.push_back(newPt);
        }

        double small = (pts[0].x - pts[1].x) * (pts[0].x - pts[1].x) + (pts[0].y - pts[1].y) * (pts[0].y - pts[1].y);
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                small = min(small, (pts[i].x - pts[j].x) * (pts[i].x - pts[j].x) + (pts[i].y - pts[j].y) * (pts[i].y - pts[j].y));
            }
        }
        //cout << small << endl;
        double area = (sqrt(small) / 2) * (sqrt(small) / 2) * 3.141592653589793;
        

        // if ((((int)(area * 10000) ) % 10) >= 5) area += .001;
        printf("Campus #%d:\nMaximum territory area = %.3f\n\n", tc, area);
        // printf("test: %f\n", (6000 * 6000 + 6000 * 6000 ) / 2* 3.141592653589793);
    }

    
}