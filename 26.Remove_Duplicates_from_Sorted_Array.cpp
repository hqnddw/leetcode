//
// Created by hqnddw on 2019/9/7.
//
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


//双指针
class Solution1 {
public:
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
        int i = 0;
        if (n == 0) return 0;
        for (int j = 1; j < n; ++j) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};


//STL
class Solution2 {
public:
    int removeDuplicates(vector<int> &nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};


class Solution3 {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty())
            return 0;
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[i] != nums[j]) {
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};


class Solution4 {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty())
            return 0;
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};