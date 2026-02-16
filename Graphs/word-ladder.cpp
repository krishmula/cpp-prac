#include <iostream>
#include <iterator>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int bfs(string& word, unordered_map<string, vector<string>>& adj, unordered_map<string, bool>& visited, string endWord) {
    queue<pair<string, int>> q;
    q.push({word, 1});
    visited[word] = 1;

    while (!q.empty()) {
        string el = q.front().first;
        int len = q.front().second;
        q.pop();

        if (el == endWord) return len;

        for (auto it: adj[el]) {
            if (visited[it] == 0) {
                q.push({it, len + 1});
                visited[it] = true;
            }
        }
    }

    return -1;
}

int ladderLength(string& beginWord, string& endWord, vector<string>& wordList) {
    int n = wordList.size();
    unordered_map<string, vector<string>> mp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < wordList[i].length(); j++) {
            string word = wordList[i];
            string rep = word.replace(j, 1, "*");
            mp[rep].push_back(wordList[i]);
        }
    }

    for (int j = 0; j < wordList[0].length(); j++) {
        string word = beginWord;
        string rep = word.replace(j, 1, "*");
        mp[rep].push_back(beginWord);
    }

    cout << "Priting out map" << endl;

    for (const auto& [key, value]: mp) {
        for (auto it: value) {
            cout << key << "->" << it << ", ";
        }
        cout << endl;
    }

    unordered_map<string, vector<string>> adj;

    for (int i = 0; i < n; i++) {
        string word = wordList[i];
        for (int j = 0; j < wordList[i].length(); j++) {
            string comb = word;
            comb = comb.replace(j, 1, "*");
            for (auto it: mp[comb]) {
                if (word != it) adj[word].push_back(it);
            }
        }
    }

    for (int j = 0; j < wordList[0].length(); j++) {
        string comb = beginWord;
        comb = comb.replace(j, 1, "*");
        for (auto it: mp[comb]) {
            if (beginWord != it) adj[beginWord].push_back(it);
        }
    }

    cout << "Printing out the adjacency list " << endl;

    for (const auto& [key, value]: adj) {
        cout << key << " -> ";
        for (auto it: value) {
            cout << it << ", ";
        }
        cout << endl;
    }

    unordered_map<string, bool> visited(n + 1);

    int len = bfs(beginWord, adj, visited, endWord);

    return len;
}

int main () {
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    string beginWord = "hit";
    string endWord = "cog";

    int res = ladderLength(beginWord, endWord, wordList);
    cout << "Result is: " << res;
}
