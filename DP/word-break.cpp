#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool solve(string& s, vector<string>& wordDict, int i) {
    if (i == s.length()) return false;

    for (int k = i + 1; k < s.length(); k++) {
        string first = s.substr(i, k - i);
        if (binary_search(wordDict.begin(), wordDict.end(), first)) {
            if (solve(s, wordDict, k)) return true;
        }
    }

    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    sort(wordDict.begin(), wordDict.end());
    return solve(s, wordDict, 0);
}

int main() {
    // string s = "catsandog";
    // vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    bool res = wordBreak(s, wordDict);
    cout << "wordBreak possible for " << s << ": " << res << endl;
}
