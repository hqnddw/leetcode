//
// Created by yida on 2020/5/19.
//
#include <vector>

using namespace std;

//二维数组
class Solution1 {
public:
    int change(int amount, vector<int> &coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        for (int k = 0; k <= coins.size(); ++k) {
            dp[k][0] = 1;
        }
        for (int i = 1; i <= coins.size(); ++i) {
            for (int j = 1; j <= amount; ++j) {
                if (j >= coins[i - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[coins.size()][amount];
    }
};


//一维数组
class Solution {
public:
    int change(int amount, vector<int> &coins) {
        vector<int> dp(amount + 1, 0);

        for (int i = 1; i <= coins.size(); ++i) {
            dp[0] = 1;
            for (int j = 1; j <= amount; ++j) {
                if (j >= coins[i-1])
                    dp[j] = dp[j] + dp[j-coins[i-1]];
            }
        }
        return dp[amount];
    }
};