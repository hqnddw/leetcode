//
// Created by yida on 2020/5/15.
//
#include <vector>
#include <unordered_map>

using namespace std;

//O(n)
class Solution1 {
public:
    int singleNonDuplicate(vector<int> &nums) {
        unordered_map<int, int> map;
        for (int i : nums) {
            map[i]++;
        }
        for (auto it : map) {
            if (it.second == 1)
                return it.first;
        }
        return -1;
    }
};

//O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        if (nums.size() == 1)
            return nums[0];
        int lo = 0;
        int hi = nums.size();
        while (lo < hi) {
            int m = lo + (hi - lo) / 2;
            int n = (m % 2 == 0) ? m + 1 : m - 1;
            if (nums[m] == nums[n])
                lo = m + 1;
            else hi = m;
        }
        return nums[lo];
    }
};