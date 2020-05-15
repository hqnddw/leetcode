//
// Created by yida on 2020/4/23.
//
#include <vector>
#include <algorithm>

using namespace std;
// 使用累加和数组
class Solution1 {
public:
    int subarraySum(vector<int> &nums, int k) {
        int res = 0;
        vector<int> sum(nums.size() + 1, 0);
        for (int i = 1; i < nums.size(); ++i) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        for (int j = 0; j < nums.size(); ++j) {
            for (int i = j + 1; i <= nums.size(); ++i) {
                if (sum[i] - sum[j] == k) {
                    res++;
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum == k)
                    res++;
            }
        }
        return res;
    }
};