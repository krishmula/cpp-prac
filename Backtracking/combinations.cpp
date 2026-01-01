#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> result;

void backtrack(vector<int>& nums, vector<int>& res, vector<bool>& flags, int k) {
    if (k == nums.size()) {
        result.push_back(res);
        return;
    }

    for (int i = 0; i<nums.size(); i++) {
        if (flags[i] == false) {
            if (k > 0 && (nums[i] - res[k - 1] == 1)) continue;
            res[k] = nums[i];
            flags[i] = true;
            backtrack(nums, res, flags, k+1);
            flags[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
   vector<int> res;
   vector<bool> flags(nums.size(), false);
   backtrack(nums, res, flags, 0);
   return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> answer = permute(nums);
    for (int i = 0; i<answer.size(); i++) {
        for (int j = 0; j<i; j++) {
            cout << answer[i][j] << " " << endl;
        }
    }
}
