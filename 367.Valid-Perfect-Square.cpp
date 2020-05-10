//
// Created by hqnddw on 2020/5/9.
//

class Solution {
public:
    bool isPerfectSquare(int num) {
        int lo = 0;
        int hi = num;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid == num / mid && (num % mid == 0))
                return true;
            else if (mid * mid < num)
                lo = mid + 1;
            else hi = mid - 1;
        }
        return false;
    }
};