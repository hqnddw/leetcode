//
// Created by yida on 2020/4/17.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int res = nums[0];
        int imax = nums[0];
        int imin = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int premax = imax;
            imax = max(imax * nums[i], max(nums[i], imin * nums[i]));
            imin = min(premax * nums[i], max(nums[i], imin * nums[i]));
            res = max(res, imax);
        }
        return res;
    }
};