#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Prototype for the MST function
int primsMST(int V, vector<pair<int, int>> adj[]);

int main() {
    int V = 5; // Number of vertices
    vector<pair<int, int>> adj[V];

    // Example: adding edges (u, v, weight)
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});
    adj[0].push_back({2, 3});
    adj[2].push_back({0, 3});
    adj[1].push_back({2, 4});
    adj[2].push_back({1, 4});

    int res = primsMST(V, adj);
    cout << res << endl;

    return 0;
}

int primsMST(int V, vector<pair<int, int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    vector<int> visited(V, 0);
    int mst = 0;

    while (!pq.empty()) {
        int weight = pq.top().first;
        int val = pq.top().second;
        pq.pop();

        if (!visited[val]) {
            visited[val] = 1;
            mst += weight;
            for (auto &edge: adj[val]) {
                if (!visited[edge.first]) pq.push({edge.second, edge.first});
            }
        }
    }

    return mst;
}