//
// Created by hqnddw on 2019/6/29.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        int max_sum = nums[0];
        int dp[10000] = {};
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (dp[i - 1] > 0)
                dp[i] = dp[i - 1] + nums[i];
            else dp[i] = nums[i];
            max_sum = max(dp[i], max_sum);
        }
        return max_sum;
    }
};

//int main() {
//    Solution s;
//    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
//    vector<int> nums(a, a + 9);
//    cout << s.maxSubArray(nums) << endl;
//}