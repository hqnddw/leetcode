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
    int removeElement(vector<int> &nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i + 1;
    }
};

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                i++;
                n--;
            } else i++;
        }
        return i;
    }
};