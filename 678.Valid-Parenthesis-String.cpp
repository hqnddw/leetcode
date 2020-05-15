//
// Created by yida on 2020/4/17.
//
#include <string>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for (char c:s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else {
                low--;
                high++;
            }
            if (high < 0) return false;
            low = max(0, low);
        }
        return low == 0;
    }
};
