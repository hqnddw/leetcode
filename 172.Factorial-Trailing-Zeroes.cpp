//
// Created by hqnddw on 2020/6/2.
//

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        int a = 1;
        for (int i = n; i >= 2; --i) {
            a *= i;
            if (a % 10 == 0) {
                a /= 10;
                res++;
            }
        }
        return res;
    }
};