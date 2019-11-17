//
// Created by hqnddw on 2019/11/17.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if (str.empty()) return res;
        string s;
        helper(res, s, str);
        return res;
    }

    void helper(vector<string> &res, string &s, string &str) {
        if (s.size() == str.size()) {
            res.push_back(s);
            return;
        }
        for (int i = 0; i < str.size(); ++i) {
            if (s.find(str[i]) != string::npos) continue;
            s.push_back(str[i]);
            helper(res, s, str);
            s.pop_back();
        }
    }
};