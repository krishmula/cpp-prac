#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>

using namespace std;

vector<vector<int>> result;

void backtrack(vector<int>& nums, vector<int>& res, int i) {
    if (i >= nums.size()) {
        result.push_back(res);
        return;
    }
    res.push_back(nums[i]);
    backtrack(nums, res, i + 1);
    res.pop_back();
    backtrack(nums, res, i + 1);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int> res;
    backtrack(nums, res, 0);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = subsetsWithDup(nums);
    for (const auto& subset : result) {
        for (int num : subset) {
            printf("%d ", num);
        }
        printf("\n");
    }
}