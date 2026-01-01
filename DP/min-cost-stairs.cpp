#include <iostream>
#include <map>
#include <vector>

using namespace std;

int backtrack(vector<int>& cost, int i) {
    if (i >= cost.size()) return 0;

    int track1 = backtrack(cost, i + 1);
    int track2 = backtrack(cost, i + 2);
    return cost[i] + min(track1, track2);
}

int minCostClimbingStairs(vector<int>& cost) {
    return min(backtrack(cost, 0), backtrack(cost, 1));
}

int main() {
    vector<int> cost {10, 15, 20};
    int ans = minCostClimbingStairs(cost);
    cout << "Ans is: " << ans << endl;
}
