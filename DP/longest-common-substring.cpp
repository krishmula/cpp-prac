#include <iostream>
#include <string>


using namespace std;

int maxVal = 0;

void backtrack(string& s1, string& s2, int n, int m, int counter) {
    if (n == 0 || m == 0) return;
    if (s1[n - 1] == s2[m - 1]) {
        counter++;
        maxVal = max(maxVal, counter);
        backtrack(s1, s2, n - 1, m - 1, counter);
    } else {
        counter = 0;
        backtrack(s1, s2, n - 1, m, 0);
        backtrack(s1, s2, n, m - 1, 0);
    }
}

int longestCommonSubstr(string& s1, string& s2) {
    int n = s1.length();
    int m = s2.length();
    backtrack(s1, s2, n, m, 0);
    return maxVal;
}

int main() {
    string s1 = "abcdgh";
    string s2 = "acdghr";
    int ans = longestCommonSubstr(s1, s2);
    cout << ans << endl;
}
