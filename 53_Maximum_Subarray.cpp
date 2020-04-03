//
// Created by hqnddw on 2019/6/29.
//
#include <iostream>
#include <vector>

using namespace std;

// O(n)空间
class Solution1 {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (dp[i - 1] > 0)
                dp[i] = dp[i - 1] + nums[i];
            else dp[i] = nums[i];
            res = max(res, dp[i]);
        }
        return res;
    }
};

//O(1)空间
class Solution2 {
public:
    int maxSubArray(vector<int> &nums) {
        int dp = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (dp < 0)
                dp = nums[i];
            else dp += nums[i];
            res = max(dp, res);
        }
        return res;
    }
};