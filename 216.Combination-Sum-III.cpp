//
// Created by yida on 2020/5/26.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> v;
        dfs(res, v, k, n, 1);
        return res;
    }

    void dfs(vector<vector<int>> &res, vector<int> &v,
             int k, int n, int start) {
        if (v.size() == 3 && n == 0) {
            res.push_back(v);
            return;
        }
        if (v.size() == 3 && n != 0)
            return;
        if (n < 0)
            return;
        for (int i = start; i <= 9; ++i) {
            v.push_back(i);
            dfs(res, v, k, n - i, i + 1);
            v.pop_back();
        }
    }
};