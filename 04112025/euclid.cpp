#include <bits/stdc++.h>

using namespace std;

struct pt {
    double x, y;
};

double area (vector<pt> &pts) {
    double a = 0;
    for (unsigned i = 0; i < pts.size(); ++i) {
        pt p = i ? pts[i - 1] : pts.back();
        pt q = pts[i];
        // printf ("new add %f\n", (p.x - q.x) * (p.y + q.y) );
        a += (p.x - q.x) * (p.y + q.y);
        // printf("cur a: %f\n", a);
    }
    return a;
}

int main() {
    double ax, ay, bx, by, cx, cy, dx, dy, ex, ey, fx ,fy; cin  >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy >> ex >> ey >> fx >>fy;
    while (ax  || ay  || bx  || by  || cx  || cy  || dx  || dy  || ex  || ey  || fx   ||fy) {

        vector<pt> tri;
        tri.push_back({dx, dy});
        tri.push_back({ex, ey});
        tri.push_back({fx, fy});
        double triA = area(tri);
        // printf("triA: %f\n", triA);
        vector<pt> par;
        
        par.push_back({ax, ay});
        
        par.push_back({cx, cy});
        par.push_back({bx + cx - ax, by + cy - ay});
        par.push_back({bx, by});
        
        // for (pt tp : par) printf("x: %f, y: %f\n", tp.x, tp.y);
        
        double parA = abs(area(par));
        
        double scale = triA / parA;
        // printf("parA: %f, scale: %f\n", parA, scale);
        par[1].x = ax + (cx - ax) * scale;
        par[1].y = ay + (cy - ay) * scale;
        par[2].x = bx + (cx - ax) * scale;
        par[2].y = by + (cy - ay) * scale;


        printf("%.3f %.3f %.3f %.3f\n", par[2].x, par[2].y, par[1].x, par[1].y);
        cin  >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy >> ex >> ey >> fx >>fy;
    }
}