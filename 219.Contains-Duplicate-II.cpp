//
// Created by hqnddw on 2020/5/8.
//
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

//暴力
class Solution1 {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j <= i + k && j < nums.size(); ++j) {
                if (nums[i] == nums[j])
                    return true;
            }
        }
        return false;
    }
};

