//
// Created by yida on 2020/5/20.
//
#include <vector>
#include <iostream>

using namespace std;

/*
Given an array of integers and a sum, the task is to print all
subsets of given array with sum equal to given sum.

    Input : arr[] = {2, 3, 5, 6, 8, 10}
            sum = 10
    Output : 5 2 3
             2 8
             10

    Input : arr[] = {1, 2, 3, 4, 5}
            sum = 10
    Output : 4 3 2 1
             5 3 2
             5 4 1
 */

class Solution {
public:
    vector<vector<int >> getSet(vector<int> &nums, int sum) {
        vector<vector<int>> res;
        vector<int> v;
        helper(nums, res, v, 0, sum);
        return res;
    }

    void helper(vector<int> &nums, vector<vector<int>> &res,
                vector<int> &v, int n, int sum) {
        if (sum == 0) {
            res.push_back(v);
            return;
        }
        if (n >= nums.size()) return;
        for (int i = n; i < nums.size(); ++i) {
            if (sum >= nums[i]) {
                v.push_back(nums[i]);
                helper(nums, res, v, i + 1, sum - nums[i]);
                v.pop_back();
            } else {
                helper(nums, res, v, i + 1, sum);
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums{2, 3, 5, 6, 8, 10};
    int sum = 10;
    for (auto v : s.getSet(nums, sum)) {
        cout << "[ ";
        for (auto i : v) {
            cout << i << " ";
        }
        cout << "]"<<endl;
    }
}