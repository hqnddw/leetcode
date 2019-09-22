//
// Created by hqnddw on 2019/9/10.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> re;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        backtrack(re, v, candidates, target, 0);
        return re;
    }

    void backtrack(vector<vector<int>> &re, vector<int> &v,
                   vector<int> &nums, int remain, int start) {
        if (remain < 0) return;
        else if (remain == 0) re.push_back(v);
        else {
            for (int i = start; i < nums.size(); ++i) {
                v.push_back(nums[i]);
                backtrack(re, v, nums, remain - nums[i], i);
                v.pop_back();
            }
        }
    }
};

class Solution2 {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> v;
        backtrack(res, candidates, v, target, 0);
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &nums,
                   vector<int> &v, int remain, int index) {
        if (remain < 0) return;
        else if (remain == 0) {
            res.push_back(v);
        } else {
            for (int i = index; i < nums.size(); ++i) {
                v.push_back(nums[i]);
                backtrack(res, nums, v, remain - nums[i], i);
                v.pop_back();
            }
        }
    }
};


class Solution3 {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> v;
        backtrack(res, v, candidates, target, 0);
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &v,
                   vector<int> &nums, int remain, int start) {
        if (remain < 0) return;
        if (remain == 0) {
            res.push_back(v);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            v.push_back(nums[i]);
            backtrack(res, v, nums, remain - nums[i], i);
            v.pop_back();
        }
    }
};

class Solution4 {
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
        else if (remain == 0) {
            res.push_back(v);
            return;
        } else {
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
