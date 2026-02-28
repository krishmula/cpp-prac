#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> topologicalSort(vector<vector<int>>& graph) {
    int n = graph.size();
}

int main () {
    vector<vector<int>> graph = {
        {1, 2},
        {3},
        {3},
        {}
    };

    // Perform topological sort
    vector<int> topoOrder = topologicalSort(graph);

    // Print the topological order
    for (int node : topoOrder) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}