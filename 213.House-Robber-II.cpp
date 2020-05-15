//
// Created by hqnddw on 2020/5/7.
//
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (nums.size() < 2)
            return n ? nums[0] : 0;
        return max(helper(nums, 0, n - 2), helper(nums, 1, n - 1));
    }

    int helper(vector<int> &nums, int left, int right) {
        int first = 0;
        int second = 0;
        for (int i = left; i <= right; ++i) {
            int tmp = second;
            second = max(first + nums[i], second);
            first = tmp;
        }
        return second;
    }
};