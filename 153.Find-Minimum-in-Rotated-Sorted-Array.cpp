//
// Created by hqnddw on 2019/10/23.
//
#include <vector>

using namespace std;

class Solution1 {
public:
    int findMin(vector<int> &nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1])
                return nums[i];
        }
        return 0;
    }
};


class Solution2 {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;

        while (lo < hi) {
            if (nums[hi] > nums[lo])
                return nums[lo];
            int mid = (lo + hi) >> 1;
            if (nums[mid] >= nums[lo])
                lo = mid + 1;
            else hi = mid;
        }
        return 0;
    }
};