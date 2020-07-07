//
// Created by lwl on 2020/7/6.
//
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (!dq.empty() && i - dq.front() == k)
                dq.pop_front();
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            if (i + 1 >= k) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};