//
// Created by hqnddw on 2020/4/4.
//
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        string str = process(s);
        int n = str.size();
        for (int i = 0; i < n / 2; ++i) {
            if (str[i] != str[n - i - 1])
                return false;
        }
        return true;
    }

    string process(string &s) {
        string res;
        for (auto c: s) {
            if (isalpha(c) || isdigit(c))
                res += tolower(c);
        }
        return res;
    }
};