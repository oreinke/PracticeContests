#include<bits/stdc++.h>

using namespace std;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator< (P p) const {return tie(x, y) < tie(p.x, p.y); }
    bool operator== (P p) const {return tie(x, y)==tie(p.x, p.y); }
    P operator+ (P p) const {return P(x+p.x, y+p.y); }
    P operator- (P p) const {return P(x-p.x, y-p.y); }
    P operator* (T d) const {return P(x*d, y*d); }
    P operator/ (T d) const {return P(x/d, y/d); }
    T dot(P p) const {return x*p.x + y*p.y; }
    T cross(P p) const {return x*p.y - y*p.x; }
    T cross(P a, P b) const {return (a-*this).cross(b-*this); }
    T dist2() const { return x * x + y * y; }
    double dist() const { return sqrt((double) dist2()); }
    double angle () const { return atan2(y, x); }
    P unit() const { return *this/dist(); }
    P perp() const { return P(-y, x); }
};

typedef Point<double> P;
#define arg(p, q) atan2(p.cross(q), p.dot(q))
double circlePoly(P c, double r, vector<P> ps) {
    auto tri = [&] (P p, P q) {
        auto r2 = r * r / 2;
        P d = q - p;
        auto a = d.dot(p) / d.dist2(), b = (p.dist2()-r*r) / d.dist2();
        auto det = a * a - b;
        if (det <= 0) return arg(p, q) * r2;
        auto s = max(0., -a-sqrt(det)), t = min(1., -a+sqrt(det));
        if (t < 0 || 1 <= s) return arg(p, q) * r2;
        P u = p + d * s, v = p + d * t;
        return arg(p,u) * r2 + u.cross(v)/2 + arg(v, q) * r2;
    };
    auto sum = 0.0;
    for (int i = 0; i < ps.size(); ++i) {
        sum += tri(ps[i] - c, ps[(i + 1) % ps.size()] - c);
    }
    return sum;
}

template<class P> bool onSeg(P s, P e, P p) {
    return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

int main () {
    double cX, cY, cR, sX, sY, sS; cin >> cX >> cY >> cR >> sX >> sY >> sS;
    vector<P> square;
    square.push_back(P(sX, sY));
    square.push_back(P(sX + sS, sY));
    square.push_back(P(sX + sS, sY + sS));
    square.push_back(P(sX, sY + sS));

    P center = P(cX, cY);

    if (abs(circlePoly(P(cX, cY), cR, square)) > .000001) {
        cout << "2\n";
    }
    else {
        bool inCircle = false;
        for (auto p : square) {
            // cout << (p - center).dist() <<endl;
            if ((p - center).dist() <= cR + .000001) inCircle = true;
        }

        vector<P> circleP;
        circleP.push_back(center + P(cR, 0));
        circleP.push_back(center + P(0 , cR));
        circleP.push_back(center + P(-cR, 0));
        circleP.push_back(center + P(0, -cR));
        for (auto cP : circleP) {
            for (int i = 0; i < 4; ++i) {
                if (onSeg(square[i], square[(i + 1) % 4], cP)) inCircle = true;
            }
        }
        if (inCircle) cout << "1\n";
        else cout << "0\n";
    }
}