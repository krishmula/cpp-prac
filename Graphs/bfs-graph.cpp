#include <queue>
#include <vector>
#include <iostream>
using namespace std;


vector<int> bfs(int V, vector<vector<int>>& adj) {
    queue<int> q;
    vector<int> visited(V, 0);
    vector<int> result;

    q.push(0);
    visited[0] = 1;

    while (!q.empty()) {
        int topEl = q.front();
        q.pop();
        result.push_back(topEl);
        vector<int> topNeighbours = adj[topEl];
        for (auto it: topNeighbours) {
            if (visited[it] == 1) continue;
            q.push(it);
            visited[it] = 1;
        }
    }

    return result;
}

int main() {
    vector<vector<int>> adj;
    adj.resize(5);

    int V = 5;

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[2].push_back(4);
    adj[4].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[0].push_back(4);
    adj[4].push_back(0);

    vector<int> res = bfs(V, adj);

    for (auto it: res) cout << it << "->" << endl;
}
