//
// Created by hqnddw on 2019/9/10.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
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