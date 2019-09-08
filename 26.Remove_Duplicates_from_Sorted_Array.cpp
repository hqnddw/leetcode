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
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};