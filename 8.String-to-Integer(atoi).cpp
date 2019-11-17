//
// Created by hqnddw on 2019/11/5.
//
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
static int x = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int myAtoi(string s) {
        stringstream ss(s);
        int t = 0;
        ss >> t;
        return t;
    }
};
