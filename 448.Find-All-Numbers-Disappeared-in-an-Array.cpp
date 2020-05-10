//
// Created by hqnddw on 2020/5/2.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            while ((nums[i] != i + 1) && (nums[i] != nums[nums[i] - 1]))
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != (j + 1))
                res.push_back(j + 1);
        }
        return res;
    }
};
