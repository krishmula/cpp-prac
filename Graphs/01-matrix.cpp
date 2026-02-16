#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> res(m, vector<int>(n, 0));
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        while (!q.empty()) {
            int a = q.front().first.first;
            int b = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            res[a][b] = dist;

            vector<pair<int, int>> neighbours = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (auto [dr, dc]: neighbours) {
                int row = a + dr;
                int col = b + dc;
                if (!visited[row][col] && row >= 0 && row < m && col >= 0 && col < n) {
                    q.push({{row, col}, dist + 1});
                    visited[row][col] = 1;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<vector<int>> mat1 = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    cout << "Test Case 1:" << endl;
    cout << "Input:" << endl;
    for (const auto& row : mat1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    vector<vector<int>> result1 = solution.updateMatrix(mat1);
    cout << "Output:" << endl;
    for (const auto& row : result1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Test case 2
    vector<vector<int>> mat2 = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    cout << "Test Case 2:" << endl;
    cout << "Input:" << endl;
    for (const auto& row : mat2) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    vector<vector<int>> result2 = solution.updateMatrix(mat2);
    cout << "Output:" << endl;
    for (const auto& row : result2) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Test case 3: Single cell with 0
    vector<vector<int>> mat3 = {{0}};
    cout << "Test Case 3:" << endl;
    cout << "Input: [[0]]" << endl;
    vector<vector<int>> result3 = solution.updateMatrix(mat3);
    cout << "Output: [[" << result3[0][0] << "]]" << endl;
    cout << endl;

    // Test case 4: Single cell with 1
    vector<vector<int>> mat4 = {{1}};
    cout << "Test Case 4:" << endl;
    cout << "Input: [[1]]" << endl;
    vector<vector<int>> result4 = solution.updateMatrix(mat4);
    cout << "Output: [[" << result4[0][0] << "]]" << endl;

    return 0;
}
