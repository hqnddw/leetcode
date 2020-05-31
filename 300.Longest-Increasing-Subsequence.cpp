//
// Created by yida on 2020/5/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> dp(nums.size());
        dp[0] = 1;
        int res = 0;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] > nums[i])
                    dp[i] = max(dp[j] + 1, dp[i]);
                else dp[i] = max(1, dp[i]);
            }
        }
        for (int k = 0; k < dp.size(); ++k) {
            res = max(res, dp[k]);
        }
        return res;
    }
};