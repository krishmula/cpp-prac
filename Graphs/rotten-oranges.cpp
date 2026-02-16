#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    int count = 0;
    void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));

        while (!q.empty()) {
            auto topEl = q.front();
            q.pop();

            int a = topEl.first;
            int b = topEl.second;

            vector<pair<int, int>> neighbours;
            if (a + 1 < grid.size()) neighbours.push_back(make_pair(a + 1, b));
            if (a - 1 >= 0) neighbours.push_back(make_pair(a - 1, b));
            if (b + 1 < grid[0].size()) neighbours.push_back(make_pair(a, b + 1));
            if (b - 1 >= 0) neighbours.push_back(make_pair(a, b - 1));

            for (auto it: neighbours) {
                int firstEl = it.first;
                int secondEl = it.second;

                if (grid[firstEl][secondEl] == 1) {
                    count++;
                    q.push(make_pair(firstEl, secondEl));
                    grid[firstEl][secondEl] = 2;
                }
            }
        }


    }


    int orangesRotting(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();

       vector<vector<int>> visited(m, vector<int>(n, 0));

       for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
           if (grid[i][j] == 2) {
            bfs(i, j, grid, visited);
            break;
           }
        }
       }

       cout << "Printing the grid after modifications: " << endl;

       for (int i = 0; i < m; i++) {
           for (int j = 0; j < n; j++ ) {
               cout << grid[i][j] << " ";
           }
       }

       for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
       }

       return count;
    }
};

int main() {
    Solution sol;

    // Test case 1: Basic test case
    vector<vector<int>> grid1 = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << "Test case 1:" << endl;
    cout << "Grid: [[2,1,1],[1,1,0],[0,1,1]]" << endl;
    int result1 = sol.orangesRotting(grid1);
    cout << "Result: " << result1 << endl;
    cout << endl;


    // Test case 2: All oranges already rotten
    // Solution sol2;
    // vector<vector<int>> grid2 = {{2, 2, 2}, {2, 2, 2}};
    // cout << "Test case 2:" << endl;
    // cout << "Grid: [[2,2,2],[2,2,2]]" << endl;
    // int result2 = sol2.orangesRotting(grid2);
    // cout << "Result: " << result2 << endl;
    // cout << endl;

    // Test case 3: Impossible case (fresh orange isolated)
    // Solution sol3;
    // vector<vector<int>> grid3 = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    // cout << "Test case 3:" << endl;
    // cout << "Grid: [[2,1,1],[0,1,1],[1,0,1]]" << endl;
    // int result3 = sol3.orangesRotting(grid3);
    // cout << "Result: " << result3 << " (should be -1 if impossible)" << endl;
    // cout << endl;

    // Test case 4: No fresh oranges
    // Solution sol4;
    // vector<vector<int>> grid4 = {{0, 2, 0}};
    // cout << "Test case 4:" << endl;
    // cout << "Grid: [[0,2,0]]" << endl;
    // int result4 = sol4.orangesRotting(grid4);
    // cout << "Result: " << result4 << endl;

    return 0;
}
