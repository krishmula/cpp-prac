#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet {
public:
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] == u) return u;
        else return find(parent[u]);
    }

    void combine(int u, int v) {
        int i = find(u);
        int j = find(v);
        if (i == j) return;
        if (size[i] < size[j]) parent[i] = j;
        else if (size[j] < size[i]) parent[j] = i;
        else {
            parent[j] = i;
            size[i] += size[j];
        }
    }

    bool areConnected(int u, int v) {
        if (find(u) == find(v)) return true;
        return false;
    }
};

int main() {
    DisjointSet ds(5);

    ds.combine(0, 1);
    ds.combine(2, 3);
    ds.combine(3, 4);

    cout << ds.find(4) << endl;

    return 0;
}