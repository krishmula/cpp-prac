#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();

    stack<int> stk;
    stk.push(nums2[n - 1]);

    vector<int> ans(n);
    ans[n - 1] = -1;

    for (int i = n - 2; i >= 0; i--) {
        while (!stk.empty() && nums2[i] > stk.top()) stk.pop();

        if (stk.empty()) ans[i] = -1;
        else ans[i] = stk.top();

        stk.push(nums2[i]);
    }

    vector<int> res;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (nums1[i] == nums2[j]) {
                res.push_back(ans[j]);
                break;
            }
        }
    }

    return res;
}

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> ans = nextGreaterElement(nums1, nums2);

    for (auto it: ans) cout << it << " ";
}