//
// Created by yida on 2020/5/21.
//
#include <vector>

using namespace std;

class NumArray {
public:
    vector<int> dp;

    NumArray(vector<int> &nums) {
        dp.resize(nums.size()+1, 0);
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = dp[i-1] + nums[i-1];
        }
    }

    int sumRange(int i, int j) {
        if (i == 0)
            return dp[j];
        return dp[j] - dp[i];
    }
};