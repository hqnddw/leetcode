//
// Created by yida on 2020/5/16.
//
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int> &nums) {
        vector<double> res;
        for (int i : nums)
            res.push_back(i);
        return dfs(res);
    }

    bool dfs(vector<double> &nums) {
        if (nums.size() == 1) {
            return abs(nums[0] - 24.0) < 0.001;
        }
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                for (double num : helper(nums[i], nums[j])) {
                    vector<double> nextRound;
                    nextRound.push_back(num);
                    for (int k = 0; k < nums.size(); ++k) {
                        if (k != i && k != j)
                            nextRound.push_back(nums[k]);
                    }
                    if (dfs(nextRound)) return true;
                }
            }
        }
        return false;
    }

    vector<double> helper(double a, double b) {
        vector<double> res{a + b, a - b, b - a, a * b, a / b, b / a};
        return res;
    }
};