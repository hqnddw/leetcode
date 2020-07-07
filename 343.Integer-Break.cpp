//
// Created by lwl on 2020/6/20.
//
#include <vector>

using namespace std;

class Solution1 {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        if (n == 2) return 1;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};


class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int res = 1;
        while (n > 4) {
            res *= 3;
            n -= 3;
        }
        res *= n;
        return res;
    }
};