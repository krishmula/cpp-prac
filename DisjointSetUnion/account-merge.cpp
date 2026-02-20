// Account Merge

#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
    int n = accounts.size();
    map<string, string> parent;
    map<string, string> name;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < accounts[i].size(); j++) {
            if (parent.count(accounts[i][j]) == 0) parent[accounts[i][j]] = accounts[i][j];
            name[accounts[i][j]] = accounts[i][0];
        }
    }

    vector<vector<string>> arr;

    for (int i = 0; i < n; i++) {
        string fix = accounts[i][1];
        for (int j = 1; j < accounts[i].size(); j++) {
            arr.push_back({fix, accounts[i][j]});
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i][0] << ", " << arr[i][1] << endl;
    }
}