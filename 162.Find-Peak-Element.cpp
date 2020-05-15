//
// Created by hqnddw on 2020/5/10.
//
#include <vector>

using namespace std;

//线性
class Solution1 {
public:
    int findPeakElement(vector<int> &nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1])
                return i;
        }
        return nums.size() - 1;
    }
};

//二分
class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[mid + 1])
                hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};