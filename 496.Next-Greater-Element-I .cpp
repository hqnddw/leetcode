//
// Created by yida on 2020/5/20.
//

#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;


//暴力
class Solution1 {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> map;
        vector<int> res;
        for (int i = 0; i < nums2.size(); ++i) {
            map[nums2[i]] = i;
        }
        bool flag = true;
        for (int i : nums1) {
            for (int j = map[i] + 1; j < nums2.size(); ++j) {
                if (nums2[j] > i) {
                    res.push_back(nums2[j]);
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(-1);
        }
        return res;
    }
};



//栈
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> map;
        stack<int> s;
        for (int num : nums2){
            while (!s.empty() && num > s.top()){
                map[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        for (int i = 0; i < nums1.size(); ++i) {
            if (map.count(nums1[i]))
                res.push_back(map[nums1[i]]);
            else res.push_back(-1);
        }
        return res;
    }
};