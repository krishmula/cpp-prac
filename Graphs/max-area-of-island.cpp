class Solution {
public:
    int maxVal = 0;
    int count = 0;
    void dfs(int i, int j, vector<vector<int>>& visited, vector<vector<int>>& grid) {
        count += 1;
        visited[i][j] = 1;
        vector<pair<int, int>> neighbours;
        if (i + 1 < grid.size()) neighbours.push_back(make_pair(i + 1, j));
        if (i - 1 >= 0) neighbours.push_back(make_pair(i - 1, j));
        if (j + 1 < grid[0].size()) neighbours.push_back(make_pair(i, j + 1));
        if (j - 1 >= 0) neighbours.push_back(make_pair(i, j - 1));

        for (auto it : neighbours) {
            int a = it.first;
            int b = it.second;
            if (!visited[a][b] && grid[a][b] == 1) {
                count++;
                dfs(a, b, visited, grid);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                count = 0;
                if (grid[i][j] == '1' && !visited[i][j]) dfs(i, j, visited, grid);
                maxVal = max(count, maxVal);
            }
        }

        return maxVal;
    }
};
