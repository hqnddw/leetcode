//
// Created by yida on 2020/5/22.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int> &nums) {
        vector<int> v(nums.begin(), nums.end());
        v.insert(v.begin(), 1);
        v.push_back(1);
        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 2; len <= n - 1; ++len) {
            for (int left = 0; left + len < n; ++left) {
                int right = left + len;
                for (int i = left + 1; i <= right - 1; ++i) {
                    dp[left][right] = max(dp[left][right],
                                          dp[left][i] + v[left] * v[i] * v[right] + dp[i][right]);
                }
            }
        }
        return dp[0][n-1];
    }
};