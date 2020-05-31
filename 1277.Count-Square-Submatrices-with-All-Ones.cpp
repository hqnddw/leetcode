//
// Created by yida on 2020/5/22.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>> &matrix) {
        int res = 0;
        if (matrix.empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i - 1][j - 1] == 1) {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                res += dp[i][j];
            }
        }
        return res;
    }
};