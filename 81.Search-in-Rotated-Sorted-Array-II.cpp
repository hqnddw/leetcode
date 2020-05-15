//
// Created by hqnddw on 2020/4/28.
//
#include <vector>

using namespace std;

//基于33题的第三种解法
class Solution {
public:
    bool search(vector<int> &nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (nums[mid] == target)
                return true;
            if ((nums[mid] == nums[lo]) && (nums[mid] == nums[hi]) {
                lo++;
                hi--;
            }
            if (nums[mid] >= nums[lo]) {
                if (target >= nums[0] && target < nums[mid])
                    hi = mid - 1;
                else lo = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[hi])
                    lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return false;
    }
};