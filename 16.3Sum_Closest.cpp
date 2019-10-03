//
// Created by hqnddw on 2019/9/7.
//
#include <vector>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution1 {
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




class Solution2 {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int re = nums[0] + nums[1] + nums[n - 1];
        for (int i = 0; i < n; ++i) {
            int lo = i + 1;
            int hi = n - 1;
            while (lo < hi) {
                int cursum = nums[i] + nums[lo] + nums[hi];
                if (cursum == target) return target;
                else {
                    if (abs(cursum - target) < abs(re - target))
                        re = cursum;
                    if (cursum > target) hi--;
                    else lo++;
                }
            }
        }
        return re;
    }
};


class Solution3 {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int re = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int lo = i + 1;
                int hi = nums.size() - 1;
                while (lo < hi) {
                    int cursum = nums[i] + nums[lo] + nums[hi];
                    if (cursum == target)
                        return target;
                    else if (cursum > target) hi--;
                    else lo++;
                    if (abs(cursum - target) < abs(re - target))
                        re = cursum;
                }
            }
        }
        return re;
    }
};


class Solution4 {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int lo = i + 1;
                int hi = nums.size() - 1;
                while (lo < hi) {
                    int curSum = nums[i] + nums[lo] + nums[hi];
                    if (curSum == target)
                        return target;
                    else if (curSum > target)
                        hi--;
                    else lo++;
                    if (abs(curSum - target) < abs(res - target))
                        res = curSum;
                }
            }
        }
        return res;
    }
};