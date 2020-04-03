//
// Created by hqnddw on 2019/10/23.
//
#include <algorithm>

class Solution1 {
public:
    int mySqrt(int x) {
        int lo = 1;
        int hi = x;
        if (x == 0) return 0;
        while (lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (mid == x / mid)
                return mid;
            else if (mid > x / mid)
                hi = mid - 1;
            else lo = mid + 1;
        }
        return hi;
    }
};