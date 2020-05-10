//
// Created by hqnddw on 2020/5/6.
//
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//sort
class Solution1 {
public:
    int majorityElement(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

//hash table
class Solution2 {
public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> map;
        int n = nums.size();
        for (int i : nums) {
            map[i]++;
            if (map[i] > n / 2)
                return i;
        }
        return -1;
    }
};


//投票法
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int count = 0;
        int cur;
        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0) {
                cur = nums[i];
                count++;
            } else if (nums[i] == cur)
                count++;
            else if (nums[i] != cur)
                count--;
        }
        return cur;
    }
};