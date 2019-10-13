//
// Created by hqnddw on 2019/10/8.
//
#include <vector>

using namespace std;

class Solution1 {
public:
    int jump(vector<int> &nums) {
        int curEnd = 0, reach = 0;
        int step = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            reach = max(reach, i + nums[i]);
            if (i == curEnd) {
                step++;
                curEnd = reach;
                if (curEnd >= nums.size() - 1)
                    break;
            }
        }
        return step;
    }
};


class Solution2 {
public:
    int jump(vector<int> &nums) {
        int n = nums.size(), start = 0, end = 0, step = 0;
        while (end < n - 1) {
            step++;
            int maxEnd = end + 1;
            for (int i = start; i < end; ++i) {
                if (i + nums[i] >= n - 1) return step;
                maxEnd = max(maxEnd, i + nums[i]);
            }
            start = end + 1;
            end = maxEnd;
        }
        return step;
    }
};


class Solution3 {
public:
    int jump(vector<int> &nums) {
        int reach = 0;
        int step = 0;
        int end = 0;
        for (int i = 0; i < nums.size(); ++i) {
            reach = max(reach, i + nums[i]);
            if (i == end) {
                step++;
                end = reach;
            }
        }
        return step;
    }
};


class Solution4 {
public:
    int jump(vector<int> &nums) {
        if (nums.size() <= 1)
            return 0;
        int i = 0;
        int level = 0;
        int curEnd = 0;
        int curMax = 0;
        while (i <= curMax) {
            curEnd = curMax;
            for (; i <= curMax; ++i) {
                curEnd = max(curEnd, i + nums[i]);
                if (curEnd >= nums.size() - 1) return level + 1;
            }
            level++;
            curMax = curEnd;
        }
        return level;
    }
};