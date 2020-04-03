//
// Created by hqnddw on 2019/10/8.
//
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        backtrack(res, nums, 0);
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &nums, int start) {
        if (start == nums.size() - 1) {
            res.push_back(nums);
            return;
        } else {
            for (int i = start; i < nums.size(); ++i) {
                if (i > start && nums[i] == nums[start]) continue;
                swap(nums[i], nums[start]);
                backtrack(res, nums, start + 1);
            }
            for (int j = nums.size() - 1; j > start && nums[j] != nums[start]; j--) {
                swap(nums[start], nums[j]);
            }
        }
    }
};