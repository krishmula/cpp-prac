#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    vector<vector<pair<int, int>>> adj = {
        {{1, 4}, {2, 4}},
        {{0, 4}, {2, 2}},
        {{0, 4}, {3, 3}, {1, 2}, {4, 1}},
        {{2, 3}, {5, 2}},
        {{2, 1}, {5, 3}},
        {{3, 2}, {4, 3}},
    };

    vector<int> distance(adj.size(), INT_MAX);
    distance[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it: adj[node]) {
           int newDist = dist + it.second;
           int newNode = it.first; 

           if (newDist < distance[newNode]) {
            distance[newNode] = newDist;
            pq.push({newDist, newNode});
           }
        }
    }

    for (auto it: distance) cout << it << " -> ";
}