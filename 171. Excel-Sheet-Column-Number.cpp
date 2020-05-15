//
// Created by yida on 2020/4/22.
//
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        if (s.size() == 1)
            return s[0] - 'A' + 1;
        int result = 0;
        int n = s.size();
        result = pow(26, n - 1) + s.back() - 'A' + 1;
        return result;
    }
};