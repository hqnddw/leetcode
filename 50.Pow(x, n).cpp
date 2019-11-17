//
// Created by hqnddw on 2019/11/12.
//

class Solution1 {
public:
    double myPow(double x, int n) {
        double res;
        unsigned long long p;
        if (n >= 0) {
            p = n;
            res = helper(x, p);
        } else {
            p = -n;
            res = 1.0 / helper(x, p);
        }
        return res;
    }

    double helper(double x, unsigned long long n) {
        double res = 1;
        double base = x;
        while (n > 0) {
            if (n & 1)
                res *= base;
            n >>= 1;
            base *= base;
        }

        return res;
    }
};