#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, t; cin >> n >> t;
    vector<pair<double, double>> realPath (n), fakePath;
    vector<int> times (n);
    for (int i = 0; i < n; ++i) {
        int time;
        double x, y; 
        cin >> x >> y >> time;
        realPath[i] = {x, y};
        times[i] = time;
    }
    
    int curTime = 0;

    for (int i = 0; i < n - 1; ++i) {
        while (curTime < times[i + 1]) {
            double xDif = realPath[i + 1].first - realPath[i].first;
            double yDif = realPath[i + 1].second - realPath[i].second;
            fakePath.push_back({realPath[i].first + (xDif * ((double) curTime - times[i]) / ((double) times[i + 1] - times[i])), realPath[i].second + (yDif * ((double) curTime - times[i]) / (times[i + 1] - times[i]))});
            // cout << fakePath[fakePath.size() - 1].first << ", " << fakePath[fakePath.size() - 1].second << ", t: " << curTime <<  endl;
            curTime += t;
        }
    }
    fakePath.push_back(realPath[n - 1]);

    double realDist = 0, gpsDist = 0;
    for (int i = 0; i < n - 1; ++i) {
        realDist += sqrt((realPath[i + 1].first - realPath[i].first) * (realPath[i + 1].first - realPath[i].first) 
                          + (realPath[i + 1].second - realPath[i].second) * (realPath[i + 1].second - realPath[i].second));                
    }

    for (int i = 0; i < fakePath.size() - 1; ++i) {
        gpsDist += sqrt((fakePath[i + 1].first - fakePath[i].first) * (fakePath[i + 1].first - fakePath[i].first) 
                          + (fakePath[i + 1].second - fakePath[i].second) * (fakePath[i + 1].second - fakePath[i].second));                
    }
    double diff = ((realDist - gpsDist ) * 100) / realDist;
    printf("%f\n", diff);
}