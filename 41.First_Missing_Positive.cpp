//
// Created by hqnddw on 2019/9/18.
//
#include <vector>

using namespace std;

class Solution1 {
public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int j = 0; j < n; ++j) {
            if (nums[j] != j + 1)
                return j + 1;
        }
        return n + 1;
    }
};


class Solution2 {
public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int j = 0; j < n; ++j) {
            if (nums[j] != j + 1)
                return j + 1;
        }
        return n + 1;
    }
};

class Solution3 {
public:
    int firstMissingPositive(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != j + 1)
                return j + 1;
        }
        return nums.size() + 1;
    }
};
