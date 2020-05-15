//
// Created by yida on 2020/4/22.
//
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> hash;
        int res = 0;
        int count = 0;
        for (auto i : nums){
            hash[i]++;
        }
        for (auto it : hash){
            if (it.second > nums.size()/2){
                return it.first;
            }
        }
        return -1;
    }
};