//
// Created by hqnddw on 2019/9/10.
//
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> v;
        backtrack(res, v, candidates, target, 0);
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &v,
                   vector<int> &nums, int remain, int start) {
        if (remain < 0) return;
        else if (remain == 0) res.push_back(v);
        else {
            for (int i = start; i < nums.size(); ++i) {
                if (i == start || (i > start && nums[i] != nums[i - 1])) {
                    v.push_back(nums[i]);
                    backtrack(res, v, nums, remain - nums[i], i + 1);
                    v.pop_back();
                }
            }
        }
    }
};


class Solution2 {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> v;
        backtrack(res, v, candidates, target, 0);
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &v,
                   vector<int> &nums, int remain, int index) {
        if (remain < 0) return;
        else if (remain == 0) res.push_back(v);
        else {
            for (int i = index; i < nums.size(); ++i) {
                v.push_back(nums[i]);

                backtrack(res, v, nums, remain - nums[i], i + 1);
                v.pop_back();
            }
        }
    }
};

