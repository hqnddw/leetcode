//
// Created by hqnddw on 2019/10/8.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> v;
        backtrack(nums, res, v);
        return res;
    }

    void backtrack(vector<int> &nums, vector<vector<int>> &res, vector<int> &v) {
        if (v.size() == nums.size()) {
            res.push_back(v);
            return;
        } else {
            for (int i = 0; i < nums.size(); ++i) {
                if (find(v.begin(), v.end(), nums[i]) != v.end())
                    continue;
                v.push_back(nums[i]);
                backtrack(nums, res, v);
                v.pop_back();
            }
        }
    }
};


class Solution2 {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        backtrack(res, nums, 0);
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &nums, int start) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        } else {
            for (int i = start; i < nums.size(); ++i) {
                swap(nums[i], nums[start]);
                backtrack(res, nums, start + 1);
                swap(nums[i], nums[start]);
            }
        }
    }
};


class Solution3 {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> v;
        backtrack(res, v, nums);
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &v, vector<int> &nums) {
        if (v.size() == nums.size()) {
            res.push_back(v);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (find(v.begin(), v.end(), nums[i]) != v.end()) continue;
            v.push_back(nums[i]);
            backtrack(res, v, nums);
            v.pop_back();
        }
    }
};


class Solution4 {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> v;
        helper(res, v, nums, 0);
        return res;
    }

    void helper(vector<vector<int>> &res, vector<int> &v, vector<int> &nums, int start) {
        if (v.size() == nums.size()) {
            res.push_back(v);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (find(v.begin(), v.end(), nums[i]) != v.end()) continue;
            v.push_back(nums[i]);
            helper(res, v, nums, i + 1);
            v.pop_back();
        }
    }
};


class Solution5 {
public:
    vector<vector<int>> permute(vector<int> &nums) {

    }
};