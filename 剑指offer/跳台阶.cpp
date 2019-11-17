//
// Created by hqnddw on 2019/11/7.
//
#include <vector>

using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        if (number <= 2)
            return number;
        int a = 1;
        int b = 2;
        while (number - 2 > 0) {
            b = a + b;
            a = b - a;
            number--;
        }
        return b;
    }
};