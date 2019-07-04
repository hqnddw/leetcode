//
// Created by hqnddw on 2019/6/29.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1 || n == 2)
            return n;
        int one_step_before = 2;
        int two_step_before = 1;
        int all = 0;
        for (int i = 3; i <= n; ++i) {
            all = one_step_before + two_step_before;
            two_step_before = one_step_before;
            one_step_before = all;
        }
        return all;
    }
};

//int main() {
//    Solution s;
//    cout << s.climbStairs(4) << endl;
//}