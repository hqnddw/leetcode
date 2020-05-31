//
// Created by yida on 2020/5/20.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {

        vector<int> res;
        for (int i = left; i <= right; ++i) {
            if (helper(i))
                res.push_back(i);
        }
        return res;
    }

    bool helper(int n) {
        int tmp = n;
        while (n) {
            if (n % 10 == 0) return false;
            int a = n % 10;
            if (tmp % a != 0) return false;
            n /= 10;
        }
        return true;
    }
};
