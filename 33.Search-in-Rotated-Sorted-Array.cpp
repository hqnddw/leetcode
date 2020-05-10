//
// Created by hqnddw on 2019/10/24.
//
#include <vector>
#include <climits>

using namespace std;

class Solution1 {
public:
    int search(vector<int> &nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[lo]) {
                if (target >= nums[lo] && target < nums[mid])
                    hi = mid - 1;
                else lo = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[hi])
                    lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return -1;
    }
};


class Solution2 {
public:
    int search(vector<int> &nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);
            int num = nums[mid];
            if ((target < nums[0]) == (num < nums[0]))
                num = nums[mid];
            else num = target < nums[0] ? INT_MIN : INT_MAX;

            if (num == target)
                return mid;
            else if (num > target)
                hi = mid - 1;
            else lo = mid + 1;
        }
        return -1;
    }
};

class Solution3 {
public:
    int search(vector<int> &nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (nums[mid] > nums[hi])
                lo = mid + 1;
            else hi = mid;
        }
        int bias = lo;
        lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int readMid = (mid + bias) % nums.size();
            if (nums[readMid] == target)
                return readMid;
            else if (nums[readMid] > target)
                hi = mid - 1;
            else lo = mid + 1;
        }
        return -1;
    }
};


class Solution4 {
public:
    int search(vector<int> &nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int num = nums[mid];
            if ((nums[mid] > nums[0]) == (target > nums[0]))
                num = nums[mid];
            else {
                if (target < nums[0])
                    num = INT_MIN;
                else num = INT_MAX;
            }
            if (num == target)
                return mid;
            else if (num > target)
                hi = mid - 1;
            else lo = mid + 1;
        }
        return -1;
    }
};


class Solution5 {
public:
    int search(vector<int> &nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] >= nums[lo]) {
                if (target >= nums[lo] && target < nums[mid])
                    hi = mid - 1;
                else lo = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[hi])
                    lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return -1;
    }
};