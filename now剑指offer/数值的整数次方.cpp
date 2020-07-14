//
// Created by hqnddw on 2019/11/12.
//

#include <cmath>

class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent >= 0)
            return helper(base, exponent);
        else {
            exponent = abs(exponent);
            return 1.0 / helper(base, exponent);
        }
    }

    double helper(double base, int exponent) {
        double res = 1.0;
        for (int i = 0; i < exponent; ++i) {
            res *= base;
        }
        return res;
    }
};