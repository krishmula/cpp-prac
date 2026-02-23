#include <iostream>
#include <vector>

using namespace std;

void cyclicSort(vector<int>& nums) {
    int n = nums.size();
    int i = 0;

    while (i < n) {
        int correctIndex = nums[i] - 1;
        if (nums[i] != nums[correctIndex]) swap(nums[i], nums[correctIndex]);
        else i++;
    }
}


int main () {
    // vector<int> nums = {3, 5, 2, 1, 4};
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    cyclicSort(nums);

    for (auto it: nums) cout << it << " ";
}