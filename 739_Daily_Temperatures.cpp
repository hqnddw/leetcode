//
// Created by hqnddw on 2019/7/6.
//
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &T) {
        int n = T.size();
        vector<int> v(n, 0);
        stack<int> s;
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && T[i] >= T[s.top()])
                s.pop();
            if (!s.empty()) v[i] = s.top() - i;
            s.push(i);
        }
        return v;
    }
};
