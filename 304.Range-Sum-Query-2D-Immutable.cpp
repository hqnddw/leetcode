//
// Created by yida on 2020/5/21.
//
#include <vector>

using namespace std;

class NumMatrix {
public:
    vector<vector<int >> dp;

    NumMatrix(vector<vector<int>> &matrix) {
        int col;
        if (matrix.empty())
            col = 1;
        else col = matrix[0].size();
        dp.resize(matrix.size() + 1, vector<int>(col + 1, 0));
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[0].size(); ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0)
            return dp[row2][col2];
        else if (row1 == 0)
            return dp[row2][col2] - dp[row2][col1 - 1];
        else if (col1 == 0)
            return dp[row2][col2] - dp[row1 - 1][col2];
        return dp[row2][col2] - dp[row1 - 1][col2] - dp[row2][col1 - 1] + dp[row1 - 1][col1 - 1];
    }
};