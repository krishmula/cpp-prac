#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <math.h>
#include <iterator>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

bool validityCheck(vector<int> arr) {
    for (auto it: arr) {
        if (it > 1) return false;
    }
    return true;
}

int main()
{
    vector<int> numArr = {1, 2, 0, 0, 1, 1, 1, 2};
    vector<int> numArr1 = {1, 1, 0, 0, 1, 1, 1};
    bool res1 = validityCheck(numArr);
    bool res2 = validityCheck(numArr1);
    cout << "Check 1 is: " << res1 << endl;
    cout << "Check 2 is: " << res2 << endl;

}
