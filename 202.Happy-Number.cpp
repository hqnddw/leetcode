//
// Created by hqnddw on 2020/4/30.
//
class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = helper(slow);
            fast = helper(helper(fast));
        } while (fast != slow);
        return slow == 1;
    }

    int helper(int n) {
        int res = 0;
        while (n) {
            int t = n % 10;
            res += t * t;
            n /= 10;
        }
        return res;
    }
};
