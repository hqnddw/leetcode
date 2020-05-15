//
// Created by yida on 2020/4/22.
//
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        vector<int> res;
        vector<int> v1(nums.begin(), nums.end() - k);
        vector<int> v2(nums.end() - k + 1, nums.end());
        nums = v1.insert(v1.end(), v2.begin(), v2.end());

    }
};