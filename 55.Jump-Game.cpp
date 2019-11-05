//
// Created by hqnddw on 2019/10/7.
//
#include <vector>
#include <algorithm>

using namespace std;

//回溯TLE
class Solution1 {
public:
    bool canJump(vector<int> &nums) {
        return helper(nums, 0);
    }

    bool helper(vector<int> &nums, int curPos) {
        if (curPos == nums.size() - 1)
            return true;
        int furthestJump = min(curPos + nums[curPos], (int) nums.size() - 1);
        for (int nextPos = curPos + 1; nextPos <= furthestJump; nextPos++) {
            if (helper(nums, nextPos))
                return true;
        }
        return false;
    }
};


//贪心
class Solution2 {
public:
    bool canJump(vector<int> &nums) {
        int i = 0;
        int n = nums.size();
        for (int reach = 0; i < n && i <= reach; i++) {
            reach = max(reach, i + nums[i]);
        }
        return i == n;
    }
};

//如果数组里边没有 0，那么无论怎么跳，一定可以从第 0 个跳到最后一个位置
//如果有 0 的话，我们只需要看 0 前边的位置，能不能跳过当前的 0
// 如果 0 前边的位置都不能跳过当前 0，那么直接返回 false，如果能的话，就看后边的 0 的情况。
class Solution3 {
public:
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == 0) {
                bool flag = false;
                int j = i - 1;
                while (j >= 0) {
                    if (j + nums[j] > i) {
                        flag = true;
                        break;
                    }
                    j--;
                }
                if (!flag) return false;
            }
        }
        return true;
    }
};


class Solution4 {
public:
    bool canJump(vector<int> &nums) {
        int reach = 0;
        int i;
        for (i = 0; i < nums.size(); ++i) {
            if (i <= reach)
                reach = max(reach, i + nums[i]);
            else break;
        }
        return i == nums.size();
    }
};


class Solution5 {
public:
    bool canJump(vector<int> &nums) {
        int reach = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > reach) return false;
            else reach = max(reach, nums[i] + i);
        }
        return true;
    }
};


class Solution6 {
public:
    bool canJump(vector<int> &nums) {
        int reach = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > reach)
                return false;
            else reach = max(reach, i + nums[i]);
        }
        return true;
    }
};
