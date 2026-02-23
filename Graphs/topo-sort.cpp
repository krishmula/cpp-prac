#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void dfs(int i, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& stk) {
    visited[i] = true;
    for (auto &edge: adj[i]) {
        if (!visited[edge]) {
            dfs(edge, adj, visited, stk);
        }
    }
    stk.push(i);
}

int main () {
    vector<vector<int>> adj = {
        {},
        {},
        {3},
        {1},
        {0, 1},
        {0, 2}
    };
    int n = adj.size();

    vector<bool> visited(adj.size(), false);
    vector<int> result;
    stack<int> stk;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, stk);
        }
    }

    while (!stk.empty()) {
        result.push_back(stk.top());
        stk.pop();
    }

    for (auto it: result) cout << it << " -> ";

}