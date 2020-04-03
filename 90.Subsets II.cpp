//
// Created by hqnddw on 2019/9/15.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> v;
        backtrack(res, v, nums, 0);
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &v, vector<int> &nums, int start) {
        res.push_back(v);
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            v.push_back(nums[i]);
            backtrack(res, v, nums, i + 1);
            v.pop_back();
        }
    }
};

//迭代
class Solution2 {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {{}};
        int start = 1;
        for (int i = 0; i < nums.size(); ++i) {
            vector<vector<int>> temp;
            for (int j = 0; j < res.size(); j++) {
                if (i > 0 && nums[i] == nums[i - 1] && j < start)
                    continue;
                vector<int> v(res[j]);
                v.push_back(nums[i]);
                temp.push_back(v);
            }
            start = res.size();
            res.insert(res.end(), temp.begin(), temp.end());
        }
        return res;
    }
};


class Solution3 {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> res = {{}};
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int count = 0;
            while ((i + 1) < nums.size() && nums[i] == nums[i + 1]) {
                count++;
                i++;
            }
            vector<vector<int>> temp;
            for (auto j:res) {
                for (int k = 0; k <= count; ++k) {
                    j.push_back(nums[i]);
                    temp.push_back(j);
                }
            }
            res.insert(res.end(), temp.begin(), temp.end());
        }
        return res;
    }
};


class Solution4 {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> v;
        backtrack(res, v, nums, 0);
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &v, vector<int> &nums, int start) {
        res.push_back(v);
        for (int i = start; i < nums.size(); ++i) {
            if (i == start || (i > 0 && nums[i] != nums[i - 1])) {
                v.push_back(nums[i]);
                backtrack(res, v, nums, i + 1);
                v.pop_back();
            }
        }
    }
};


class Solution5 {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> res = {{}};
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int count = 0;
            while ((i + 1) < nums.size() && nums[i] == nums[i + 1]) {
                i++;
                count++;
            }
            vector<vector<int>> temp;
            for (auto j : res) {
                for (int k = 0; k <= count; k++) {
                    j.push_back(nums[i]);
                    temp.push_back(j);
                }
            }
            res.insert(res.end(), temp.begin(), temp.end());
        }
        return res;
    }
};


class Solution6 {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> v;
        backtrack(res, v, nums, 0);
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &v, vector<int> &nums, int start) {
        res.push_back(v);
        for (int i = start; i < nums.size(); ++i) {
            if (i == start && i > 0 && nums[i] == nums[i - 1])
                continue;
            v.push_back(nums[i]);
            backtrack(res, v, nums, i + 1);
            v.pop_back();
        }
    }
};


class Solution7 {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            int dupCount = 0;
            while ((i + 1) < nums.size() && nums[i] == nums[i + 1]) {
                dupCount++;
                i++;
            }
            vector<vector<int>> temp;
            int resSize = res.size();
            for (int j = 0; j <= resSize; ++j) {
                while (dupCount--) {
                    vector<int> v(res[j]);
                    v.push_back(nums[i]);
                    temp.push_back(v);
                }
            }
            res.insert(res.end(), temp.begin(), temp.end());
        }
        return res;
    }
};