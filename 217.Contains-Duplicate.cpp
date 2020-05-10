//
// Created by hqnddw on 2020/5/8.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_map<int, int> map;
        for (int i : nums) {
            if (++map[i] == 2)
                return false;
        }
        return true;
    }
};
