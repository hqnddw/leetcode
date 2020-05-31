//
// Created by yida on 2020/5/17.
//
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> map;
        vector<int> res;
        for (int i : nums2)
            map[i]++;
        for (int i : nums1) {
            if (map[i] > 0) {
                res.push_back(i);
                map[i]--;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        int l1 = 0, l2 = 0;
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (l1 < nums1.size() && l2 < nums2.size()) {
            if (nums1[l1] == nums2[l2]) {
                res.push_back(nums1[l1]);
                l1++;
                l2++;
            } else if (nums1[l1] > nums2[l2])
                l2++;
            else l1++;
        }
        return res;
    }
};