//
// Created by hqnddw on 2019/6/29.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//使用二维数组
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long >> dp(m + 1, vector<long long>(n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (!obstacleGrid[i - 1][j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};


//使用一维数组
class Solution1 {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < obstacleGrid.size(); ++i)
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1)
                    dp[j] = 0;
                else
                    dp[j] += dp[j - 1];
            }
        return dp[n - 1];
    }
};


//int main() {
//    vector<vector<int>> nums(3, vector<int>(3, 0));
//    nums[1][1] = 1;
//    Solution1 s;
//    cout << s.uniquePathsWithObstacles(nums) << endl;
//}