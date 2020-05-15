//
// Created by hqnddw on 2020/5/2.
//
class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (!isBadVersion(mid))
                lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};
