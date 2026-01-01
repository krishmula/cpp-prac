#include <iostream>
#include <string>
#include<set>
#include <vector>

using namespace std;

int backtrack(string s, int i, vector<int>& dp) {
    if (i == s.length()) return 1;
    if (i > s.length()) return 0;
    if (dp[i] != -1) return dp[i];

    int count = 0;
    for (int j = i; j<s.length(); j++) {
        string st = s.substr(i, j - i + 1);
        int num = stoi(st);
        if (num < 1 || num > 26) break;
        count += backtrack(s, j+1, dp);
    }

    return dp[i] = count;
}

int numDecodings(string s) {
    vector<int> dp(s.length() + 1, -1);
    dp[s.length()] = 1;
    int ans = backtrack(s, 0, dp);
    cout << "dp is: " << endl;
    for (auto it: dp) {
        cout << it << " ";
    }
    cout << endl;
    return ans;
}


int main() {
    string s = "41461";
    int ans = numDecodings(s);
    cout << ans << endl;
}
