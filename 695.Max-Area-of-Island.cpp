//
// Created by yida on 2020/5/25.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution1 {
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        if (grid.empty()) return 0;
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    res = max(res, dfs(grid, i, j, visited));
                }
            }
        }
        return res;
    }

    int dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool >> &visited) {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() ||
            grid[i][j] == 0 || visited[i][j])
            return 0;
        visited[i][j] = true;
        return 1 + dfs(grid, i + 1, j, visited)
               + dfs(grid, i - 1, j, visited)
               + dfs(grid, i, j + 1, visited)
               + dfs(grid, i, j - 1, visited);
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        if (grid.empty()) return 0;
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int sum = 0;
                    dfs(grid, i, j, sum, visited);
                    res = max(res, sum);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>> &grid, int i, int j, int &sum, vector<vector<bool>> &visited) {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size()
            || visited[i][j] || grid[i][j] == 0)
            return;
        visited[i][j] = true;
        sum++;
        dfs(grid, i + 1, j, sum, visited);
        dfs(grid, i - 1, j, sum, visited);
        dfs(grid, i, j + 1, sum, visited);
        dfs(grid, i, j - 1, sum, visited);
    }
};