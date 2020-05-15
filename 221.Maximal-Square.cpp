//
// Created by hqnddw on 2020/4/29.
//
#include <vector>

using namespace std;

//暴力解法，搜索每一个可能的子集
class Solution1 {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.empty()) return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int res = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    int len = 1;
                    bool flag = true;
                    while (len + i < row && len + j < col && flag) {
                        for (int k = j; k <= j + len; ++k) {
                            if (matrix[i + len][k] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        for (int l = i; l <= i + len; ++l) {
                            if (matrix[l][j + len] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        if (flag) len++;
                    }
                    res = max(res, len);
                }
            }
        }
        return res * res;
    }
};

//动态规划，O(n*n) space
class Solution2 {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res * res;
    }
};

//O(n) space
class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        int pre = 0;
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int tmp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = min(dp[j - 1], min(dp[j], pre)) + 1;
                    res = max(res, dp[j]);
                } else dp[j] = 0;
                pre = tmp;
            }
        }
        return res * res;
    }
};