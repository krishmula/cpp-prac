#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int ninjasTraining(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int res = 0;
    int check;

    int i = 0;
    while (i < m) {
        int maxVal = 0;
        for (int k = 0; k < n; k++) {
            if (k != check) {
                if (matrix[i][k] > maxVal) {
                    maxVal = matrix[i][k];
                    check = k;
                }
            }
        }
        res += maxVal;
        i++;
    }
    return res;
}

int main() {
    vector<vector<int>> matrix = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    int res = ninjasTraining(matrix);
    cout << res << endl;
}
