#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    // map<char, int> checkMap = {{'c', 2}, {'a', 4}};
    // if (checkMap.find('a') != checkMap.end()) {
    //     checkMap.find('a')->second++;
    // }

    // for (auto iter = checkMap.begin(); iter != checkMap.end(); ++iter) {
    //     cout << iter->first << "->" << iter->second << " ";
    // }
    // cout << endl;
    // cout << 'a'-1 << endl;

   multimap<int, int> checkMap;
    // checkMap.insert({1, {2, 3}});
    // checkMap.insert({4, {4, 5}});
    // checkMap.insert({3, {6, 7}});
    // checkMap.insert({5, {8, 9}});
    // checkMap.insert({2, {10, 11}});
    checkMap.insert(make_pair(1, 20));
    checkMap.insert(make_pair(2, 30));
    checkMap.insert(make_pair(1, 40));
    checkMap.insert(make_pair(4, 50));

    for (auto iter = checkMap.crbegin(); iter != checkMap.crend(); iter++) {
        cout << iter->first << "->" << iter->second << endl;
    }
}