//
// Created by hqnddw on 2020/5/9.
//

class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        for (int i = 1; i < n; ++i) {
            if (helper(i))
                res++;
        }
        return res;
    }

    bool helper(int n) {
        for (int i = 2; i * i < n; ++i) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};