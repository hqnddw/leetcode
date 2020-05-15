//
// Created by yida on 2020/4/15.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        unordered_map<int, int> hash;
        int res = 0;
        int count = 0;
        hash[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            count += (nums[i] == 1) ? 1 : -1;
            if (hash.count(count))
                res = max(res, i - hash[count]);
            else hash[count] = i;
        }
        return res;
    }
};