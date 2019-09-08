//
// Created by hqnddw on 2019/9/7.
//
#include <vector>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        int re = 0;
        int result = INT_MAX;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int lo = i + 1;
                int hi = nums.size() - 1;
                while (lo < hi) {
                    sum = nums[i] + nums[lo] + nums[hi];
                    if (target == sum)
                        return target;
                    else if (sum > target) {
                        if (abs(sum - target) < result) {
                            re = sum;
                            result = abs(sum - target);
                        };
                        while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
                        hi--;
                    } else {
                        if (abs(sum - target) < result) {
                            re = sum;
                            result = abs(sum - target);
                        };
                        while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                        lo++;
                    }
                }
            }
        }
        return re;
    }
};

//int main() {
//    Solution s;
//    vector<int> nums{-1, 2, 1, -4};
//    int target = -1;
//    cout << s.threeSumClosest(nums, target) << endl;
//}
