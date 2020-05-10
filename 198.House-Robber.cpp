//
// Created by hqnddw on 2020/5/6.
//
#include <vector>

using namespace std;

//O(n)空间
class Solution1 {
public:
    int rob(vector<int> &nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i + 1] = max(dp[i - 1] + nums[i], dp[i]);
        }
        return dp[n];
    }
};

//O(1)空间
class Solution {
public:
    int rob(vector<int> &nums) {
        int first = 0;
        int second = 0;
        for (int i : nums) {
            int tmp = second;
            second = max(first + i, second);
            first = tmp;
        }
        return second;
    }
};