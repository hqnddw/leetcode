//
// Created by yida on 2020/4/22.
//
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > nums[mid + 1])
                hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};