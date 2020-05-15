//
// Created by hqnddw on 2020/4/28.
//
#include <vector>
#include <unordered_map>

using namespace std;

//暴力解法
class Solution1 {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                if (nums[j] == s) {
                    if (res == 0)
                        res = j - i + 1;
                    else res = min(res, j - i + 1);
                }
            }
        }
        return res;
    }
};


//双指针
class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int res = INT_MAX;
        int sum = 0;
        int left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (sum >= s) {
                res = min(res, i - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return (res == INT_MAX) ? 0 : res;
    }
};