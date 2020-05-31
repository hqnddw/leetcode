//
// Created by yida on 2020/5/28.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int l = 0, r = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                l++;
            else if (s[i] == ')') {
                if (l != 0)
                    l--;
                else r++;
            }
        }
        dfs(s, res, 0, r, l);
        return res;
    }

    bool isValid(string &s) {
        int count = 0;
        for (char c :s) {
            if (c == '(') count++;
            if (c == ')') count--;
            if (c < 0)return false;
        }
        return count == 0;
    }

    void dfs(string &s, vector<string> &res, int start, int l, int r) {
        if (l == 0 && r == 0) {
            if (isValid(s)) {
                res.push_back(s);
                return;
            }
        }
        for (int i = start; i < s.size(); ++i) {
            if (i > start && s[i] == s[i - 1]) continue;
            if (s[i] == '(' || s[i] == ')') {
                string tmp = s;
                tmp.erase(i, 1);
                if (r > 0)
                    dfs(tmp, res, i, l, r - 1);
                else if (l > 0)
                    dfs(tmp, res, i, l - 1, r);
            }
        }
    }
};