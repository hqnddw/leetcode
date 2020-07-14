//
// Created by hqnddw on 2019/11/7.
//

class Solution1 {
public:
    int jumpFloorII(int number) {
        if (number <= 1)
            return number;
        return 2 * jumpFloorII(number - 1);
    }
};


class Solution2 {
public:
    int jumpFloorII(int number) {
        if (number <= 1)
            return number;
        int res = 1;
        while (--number > 0) {
            res = res * 2;
        }
        return res;
    }
};