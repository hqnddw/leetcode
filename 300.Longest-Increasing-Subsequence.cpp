//
// Created by yida on 2020/5/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cur = 0;
                if (grid[i][j] == 1) {
                    dfs(grid, m, n, i, j, cur);
                    res = max(res, cur);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>> &grid, int row, int col, int i, int j, int &cur) {
        if (i < 0 || i == row || j < 0 || j == col || grid[i][j] != '1')
            return;
        grid[i][j] = 0;
        cur++;
        dfs(grid, row, col, i - 1, j, cur);
        dfs(grid, row, col, i + 1, j, cur);
        dfs(grid, row, col, i, j - 1, cur);
        dfs(grid, row, col, i, j + 1, cur);
    }
};