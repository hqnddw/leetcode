//
// Created by hqnddw on 2019/10/23.
//
#include <vector>
#include <algorithm>
#include <cmath>

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
            if (nums[mid] > nums[lo])
                lo = mid + 1;
            else hi = mid;
        }
        return nums[hi];
    }
};


class Solution3 {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 1)
            return nums[0];
        int lo = 0;
        int hi = nums.size() - 1;
        if (nums[hi] > nums[lo])
            return nums[lo];
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            if (nums[mid - 1] > nums[mid])
                return nums[mid];
            if (nums[mid] > nums[lo])
                lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }
};



