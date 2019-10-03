//
// Created by hqnddw on 2019/9/4.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution1 {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> re;
        unordered_map<int, int> dict;
        for (int i = 0; i < nums.size(); ++i) {
            int key = target - nums[i];
            if (dict.find(key) != dict.end()) {
                re.push_back(i);
                re.push_back(dict.find(key)->second);
                return re;
            } else dict.insert(make_pair(nums[i], i));
        }
        return re;
    }
};


class Solution2 {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> dict;
        vector<int> v;
        for (int i = 0; i < nums.size(); ++i) {
            int key = target - nums[i];
            if (dict.find(key) != dict.end()) {
                v.push_back(dict[key]);
                v.push_back(i);
                return v;
            } else dict[nums[i]] = i;
        }
        return v;
    }
};


class Solution3 {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> dict;
        vector<int> v;
        for (int i = 0; i < nums.size(); ++i) {
            int key = target - nums[i];
            if (dict.find(key) != dict.end()) {
                v.push_back(dict[key]);
                v.push_back(i);
            } else dict[nums[i]] = i;
        }
        return v;
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> res;
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            int key = target - nums[i];
            if (hash.find(key) != hash.end()) {
                res.push_back(hash[key]);
                res.push_back(i);
                return res;
            } else hash[nums[i]] = i;
        }
        return res;
    }
};