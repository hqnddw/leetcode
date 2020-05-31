//
// Created by yida on 2020/5/19.
//
#include <vector>
#include <iostream>

using namespace std;

/*
Given a set of non-negative integers, and a value sum,
determine if there is a subset of the given set with sum equal to given sum.

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True
Explanation: There is a subset (4, 5) with sum 9.

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
Output: False
Explanation:  There is no subset that add up to 30.
*/

//二维数组
class Solution1 {
public:
    bool isSubsetSum(vector<int> nums, int sum) {
        vector<vector<bool>> dp(nums.size() + 1,
                                vector<bool>(sum + 1, false));
        for (int i = 0; i <= nums.size(); i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= sum; j++) {
                if (j >= nums[i - 1])
                    dp[i][j] = dp[i - 1][j] ||
                               dp[i - 1][j - nums[i - 1]];
                else dp[i][j] = dp[i - 1][j];

            }
        }
        return dp[nums.size()][sum];
    }
};

class Solution {
public:
    bool isSubsetSum(vector<int> nums, int sum) {
        vector<bool > dp(sum + 1, false);
        dp[0] = true;
        for (int i = 1; i <= nums.size() ; ++i) {
            for (int j = sum; j >= 1 ; --j) {
                if (j >= nums[i])
                    dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[sum];
    }
};

int main() {
    Solution s;
    vector<int> set = {3, 34, 4, 12, 5, 2};
    int sum = 11;
    if (s.isSubsetSum(set, sum))
        cout << "Found a subset with given sum" << endl;
    else
        cout << "No subset with given sum" << endl;
    return 0;
}