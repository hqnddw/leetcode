//
// Created by lwl on 2020/7/14.
//
#include <vector>

using namespace std;

class Solution {
public:
    int reversePairs(vector<int> &nums) {
        vector<int> tmp(nums.size(), 0);
        return count(nums, 0, nums.size()-1, tmp);
    }

    int count(vector<int> &nums, int l, int r, vector<int> &tmp) {
        if (l >= r) return 0;
        int mid = l + (r - l) / 2;
        int res = count(nums, l, mid, tmp) + count(nums, mid + 1, r, tmp);
        for (int i = l, j = mid + 1; i <= mid; ++i) {
            while (j <= r && nums[i] / 2.0 > nums[j]) j++;
            res += (j - mid - 1);
        }
        merge(nums, l, mid, r, tmp);
        return res;
    }

    void merge(vector<int> &nums, int l, int mid, int r, vector<int> &tmp) {
        for (int i = l; i <= r; ++i) {
            tmp[i] = nums[i];
        }
        int i = l, j = mid + 1, k = l;
        while (i <= mid || j <= r) {
            if (j > r || (i <= mid && tmp[i] < tmp[j]))
                nums[k++] = tmp[i++];
            else nums[k++] = tmp[j++];
        }
    }
};