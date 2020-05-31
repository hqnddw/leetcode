//
// Created by yida on 2020/5/26.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> v;
        helper(res, v, n, k, 1);
        return res;
    }

    void helper(vector<vector<int>> &res, vector<int> &v,
                int n, int k, int start) {
        if (v.size() == k) {
            res.push_back(v);
            return;
        }
        for (int i = start; i <= n; ++i) {
            v.push_back(i);
            helper(res, v, n, k, i + 1);
            v.pop_back();
        }
    }
};