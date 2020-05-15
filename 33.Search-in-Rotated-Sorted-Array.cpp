//
// Created by hqnddw on 2019/10/24.
//
#include <vector>
#include <climits>

using namespace std;

//找到最小值的下标，将当前的索引转换为排序后的索引
// 然后用正常的二分查找法
class Solution1 {
public:
    int search(vector<int> &nums, int target) {
        int hi = nums.size() - 1;
        int lo = 0;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[hi])
                lo = mid + 1;
            else hi = mid;
        }
        int bias = lo;
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int realMid = (mid + bias) % nums.size();
            if (nums[realMid] == target)
                return realMid;
            else if (nums[realMid] > target)
                end = mid - 1;
            else start = mid + 1;
        }
        return -1;
    }
};

//对于我们要找的 target ， target 不在的那一段，所有数字可以看做无穷大，
//这样整个数组就可以看做有序的了，可以用正常的二分法去找 target了
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int num = nums[mid];
            if ((target < nums[0]) == (nums[mid] < nums[0]))
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


class Solution3 {
public:
    int search(vector<int> &nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] >= nums[lo]){
                if (target >= nums[lo] && target <nums[mid])
                    hi = mid - 1;
                else lo = mid +1;
            } else {
                if (target >nums[mid] && target <=nums[hi])
                    lo = mid +1;
                else hi = mid -1;
            }
        }
        return -1;
    }
};