//
// Created by yida on 2020/5/18.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, amount+1);
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i - coin] + 1, dp[i]);
                }
            }
        }
        return (dp[amount] == amount+1) ? -1 : dp[amount];
    }
};