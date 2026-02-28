#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    // vector<vector<int>> intervals = {
    //     {1, 2},
    //     {2, 3},
    //     {3, 4},
    //     {1, 3}
    // };

    vector<vector<int>> intervals = {{-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}};

    sort(intervals.begin(), intervals.end());
    cout << "Sorted Intervals: " << endl;

    for (int i = 0 ; i < intervals.size(); i++) {
        cout << intervals[i][0] << " " << intervals[i][1] << endl;
    }
}