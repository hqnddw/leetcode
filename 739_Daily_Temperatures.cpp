//
// Created by hqnddw on 2019/7/6.
//
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &T) {
        stack<int> s;
        int i = T.size() - 1;
        vector<int> res;
        while (i >= 0) {
            if (s.empty()) {
                s.push(i);
                res.push_back(0);
            } else {
                while (!s.empty() && T[i] >= T[s.top()])
                    s.pop();
                if (s.empty()) res.push_back(0);
                else res.push_back(s.top() - i);
                s.push(i);
            }
            i--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
