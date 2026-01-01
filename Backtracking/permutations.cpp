#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> result;

void backtrack(vector<int>& nums, vector<int>& res, vector<bool>& flags) {
    if (res.size() == nums.size()) {
        result.push_back(res);
        return;
    }

    for (int i = 0; i<nums.size(); i++) {
        if (flags[i] == true) continue;
        res.push_back(nums[i]);
        flags[i] = true;
        backtrack(nums, res, flags);
        res.pop_back();
        flags[i] = false;
    }


}

vector<vector<int>> permute(vector<int>& nums) {
    vector<int> res;
    vector<bool> flags(nums.size(), false);
    backtrack(nums, res, flags);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> answer = permute(nums);
    for (auto it: answer) {
        for (auto it1: it) {
            cout << it1 << endl;
        }
    }
}
