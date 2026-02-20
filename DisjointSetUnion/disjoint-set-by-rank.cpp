#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class DisjointSet {
public:
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n) {
       parent.resize(n);
       rank.resize(n, 0); 
       for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] == u) return true;
        else return find(parent[u]);
    }

    void combine(int u, int v) {
        int i = find(u);
        int j = find(v);

        if (i == j) return;
        else if (rank[i] < rank[j]) {
            parent[i] = j;
            rank[j]++;
        } else {
            parent[j] = i;
            rank[i]++;
        }
    }

    bool areConnected(int u, int v) {
        if (find(u) == find(v)) return true;
        return false;
    }
};

int main() {
    DisjointSet ds(5);

    ds.combine(1, 2);
    ds.combine(3, 0);
    ds.combine(4, 0);

    cout << ds.find(4) << endl;
}