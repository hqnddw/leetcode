//
// Created by hqnddw on 2020/5/7.
//
#include <vector>

using namespace std;

//intuition
class Solution1 {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        for (int i = 0; i <= num; ++i) {
            res.push_back(helper(i));
        }
        return res;
    }

    int helper(int n) {
        int res = 0;
        while (n) {
            res += n / 2;
            n /= 2;
        }
        return res;
    }
};


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        for (int i = 1; i <= num; ++i) {
            dp[i] = dp[i >> 1] + i & 1;
        }
        return dp;
    }
};