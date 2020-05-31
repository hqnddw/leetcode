//
// Created by yida on 2020/5/17.
//
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> set(nums2.begin(), nums2.end());
        unordered_set<int> v(nums1.begin(), nums1.end());
        vector<int > res;
        for (auto it : v){
            if (set.count(it))
                res.push_back(it);
        }
        return res;
    }
};