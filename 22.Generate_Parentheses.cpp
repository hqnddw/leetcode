//
// Created by hqnddw on 2019/9/11.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution1 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", n, 0, 0);
        return res;
    }

    void backtrack(vector<string> res, string s, int max, int left, int right) {
        if (s.size() == max * 2) {
            res.push_back(s);
            return;
        }
        if (left < max)
            backtrack(res, s + "(", max, left + 1, right);
        if (left > right)
            backtrack(res, s + ")", max, left, right + 1);
    }
};


class Solution2 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, n, "", 0, 0);
        return res;
    }

    void backtrack(vector<string> &res, int max, string s, int left, int right) {
        if (s.size() == max * 2) {
            res.push_back(s);
            return;
        }
        if (left < max)
            backtrack(res, max, s + "(", left + 1, right);
        if (right < left)
            backtrack(res, max, s + ")", left, right + 1);
    }
};