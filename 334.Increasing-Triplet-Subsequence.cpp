//
// Created by hqnddw on 2020/6/2.
//
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        int minimum = INT_MAX;
        int maximum = INT_MAX;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= minimum) {
                minimum = nums[i];
            } else if (nums[i] <= maximum)
                maximum = nums[i];
            else return true;
        }
        return false;
    }
};