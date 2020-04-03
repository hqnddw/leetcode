//
// Created by hqnddw on 2019/10/26.
//
#include <vector>
#include <cmath>
#include <string>

using namespace std;

class Solution1 {
public:
    vector<int> plusOne(vector<int> &digits) {
        for (int i = digits.size(); i >= 0; --i) {
            if (digits[i] == 9)
                digits[i] = 0;
            else {
                digits[i]++;
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};


class Solution2 {
public:
    vector<int> plusOne(vector<int> &digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] == 9)
                digits[i] = 0;
            else {
                digits[i] += 1;
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};