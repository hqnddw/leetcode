//
// Created by yida on 2020/5/21.
//
#include <vector>
#include <stack>

using namespace std;

//暴力
class Solution1 {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        vector<int> res;
        stack<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            int flag = true;
            for (int j = i; j < i + nums.size(); ++j) {
                if (nums[j % nums.size()] > nums[i]) {
                    res.push_back(nums[j % nums.size()]);
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(-1);
        }
        return res;
    }
};

//栈
class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> s;
        for (int i = 0; i < 2 * n; ++i) {
            while (!s.empty() && nums[i % n] > nums[s.top()]) {
                res[s.top()] = nums[i % n];
                s.pop();
            }
            s.push(i%n);
        }
        return res;
    }
};
