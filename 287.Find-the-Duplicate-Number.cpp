//
// Created by hqnddw on 2020/4/30.
//
#include <algorithm>
#include <vector>

using namespace std;


//排序（不符合不能改动原数组的要求）
class Solution1 {
public:
    int findDuplicate(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1])
                return nums[i];
        }
        return -1;
    }
};


//环检测算法
class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int slow = nums[0];
        int fast = nums[0];
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (fast == slow) {
                slow = nums[0];
                while (slow != fast) {
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow;
            }
        } while (true);
        return -1;
    }
};
