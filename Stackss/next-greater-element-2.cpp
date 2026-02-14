#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();

    stack<int> stk;
    stk.push(nums[n - 1]);

    vector<int> ans(n);

    for (int i = n - 2; i >= 0; i--) {
        while (!stk.empty() && nums[i] > stk.top()) stk.pop();

        if (stk.empty()) ans[i] = -1;
        else ans[i] = stk.top();

        stk.push(nums[i]);
    }
    stk.pop();
    int lastEl = nums[n - 1];
    while (!stk.empty() && lastEl > stk.top()) stk.pop();
    if (stk.empty()) ans[n - 1] = -1;
    else ans[n - 1] = stk.top();

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 3};

    vector<int> ans = nextGreaterElement(nums);

    for (auto it: ans) cout << it << " ";
}