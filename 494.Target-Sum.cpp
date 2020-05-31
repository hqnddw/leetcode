//
// Created by yida on 2020/5/20.
//
#include <vector>

using namespace std;

//回溯
class Solution1 {
public:
    int count = 0;

    int findTargetSumWays(vector<int> &nums, int S) {
        helper(nums, S, 0);
        return count;
    }

    void helper(vector<int> &nums, long sum, int index) {
        if (sum == 0 && index == nums.size()) {
            count++;
            return;
        }
        if (index == nums.size()) return;
        helper(nums, sum - nums[index], index + 1);
        helper(nums, sum + nums[index], index + 1);
    }
};


//动态规划
class Solution2 {
public:
    int findTargetSumWays(vector<int> &nums, int S) {
        int sum = 0;
        for (int num : nums)
            sum += num;
        if ((sum+S) % 2 != 0 || sum < S) return false;
        sum += S;
        sum /= 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = 1; j <= sum; ++j) {
                if (j >= nums[i - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[nums.size()][sum];
    }
};


class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int S) {
        int sum = 0;
        for (int num : nums)
            sum += num;
        if ((sum+S) % 2 != 0 || sum < S) return false;
        sum += S;
        sum /= 2;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = sum; j >= 1; --j) {
                    dp[j] += dp[j - nums[i - 1]];
            }
        }
        return dp[sum];
    }
};