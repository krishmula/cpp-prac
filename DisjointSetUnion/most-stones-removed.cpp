// Most Stones Removed with Same Row or Column

#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    int n = stones.size();
    map<int, vector<int>> mp;

    for (int i = 0; i < n; i++) {
        mp[stones[i][0]].push_back(i);
        if (stones[i][0] != stones[i][1]) mp[stones[i][1]].push_back(i);
    }

    vector<vector<int>> arr;

    for (auto &[key, val] : mp) {
        int el = val[0];
        for (auto it: val) {
            arr.push_back({el, it});
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i][0] << ", " << arr[i][1] << endl;
    }

}