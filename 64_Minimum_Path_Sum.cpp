//
// Created by hqnddw on 2019/6/29.
//
#include <iostream>
#include <vector>

using namespace std;

//O(m*n)
class Solution1 {
public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int k = 1; k < m; ++k) {
            for (int i = 1; i < n; ++i) {
                dp[k][i] = min(dp[k - 1][i], dp[k][i - 1]) + grid[k][i];
            }
        }
        return dp[m - 1][n - 1];
    }
};

//O(m)
class Solution2 {
public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.empty()) return 0;
        int m = grid[0].size();
        vector<int> pre(m, grid[0][0]);
        vector<int> cur(m, 0);
        for (int i = 1; i < m; ++i) {
            pre[i] = pre[i-1] + grid[0][i];
        }
        for (int j = 1; j < grid.size(); ++j) {
            cur[0] = pre[0] + grid[j][0];
            for (int i = 1; i < grid[0].size(); ++i) {
                cur[i] = min(cur[i-1], pre[i]) + grid[j][i];
            }
            swap(cur, pre);
        }
        return cur[m-1];
    }
};

//O(1)
class Solution3 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> cur(grid[0].size(), grid[0][0]);
        for (int i = 1; i < grid[0].size(); ++i) {
            cur[i] = cur[i-1] + grid[0][i];
        }
        for (int i = 1; i < grid.size(); ++i) {
            cur[0] += grid[i][0];
            for (int j = 1; j < grid[0].size(); ++j) {
                cur[i] = min(cur[i-1], cur[i]) + grid[i][j];
            }
        }
        return cur[grid[0].size()-1];
    }
};
