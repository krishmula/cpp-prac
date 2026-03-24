#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int i, vector<int>& result, vector<int>& nums) {
    if (i == nums.size()) return;

    if (nums[i] > result.back()) {
        result.push_back(nums[i]);
        solve(i + 1, result, nums);
    }
    result.pop_back();

    solve(i + 1, result, nums);

}

int main () {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> result;

    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (nums[i - 1] > nums[j - 1]) {
                dp[i][j] = max(dp[i][j - 1], 1 + dp[i][j - 1]);
            } else {
                dp[i][j] = dp[i][j - 1];
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    solve(0, result, nums); 
    cout << result.size() << endl;
}