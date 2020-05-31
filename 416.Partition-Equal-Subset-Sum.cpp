//
// Created by yida on 2020/5/19.
//
#include <vector>

using namespace std;


//O(m*n)
class Solution1 {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int i : nums)
            sum += i;
        sum /= 2;
        vector<vector<bool >> dp(nums.size() + 1, vector<bool>(sum + 1, false));
        for (int k = 0; k <= nums.size(); ++k) {
            dp[k][0] = true;
        }
        for (int j = 1; j <= nums.size(); ++j) {
            for (int i = 1; i <= sum; ++i) {
                if (nums[j - 1] > i)
                    dp[j][i] = dp[j - 1][i];
                else dp[j][i] = dp[j - 1][i - nums[j - 1]] || dp[j - 1][i];
            }
        }
        return dp[nums.size()][sum];
    }
};

//O(n)
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) return false;
        sum /= 2;

        vector<bool> dp(sum + 1, false);
        for (int i = 1; i <= nums.size(); ++i) {
            dp[0] = true;
            for (int j = sum; j >= 1; --j) {
                if (j >= nums[i - 1])
                dp[j] = dp[j] || dp[j - nums[i - 1]];
            }
        }
        return dp[sum];
    }
};