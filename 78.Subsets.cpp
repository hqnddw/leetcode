//
// Created by hqnddw on 2019/9/14.
//
#include <vector>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> v;
        backtrack(res, v, nums, 0);
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &v, vector<int> &nums, int start) {
        res.push_back(v);
        for (int i = start; i < nums.size(); ++i) {
            v.push_back(nums[i]);
            backtrack(res, v, nums, i + 1);
            v.pop_back();
        }
    }
};


class Solution2 {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> v;
        backtrack(res, v, nums, 0);
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &v, vector<int> &nums, int i) {
        if (i >= nums.size()) {
            res.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        backtrack(res, v, nums, i + 1);
        v.pop_back();
        backtrack(res, v, nums, i + 1);
    }
};


//迭代
class Solution3 {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res = {{}};
        for (int i = 0; i < nums.size(); ++i) {
            vector<vector<int>> temp;
            for (auto j:res) {
                j.push_back(nums[i]);
                temp.push_back(j);
            }
            res.insert(res.end(), temp.begin(), temp.end());
        }
        return res;
    }
};


//位运算
class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        int n = nums.size();
        int p = 1 << n;
        vector<vector<int>> res(p);
        for (int i = 0; i < p; ++i) {
            vector<int> temp;
            for (int j = 0; j < nums.size(); ++j) {
                if (i & (1 << j))
                    temp.push_back(nums[j]);
            }
            res.push_back(temp);
        }
        return res;
    }
};