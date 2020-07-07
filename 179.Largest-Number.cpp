//
// Created by hqnddw on 2020/6/2.
//
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        struct compare {
            bool operator()(string s1, string s2) {
                string res1 = s1 + s2;
                string res2 = s2 + s1;
                return res1 > res2;
            }
        };
        vector<string> v;
        for (auto i : nums)
            v.push_back(to_string(i));
        sort(v.begin(), v.end(), compare());
        string res;
        for (auto i : v) {
            res += i;
        }
        if (res[0] == '0')
            return "0";
        return res;
    }
};