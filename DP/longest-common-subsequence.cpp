#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string res = "";

string getString(vector<vector<int>>& dp, string& s1, string& s2, int i, int j) {
    string res = "";
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            res.push_back(s1[i - 1]);
            i--; j--;
        }
        else if (dp[i][j - 1] > dp[i - 1][j]) j--;
        else i--;
    }
    reverse(res.begin(), res.end());
    return res;
}

string longestCommonSubsequence(string& s1, string& s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string res = getString(dp, s1, s2, n, m);
    return res;
}



// int maxVal = 0;

// void backtrack(string& s1, string& s2, int n, int m, int counter) {
//     if (n == 0 || m == 0) return;
//     if (s1[n - 1] == s2[m - 1]) {
//         counter++;
//         maxVal = max(maxVal, counter);
//         backtrack(s1, s2, n - 1, m - 1, counter);
//     } else {
//         counter = 0;
//         backtrack(s1, s2, n - 1, m, 0);
//         backtrack(s1, s2, n, m - 1, 0);
//     }
// }

// int longestCommonSubsequence(string& s1, string& s2) {
//     int n = s1.length();
//     int m = s2.length();
//     backtrack(s1, s2, n, m, 0);
//     return maxVal;
// }

int main() {
    string s1 = "acbcf";
    string s2 = "abcdaf";
    string ans = longestCommonSubsequence(s1, s2);
    cout << ans << endl;
}
