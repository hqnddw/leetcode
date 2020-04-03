//
// Created by hqnddw on 2019/10/27.
//
#include <vector>

using namespace std;

class Solution1 {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty())
            return 0;
        int i = 0;
        int flag = false;
        for (int j = 1; j < nums.size(); ++j) {
            if (nums[j] == nums[i]) {
                if (!flag) {
                    nums[++i] = nums[j];
                    flag = true;
                }
            } else {
                nums[++i] = nums[j];
                flag = false;
            }
        }
        return i + 1;
    }
};


class Solution2 {
public:
    int removeDuplicates(vector<int> &nums) {
        int i = 0;
        for (auto n : nums) {
            if (i < 2 || n > nums[i - 2])
                nums[++i] = n;
        }
        return i + 1;
    }
};


class Solution3 {
public:
    int removeDuplicates(vector<int> &nums) {
        int i = 0;
        int j = 0;
        while (j < nums.size()) {
            if (i < 2 || nums[j] > nums[i - 2])
                nums[i++] = nums[j++];
            else j++;
        }
        return i;
    }
};