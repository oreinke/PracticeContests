#include <bits/stdc++.h>

using namespace std;

int main() {
    int numCases;
    scanf("%d", &numCases);

    while (numCases > 0) {
        int nodes, edges, sensors;
        scanf("%d %d %d", &nodes, &edges, &sensors);

        unordered_set<int> sensorList;
        vector<vector<pair<int, int>>> adjList(nodes);

        for (int i = 0; i < sensors; i++) {
            int newSensor;
            scanf("%d", &newSensor);
            newSensor--;
            sensorList.insert(newSensor);
        }

        for (int i = 0; i < edges; i++) {
            int s, e, r;
            scanf("%d %d %d", &s, &e, &r);
            s--;
            e--;
            adjList[e].push_back({s, r});
        }

        // Dijkstra's on source node (0) w/ reversed edges;

        vector<int> distance(nodes, INT_MAX);
        distance[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            int cost = pq.top().first;
            int cur = pq.top().second;
            pq.pop();

            if (cost > distance[cur])
                continue;
            
            for (auto [v, w] : adjList[cur])
            {
                if (distance[v] > w + cost) {
                    distance[v] = w + cost;
                    pq.push({distance[v], v});
                }
            }
        }

        int sum = 0;
        for (int i : sensorList)
            sum += distance[i];


        printf("%d\n", sum);
        numCases--;
    }
}