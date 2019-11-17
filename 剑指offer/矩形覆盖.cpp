//
// Created by hqnddw on 2019/11/11.
//

class Solution {
public:
    int rectCover(int number) {
        if (number < 1) return 0;
        int f = 1, g = 2;
        while (--number) {
            g = f + g;
            f = g - f;
        }
        return f;
    }
};