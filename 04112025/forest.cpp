#include <bits/stdc++.h>

using namespace std;

struct pt {
    double x, y;
};

int oreintation(pt a, pt b, pt c) {
    double v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    if (v < 0) return -1;
    if (v > 0) return +1;
    return 0;
}

bool cw (pt a, pt b, pt c, bool include_collinear) {
    int o = oreintation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}

bool ccw (pt a, pt b, pt c, bool include_collinear) {
    int o = oreintation(a, b, c);
    return o >  0 || (include_collinear && o == 0);
}

void convex_hull(vector<pt>& a, bool include_collinear) {
    if (a.size() == 1) return;

    sort (a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    });
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); ++i) {
        if (i == a.size() - 1 || cw(p1, a[i], p2, include_collinear)) {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i], include_collinear)) up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2, include_collinear)) {
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i], include_collinear)) down.pop_back();
            down.push_back(a[i]);
        }
    }

    if (include_collinear && up.size() == a.size()) {
        reverse(a.begin(), a.end());
        return;
    }
    a.clear();
    for (int i = 0; i < (int)up.size(); ++i)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; --i)
        a.push_back(down[i]);
}

int main() { 
    int n, c; cin >> n >> c;
    vector<pt> pts;
    for (int i = 0; i < n; ++i) {
        double x, y; cin >> x >> y;
        pt p;
        p.x = x;
        p.y = y;
        pts.push_back(p);
    }

    convex_hull(pts, true);
    double len = 2 * c * 3.141592653589793, area = c * c * 3.141592653589793;
    for (int i = 0; i < pts.size(); ++i) {
        double dist = sqrt((pts[i].x - pts[(i + 1) % pts.size()].x) * (pts[i].x - pts[(i + 1) % pts.size()].x) + (pts[i].y - pts[(i + 1) % pts.size()].y) * (pts[i].y - pts[(i + 1) % pts.size()].y));
        len += dist;
        area += dist * c;
    }

    double innerA = 0;
    for (unsigned i = 0; i < pts.size(); ++i) {
        pt p = i ? pts[i - 1] : pts.back();
        pt q = pts[i];
        innerA += (p.x - q.x) * (p.y + q.y);
    }
    innerA = fabs(innerA) / 2;
    area += innerA;
    printf("%.2f %.2f\n", len, area);
    //for (pt p : pts) cout << p.x << " " << p.y << endl;

}