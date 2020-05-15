//
// Created by yida on 2020/4/16.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);
        vector<int> res(nums.size());
        for (int i = 1; i < nums.size(); ++i) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        for (int j = nums.size() - 2; j >= 0; --j) {
            right[j] = right[j + 1] * nums[j + 1];
        }
        for (int k = 0; k < nums.size(); ++k) {
            res[k] = left[k] *right[k];
        }
        return res;
    }
};