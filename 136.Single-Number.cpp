//
// Created by hqnddw on 2020/4/3.
//
#include <vector>
#include <unordered_map>

using namespace std;

//位运算
class Solution1 {
public:
    int singleNumber(vector<int> &nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            res ^= nums[i];
        }
        return res;
    }
};

//哈希表
class Solution2 {
public:
    int singleNumber(vector<int> &nums) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            if (hash.count(nums[i]))
                hash[nums[i]]--;
            else hash[nums[i]]++;
        }
        for (auto j = hash.begin(); j != hash.end(); ++j) {
            if (j->second == 1)
                return j->first;
        }
        return -1;
    }
};