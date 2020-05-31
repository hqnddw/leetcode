//
// Created by yida on 2020/5/25.
//
#include <vector>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>> &M) {
        int res = 0;
        if (M.empty()) return res;
        int m = M.size(), n = M[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == 1 && !visited[i][j]) {
                    res++;
                    dfs(M, i, j, visited);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>> &grid, int i, int j,
             vector<vector<bool>> &visited) {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size()
            || visited[i][j])
            return;
        visited[i][j] = true;
        visited[j][i] = true;
        for (int k = 0; k < grid[0].size(); ++k) {
            if (grid[i][k] == 1 && !visited[i][k])
                dfs(grid, i, k, visited);
        }
        for (int l = 0; l < grid.size(); ++l) {
            if (grid[l][j] == 1 && !visited[l][j])
                dfs(grid, l, j, visited);
        }
    }
};
