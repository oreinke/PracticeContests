#include <bits/stdc++.h>

using namespace std;

template <class T> int sgn(T x) {return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y = 0) : x(x), y(y) {}
    bool operator< (P p) const { return tie(x,y) < tie(p.x, p.y); }
    bool operator== (P p) const { return tie(x,y) == tie(p.x, p.y); }
    P operator+ (P p) const { return P(x + p.x, y + p.y); }
    P operator- (P p) const { return P(x - p.x, y - p.y); }
    P operator* (T d) const { return P(x * d, y * d); }
    P operator/ (T d) const { return P(x / d, y / d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const {return (a-*this).cross(b-*this); }
    T dist2() const { return x * x + y * y;}
    double dist() const { return sqrt((double) dist2()); }

    
    
};

template<class P> bool onSeg (P s, P e, P p) {
    return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

bool canPass (Point<int> first, Point<int> last, vector<Point<int>> &arr) {
    int n = arr.size();
    for (auto p : arr) {
        if (p == first || p == last) continue;
        if (onSeg(first, last, p)) return false;
    }
    return true;
}

int main() {
    int n; cin >> n;
    vector<Point<int>> arr (n * 2), t1 (n), t2 (n);
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        t1[i] = Point(x, y);
        arr[i] = Point(x, y);
    }

    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        t2[i] = Point(x, y);
        arr[i + n] = Point(x, y);
    }

    map<int, set<int>> adjL;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (canPass(t1[i], t1[j], arr)) {
                adjL[i].insert(j);
                adjL[j].insert(i);
            }
        }
    }

    vector<int> dist (n, -1);
    deque<int> q;
    q.push_back(0);
    int step = 0;
    while (!q.empty()) {
        deque<int> next;
        while (!q.empty()) {
            int cur = q.front(); q.pop_front();
            if (dist[cur] == -1) {
                dist[cur] = step;
                for (int v : adjL[cur]) {
                    if (dist[v] == -1) next.push_back(v);
                }
            }
        }
        q = next;
        step++;
    }
    
    cout << dist[n - 1] << endl;
}