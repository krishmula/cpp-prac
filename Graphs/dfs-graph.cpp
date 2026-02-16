#include <iostream>
#include <vector>

using namespace std;

vector<int> res;

void dfs(int el, int V, vector<vector<int>>& adj, vector<int>& vis) {

    vis[el] = 1;
    res.push_back(el);

    for (auto it: adj[el]) {
        if (!vis[it]) {
            dfs(it, V, adj, vis);
        }
    }

    return;
}

int main () {
    vector<vector<int>> adj;
    adj.resize(5);
    int V = 5;
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[2].push_back(0);
    adj[2].push_back(4);
    adj[3].push_back(0);
    adj[4].push_back(2);

    vector<int> vis(V, 0);

    dfs(0, V, adj, vis);


    for (auto it: res) {
        cout << it << "->";
    }
}
